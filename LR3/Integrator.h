#pragma once
#include "TTargets.h";



class Integrator
{
public:
	Integrator() {}
	virtual void Intergate(TTarget *target, int n, float t0, float tk, float dt)=0;
	virtual void OneStep(TTarget* target, int n, float t0, float dt) { };
	~Integrator() {};
protected:

};

class TEuler :Integrator
{
public:
	TEuler() {};
	~TEuler() {};

	virtual void Intergate(TTarget* target, int n, float t0, float tk, float dt);
	virtual double* OneStep(TTarget* target, int n, float dt);
};

void TEuler::Intergate(TTarget* target, int n, float t0, float tk, float dt)
{
	while (t0 < tk)
	{
		OneStep(target, n, dt);
		t0 += dt;
	}
};
double* TEuler::OneStep(TTarget* target, int n, float dt)
{
	double* res = new double[n];
	for (int i = 0; i < n; i++)
		res[i] = target->state_vector[i] + target->functions(i) * dt;

	target->Synchronization(res);

	return res;

};