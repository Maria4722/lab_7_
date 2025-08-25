#include <iostream>
#include "MySet.h"

void demonstrate_operations(const MySet& a, const MySet& b)
{
    std::cout << "--------------------------------\n";
    std::cout << "������� A = " << a << std::endl;
    std::cout << "������� B = " << b << std::endl;
    std::cout << "--------------------------------\n";

    MySet union_set = a + b;
    std::cout << "��'������� (A + B): " << union_set << std::endl;

    MySet intersection_set = a * b;
    std::cout << "������� (A * B):   " << intersection_set << std::endl;

    MySet difference_set = a - b;
    std::cout << "г����� (A - B):    " << difference_set << std::endl;

    int element_to_check = 5;
    std::cout << "\n�������� ��������� �������� " << element_to_check << " � ������� A: "
        << (a.contains(element_to_check) ? "���" : "ͳ") << std::endl;

    MySet subset = { 4, 5 };
    std::cout << "\n�������� ��������:" << std::endl;
    std::cout << "�� � " << subset << " ���������� " << a << "? "
        << (subset <= a ? "���" : "ͳ") << std::endl;
    std::cout << "�� � " << a << " ����������� " << subset << "? "
        << (a >= subset ? "���" : "ͳ") << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    std::cout << "========== ������ 1 ==========\n";
    MySet setA = { 1, 2, 3, 4, 5 };
    MySet setB = { 4, 5, 6, 7, 8 };
    demonstrate_operations(setA, setB);

    std::cout << "\n\n========== ������ 2 ==========\n";
    MySet setC = { 10, 20, 30 };
    MySet setD = { 20* 40 };
    demonstrate_operations(setC, setD);

    std::cout << "\n\n========== ������������ ��������-��������� ==========\n";
    MySet userSet;
    std::cout << "������ �������� ��� ���� ������� ����� ����� �� �������� Enter (����., 5 12 3 5):" << std::endl;
    std::cin >> userSet;
    std::cout << "���� ������� �������: " << userSet << std::endl;

    return 0;
}