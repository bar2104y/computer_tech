#pragma once
#include <iostream>
#include "types.h"

//typedef float(*movement_)(int);

#define COUNT_FUNCTIONS			7
#define default_Cx				1.0
#define default_P				1.0
#define default_mass			1.0

#define default_rocket_mass		1.0
#define default_ro				1.0
#define default_S				2.0
#define default_rocket_S		1.0
#define default_massfuel0		10.0
#define default_mass_crit		4.0


using namespace std;

// Базовый класс цели
class TTarget : public TPosObject
{
public:
	friend class Integrator;
	friend class TEuler;
	// Конструктор по умолчанию
	void init()
	{
		P0 = default_P;
		P = P0;
		Xdrag = 0;
		mass = default_mass;
		Cx = default_Cx;
		ro = default_ro;
		S = default_S;
		mass_fuel = default_massfuel0;
		mass_crit = default_mass_crit;

		dt = d_dt;
		state_vector = new double[COUNT_FUNCTIONS];
		for (int i = 0; i < COUNT_FUNCTIONS; i++)
			state_vector[i] = 0;
		
		steps_count = 0;
		ofstream FT;
		FT.open("dump.log.txt");
		FT.close();



		TargetType = target_type::Unknown;
	};
	TTarget(): TPosObject()
	{
		init();
	}
	TTarget(double x, double y, double t, double vel, double ang) : TPosObject(x, y, t)
	{
		init();

		state_vector[0] = x;
		state_vector[1] = y;
		state_vector[2] = vel;
		state_vector[3] = Cx * ro * state_vector[2] * state_vector[2] * S / 2;
		state_vector[4] = P0;
		state_vector[5] = default_massfuel0;
		state_vector[6] = ang;
		
		this->dump();
	}
	~TTarget() {};

	string getTargetType()
	{
		if (TargetType == target_type::Missile)
			return "Missile";
		else if (TargetType == target_type::Aircraft)
			return "Aircraft";
		else
			return "Unknown";
	}
	
	virtual void Move(double t) {};

	double get_Vel() { return state_vector[0]; }
	double get_Ang() { return state_vector[6]; }

	void dump() {
		ofstream FT;
		FT.open("dump.log.txt", ios_base::app);
		FT.setf(ios::fixed);
			FT<<" X: "<<state_vector[0]<< " Y: " << state_vector[1]<< " V: " << state_vector[2]<< " Xdrag: " << state_vector[3]<< " P: " << state_vector[4]<< " massFuel: " << state_vector[5] << " Angle: " << state_vector[6] <<endl;
		FT.close();
	};
	//0-x 1-y 2-v 3-xdrag 4-p 5-mfuel; 6-Angle
	double* state_vector;
	unsigned int steps_count;
public:
	//Законы движения
	double Fdmdt() { return -0.4; };
	double Fx() { return state_vector[2] * cos(state_vector[6]); };
	double Fy() { return state_vector[2] * sin(state_vector[6]); };
	double Fvel() { return (FP() - FXdrag())/ (state_vector[5]+default_mass); };
	double FXdrag() { return Cx*ro* state_vector[2] * state_vector[2] *S/2; };
	double FP()
	{
		if (state_vector[5] >= mass_crit)
			return P0;
		if (state_vector[5] > 0)
			return state_vector[5] / mass_crit;
		else
			return 0;
	};;
	double Fmass_fuel()
	{
		if (state_vector[5] >0) return Fdmdt();
		else return 0.0;
	};

	double functions(int i)
	{
		switch (i)
		{
		case 0:
			return Fx();
			break;
		case 1:
			return Fy();
			break;
		case 2:
			return Fvel();
			break;
		case 3:
			return FXdrag();
			break;
		case 4:
			return FP();
			break;
		case 5:
			return Fmass_fuel();
			break;
		case 6:
			return state_vector[6];
			break;
		default:
			break;
		}
	};
	
	double dt;

	target_type TargetType;
private:

	
	void Synchronization(double* vector)
	{
		for (int i = 0; i < COUNT_FUNCTIONS; i++)
			state_vector[i] = vector[i];
	};

	double P0, mass_obj, mass_fuel, mass_crit;

	double P, Xdrag, mass, Cx, ro, S;
	unsigned int last_iter;
};



/********************************************************************/
// Цель- САМОЛЕТ
class TAircraft : public TTarget
{
public:
	TAircraft() :TTarget()
	{
		TargetType = target_type::Aircraft;
	}
	TAircraft(double x, double y, double t, double vel, double ang) : TTarget(x, y, t, vel, ang)
	{
		TargetType = target_type::Aircraft;
	}
	~TAircraft() {};

	virtual void Move(double t); // метод движения
};

// Метод движения
void TAircraft::Move(double t)
{
	/*CurTime = t; // Обновление времени(устанавливается текущее)

	CurPosition.x = InitPosition.x + Vel * cos(Ang) * (t); // Текущая координата X
	CurPosition.y = InitPosition.y + Vel * sin(Ang) * (t); // екущая координата Y*/
}


/********************************************************************/
//Класс Ракеты, наследуется от базового класса цели
class TMissile : public TTarget
{
public:
	// Конструктор по умолчанию
	TMissile() : TTarget() {
		TargetType = target_type::Missile;
		Accel = 0;
	}
	// Конструктор
	TMissile(double x, double y, double t, double vel, double ang, double accel) : TTarget(x, y, t, vel, ang)
	{
		TargetType = target_type::Missile;
		Accel = accel;
	};
	~TMissile() {};

	virtual void Move(double t);
protected:
	double Accel;
};

// Метод движения 
void TMissile::Move(double t)
{/*
	CurTime = t; // Обновление времени(текущее)
	double nVel = Vel + Accel * (t); //Текущая скорость

	CurPosition.x = InitPosition.x + nVel * cos(Ang) * (t); // Текущая координата X
	CurPosition.y = InitPosition.y + nVel * sin(Ang) * (t); // Текущая координата Y*/
}
