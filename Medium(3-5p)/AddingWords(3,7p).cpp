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

//https://open.kattis.com/problems/addingwords

unordered_map<string, int> definitions;
unordered_map<int, string> reversedDefinitions;
string getShittyString(string newLine) {
    int total = 0;
    string answer = "";
    istringstream ss(newLine.substr(1));
    char sign = '+';

    string word1;
    while (ss >> word1) {
        if (definitions.find(word1) == definitions.end()) {
            return newLine.substr(1) + " unknown";
        }
        else {
            if (sign == '+') {
                total += definitions[word1];
            }
            else if (sign == '-') {
                total -= definitions[word1];
            }
            ss >> sign;
        }
    }
    if (reversedDefinitions.find(total) == reversedDefinitions.end())
    {
        answer = "unknown";
    }
    else {
        answer = reversedDefinitions[total];
    }
    return newLine.substr(1) + " " +answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string word;
    while (cin >> word) {
        if (word == "clear") {
            definitions.clear();
            reversedDefinitions.clear();
            continue;
        }
        if (word == "def") {
            cin >> word;
            int value;
            cin >> value;
            if (definitions.find(word) != definitions.end()) {
                int removeValue = definitions[word];
                reversedDefinitions.erase(removeValue);
            }
            definitions[word] = value;
            reversedDefinitions[value] = word;
        }
        else if (word == "calc") {
            string newLine;
            getline(cin, newLine);
            
            cout << getShittyString(newLine) << endl;
                
        }
    }
    return 0;
}
