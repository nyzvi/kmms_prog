#include <cmath>
#include <iostream>

int main() {
    setlocale(LC_ALL,"RUS"); 
    double corner;
    std::cout << "Введите угол" << std::endl;
    std::cin >> corner;
    
    double cos_result;
    int double_corner = 2 * corner;
    if  (cos(double_corner) != 1)  
    {  
        cos_result = (1 + sin(double_corner)) / (1 - cos(double_corner));
        std::cout << "F(x1)="<< cos_result << std::endl;
    }
    else 
    {
        std::cout << "Неверный ввод для F(x1)" << std::endl;
    }

    double tg_result;
    double tg = tan(corner);
    if  (tg != 1) 
    {
        tg_result = (1 + tg * tg) / (1 - tg * tg);
        std::cout << "F(X2)=" << tg_result << std::endl;
    }
    else 
    {
        std::cout << "Неверный ввод для F(x2)" << std::endl;
    }

    system("pause");
    return 0;
}
