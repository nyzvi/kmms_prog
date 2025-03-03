#include "menu_func.hpp"

#include <iostream>

const fym::MenuItem* fym::show_menu (const MenuItem* current) {
    for (int i = 1; i < current->children_count; i++){
            std::cout << current->children[i]->title << std::endl;
        }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Выбор > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const fym::MenuItem* fym::exit (const MenuItem* current) {
    std::exit(0);
}

const fym::MenuItem* fym::program (const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const fym::MenuItem* fym::algorithm (const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const fym::MenuItem* fym::another (const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const fym::MenuItem* fym::class_go_back (const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

const fym::MenuItem* fym::database (const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

const fym::MenuItem* fym::multithreaded_programming (const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

const fym::MenuItem* fym::network_technologies (const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

const fym::MenuItem* fym::go_back (const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}