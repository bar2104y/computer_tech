#include <iostream>

#include "types.h"

int main()
{
    std::cout << "Program was started\n";

    // Создание экземпляра объекта
    TRadar* Radar = new TRadar(0, 0, 70, 1e-1, 4);
    // Введение 4-х отслеживаемых целей
    Radar->targets[0] = new TAircraft(0, 10, 2, 3.14/2.0);
    Radar->targets[1] = new TMissile(-20, 20, 2, 0, 0, 100);
    Radar->targets[2] = new TAircraft(-20, -20, 2, 0);
    Radar->targets[3] = new TAircraft(20, -20, 2, 0);

    // Отслеживание целей
    Radar->Peleng(0, 10);
    
    //Очистка памяти
    delete Radar;

}
