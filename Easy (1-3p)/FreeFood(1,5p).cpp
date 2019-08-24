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

//https://open.kattis.com/problems/freefood


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cases;
    cin >> cases;
    unordered_set<int> allDays;
    for (int i = 0; i < cases; i++) {
        int lower, higher;
        cin >> lower >> higher;
        for (int j = lower; j <= higher; j++) {
            allDays.insert(j);
        }
    }
    cout << allDays.size();
    return 0;
}
