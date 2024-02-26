#include <iostream>
#include <string>
#include <vector>
using namespace std;

// All struct.
typedef struct player;

// All helper functions.
void printCentered(const string& text, int width, char c);
void printFilled(int width, char c);
void writeFile(string path, vector<player> list);
void readFile(string path, vector<player> &list);
void printLeaderBoard(vector<player> v);
void resetLeaderBoard(string path);
void printHelp();
void printOptions();
void printTitle();