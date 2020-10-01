#pragma once
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Перечисляемый тип с типами целей
enum class target_type { Unknown, Missile, Aircraft };

// Базовый класс цели
class TTarget
{
public:
	TTarget(); // Конструктор
	~TTarget() {}; // Деструктор(формальный)

	// Получение типа цели данного экземпляра
	string getTargetType()
	{
		if (TargetType == target_type::Missile)
			return "Missile";
		else if (TargetType == target_type::Aircraft)
			return "Aircraft";
		else
			return "Unknown";
	}

	// Абстрактный метод движения, будет переобпределен в наследуемых классах
	virtual void Move(float t) = 0;

	// геттеры
	float get_x() { return x; }
	float get_y() { return y; }

protected:
	float StartX, StartY, Vel, Ang;
	target_type TargetType;
	float Time, x,y;
};

// Базовый конструктор
TTarget::TTarget() {
	StartX = 0; StartY = 0; Vel = 0; Ang = 0;
	TargetType = target_type::Unknown;
	Time = 0; x = 0; y = 0;
}


// Класс самолета, наследуется от цели
class TAircraft : public TTarget
{
public:
	TAircraft(float aX, float aY, float aVel, float ang); // Конструктор
	virtual void Move(float ti); // метод движения
};

// Конструктор. Присваевает переданные параметры соответсвующим переменным
TAircraft::TAircraft(float aX, float aY, float aVel, float ang)
{
	StartX = aX;
	StartY = aY;
	Vel = aVel;
	Ang = ang;
	TargetType = target_type::Aircraft;
	// Сообщение о создании цели
	cout << "TAircraft was created" << endl;
}


// Метод движения
void TAircraft::Move(float ti)
{
	Time = ti; // Обновление времени(устанавливается текущее)

	x = StartX - Vel * cos(Ang) * (ti); // Текущая координата X
	y = StartY - Vel * sin(Ang) * (ti); // екущая координата Y
}


//Класс Ракеты, наследуется от базового класса цели
class TMissile : public TTarget
{
public:
	// Измененный конструктор( не успел разобраться с наследованием конструкторов)
	TMissile(float aX, float aY, float aVel, float ang, float aAccel, float max_speed);
	~TMissile() {};// Формальный деструктор

	virtual void Move(float ti);
private:
	// Класс расширяется ускорением и максимальной скоростью
	float Accel, max_speed;
};

// Конструктор
TMissile::TMissile(float aX, float aY, float aVel, float ang, float aAccel, float amax_speed)
{
	StartX = aX;
	StartY = aY;
	Vel = aVel;
	Ang = ang;
	Accel = aAccel;
	max_speed = amax_speed;
	TargetType = target_type::Missile;

	cout << "Missile was creaated" << endl;
}

// Метод движения 
void TMissile::Move(float ti)
{
	Time = ti; // Обновление времени(текущее)
	float nVel = Vel + Accel * (ti); //Текущая скорость
	// Ограничение на максимальную скорость
	if (nVel > max_speed)
		nVel = max_speed;

	x = StartX - nVel * cos(Ang) * (ti); // Текущая координата X
	y = StartY - nVel * sin(Ang) * (ti); // Текущая координата Y
}


//Класс РЛС
class TRadar
{
public:
	TRadar(float aX, float aY, float aMaxDistance, float adt, int aN);
	~TRadar();

	TTarget** targets;
	void Peleng(float t0, float tk);
	float get_MaxDistance() { return MaxDistance; };
	int get_NTargets() { return NTargets; };

private:
	float x, y, dt, MaxDistance;
	int NTargets;
	string filename;
};

// Конструктор
TRadar::TRadar(float aX, float aY, float aMaxDistance, float adt, int aN)
{
	x = aX;
	y = aY;
	MaxDistance = aMaxDistance;
	dt = adt;
	NTargets = aN;

	// Имя файла логгирования
	filename = "LR1.log.txt";

	//Пересоздание(очистка файла)
	ofstream fout(filename);
	fout.close();

	// Инициализация массива целей
	targets = new TTarget*[NTargets];

}

// Деструктор
TRadar::~TRadar()
{
	for (int i = 0; i < NTargets; i++)
		delete targets[i]; // Очистка памяти на каждую цель
	delete targets; // Очистка памяти для маасива целей
}

// Метод отслеживания
void TRadar::Peleng(float t0, float tk)
{
	// ОТкрытие файла на дозапись в конец
	ofstream fout(filename, ios_base::app);
	fout.setf(ios::fixed);// Установление правил вывода чисел с плавающей точкой

	// Информация о временном интервале и шаге
	fout << "Peling(" << t0 << "," << tk << ") dt=" << dt << endl;

	float t = t0; // Установка текущего времени на начальное

	while (t <= tk) // По всему отслеживаемому промежутку
	{
		fout << "--t=" << t << endl; // Текущее время

		// Для каждой из отслеживаемых целей
		for (int i = 0; i < NTargets; i++)
		{
			targets[i]->Move(t); // Вычисляем положение в данный момент времени
			float dx = targets[i]->get_x() - x; // Получаем расстояние до цели по оси X
			float dy = targets[i]->get_y() - y; // Получаем расстояние до цели по оси Y
			float d = sqrt(dx*dx + dy*dy); // Расстояние до цели

			//Вывод информации о цели
			fout << "----Target" << i << " " << targets[i]->getTargetType() << " D=" << d;
			if (d <= MaxDistance) //Если радар видит цель
			{
				float e = atan2(dx, dy);
				fout << "  eps="; fout << e; fout << " rad = ";fout << e * 180.0 / 3.14;
			}

			if (d < 1) //Если цель критически близко к РЛС - РЛС - уничтожена
			{
				fout << endl;
				fout<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
				cout << "LOST CONNECTION";
				return;
			}
			fout << endl;			
		}
		t += dt; // Увеличиваем текущее время на шаг dt
	}
	fout.close();
}