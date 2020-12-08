﻿#pragma once
#include "TSimulator.h"

namespace LR2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			Sim = new TSimulator();
			//
			//TODO: добавьте код конструктора
			//
		};
		void updateObjectList();
		void Graph();
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			delete Sim;
			if (components)
			{
				delete components;
			}
		}
	protected:TSimulator* Sim;
	private: System::Windows::Forms::Label^ header;
	private: System::Windows::Forms::Button^ btn_create_obj;
	private: System::Windows::Forms::TextBox^ y_coord;





	private: System::Windows::Forms::Label^ lbl_RLS_y_coord;
	private: System::Windows::Forms::TextBox^ x_coord;

	private: System::Windows::Forms::Label^ lbl_RLS_x_coord;
	private: System::Windows::Forms::Label^ lbl1;
	private: System::Windows::Forms::Button^ btn_open_create_Target;
	private: System::Windows::Forms::TextBox^ velocity;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ course;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ acceleration;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::RadioButton^ radioButton_CP;
	private: System::Windows::Forms::RadioButton^ radioButton_RLS;
	private: System::Windows::Forms::RadioButton^ radioButton_Air;
	private: System::Windows::Forms::RadioButton^ radioButton_Miss;
	private: System::Windows::Forms::TextBox^ safety_d;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ radius;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Label^ label8;
	private: System::DirectoryServices::DirectorySearcher^ directorySearcher1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ X;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Y;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Vel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Azimuth;
	private: System::Windows::Forms::Button^ reset;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart3;





























	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->header = (gcnew System::Windows::Forms::Label());
			this->btn_create_obj = (gcnew System::Windows::Forms::Button());
			this->y_coord = (gcnew System::Windows::Forms::TextBox());
			this->lbl_RLS_y_coord = (gcnew System::Windows::Forms::Label());
			this->x_coord = (gcnew System::Windows::Forms::TextBox());
			this->lbl_RLS_x_coord = (gcnew System::Windows::Forms::Label());
			this->lbl1 = (gcnew System::Windows::Forms::Label());
			this->btn_open_create_Target = (gcnew System::Windows::Forms::Button());
			this->velocity = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->course = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->acceleration = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->radioButton_CP = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_RLS = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_Air = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_Miss = (gcnew System::Windows::Forms::RadioButton());
			this->safety_d = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->radius = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->directorySearcher1 = (gcnew System::DirectoryServices::DirectorySearcher());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Y = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Vel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Azimuth = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->reset = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
			this->SuspendLayout();
			// 
			// header
			// 
			this->header->Font = (gcnew System::Drawing::Font(L"GOST Common", 26.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->header->Location = System::Drawing::Point(20, 10);
			this->header->Name = L"header";
			this->header->Size = System::Drawing::Size(575, 93);
			this->header->TabIndex = 0;
			this->header->Text = L"Лабораторная работа 3";
			this->header->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->header->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// btn_create_obj
			// 
			this->btn_create_obj->BackColor = System::Drawing::SystemColors::Highlight;
			this->btn_create_obj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_create_obj->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_create_obj->Location = System::Drawing::Point(19, 678);
			this->btn_create_obj->Name = L"btn_create_obj";
			this->btn_create_obj->Size = System::Drawing::Size(353, 61);
			this->btn_create_obj->TabIndex = 1;
			this->btn_create_obj->Text = L"Создать объект";
			this->btn_create_obj->UseVisualStyleBackColor = false;
			this->btn_create_obj->Click += gcnew System::EventHandler(this, &MyForm::btn_create_obj_Click);
			// 
			// y_coord
			// 
			this->y_coord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->y_coord->Location = System::Drawing::Point(283, 359);
			this->y_coord->Name = L"y_coord";
			this->y_coord->Size = System::Drawing::Size(75, 26);
			this->y_coord->TabIndex = 5;
			this->y_coord->Text = L"0,0";
			// 
			// lbl_RLS_y_coord
			// 
			this->lbl_RLS_y_coord->AutoSize = true;
			this->lbl_RLS_y_coord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_RLS_y_coord->Location = System::Drawing::Point(228, 362);
			this->lbl_RLS_y_coord->Name = L"lbl_RLS_y_coord";
			this->lbl_RLS_y_coord->Size = System::Drawing::Size(24, 20);
			this->lbl_RLS_y_coord->TabIndex = 4;
			this->lbl_RLS_y_coord->Text = L"Y:";
			// 
			// x_coord
			// 
			this->x_coord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->x_coord->Location = System::Drawing::Point(111, 359);
			this->x_coord->Name = L"x_coord";
			this->x_coord->Size = System::Drawing::Size(75, 26);
			this->x_coord->TabIndex = 3;
			this->x_coord->Text = L"0,0";
			this->x_coord->TextChanged += gcnew System::EventHandler(this, &MyForm::RLS_x_coord_TextChanged);
			// 
			// lbl_RLS_x_coord
			// 
			this->lbl_RLS_x_coord->AutoSize = true;
			this->lbl_RLS_x_coord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_RLS_x_coord->Location = System::Drawing::Point(23, 362);
			this->lbl_RLS_x_coord->Name = L"lbl_RLS_x_coord";
			this->lbl_RLS_x_coord->Size = System::Drawing::Size(24, 20);
			this->lbl_RLS_x_coord->TabIndex = 2;
			this->lbl_RLS_x_coord->Text = L"X:";
			// 
			// lbl1
			// 
			this->lbl1->AutoSize = true;
			this->lbl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl1->Location = System::Drawing::Point(19, 316);
			this->lbl1->Name = L"lbl1";
			this->lbl1->Size = System::Drawing::Size(92, 25);
			this->lbl1->TabIndex = 6;
			this->lbl1->Text = L"Объект";
			this->lbl1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// btn_open_create_Target
			// 
			this->btn_open_create_Target->BackColor = System::Drawing::SystemColors::HotTrack;
			this->btn_open_create_Target->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->btn_open_create_Target->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_open_create_Target->Location = System::Drawing::Point(19, 745);
			this->btn_open_create_Target->Name = L"btn_open_create_Target";
			this->btn_open_create_Target->Size = System::Drawing::Size(353, 61);
			this->btn_open_create_Target->TabIndex = 7;
			this->btn_open_create_Target->Text = L"Моделировать";
			this->btn_open_create_Target->UseVisualStyleBackColor = false;
			this->btn_open_create_Target->Click += gcnew System::EventHandler(this, &MyForm::btn_open_create_Target_Click);
			// 
			// velocity
			// 
			this->velocity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->velocity->Location = System::Drawing::Point(111, 399);
			this->velocity->Name = L"velocity";
			this->velocity->Size = System::Drawing::Size(75, 26);
			this->velocity->TabIndex = 9;
			this->velocity->Text = L"0,0";
			this->velocity->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(20, 402);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 20);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Скорость:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_2);
			// 
			// course
			// 
			this->course->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->course->Location = System::Drawing::Point(283, 399);
			this->course->Name = L"course";
			this->course->Size = System::Drawing::Size(75, 26);
			this->course->TabIndex = 11;
			this->course->Text = L"0,0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(228, 402);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 20);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Курс:*";
			// 
			// acceleration
			// 
			this->acceleration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->acceleration->Location = System::Drawing::Point(111, 435);
			this->acceleration->Name = L"acceleration";
			this->acceleration->Size = System::Drawing::Size(75, 26);
			this->acceleration->TabIndex = 13;
			this->acceleration->Text = L"0,0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(20, 438);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 20);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Ускорение:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(20, 541);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(120, 20);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Тип объекта:";
			// 
			// radioButton_CP
			// 
			this->radioButton_CP->AutoSize = true;
			this->radioButton_CP->Location = System::Drawing::Point(135, 543);
			this->radioButton_CP->Name = L"radioButton_CP";
			this->radioButton_CP->Size = System::Drawing::Size(40, 17);
			this->radioButton_CP->TabIndex = 15;
			this->radioButton_CP->TabStop = true;
			this->radioButton_CP->Text = L"КЦ";
			this->radioButton_CP->UseVisualStyleBackColor = true;
			// 
			// radioButton_RLS
			// 
			this->radioButton_RLS->AutoSize = true;
			this->radioButton_RLS->Location = System::Drawing::Point(134, 564);
			this->radioButton_RLS->Name = L"radioButton_RLS";
			this->radioButton_RLS->Size = System::Drawing::Size(47, 17);
			this->radioButton_RLS->TabIndex = 16;
			this->radioButton_RLS->TabStop = true;
			this->radioButton_RLS->Text = L"РЛС";
			this->radioButton_RLS->UseVisualStyleBackColor = true;
			// 
			// radioButton_Air
			// 
			this->radioButton_Air->AutoSize = true;
			this->radioButton_Air->Location = System::Drawing::Point(232, 544);
			this->radioButton_Air->Name = L"radioButton_Air";
			this->radioButton_Air->Size = System::Drawing::Size(69, 17);
			this->radioButton_Air->TabIndex = 17;
			this->radioButton_Air->TabStop = true;
			this->radioButton_Air->Text = L"Самолет";
			this->radioButton_Air->UseVisualStyleBackColor = true;
			// 
			// radioButton_Miss
			// 
			this->radioButton_Miss->AutoSize = true;
			this->radioButton_Miss->Location = System::Drawing::Point(232, 564);
			this->radioButton_Miss->Name = L"radioButton_Miss";
			this->radioButton_Miss->Size = System::Drawing::Size(61, 17);
			this->radioButton_Miss->TabIndex = 18;
			this->radioButton_Miss->TabStop = true;
			this->radioButton_Miss->Text = L"Ракета";
			this->radioButton_Miss->UseVisualStyleBackColor = true;
			// 
			// safety_d
			// 
			this->safety_d->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->safety_d->Location = System::Drawing::Point(226, 493);
			this->safety_d->Name = L"safety_d";
			this->safety_d->Size = System::Drawing::Size(75, 26);
			this->safety_d->TabIndex = 22;
			this->safety_d->Text = L"0,0";
			this->safety_d->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged_1);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(20, 496);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(185, 20);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Безопасная дистанция";
			// 
			// radius
			// 
			this->radius->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radius->Location = System::Drawing::Point(226, 464);
			this->radius->Name = L"radius";
			this->radius->Size = System::Drawing::Size(75, 26);
			this->radius->TabIndex = 20;
			this->radius->Text = L"0,0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(20, 467);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(170, 20);
			this->label6->TabIndex = 19;
			this->label6->Text = L"Радиус обнаружения:";
			// 
			// label7
			// 
			this->label7->AllowDrop = true;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(21, 602);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 16);
			this->label7->TabIndex = 23;
			this->label7->UseCompatibleTextRendering = true;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->label8);
			this->flowLayoutPanel1->Location = System::Drawing::Point(24, 587);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(345, 52);
			this->flowLayoutPanel1->TabIndex = 24;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(325, 39);
			this->label8->TabIndex = 0;
			this->label8->Text = L"* От горизонтальной оси против часовой стрелки.\\nВведите отрицательный, чтобы нап"
				L"равление на цель было рассчитано автоматически";
			this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
			// 
			// directorySearcher1
			// 
			this->directorySearcher1->ClientTimeout = System::TimeSpan::Parse(L"-00:00:01");
			this->directorySearcher1->ServerPageTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
			this->directorySearcher1->ServerTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->label9);
			this->flowLayoutPanel2->Controls->Add(this->checkedListBox1);
			this->flowLayoutPanel2->Location = System::Drawing::Point(601, 12);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(848, 102);
			this->flowLayoutPanel2->TabIndex = 25;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(3, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(268, 13);
			this->label9->TabIndex = 1;
			this->label9->Text = L"Чеклист для помощи(нажатия ни на что не влияют)";
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"1) Ввести координаты Командногоцентра, безопасной дистанции, выбрать тип КЦ, созд"
					L"ать объект",
					L"2) Ввести кооринаты РЛС, радиус обнаружения, сменить тип на РЛС, создать объект", L"3) Ввести начальные координаты цели, ее скорость, направление движения, при необх"
					L"одимости ускорение. Указать тип цели. Нажать Создать объект.",
					L"4) Повторить п.3 нужное кол-во раз", L"5) Нажать \"Моделировать\""
			});
			this->checkedListBox1->Location = System::Drawing::Point(3, 16);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(814, 79);
			this->checkedListBox1->TabIndex = 0;
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::checkedListBox1_SelectedIndexChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->type, this->X,
					this->Y, this->Vel, this->Azimuth
			});
			this->dataGridView1->Location = System::Drawing::Point(24, 120);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(571, 121);
			this->dataGridView1->TabIndex = 26;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// type
			// 
			this->type->HeaderText = L"Тип";
			this->type->Name = L"type";
			this->type->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// X
			// 
			this->X->HeaderText = L"X";
			this->X->Name = L"X";
			// 
			// Y
			// 
			this->Y->HeaderText = L"Y";
			this->Y->Name = L"Y";
			// 
			// Vel
			// 
			this->Vel->HeaderText = L"Скорость";
			this->Vel->Name = L"Vel";
			// 
			// Azimuth
			// 
			this->Azimuth->HeaderText = L"Курс";
			this->Azimuth->Name = L"Azimuth";
			// 
			// reset
			// 
			this->reset->BackColor = System::Drawing::Color::DarkRed;
			this->reset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->reset->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->reset->Location = System::Drawing::Point(14, 812);
			this->reset->Name = L"reset";
			this->reset->Size = System::Drawing::Size(141, 61);
			this->reset->TabIndex = 27;
			this->reset->Text = L"Сбросить";
			this->reset->UseVisualStyleBackColor = false;
			this->reset->Click += gcnew System::EventHandler(this, &MyForm::reset_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(623, 130);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(410, 302);
			this->chart1->TabIndex = 28;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(1039, 130);
			this->chart2->Name = L"chart2";
			this->chart2->Size = System::Drawing::Size(410, 609);
			this->chart2->TabIndex = 29;
			this->chart2->Text = L"chart2";
			// 
			// chart3
			// 
			chartArea3->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->chart3->Legends->Add(legend3);
			this->chart3->Location = System::Drawing::Point(623, 437);
			this->chart3->Name = L"chart3";
			this->chart3->Size = System::Drawing::Size(410, 302);
			this->chart3->TabIndex = 30;
			this->chart3->Text = L"chart3";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1461, 899);
			this->Controls->Add(this->chart3);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->reset);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->safety_d);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->radius);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->radioButton_Miss);
			this->Controls->Add(this->radioButton_Air);
			this->Controls->Add(this->radioButton_RLS);
			this->Controls->Add(this->radioButton_CP);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->acceleration);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->course);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->velocity);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_open_create_Target);
			this->Controls->Add(this->lbl1);
			this->Controls->Add(this->y_coord);
			this->Controls->Add(this->lbl_RLS_y_coord);
			this->Controls->Add(this->x_coord);
			this->Controls->Add(this->lbl_RLS_x_coord);
			this->Controls->Add(this->btn_create_obj);
			this->Controls->Add(this->header);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Barichev\'s";
			this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click_2(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void RLS_x_coord_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btn_create_obj_Click(System::Object^ sender, System::EventArgs^ e) {
	/*string needle = ".";
	size_t pos;

	string ax = x_coord->Text->ToString();
	String^ ay = y_coord->Text->ToString();
	String^ avel = velocity->Text->ToString();
	String^ aco = course->Text->ToString();
	String^ aaccel= acceleration->Text->ToString();

	while ((pos = ax.find(needle)) != ax.npos)
		ax.replace(pos, pos + needle.length(), "\"");*/
	


	double x = Convert::ToDouble(x_coord->Text),
			y = Convert::ToDouble(y_coord->Text),
			vel = Convert::ToDouble(velocity->Text),
			co = Convert::ToDouble( course->Text),
			accel = Convert::ToDouble(acceleration->Text),
			sd = Convert::ToDouble(safety_d->Text),
			r = Convert::ToDouble(radius->Text);
	//0-x; 1-y; 2-velocity; 3-course; 4-acceleration; 5-radius; 6-SafetyDistanse;
	double params[] = {x,y,vel,co,accel,r,sd};
	int type;
	if (radioButton_CP->Checked)
		type = 0;
	else if (radioButton_RLS->Checked)
		type = 1;
	else if (radioButton_Air->Checked)
		type = 2;
	else if (radioButton_Miss->Checked)
		type = 3;
	int res = Sim->CreateObject(type, params);
	
	String^ status = "Ошибок, вроде, не выявлено, объект создан";
	switch (res)
	{
	case 0:
		status = "Ошибок, вроде, не найдено";
		break;
	case 1:
		status = "Непонятный тип объекта";
		break;
	case 2:
		status = "Ошибка при создании самолета";
		break;
	case 3:
		status = "Ошибка при создании ракеты";
		break;
	default:
		break;
	}
	//MessageBox::Show(status, "Статус:");
	updateObjectList();
}
private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btn_open_create_Target_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->Rows->Clear();
	//Sim->Run();
	//TEuler* Sim2 = new TEuler();
	//Sim2->Intergate(Sim->Targets[0], 0, 10, (float)0.01);
	updateObjectList();
	Graph();
	MessageBox::Show("Моделирование завершено, лог записан на диск", "Статус:");
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void reset_Click(System::Object^ sender, System::EventArgs^ e) {
	delete Sim;
	Sim = new TSimulator();
	updateObjectList();
	chart1->Series->Clear();
	chart2->Series->Clear();
	chart3->Series->Clear();
}
private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void chart2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
	void MyForm::updateObjectList()
	{
		short i = 0;
		dataGridView1->Rows->Clear();
		dataGridView1->Rows->Add();
		dataGridView1->Rows->Add();

		dataGridView1->Rows[i]->Cells[0]->Value = "Командный пост";
		dataGridView1->Rows[i]->Cells[1]->Value = Sim->CP->get_x();
		dataGridView1->Rows[i]->Cells[2]->Value = Sim->CP->get_y();
		i++;
		dataGridView1->Rows[i]->Cells[0]->Value = "Радар";
		dataGridView1->Rows[i]->Cells[1]->Value = Sim->RLS->get_x();
		dataGridView1->Rows[i]->Cells[2]->Value = Sim->RLS->get_y();

		for (unsigned int j = 0; j < Sim->CountTarget; j++)
		{
			i++;
			dataGridView1->Rows->Add();
			//dataGridView1->Rows[i]->Cells[0]->Value = Sim->Targets[j]->getTargetType();
			dataGridView1->Rows[i]->Cells[1]->Value = Sim->Targets[j]->get_x();
			dataGridView1->Rows[i]->Cells[2]->Value = Sim->Targets[j]->get_y();

			dataGridView1->Rows[i]->Cells[3]->Value = Sim->Targets[j]->get_Vel();
			dataGridView1->Rows[i]->Cells[4]->Value = Sim->Targets[j]->get_Ang();
		}

	}
	void MyForm::Graph()
	{
		chart1->Series->Clear();
		chart2->Series->Clear();
		chart3->Series->Clear();

		Series^ series1 = gcnew Series(L"Позиция F(x,y)");
		series1->Color = Color::Blue;
		series1->IsVisibleInLegend = true;
		series1->IsXValueIndexed = true;
		series1->ChartType = SeriesChartType::Line;
		

		Series^ series2 = gcnew Series(L"V=f(t)");
		series2->Color = Color::Green;
		series2->IsVisibleInLegend = true;
		series2->IsXValueIndexed = true;
		series2->ChartType = SeriesChartType::Line;

		Series^ series3 = gcnew Series(L"Mass=f(t)");
		series3->Color = Color::Aqua;
		series3->IsVisibleInLegend = true;
		series3->IsXValueIndexed = true;
		series3->ChartType = SeriesChartType::Line;

		Series^ series4 = gcnew Series(L"Xdrag=f(t)");
		series4->Color = Color::Chocolate;
		series4->IsVisibleInLegend = true;
		series4->IsXValueIndexed = true;
		series4->ChartType = SeriesChartType::Line;

		Series^ series5 = gcnew Series(L"P=f(t)");
		series5->Color = Color::DarkRed;
		series5->IsVisibleInLegend = true;
		series5->IsXValueIndexed = true;
		series5->ChartType = SeriesChartType::Line;


		chart1->Series->Add(series1);
		chart2->Series->Add(series2);
		chart2->Series->Add(series4);
		chart2->Series->Add(series5);
		chart3->Series->Add(series3);

		double t0 = 0.0;
		double tk = 30.0;
		double dt = 0.05;

		TEuler integr = TEuler();

		while (t0 < tk)
		{
			integr.OneStep(Sim->Targets[0], COUNT_FUNCTIONS, dt);
			//Sim->Targets[0]->dump();
			//0-x 1-y 2-v 3-xdrag 4-p 5-mfuel

			series1->Points->AddXY(Sim->Targets[0]->state_vector[0], Sim->Targets[0]->state_vector[1]);
			series2->Points->AddXY(t0, Sim->Targets[0]->state_vector[2]);
			series4->Points->AddXY(t0, Sim->Targets[0]->FXdrag());
			series5->Points->AddXY(t0, Sim->Targets[0]->FP());
			series3->Points->AddXY(t0, Sim->Targets[0]->state_vector[5]);

			t0 += dt;
			cout << t0 << endl;
		}
	}
}


