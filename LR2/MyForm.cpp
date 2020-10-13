#include "MyForm.h"
#include <Windows.h>
#include <iostream>



using namespace System;
using namespace System::Windows::Forms;


using namespace std;

//[STAThreadAttribute]
void main(/*array<String>* args*/) {
	/*int i;
	cout << "tst" << endl;
	
	TSimulator* Sim = new TSimulator();
	//0-x; 1-y; 2-velocity; 3-course; 4-acceleration; 5-radius; 6-SafetyDistanse;
	double params[] = { 0,0,0,-1,0,100,10 };
	//0-CP; 1-RSL;2-Air;3-Miss;

	Sim->CreateObject(0, params);
	Sim->CreateObject(1, params);
	params[0] = 20; params[1] = 20; params[2] = 5;
	Sim->CreateObject(2, params);
	
	cout.setf(ios::fixed);
	cout << "CP : X:" << Sim->CP->get_x()<< "  Y: " << Sim->CP->get_x() << "  SafetyD:" << Sim->CP->SafetyDistance<< endl;
	cout << "RSL: X:" << Sim->RLS->get_x() << "  Y: "<< Sim->RLS->get_y() << "  MaxD:" << Sim->RLS->get_RMax() << endl;
	cout << "Targ: X:" << Sim->Targets[0]->get_x()<<"  Y: " << Sim->Targets[0]->get_y() << " Velocity:" << Sim->Targets[0]->get_Vel()<<" Ang: "<< Sim->Targets[0]->get_Ang()<<  "  Ty:"<< Sim->Targets[0]->getTargetType() << endl;

	Sim->Run();

	delete Sim;

	
	
	cin >> i;*/
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);


	LR2::MyForm form;
	Application::Run(% form);

}

