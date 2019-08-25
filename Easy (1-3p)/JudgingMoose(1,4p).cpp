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

//https://open.kattis.com/problems/judgingmoose

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int left, right;
    cin >> left >> right;
    if (left == right) {
        if (left == 0) {
            cout << "Not a moose";
        }
        else {
            cout << "Even " << left * 2;
        }
    }
    else {
        cout << "Odd " << max(left, right) * 2;
    }
    return 0;
}
