#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "HangMan.h"
using namespace std;

int makeRandomNumber(int value)
{
    srand(time(NULL));
    int random_number = rand() % value + 1;
    return random_number - 1;
}

void hangman::makeWord(string path)
{
    ifstream file;
    file.open(path.c_str());
    int numWordInFile;
    file >> numWordInFile;
    file.ignore();
    int random = makeRandomNumber(numWordInFile);
    string temp;
    for (int i = random; i != 0; --i)
        getline(file, temp);
    this->word = temp;
    file.close();
}

void hangman::printWord()
{
    cout << this->word << endl;
}

vector<vector<int>> play_support(string s)
{
    vector<vector<int>> table(26);
    int len = s.length();
    for (int i = len; i != 0; --i)
        table[s[i]-'a'].push_back(i-1);
    return table;
}

// string makeStringWithSpecialSymbol(int length, char symbol)
// {
//     string res = "";
//     for (int i = 0; i < length; ++i)
//         res.push_back(symbol);
//     return res;
// }

void hangman::play(int cnt)
{
    cout << this->word;
    vector<vector<int> > table = play_support(this->word);
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < table[i].size(); ++j)
            cout << table[i][j];
    cout << "You have " << cnt << " times to play this game!" << endl;
    string s;
    for (int i = 0; i < this->word.length(); ++i)
        s.push_back('.');
    int cnt_char = s.length();
    while (cnt != 0)
    {
        cout << s << endl;
        char c;
        cout << "Your choice is: ";
        cin >> c;
        if (cnt_char==0)
            break;
        if (table[c-'a'].size() != 0)
        {
            for (int i = table[c-'a'].size(); i != 0; --i)
                s[table[c-'a'][i-1]] = c;
            cnt_char -= table[c-'a'].size();
        }
        else
        {
            cnt--;
            cout << "This char is not existed!" << endl;
        }
    }
    if (cnt==0)
        cout << "Good luck to you!" << endl;
    else
        cout << "Congratulation to you!" << endl;
}