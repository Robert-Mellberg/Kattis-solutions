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

//https://open.kattis.com/problems/dicegame

int main()
{
    int gunnar = 0, emma = 0;
    for (int i = 0; i < 4; i++) {
        int score;
        cin >> score;
        gunnar += score;
    }
    for (int i = 0; i < 4; i++) {
        int score;
        cin >> score;
        emma += score;
    }
    if (!(gunnar - emma)) {
        cout << "Tie";
    }
    else if (gunnar > emma) {
        cout << "Gunnar";
    }
    else {
        cout << "Emma";
    }
    return 0;
}
