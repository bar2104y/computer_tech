#pragma once
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// ������������� ��� � ������ �����
enum class target_type { Unknown, Missile, Aircraft };

// ������� ����� ����
class TTarget
{
public:
	TTarget(); // �����������
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
	virtual void Move(float t) = 0;

	// �������
	float get_x() { return x; }
	float get_y() { return y; }

protected:
	float StartX, StartY, Vel, Ang;
	target_type TargetType;
	float Time, x,y;
};

// ������� �����������
TTarget::TTarget() {
	StartX = 0; StartY = 0; Vel = 0; Ang = 0;
	TargetType = target_type::Unknown;
	Time = 0; x = 0; y = 0;
}


// ����� ��������, ����������� �� ����
class TAircraft : public TTarget
{
public:
	TAircraft(float aX, float aY, float aVel, float ang); // �����������
	virtual void Move(float ti); // ����� ��������
};

// �����������. ����������� ���������� ��������� �������������� ����������
TAircraft::TAircraft(float aX, float aY, float aVel, float ang)
{
	StartX = aX;
	StartY = aY;
	Vel = aVel;
	Ang = ang;
	TargetType = target_type::Aircraft;
	// ��������� � �������� ����
	cout << "TAircraft was created" << endl;
}


// ����� ��������
void TAircraft::Move(float ti)
{
	Time = ti; // ���������� �������(��������������� �������)

	x = StartX - Vel * cos(Ang) * (ti); // ������� ���������� X
	y = StartY - Vel * sin(Ang) * (ti); // ������ ���������� Y
}


//����� ������, ����������� �� �������� ������ ����
class TMissile : public TTarget
{
public:
	// ���������� �����������( �� ����� ����������� � ������������� �������������)
	TMissile(float aX, float aY, float aVel, float ang, float aAccel, float max_speed);
	~TMissile() {};// ���������� ����������

	virtual void Move(float ti);
private:
	// ����� ����������� ���������� � ������������ ���������
	float Accel, max_speed;
};

// �����������
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

// ����� �������� 
void TMissile::Move(float ti)
{
	Time = ti; // ���������� �������(�������)
	float nVel = Vel + Accel * (ti); //������� ��������
	// ����������� �� ������������ ��������
	if (nVel > max_speed)
		nVel = max_speed;

	x = StartX - nVel * cos(Ang) * (ti); // ������� ���������� X
	y = StartY - nVel * sin(Ang) * (ti); // ������� ���������� Y
}


//����� ���
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

// �����������
TRadar::TRadar(float aX, float aY, float aMaxDistance, float adt, int aN)
{
	x = aX;
	y = aY;
	MaxDistance = aMaxDistance;
	dt = adt;
	NTargets = aN;

	// ��� ����� ������������
	filename = "LR1.log.txt";

	//������������(������� �����)
	ofstream fout(filename);
	fout.close();

	// ������������� ������� �����
	targets = new TTarget*[NTargets];

}

// ����������
TRadar::~TRadar()
{
	for (int i = 0; i < NTargets; i++)
		delete targets[i]; // ������� ������ �� ������ ����
	delete targets; // ������� ������ ��� ������� �����
}

// ����� ������������
void TRadar::Peleng(float t0, float tk)
{
	// �������� ����� �� �������� � �����
	ofstream fout(filename, ios_base::app);
	fout.setf(ios::fixed);// ������������ ������ ������ ����� � ��������� ������

	// ���������� � ��������� ��������� � ����
	fout << "Peling(" << t0 << "," << tk << ") dt=" << dt << endl;

	float t = t0; // ��������� �������� ������� �� ���������

	while (t <= tk) // �� ����� �������������� ����������
	{
		fout << "--t=" << t << endl; // ������� �����

		// ��� ������ �� ������������� �����
		for (int i = 0; i < NTargets; i++)
		{
			targets[i]->Move(t); // ��������� ��������� � ������ ������ �������
			float dx = targets[i]->get_x() - x; // �������� ���������� �� ���� �� ��� X
			float dy = targets[i]->get_y() - y; // �������� ���������� �� ���� �� ��� Y
			float d = sqrt(dx*dx + dy*dy); // ���������� �� ����

			//����� ���������� � ����
			fout << "----Target" << i << " " << targets[i]->getTargetType() << " D=" << d;
			if (d <= MaxDistance) //���� ����� ����� ����
			{
				float e = atan2(dx, dy);
				fout << "  eps="; fout << e; fout << " rad = ";fout << e * 180.0 / 3.14;
			}

			if (d < 1) //���� ���� ���������� ������ � ��� - ��� - ����������
			{
				fout << endl;
				fout<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
				cout << "LOST CONNECTION";
				return;
			}
			fout << endl;			
		}
		t += dt; // ����������� ������� ����� �� ��� dt
	}
	fout.close();
}