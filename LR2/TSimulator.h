#pragma once
#include <fstream>
#include <cmath>
#include "types.h"
#include "TTargets.h"
#include "TRLS.h"
#include "TCommandPost.h"


class TSimulator
{
public:
	TSimulator();
	~TSimulator() {};

	virtual void Move(double t) {};
	int CreateObject(int type, double params[]);
	int Run();

	unsigned int get_CountTarget() { return CountTarget; }

public:
	double t0, tk, dt;
	TRLS *RLS;
	TCommandPost *CP;
	TTarget** Targets;
	
	ofstream FT;
	unsigned int CountTarget;

	double getCourse(double x, double y);
};

TSimulator::TSimulator()
{
	RLS = new TRLS();
	CP = new TCommandPost();
	CountTarget = 0;
	Targets = new TTarget * [0];
	
	t0 = 0.0; tk = 10.0;
	dt = 0.1;

	FT.open("result.txt");
	FT.close();
}

double TSimulator::getCourse(double x, double y)
{
	return atan2(y, x);
}

int TSimulator::CreateObject(int type, double params[])
{
	//0-Command Post; 1-RLS; 2-Aircraft; 3-Missile

	if (type == 2 || type == 3)
	{
		CountTarget++;
		TTarget** nTargets = new TTarget* [CountTarget];

		for (unsigned int i = 0; i < CountTarget-1; i++)
			nTargets[i] = Targets[i];
		//delete[] Targets;

		Targets = nTargets;

		if (params[3] < 0)
			params[3] = getCourse(params[0], params[1])+3.14;
	}
	// params[]
	//0-x; 1-y; 2-velocity; 3-course; 4-acceleration; 5-radius; 6-SafetyDistanse;
	switch (type)
	{
	case 0:
		try
		{
			CP = new TCommandPost(params[0], params[1], 0, params[6]);
		}
		catch (const std::exception&)
		{
			return 4;
		}
		break;
	case 1:
		try
		{
			RLS = new TRLS(params[0], params[1], 0, params[5]);
		}
		catch (const std::exception&)
		{
			return 5;
		}
		break;
	
	case 2:
		try
		{
			Targets[CountTarget - 1] = new TAircraft(params[0], params[1], 0, params[2], params[3]);
		}
		catch (const std::exception&)
		{
			return 2;
		}	
		break;
	case 3:
		try
		{
			Targets[CountTarget - 1] = new TMissile(params[0], params[1], 0, params[2], params[3], params[4]);
		}
		catch (const std::exception&)
		{
			return 3;
		}
		break;
	default:
		return 1;
		break;
	}
	return 0;
}

int TSimulator::Run()

{
	FT.open("result.txt", ios_base::app);
	FT.setf(ios::fixed);
	FT << "Peling(" << t0 << "," << tk << ") dt=" << dt << endl;
	
	double t = t0;
	while (t <= tk) // По всему отслеживаемому промежутку
	{
		FT << "--t=" << t << endl; // Текущее время

		// Для каждой из отслеживаемых целей
		for (unsigned int i = 0; i < CountTarget; i++)
		{
			Targets[i]->Move(t); // Вычисляем положение в данный момент времени
			if (RLS->Measure(*Targets[i]))
			{
				double dx = Targets[i]->get_x() - CP->get_x(); // Получаем расстояние до цели по оси X
				double dy = Targets[i]->get_y() - CP->get_y(); // Получаем расстояние до цели по оси Y
				double d = sqrt(dx * dx + dy * dy); // Расстояние до цели
				double e = atan2(dy, dx);

				RLS->set_Distance(d);
				RLS->set_Peleng(e);
			

				//Вывод информации о цели
				FT << "----Target" << i << " " << Targets[i]->getTargetType() << " D=" << RLS->get_Distance();
				
				FT << "  rad="; FT << e; FT << " deg = "; FT << e * 180.0 / 3.14;

				
				if (RLS->get_Distance() < CP->SafetyDistance) //Если цель критически близко к РЛС - РЛС - уничтожена
				{
					FT << endl;
					FT << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Командный пункт уничтожен!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
				}
			}

			
			FT << endl;
		}
		t += dt; // Увеличиваем текущее время на шаг dt
	}

	FT.close();
	return 0;
}