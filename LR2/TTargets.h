#pragma once
#include <iostream>
#include "types.h"

using namespace std;

class TTarget : public TPosObject
{
public:
	TTarget(): TPosObject() {};
	TTarget(double x, double y, double t, double vel, double ang) : TPosObject(x, y, t)
	{
		TargetType = target_type::Unknown;
		Vel = vel;
		Ang = ang;
	}
	~TTarget() {}; // ����������(����������)

	// ��������� ���� ���� ������� ����������
	string getTargetType()
	{
		if (TargetType == target_type::Missile)
			return "Missile";
		else if (TargetType == target_type::Aircraft)
			return "Aircraft";
		else
			return "Unknown";
	}

	// ����������� ����� ��������, ����� �������������� � ����������� �������
	virtual void Move(double t) {};

	double get_Vel() { return Vel; }
	double get_Ang() { return Ang; }

protected:
	double Vel, Ang;
	target_type TargetType;
};

/********************************************************************/
class TAircraft : public TTarget
{
public:
	TAircraft(double x, double y, double t, double vel, double ang) : TTarget(x, y, t, vel, ang)
	{
		TargetType = target_type::Aircraft;
	};
	~TAircraft() {};
	virtual void Move(double t); // ����� ��������
};

// ����� ��������
void TAircraft::Move(double t)
{
	CurTime = t; // ���������� �������(��������������� �������)

	CurPosition.x = InitPosition.x + Vel * cos(Ang) * (t); // ������� ���������� X
	CurPosition.y = InitPosition.y + Vel * sin(Ang) * (t); // ������ ���������� Y
}

/********************************************************************/
//����� ������, ����������� �� �������� ������ ����
class TMissile : public TTarget
{
public:
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

// ����� �������� 
void TMissile::Move(double t)
{
	CurTime = t; // ���������� �������(�������)
	double nVel = Vel + Accel * (t); //������� ��������

	CurPosition.x = InitPosition.x + nVel * cos(Ang) * (t); // ������� ���������� X
	CurPosition.y = InitPosition.y + nVel * sin(Ang) * (t); // ������� ���������� Y
}
