#include <iostream>
#include <vector>
using namespace std;

class Point
{
public:
    int point, coefficient;
    Point();
    Point(int point, int coefficient);
};

class CGPA
{
private:
    vector<Point> v;
public:
    void addPoint(int point, int coefficient);
    double calc();
    void clear();
    void display();
    void change(int index, int point, int coefficient);
};