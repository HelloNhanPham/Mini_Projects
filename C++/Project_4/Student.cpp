#include "Student.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

student::student(string name, string ID, string birthdate, unsigned short int age, bool sex)
{
    this->name = name;
    this->ID = ID;
    this->birthdate = birthdate;
    this->age = age;
    this->sex = sex;
}

student::student()
{
    this->name = "";
    this->ID = "";
    this->birthdate = "";
    this->age = 0;
    this->sex = false;
}

void student::printInfo()
{
    cout << setw(30) << setfill(' ') << this->name;
    cout << setw(15) << setfill(' ') << this->ID;
    cout << setw(20) << setfill(' ') << this->birthdate;
    cout << setw(10) << setfill(' ') << this->age;
    cout << setw(10) << setfill(' ') << this->sex;
    cout << endl;
}

ostream& operator << (ostream &out, const student &s)
{
    out << setw(30) << setfill(' ') << s.name;
    out << setw(15) << setfill(' ') << s.ID;
    out << setw(20) << setfill(' ') << s.birthdate;
    out << setw(10) << setfill(' ') << s.age;
    out << setw(10) << setfill(' ') << s.sex;
    return out;
}

school::school()
{
}

void school::addStudent(const student &s)
{
    list.push_back(s);
}

void school::writeFile(string path)
{
    ofstream file;
    file.open(path.c_str());
    int size = this->list.size();
    file << size << endl;
    for (int i = 0; i < size; ++i)
    {
        file << list[i].name << endl;
        file << list[i].ID << endl;
        file << list[i].birthdate << endl;
        file << list[i].age << endl;
        file << list[i].sex;
        if (i != size-1)
            file << endl;
    }
    cout << "Write data successfully!" << endl;
    file.close();
}

void school::readFile(string path)
{
    this->list.clear();
    ifstream file;
    file.open(path.c_str());
    int num;
    file >> num;
    file.ignore();
    string s1, s2, s3;
    unsigned short int u1;
    bool b1;
    for (int i = num; i != 0; --i)
    {
        getline(file, s1);
        getline(file, s2);
        getline(file, s3);
        file >> u1;
        file >> b1;
        file.ignore();
        this->list.push_back(student(s1,s2,s3,u1,b1));
    }
    cout << "Read data successfully!" << endl;
    file.close();
}

void school::printList()
{
    int size = this->list.size();
    cout << "List of all students in shool: " << endl;
    cout << setw(30) << setfill(' ') << "Name";
    cout << setw(15) << setfill(' ') << "ID";
    cout << setw(20) << setfill(' ') << "Date of birth";
    cout << setw(10) << setfill(' ') << "Age";
    cout << setw(10) << setfill(' ') << "Sex";
    cout << endl;
    for (int i = 0; i < size; ++i)
        this->list[i].printInfo();
}

template<typename T>
void printVector(vector<T> list)
{
    int size = list.size();
    cout << "List of all students in shool: " << endl;
    cout << setw(30) << setfill(' ') << "Name";
    cout << setw(15) << setfill(' ') << "ID";
    cout << setw(20) << setfill(' ') << "Date of birth";
    cout << setw(10) << setfill(' ') << "Age";
    cout << setw(10) << setfill(' ') << "Sex";
    cout << endl;
    for (int i = 0; i < size; ++i)
        cout << list[i] << endl;
}

vector<student> filterByName::filterList(vector<student> list, string name = "", string ID = "", string birth = "", unsigned short int age = 1, bool sex = 0)
{
    vector<student> list_filter;
    int size = list.size();
    for (int i = 0; i < size; ++i)
        if (list[i].name == name)
            list_filter.push_back(list[i]);
    return list_filter;
}

vector<student> filterByID::filterList(vector<student> list, string name = "", string ID = "", string birth = "", unsigned short int age = 1, bool sex = 0)
{
    vector<student> list_filter;
    int size = list.size();
    for (int i = 0; i < size; ++i)
        if (list[i].name == ID)
            list_filter.push_back(list[i]);
    return list_filter;
}

void school::filterList()
{
    int n;
    vector<student> list_temp;
    cout << "Menu options:\n1. Name\n2. ID\n";
    cout << "Your choice is: ";
    cin >> n;
    if (n==1)
    {
        string name;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        filterByName obj;
        list_temp = obj.filterList(this->list, name);
    }
    else if (n==2)
    {
        string ID;
        cout << "ID: ";
        cin.ignore();
        getline(cin, ID);
        filterByID obj;
        list_temp = obj.filterList(this->list, "", ID);
    }
    printVector(list_temp);
}