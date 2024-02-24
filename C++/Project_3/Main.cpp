#include <iostream>
#include "HangMan.cpp"
using namespace std;

int main()
{
    hangman game;
    game.makeWord("Fruits.txt");
    game.play();
    return 0;
}