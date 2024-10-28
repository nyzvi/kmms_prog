#include <cmath>
#include <iostream>

int main() {
    double corner;
    std::cout << "Введите угол";
    std::cin >> corner;
    
    double cos_result;
    if  (std::cos(2 * corner) != 1) {  
        cos_result = (1 + std::sin(2 * corner)) / (1 - std::cos(2 * corner));
        std::cout << "F(x1)="<< cos_result << std::endl;
    }
    else if (std:: cos(2 * angle) == 1) {
        std::cout << "Неверный ввод для F(x1)" << std::endl;
    }

    double tg_result;
    double tg = std::tan(corner);
    if  (tg != 1) {
        tg_result = (1 + tg * tg) / (1 - tg * tg);
        std::cout << "F(X2)=" << tg_result << std::endl;
    }
    else if (tg == 1) {
        std::cout << "Неверный ввод для F(x2)" << std::endl;
    }
    
    return 0;
}
