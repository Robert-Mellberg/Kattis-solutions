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

//https://open.kattis.com/problems/nodup

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    getline(cin, input);
    stringstream ss(input);
    string word;
    unordered_set<string> duplicates;
    bool correct = true;
    while (ss >> word) {
        if (duplicates.find(word) != duplicates.end()) {
            correct = false;
        }
        duplicates.insert(word);
    }
    if (correct) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
    return 0;
}
