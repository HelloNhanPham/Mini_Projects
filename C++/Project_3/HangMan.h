#include <iostream>
#include <string>
using namespace std;

class hangman
{
private:
    string word;
public:
    void makeWord(string filename);
    void printWord();
    void play(int cnt = 5);
};