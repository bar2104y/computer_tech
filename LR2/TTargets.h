#pragma once
#include <iostream>
#include "types.h"

using namespace std;

// Базовый класс цели
class TTarget : public TPosObject
{
public:
	// Конструктор по умолчанию
	TTarget(): TPosObject()
	{
		TargetType = target_type::Unknown;
		Vel = 0;
		Ang = 0;
	}
	// Конструктор
	TTarget(double x, double y, double t, double vel, double ang) : TPosObject(x, y, t)
	{
		TargetType = target_type::Unknown;
		Vel = vel;
		Ang = ang;
	}
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
	virtual void Move(double t) {};

	double get_Vel() { return Vel; }
	double get_Ang() { return Ang; }

protected:
	double Vel, Ang;
	target_type TargetType;
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
	CurTime = t; // Обновление времени(устанавливается текущее)

	CurPosition.x = InitPosition.x + Vel * cos(Ang) * (t); // Текущая координата X
	CurPosition.y = InitPosition.y + Vel * sin(Ang) * (t); // екущая координата Y
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
{
	CurTime = t; // Обновление времени(текущее)
	double nVel = Vel + Accel * (t); //Текущая скорость

	CurPosition.x = InitPosition.x + nVel * cos(Ang) * (t); // Текущая координата X
	CurPosition.y = InitPosition.y + nVel * sin(Ang) * (t); // Текущая координата Y
}
