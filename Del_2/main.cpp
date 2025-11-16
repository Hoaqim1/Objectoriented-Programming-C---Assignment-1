#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "menu.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(nullptr));
    Menu();
    return 0;
}