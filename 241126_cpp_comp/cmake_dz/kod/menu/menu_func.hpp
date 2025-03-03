#pragma once 

#include "menu.hpp"

namespace fym {
    const MenuItem* show_menu (const MenuItem* current);

    const MenuItem* exit (const MenuItem* current);
    
    const MenuItem* program (const MenuItem* current);
    const MenuItem* algorithm (const MenuItem* current);
    const MenuItem* another (const MenuItem* current);
    const MenuItem* class_go_back (const MenuItem* current);

    const MenuItem* database (const MenuItem* current);
    const MenuItem* multithreaded_programming (const MenuItem* current);
    const MenuItem* network_technologies (const MenuItem* current);
    const MenuItem* go_back (const MenuItem* current);
}