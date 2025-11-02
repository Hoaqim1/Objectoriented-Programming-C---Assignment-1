#include <iostream>

void Menu() {

    int choice;

    do {
        std::cout << "1. Läs nya mätvärden från alla sensorer" << '\n';
        std::cout << "2. Visa statistik per sensor" << '\n';
        std::cout << "3. Visa alla mätvärden" << '\n';
        std::cout << "4. Spara alla mätvärden till fil" << '\n';
        std::cout << "5. Läs in mätvärden från fil" << '\n';
        std::cout << "6. Avsluta program" << '\n';

        std::cin >> choice;

        if (!std::cin) {
            std::cout << "Ogiltig inmatning" << '\n';
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch(choice){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            default:
            std::cout << "Ogiltig inmatning, välj mellan 1-6!" << '\n';
            break;
        }

    } while(choice != 10);

}