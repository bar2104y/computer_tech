#pragma once
#include "types.h"

class TCommandPost : public TPosObject
{
public:
	TCommandPost() : TPosObject() {};
	TCommandPost(double x, double y, double t, double sd) : TPosObject(x, y, t)
	{
		SafetyDistance = sd;
	};
	~TCommandPost() {};

	virtual void Move(double t) {};

	double SafetyDistance;

};