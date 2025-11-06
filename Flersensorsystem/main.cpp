#include <iostream>
#include <windows.h>
#include "sensor.h"
#include "storage.h"
#include "measurement.h"
#include "menu.h"

int main(){
    SetConsoleOutputCP(CP_UTF8);

    srand(time(nullptr));
    Menu();

    return 0;
}