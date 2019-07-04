#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(string s)
{
    if (s.length() == 0)
    {
        return true;
    }
    for (int i = 0; i <= (s.length() - 1)/2; i++)
    {
        if (s[i] != s[s.length() -(1 + i)])
        {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLenght)
{

}

int main()
{
    int minLenght;
    cin >> minLenght;
    vector<string> words{"weew", "bro", "maam"};
    PalindromFilter(words, minLenght);
    return 0;
}

