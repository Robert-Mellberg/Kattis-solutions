#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
using namespace std;

//https://open.kattis.com/problems/autori

int main()
{
    vector<char> kortning;
    string namn;
    cin >> namn;
    kortning.push_back(namn[0]);
    for (int i = 1; i < namn.length(); i++) {
        if (namn[i] == '-') {
            kortning.push_back(namn[i+1]);
        }
    }
    for (char c : kortning) {
        cout << c;
    }
    return 0;
}
