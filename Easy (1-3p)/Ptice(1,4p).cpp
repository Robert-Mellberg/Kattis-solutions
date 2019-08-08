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

//https://open.kattis.com/problems/ptice

//Compare all the letters from the key to every persons answer pattern. Count the amount of right answers.


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    unordered_map<char, char> charMap;
    
    vector<char> adrianChance = { 'A', 'B', 'C' };
    vector<char> brunoChance = { 'B', 'A', 'B', 'C' };
    vector<char> goranChance = { 'C', 'C', 'A', 'A', 'B', 'B' };

    string input;
    cin >> input >> input;
    int countB = 0, countA = 0, countG = 0;
    for (int i = 0; i < input.length(); i++) {
        char ans = input[i];
        if (ans == adrianChance[i % 3]) {
            countA++;
        }
        if (ans == brunoChance[i % 4]) {
            countB++;
        }
        if (ans == goranChance[i % 6]) {
            countG++;
        }
    }

    int best = max(countA, countB);
    best = max(best, countG);
    cout << best << "\n";
    if (countA == best) {
        cout << "Adrian\n";
    }
    if (countB == best) {
        cout << "Bruno\n";
    }
    if (countG == best) {
        cout << "Goran\n";
    }

    return 0;
}
