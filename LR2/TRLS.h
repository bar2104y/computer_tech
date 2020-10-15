#pragma once
#include <iostream>
#include "TTargets.h"

using namespace std;

class TRLS : public TPosObject
{
private:
	double RMax, // радиус обнаружения
		Distace, Peleng; // Дистанция и курс текущей  цели
		

public:
	TRLS() : TPosObject() {
		RMax = 0;
		Distace = 0;
		Peleng = 0;
	};
	TRLS(double x, double y, double t, double r) : TPosObject(x, y, t) {
		RMax = r;
		Distace = 0;
		Peleng = 0;
	};
	~TRLS() {};

	virtual bool Measure(TTarget target); // Видит ли цель
	virtual void Move(double t) {};

	void set_Distance(double d) { Distace = d; }
	void set_Peleng(double p) { Peleng = p; }

	double get_Distance() { return Distace; }
	double get_Peleng() { return Peleng; }
	double get_RMax() { return RMax; }


};

bool TRLS::Measure(TTarget target)
{
	double dx = target.get_x() - CurPosition.x; // Получаем расстояние до цели по оси X
	double dy = target.get_y() - CurPosition.y; // Получаем расстояние до цели по оси Y
	//,,cout << RMax << " dx:" <<dx <<" y:"<<dy <<" d:" << sqrt(dx * dx + dy * dy) << endl;
	if (RMax > sqrt(dx * dx + dy * dy))
		return true;
	else
		return false;
}
