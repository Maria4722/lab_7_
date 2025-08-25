#include "MySet.h"
#include <sstream>

// ������������
MySet::MySet() {}

MySet::MySet(std::initializer_list<SetElement> list) : data(list) {}

// �������� ��������� ��������
bool MySet::contains(const SetElement& element) const
{
    return data.count(element) > 0;
}

// ��'������� (+)
MySet MySet::operator+(const MySet& other) const
{
    MySet result;
    std::set_union(this->data.begin(), this->data.end(),
        other.data.begin(), other.data.end(),
        std::inserter(result.data, result.data.begin()));
    return result;
}

// ������� (*)
MySet MySet::operator*(const MySet& other) const
{
    MySet result;
    std::set_intersection(this->data.begin(), this->data.end(),
        other.data.begin(), other.data.end(),
        std::inserter(result.data, result.data.begin()));
    return result;
}

// г����� (-)
MySet MySet::operator-(const MySet& other) const
{
    MySet result;
    std::set_difference(this->data.begin(), this->data.end(),
        other.data.begin(), other.data.end(),
        std::inserter(result.data, result.data.begin()));
    return result;
}

// ��������� ����� ����
bool MySet::operator<=(const MySet& other) const
{
    return std::includes(other.data.begin(), other.data.end(),
        this->data.begin(), this->data.end());
}

// ��������� ����� ����
bool MySet::operator>=(const MySet& other) const
{
    return std::includes(this->data.begin(), this->data.end(),
        other.data.begin(), other.data.end());
}

// ���������
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

// ��������
std::istream& operator>>(std::istream& is, MySet& s)
{
    s.data.clear(); // ������� ������� ����� ����� ���������

    std::string line;
    // 1. ������� ���� ����� �� ���������� Enter
    std::getline(is, line);

    // 2. ��������� "�������� ����" � ���������� �����
    std::stringstream ss(line);

    SetElement elem;
    // 3. ����� ������� ����� � ����� ��������� ������, � �� � ������ �������
    while (ss >> elem)
    {
        s.data.insert(elem);
    }

    return is;
}
