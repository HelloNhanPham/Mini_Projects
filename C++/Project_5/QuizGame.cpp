#include "QuizGame.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

// Implementation.
void printHelp()
{
    printFilled(100, '#');
    cout << "\n\nThis program is made by Nhan Pham\n";
    cout << "Role of this game:\n";
    cout << "   - In this game, the player must answer the question and get point.\n";
    cout << "   - There are so many questions. Each truth answer will give the player 1 point.\n";
    cout << "   - If you anwer wrong, you will not receive any points and you will lose the game.\n";
    cout << "Thank you for playing this game! :3 :3 :3\n\n";
    printFilled(100, '#');
    cout << endl;
}

typedef struct player
{
    string name;
    int point;
    player() : name(""), point(0) {}
    player(string name, int point) : name(name), point(point) {}
};

void printCentered(const string& text, int width, char c) 
{
    int padding = (width - text.length()) / 2;
    for (int i = 0; i < padding; ++i) {
        cout << c;
    }
    cout << text;
}

void printFilled(int width, char c)
{
    for (int i = 0; i < width; ++i)
        cout << c;
}

void writeFile(string path, vector<player> list)
{
    int size = list.size();
    ofstream file;
    file.open(path.c_str());
    file << size << endl;
    for (int i = 0; i < size; ++i)
    {
        file << list[i].name << " " << list[i].point;
        if (i!=size-1)
            file << endl;
    }
    file.close();
}

void readFile(string path, vector<player> &list)
{
    list.clear();
    ifstream file;
    file.open(path.c_str());
    int n;
    file >> n;
    for (int i = 0; i < n; ++i)
    {
        player p;
        file >> p.name >> p.point;
        list.push_back(p);
    }
    file.close();
}

void printLeaderBoard(vector<player> v)
{
    int size = v.size();
    cout << setw(10) << setfill(' ') << "Name";
    cout << setw(15) << setfill(' ') << "Point";
    cout << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << setw(10) << setfill(' ') << v[i]. name;
        cout << setw(15) << setfill(' ') << v[i].point; 
        cout << endl;
    }
}

void resetLeaderBoard(string path)
{
    ofstream file;
    file.open(path.c_str());
    file << 0;
    file.close();
    cout << "\nReset leaderboard successfully!" << endl;
}

void printOptions()
{
    printFilled(100, '_');
    cout << endl;
    cout << " > Press S to start the game\n";
    cout << " > Press U to view the highest score\n";
    cout << " > Press R to reset score\n";
    cout << " > Press H for help\n";
    cout << " > Press Q to quit\n";
    printFilled(100, '_');
    cout << endl;
}

void printTitle()
{
    printCentered("C++ Fun Quiz Game", 100, ' ');
    cout << endl;
    printFilled(100, '_');
    cout << endl;
    printCentered("WELCOME", 100, ' ');
    cout << endl;
    printCentered("to", 100, ' ');
    cout << endl;
    printCentered("THE GAME", 100, ' ');
    cout << endl;
    printFilled(100, '_');
    cout << endl;
    printFilled(100, '_');
    cout << endl;
    printCentered("$$$ BECOME A MILLIONAIRE $$$", 100, ' ');
    cout << endl;
    printFilled(100, '_');
    cout << endl;
    printOptions();
}