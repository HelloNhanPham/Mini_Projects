#include <iostream>
#include <iomanip>
#include "Point.h"
using namespace std;

Point::Point()
{
    this->point = 0;
    this->coefficient = 0;
}

Point::Point(int point, int coefficient)
{
    this->point = point;
    this->coefficient = coefficient;
}  

void CGPA::addPoint(int point, int coefficient)
{
    Point obj(point, coefficient);
    this->v.push_back(obj);
}

double CGPA::calc()
{
    int sumPoint = 0;
    int sumCoefficient = 0;
    for (int i = 0; i < this->v.size(); ++i)
    {
        sumPoint += (v.at(i).point * v.at(i).coefficient);
        sumCoefficient += (v.at(i).coefficient);
    }
    return double(sumPoint)/sumCoefficient;
}

void CGPA::clear()
{
    this->v.clear();
}

void CGPA::display()
{
    int size = this->v.size();
    if (size==0)
        return;
    cout << "             Point     Coefficient" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "Line ";
        cout << setw(3) << setfill(' ') << i + 1;
        cout << setw(10) << setfill(' ') << v.at(i).point << "     ";
        cout << setw(10) << setfill(' ') << v.at(i).coefficient << endl;
    }
}

void CGPA::change(int index, int point, int coefficient)
{
    this->v.at(index).point = point;
    this->v.at(index).coefficient = coefficient;
    cout << "Change successfully!" << endl;
}