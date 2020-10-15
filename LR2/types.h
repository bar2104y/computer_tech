#pragma once
//Типы целей
enum class target_type { Unknown, Missile, Aircraft };

//Координаты
struct TPoint
{
	double x, y;
};

//Базовый класс объекта
class TPosObject
{
public:
	TPosObject();
	TPosObject(double x, double y, double t);
	~TPosObject() {};
	virtual void Move(double t) = 0 ;

	// геттеры
	double get_x() { return CurPosition.x; }
	double get_y() { return CurPosition.y; }

protected:
	TPoint InitPosition, CurPosition;
	double CurTime;

};


//Конструктор по умолчанию
TPosObject::TPosObject() {
	InitPosition.x = 0;
	InitPosition.y = 0;

	CurPosition.x = InitPosition.x;
	CurPosition.y = InitPosition.y;

	CurTime = 0;
}

TPosObject::TPosObject(double x, double y, double t) {
	InitPosition.x = x;
	InitPosition.y = y;

	CurPosition.x = InitPosition.x;
	CurPosition.y = InitPosition.y;

	CurTime = t;
}

