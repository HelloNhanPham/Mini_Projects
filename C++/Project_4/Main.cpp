#include <iostream>
#include <string>
#include <vector>
#include "Student.cpp"
using namespace std;

int main()
{
    school obj;
    obj.readFile("Data.txt");
    student s1("Pham Thanh Nhan", "22127307", "23/01/2004", 20, 0);
    obj.addStudent(s1);
    student s2("Duong Trung Nghia", "22127293", "26/09/2004", 20, 0);
    obj.addStudent(s2);
    obj.printList();
    obj.writeFile("Data.txt");
    obj.filterList();
    return 0;
}