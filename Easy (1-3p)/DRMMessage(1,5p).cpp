#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

//https://open.kattis.com/problems/drmmessages

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    
    string word1 = input.substr(0, input.size()/2), word2 = input.substr(input.size()/2);
    int totalWord1 = 0;
    for (char c : word1) {
        totalWord1 += (int)c;
    }
    totalWord1 %= 26;
    for (int i = 0; i < word1.length(); i++) {
        int newChar = (int)word1[i]+totalWord1;
        if (newChar > 90) {
            word1[i] = (char)(newChar - 26);
        }
        else {
            word1[i] = (char)(newChar);
        }

    }

    int totalWord2 = 0;
    for (char c : word2) {
        totalWord2 += (int)c;
    }
    totalWord2 %= 26;
    for (int i = 0; i < word2.length(); i++) {
        int newChar = (int)word2[i] + totalWord2;
        if (newChar > 90) {
            word2[i] = (char)(newChar - 26);
        }
        else {
            word2[i] = (char)(newChar);
        }

    }
    string newWord = "";
    for (int i = 0; i < word1.size(); i++) {
        int charValue = (int)word1[i] + (int)word2[i] - 65;
        if (charValue > 90) {
            charValue -= 26;
        }
        newWord += (char)(charValue);
    }

    cout << newWord;
    
    
    return 0;
}
