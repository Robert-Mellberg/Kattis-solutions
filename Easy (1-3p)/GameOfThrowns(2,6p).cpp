#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/throwns

int main()
{
    vector<int> allaTal;
    int antalBarn, commandon;
    cin >> antalBarn >> commandon;
    for (int j = 0; j < commandon; j++) {
        string input;
        cin >> input;
        if (((int)input[0] >= 48 && (int)input[0] <= 57) || ((int)input[1] >= 48 && (int)input[1] <= 57)) {
            allaTal.push_back(atoi(input.c_str()));
        }
        else {
            int undo;
            cin >> undo;
            for (int i = 0; i < undo; i++) {
                allaTal.pop_back();
            }
        }
    }
    long long total = 0;
    for (int i : allaTal) {
        total += i;
    }
    total %= antalBarn;
    if (total < 0) {
        total += antalBarn;
    }
    cout << total;
    return 0;
}
