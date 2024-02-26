#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

// All class
class answer;
class question;
class game;

// Implementation
class game
{
public:
    vector<question> list;
    void loadData(string path);
    void initGame(string path, int &point);
};

class question
{
public:
    string content;
    vector<answer> list_answer;
    void init(string content);
    void addAnswer(answer ans);
    void printQuestion();
};

class answer
{
public:
    string ans;
    bool truth;
    answer(string ans, bool truth) : ans(ans), truth(truth) {}
    answer() : ans(""), truth(false) {}
};