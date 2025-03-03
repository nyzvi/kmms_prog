#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_func.hpp"
#include "menu_items.hpp"

int main () {
    std::setlocale(LC_ALL, "");
    std::cout << "Привет!" << std::endl;
    std::cout << "Выбери, что ты хочешь сделать:" << std::endl;
    
    const fym::MenuItem* current = &fym::MAIN;
    do {
        current = current->func(current);
    } while (true);

    return 0;
}