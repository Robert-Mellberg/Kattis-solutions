#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <sstream>
using namespace std;

//https://open.kattis.com/problems/welcomeeasy

int total = 0;
unordered_map<char, vector<int>> charIndexes;
vector<char> phrase = {'w', 'e', 'l', 'c', 'o', 'm', 'e', ' ', 't', 'o', ' ', 'c', 'o', 'd', 'e', ' ', 'j', 'a', 'm'};
void validCases(int lower, int level) {
    vector<int> indexes = charIndexes[phrase[level]];
    if (level == 18) {
        for (int index : indexes) {
            if (index >= lower) {
                total++;
            }
        }
        return;
    }
    for (int index : indexes) {
        if (index > lower) {
            validCases(index, level+1);
        }
    }
}
int main()
{
    int antalCases;
    cin >> antalCases;
    cin.ignore();
    for (int p = 0; p < antalCases; p++) {
        total = 0;
        string input;
        getline(cin, input);
        charIndexes.clear();
        for (int k = 0; k < input.size(); k++){
            charIndexes[input[k]].push_back(k);
        }
        validCases(-1, 0);
        cout << "Case #" << p + 1 << ": ";
        if (total % 10000 < 1000) {
            cout << "0";
            if (total % 10000 < 100) {
                cout << "0";
                if (total % 10000 < 10) {
                    cout << "0";
                }
            }
        }
        cout << total % 10000 << endl;
    }


    return 0;
}
