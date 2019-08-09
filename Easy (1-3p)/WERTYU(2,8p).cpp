#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/wertyu

//Make a unordered_map where every keyboardkey maps to the keyboardkey to the right of it
//Iterate the word and translate char for char.

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    unordered_map<char, char> charMap;
    for (int i = 2; i <= 9; i++) {
        charMap[char(i + '0')] = char(i - 1 + '0');
    }
    charMap['0'] = '9';
    charMap['1'] = '‘';
    charMap['W'] = 'Q';
    charMap['E'] = 'W';
    charMap['R'] = 'E';
    charMap['T'] = 'R';
    charMap['Y'] = 'T';
    charMap['U'] = 'Y';
    charMap['I'] = 'U';
    charMap['O'] = 'I';
    charMap['P'] = 'O';
    charMap['S'] = 'A';
    charMap['D'] = 'S';
    charMap['F'] = 'D';
    charMap['G'] = 'F';
    charMap['H'] = 'G';
    charMap['J'] = 'H';
    charMap['K'] = 'J';
    charMap['L'] = 'K';
    charMap['X'] = 'Z';
    charMap['C'] = 'X';
    charMap['V'] = 'C';
    charMap['B'] = 'V';
    charMap['N'] = 'B';
    charMap['M'] = 'N';
    charMap['-'] = '0';
    charMap['='] = '-';
    charMap['['] = 'p';
    charMap[']'] = '[';
    charMap[char(92)] = ']';
    charMap[char(59)] = 'L';
    charMap[char(39)] = char(59);
    charMap[','] = 'M';
    charMap['.'] = ',';
    charMap['/'] = '.';
    charMap[' '] = ' ';

    string input;
    while (getline(cin, input)) {
        for (char c : input) {
            cout << charMap[c];
        }
        cout << "\n";
    }

    return 0;
}
