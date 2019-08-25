#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
#include <random>
using namespace std;

//https://open.kattis.com/problems/helpme

unordered_map<char, vector<vector<string>>> allaPjaser;
bool firstPjas = true;
void print(char caseChar, char printChar, bool white) {
    if (white) {
        for (int i = 1; i <= 8; i++) {
            vector<string> pjas = allaPjaser[caseChar][i];
            if (pjas.size() == 0) {
                continue;
            }
            for (string p : pjas) {
                if (!firstPjas) {
                    cout << ",";
                }
                else {
                    firstPjas = false;
                }
                if (printChar != 'P') {
                    cout << printChar;
                }
                cout << p;
            }
        }
    }
    else{
        for (int i = 8; i >= 1; i--) {
            vector<string> pjas = allaPjaser[caseChar][i];
            if (pjas.size() == 0) {
                continue;
            }
            for (string p : pjas) {
                if (!firstPjas) {
                    cout << ",";
                }
                else {
                    firstPjas = false;
                }
                if (printChar != 'P') {
                    cout << printChar;
                }
                cout << p;
            }
        }
    }
}

int main()
{
    vector<string> tomVect;
    vector<vector<string>> tom(9, tomVect);
    allaPjaser[':'] = tom;
    allaPjaser['.'] = tom;
    allaPjaser['r'] = tom;
    allaPjaser['b'] = tom;
    allaPjaser['q'] = tom;
    allaPjaser['k'] = tom;
    allaPjaser['n'] = tom;
    allaPjaser['p'] = tom;
    allaPjaser['R'] = tom;
    allaPjaser['B'] = tom;
    allaPjaser['Q'] = tom;
    allaPjaser['K'] = tom;
    allaPjaser['N'] = tom;
    allaPjaser['P'] = tom;

    string trash;
    cin >> trash;
    for (int i = 8; i >= 1; i--) {
        string content;
        cin >> content >> trash;
        for (int j = 2; j <= 30; j+=4) {
            char letter1 = (char)((j - 2) / 4 + 97);
            string word = "dd";
            word[0] = letter1;
            word[1] = (char)(i+48);
            allaPjaser[content[j]][i].push_back(word);
        }
    }
    cout << "White: ";
    print('K', 'K', true);
    print('Q', 'Q', true);
    print('R', 'R', true);
    print('B', 'B', true);
    print('N', 'N', true);
    print('P', 'P', true);
    cout << endl << "Black: ";
    firstPjas = true;
    print('k', 'K', false);
    print('q', 'Q', false);
    print('r', 'R', false);
    print('b', 'B', false);
    print('n', 'N', false);
    print('p', 'P', false);

}
