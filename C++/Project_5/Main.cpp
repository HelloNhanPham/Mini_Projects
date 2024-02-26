#include <iostream>
#include <conio.h>
#include "QuizGame.cpp"
#include "Object.cpp"
using namespace std;

int main()
{
    while (true)
    {
        printTitle();
        while (true)
        {
            char key;
            bool flag = false;
            if (_kbhit())
            {
                key = _getch();
                if (key == int('Q') || key == int('q'))
                {
                    system("cls");
                    cout << "Quit successfully!";
                    break;
                }
                else if (key == int('S') || key == int('s'))
                {
                    system("cls");
                    game obj;
                    int point = 0;
                    obj.initGame("Question.txt", point);
                    vector<player> list;
                    readFile("ViewHighestScore.txt", list);
                    if (list.size() == 0)
                    {
                        player p;
                        cout << "Input your name: ";
                        cin >> p.name;
                        p.point = point;
                        vector<player> v;
                        v.push_back(p);
                        writeFile("ViewHighestScore.txt", v);
                        cout << "\nYour score is saved successfully!\n";
                    }
                    else if (point > list[0].point)
                    {
                        cout << "\nYou get a new highest point!" << endl;
                        cout << " > Press Y to confirm\n";
                        cout << " > Press N to cancel\n";
                        while (true)
                        {
                            char choice;
                            if (_kbhit())
                            {
                                choice = _getch();
                                if (choice == int('Y') || choice == int('y'))
                                {
                                    player p;
                                    cout << "Input your name: ";
                                    cin >> p.name;
                                    p.point = point;
                                    vector<player> v;
                                    v.push_back(p);
                                    writeFile("ViewHighestScore.txt", v);
                                    cout << "\nYour score is saved successfully!\n";
                                    break;
                                }
                                if (choice == int('N') || choice == int('n'))
                                {
                                    break;
                                }
                            }
                        }
                    }
                    flag = true;
                    cout << "\n > Press SPACE to exit the main menu.\n";
                    while (true)
                    {
                        char choice;
                        if (_kbhit())
                        {
                            choice = _getch();
                            if (choice == int(' '))
                                break;
                        }
                    }
                }
                else if (key == int('U') || key == int('u'))
                {
                    system("cls");
                    vector<player> list;
                    readFile("ViewHighestScore.txt", list);
                    printLeaderBoard(list);
                    cout << "\n > Press SPACE to return the main menu\n";
                    while (true)
                    {
                        char key;
                        if (_kbhit())
                        {
                            key = _getch();
                            if (key == 32)
                                break;
                        }
                    }
                    flag = true;
                }
                else if (key == int('R') || key == int('r'))
                {
                    system("cls");
                    while (true)
                    {
                        char choice;
                        cout << " > Press Y to confirm" << endl;
                        cout << " > Press N to return" << endl;
                        while (true)
                        {
                            char choice;
                            if (_kbhit())
                            {
                                choice = _getch();
                                if (choice == int('Y') || choice == int('y'))
                                {
                                    resetLeaderBoard("ViewHighestScore.txt");
                                    break;
                                }
                                else if (choice == int('N') || choice == int('n'))
                                    break;
                            }
                        }
                        break;
                    }
                    flag = true;
                }
                else if (key == int('H') || key == int('h'))
                {
                    system("cls");
                    printHelp();
                    cout << "\n > Press SPACE to return the main menu\n";
                    while (true)
                    {
                        char key;
                        if (_kbhit())
                        {
                            key = _getch();
                            if (key == 32)
                                break;
                        }
                    }
                    flag = true;
                }
                if (flag)
                {
                    system("cls");
                    printOptions();
                }
            }
        }
        break;
    }
}