#pragma one
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//////////////
class student;
class school; 
class filter; 
//////////////

class student
{
public:
    string name;
    string ID;
    string birthdate;
    unsigned short int age;
    bool sex; // 0: Man, 1: Woman;
    student();
    student(string name, string ID, string birthdate, unsigned short int age, bool sex);
    void printInfo();
    friend ostream& operator << (ostream &out, const student &s); 
};

class school
{
private:
    vector<student> list;
public:
    school();
    void addStudent(const student &s);
    void writeFile(string path);
    void readFile(string path);
    void printList();
    void filterList();
};

class filter
{
public:
    virtual vector<student> filterList(vector<student> list, string name = "", string ID = "", string birth = "", unsigned short int age = 1, bool sex = false) const = 0;
};

class filterByName : public filter
{
public:
    vector<student> filterList(vector<student> list, string name = "", string ID = "", string birth = "", unsigned short int age = 1, bool sex = false) override;
};

class filterByID : public filter
{
public:
    vector<student> filterList(vector<student> list, string name = "", string ID = "", string birth = "", unsigned short int age = 1, bool sex = false) override;
};