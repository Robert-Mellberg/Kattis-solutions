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
using namespace std;

//https://open.kattis.com/problems/erase

int main()
{
    int timesOverwritten;
    cin >> timesOverwritten;
    string before, after;
    cin >> before >> after;
    if (timesOverwritten % 2 == 0) {
        if (before == after) {
            cout << "Deletion succeeded";
        }
        else {
            cout << "Deletion failed";
        }
    }
    else {
        for (int i = 0; i < before.length(); i++) {
            if (abs(before[i] - after[i]) != 1) {
                cout << "Deletion failed";
                return 0;
            }
        }
        cout << "Deletion succeeded";
    }
    return 0;
}
