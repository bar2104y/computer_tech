#pragma once
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

enum target_type { Unknown, Missile, Aircraft };

class TTarget
{
public:
	TTarget() {};
	TTarget(float aX, float aY, float aVel, float ang);
	~TTarget();

	string getTargetType()
	{
		if (TargetType == Missile)
			return "Missile";
		else if (TargetType == Aircraft)
			return "Aircraft";
		else
			return "Unknown";
	}

	virtual void Move(float t) = 0;

	float get_x() { return x; }
	float get_y() { return y; }

protected:
	float StartX, StartY, Vel, Ang;
	target_type TargetType;
	float Time, x,y;
};

TTarget::TTarget(float aX, float aY, float aVel, float ang)
{
	StartX = aX;
	StartY = aY;
	Vel = aVel;
	Ang = ang;
	TargetType = Aircraft;
	cout << "TTarget" << endl;
}

TTarget::~TTarget()
{
}



class TAircraft : public TTarget
{
public:
	TAircraft(float aX, float aY, float aVel, float ang) : TTarget(aX, aY, aVel, ang) {};
	virtual void Move(float ti);
};

void TAircraft::Move(float ti)
{
	Time = ti;

	x = StartX - Vel * cos(Ang) * (ti);
	y = StartY - Vel * sin(Ang) * (ti);
}

class TMissile : public TTarget
{
public:
	TMissile(float aX, float aY, float aVel, float ang, float aAccel);
	~TMissile();

	virtual void Move(float ti);
private:
	float Accel;
};

TMissile::TMissile(float aX, float aY, float aVel, float ang, float aAccel)
{
	StartX = aX;
	StartY = aY;
	Vel = aVel;
	Ang = ang;
	Accel = aAccel;
	TargetType = Missile;

	cout << "Missile";
}

TMissile::~TMissile()
{
}


void TMissile::Move(float ti)
{
	Time = ti;
	x = StartX - (Vel + Accel * (ti)) * cos(Ang) * (ti);
	y = StartY - (Vel + Accel * (ti)) * sin(Ang) * (ti);
}

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
	// ofstream fout;
	string filename;
};

TRadar::TRadar(float aX, float aY, float aMaxDistance, float adt, int aN)
{
	x = aX;
	y = aY;
	MaxDistance = aMaxDistance;
	dt = adt;
	NTargets = aN;

	filename = "LR1.log.txt";

	ofstream fout(filename);
	fout.close();

	targets = new TTarget*[NTargets];

	/*for (int i = 0; i < NTargets; i++)
	{
		cout << "Enter type (1-Aircaraft; 2-Missile):";
		int tmp;
		float x, y;
		cin >> tmp;
		cout << "Start X and Y";
		cin >> x, y;

	}*/


}

TRadar::~TRadar()
{
	for (int i = 0; i < NTargets; i++)
		delete targets[i];
	delete targets;
}

void TRadar::Peleng(float t0, float tk)
{
	
	ofstream fout(filename, ios_base::app);
	fout.setf(ios::fixed);

	fout << "Peling(" << t0 << "," << tk << ") dt=" << dt << endl;
	//writeln(fout, 'Peling(', t0:4 : 4, ',', tk : 4 : 4, ')  dt=', dt : 4 : 4);
	float t = t0;

	while (t <= tk)
	{
		//writeln(fout, '--t=', t:3 : 3);
		fout << "--t=" << t << endl;

		for (int i = 0; i < NTargets; i++)
		{
			targets[i]->Move(t);
			float dx = targets[i]->get_x() - x;
			float dy = targets[i]->get_y() - y;
			float d = sqrt(dx*dx + dy*dy);


			//write(fout, '----Target', i, ' ', targets[i] ^ .getTargetType, ' D=', d:4 : 4);
			fout << "----Target" << i << " " << targets[i]->getTargetType() << " D=" << d;
			if (d <= MaxDistance) 
			{
				float e = atan2(dx, dy);
				
				//write(fout, '  eps=', e:1 : 4, ' rad = ', e * 180 / pi : 3 : 5);
				fout << "  eps="; fout << e; fout << " rad = ";fout << e * 180 / 3.14;
			}

			if (d < 1) 
			{
				fout << endl;
				fout<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
				// writeln(fout, '');
				//write(fout, '!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!');
			}
			fout << endl;
			// writeln(fout, '');
			
		}
		t += dt;
		
		//flush(fout);
	}
	fout.close();
}