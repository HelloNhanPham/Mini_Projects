#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>
#include "Object.h"
#include <cstdlib>
using namespace std;

void game::initGame(string path, int &point)
{
    loadData(path);
    vector<bool> v (this->list.size(), 0);
    int size = v.size();
    point = 0;
    while (true)
    {
        int no;
        while (true)
        {
            no = rand() % size;
            if (!v[no])
                break;
        }
        system("cls");
        this->list[no].printQuestion();
        v[no] = true;
        int choose;
        while (true)
        {
            char key;
            if (_kbhit())
            {
                key = _getch();
                if (key == int('A') || key == int('a'))
                {
                    choose = 0;
                    break;
                }
                if (key == int('B') || key == int('b'))
                {
                    choose = 1;
                    break;
                }
                if (key == int('C') || key == int('c'))
                {
                    choose = 2;
                    break;
                }
                if (key == int('D') || key == int('d'))
                {
                    choose = 3;
                    break;
                }
            }
        }
        if (this->list[no].list_answer[choose].truth)
            point++;
        else
            break;
        if (point == size)
        {
            cout << "You are champion!\n";
            break;
        }
    }
    cout << "\nYou get " << point << " points.\n";
}

void game::loadData(string path)
{
    ifstream file;
    file.open(path.c_str());
    int n;
    file >> n;
    file.ignore();
    for (int i = n; i != 0; --i)
    {
        question q;
        getline(file, q.content);
        for (int i = 0; i < 4; ++i)
        {
            answer a;
            file >> a.truth;
            file.ignore();
            getline(file, a.ans);
            q.list_answer.push_back(a);
        }
        this->list.push_back(q);
    }
    file.close();
}

void question::printQuestion()
{
    cout << "Question: " << this->content << endl;
    cout << "A - " << this->list_answer[0].ans << endl;
    cout << "B - " << this->list_answer[1].ans << endl;
    cout << "C - " << this->list_answer[2].ans << endl;
    cout << "D - " << this->list_answer[3].ans << endl;
}

void question::init(string content)
{
    this->content = content;
}

void question::addAnswer(answer ans)
{
    this->list_answer.push_back(ans);
}