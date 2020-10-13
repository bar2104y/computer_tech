#include <iostream>

#include "types.h"

int main()
{
    std::cout << "Program was started\n";

    float e = (float)1e-1;
    //float ang = (float)(3.14 / 2.0);

    // Создание экземпляра объекта
    TRadar* Radar = new TRadar(0, 0, 70, (float)e);

    // Отслеживание целей
    Radar->Peleng(0, 10);
    
    //Очистка памяти
    delete Radar;

}
