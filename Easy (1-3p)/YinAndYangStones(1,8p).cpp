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

//https://open.kattis.com/problems/yinyangstones

//The stones can always be balanced if there are as many white stones as black stones.
int main()
{
    int wCount = 0, bCount = 0;
    char c;
    while (cin >> c) {
        if (c == 'W') {
            wCount++;
        }
        else {
            bCount++;
        }
    }
    if (bCount == wCount) {
        cout << "1";
    }
    else {
        cout << "0";
    }
    return 0;
}
