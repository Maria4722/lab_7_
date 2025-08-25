#include "MySet.h"
#include <sstream>

// Конструктори
MySet::MySet() {}

MySet::MySet(std::initializer_list<SetElement> list) : data(list) {}

// Перевірка входження елемента
bool MySet::contains(const SetElement& element) const
{
    return data.count(element) > 0;
}

// Об'єднання (+)
MySet MySet::operator+(const MySet& other) const
{
    MySet result;
    std::set_union(this->data.begin(), this->data.end(),
        other.data.begin(), other.data.end(),
        std::inserter(result.data, result.data.begin()));
    return result;
}

// Перетин (*)
MySet MySet::operator*(const MySet& other) const
{
    MySet result;
    std::set_intersection(this->data.begin(), this->data.end(),
        other.data.begin(), other.data.end(),
        std::inserter(result.data, result.data.begin()));
    return result;
}

// Різниця (-)
MySet MySet::operator-(const MySet& other) const
{
    MySet result;
    std::set_difference(this->data.begin(), this->data.end(),
        other.data.begin(), other.data.end(),
        std::inserter(result.data, result.data.begin()));
    return result;
}

// Порівняння менше рівне
bool MySet::operator<=(const MySet& other) const
{
    return std::includes(other.data.begin(), other.data.end(),
        this->data.begin(), this->data.end());
}

// Порівняння більше рівне
bool MySet::operator>=(const MySet& other) const
{
    return std::includes(this->data.begin(), this->data.end(),
        other.data.begin(), other.data.end());
}

// Виведення
std::ostream& operator<<(std::ostream& os, const MySet& s)
{
    os << "{ ";
    for (const auto& elem : s.data)
    {
        os << elem << " ";
    }
    os << "}";
    return os;
}

// Введення
std::istream& operator>>(std::istream& is, MySet& s)
{
    s.data.clear(); // Очищуємо множину перед новим введенням

    std::string line;
    // 1. Зчитуємо весь рядок до натискання Enter
    std::getline(is, line);

    // 2. Створюємо "рядковий потік" з отриманого рядка
    std::stringstream ss(line);

    SetElement elem;
    // 3. Тепер зчитуємо числа з цього рядкового потоку, а не з консолі напряму
    while (ss >> elem)
    {
        s.data.insert(elem);
    }

    return is;
}
