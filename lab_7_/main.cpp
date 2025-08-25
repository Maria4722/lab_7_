#include <iostream>
#include "MySet.h"

void demonstrate_operations(const MySet& a, const MySet& b)
{
    std::cout << "--------------------------------\n";
    std::cout << "Множина A = " << a << std::endl;
    std::cout << "Множина B = " << b << std::endl;
    std::cout << "--------------------------------\n";

    MySet union_set = a + b;
    std::cout << "Об'єднання (A + B): " << union_set << std::endl;

    MySet intersection_set = a * b;
    std::cout << "Перетин (A * B):   " << intersection_set << std::endl;

    MySet difference_set = a - b;
    std::cout << "Різниця (A - B):    " << difference_set << std::endl;

    int element_to_check = 5;
    std::cout << "\nПеревірка входження елемента " << element_to_check << " у множину A: "
        << (a.contains(element_to_check) ? "Так" : "Ні") << std::endl;

    MySet subset = { 4, 5 };
    std::cout << "\nПеревірка відношень:" << std::endl;
    std::cout << "Чи є " << subset << " підмножиною " << a << "? "
        << (subset <= a ? "Так" : "Ні") << std::endl;
    std::cout << "Чи є " << a << " надмножиною " << subset << "? "
        << (a >= subset ? "Так" : "Ні") << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    std::cout << "========== Масиви 1 ==========\n";
    MySet setA = { 1, 2, 3, 4, 5 };
    MySet setB = { 4, 5, 6, 7, 8 };
    demonstrate_operations(setA, setB);

    std::cout << "\n\n========== Масиви 2 ==========\n";
    MySet setC = { 10, 20, 30 };
    MySet setD = { 20* 40 };
    demonstrate_operations(setC, setD);

    std::cout << "\n\n========== Демонстрація введення-виведення ==========\n";
    MySet userSet;
    std::cout << "Введіть елементи для вашої множини через пробіл та натисніть Enter (напр., 5 12 3 5):" << std::endl;
    std::cin >> userSet;
    std::cout << "Ваша введена множина: " << userSet << std::endl;

    return 0;
}