#include "menu_items.hpp"
#include "menu_func.hpp"

const fym::MenuItem fym::DATABASE = {
    "1 - Базы данных", fym::database, &fym::PROGRAM
};

const fym::MenuItem fym::MULTITHREADED_PROGRAMMING = {
    "2 - Многопоточное программирование", fym::multithreaded_programming, &fym::PROGRAM
};

const fym::MenuItem fym::NETWORK_TECHNOLOGIES = {
    "3 - Сетевые технологии", fym::network_technologies, &fym::PROGRAM
};

const fym::MenuItem fym::GO_BACK = {
    "0 - Выйти в предыдущее меню", fym::go_back, &fym::PROGRAM
};

namespace {
    const fym::MenuItem* program_children[] = {
        &fym::GO_BACK,
        &fym::DATABASE,
        &fym::MULTITHREADED_PROGRAMMING,
        &fym::NETWORK_TECHNOLOGIES
    };
    const int size_program = sizeof(program_children) / sizeof(program_children[0]);
}
//
const fym::MenuItem fym::PROGRAM = {
    "1 - Изучать языки программирования", fym::show_menu, &fym::SHOW_MENU, program_children, size_program
};

const fym::MenuItem fym::ALGORITHM = {
    "2 - Алгоритмы и структуры", fym::algorithm, &fym::SHOW_MENU
};

const fym::MenuItem fym::ANOTHERM = {
    "3 - Другие технологии", fym::another, &fym::SHOW_MENU
};

const fym::MenuItem fym::CLASS_GO_BACK = {
    "0 - Выход в главное меню", fym::class_go_back, &fym::SHOW_MENU
};

namespace {
    const fym::MenuItem* study_children[] = {
        &fym::CLASS_GO_BACK,
        &fym::PROGRAM,
        &fym::ALGORITHM,
        &fym::ANOTHERM,
    };
    const int size_study = sizeof(study_children) / sizeof(study_children[0]);
}

const fym::MenuItem fym::SHOW_MENU = {
    "1 - Изучать программирование", fym::show_menu, &fym::MAIN, study_children, size_study
};

const fym::MenuItem fym::EXIT = {
    "0 - Пойти играть в футбол", fym::exit, &fym::MAIN
};

namespace {
    const fym::MenuItem* main_children[] = {
        &fym::EXIT, 
        &fym::SHOW_MENU
    };
    const int size_main = sizeof(main_children) / sizeof(main_children[0]);
}

const fym::MenuItem fym::MAIN = {
    nullptr, fym::show_menu, nullptr, main_children, size_main 
};





