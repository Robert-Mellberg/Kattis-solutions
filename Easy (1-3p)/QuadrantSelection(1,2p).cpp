#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
using namespace std;

//https://open.kattis.com/problems/quadrant

int main()
{
    int x, y;
    cin >> x >> y;
    if ((double)x / y > 0) {
        if (x > 0) {
            cout << 1;
        }
        else {
            cout << 3;
        }
    }
    else {
        if (x > 0) {
            cout << 4;
        }
        else {
            cout << 2;
        }
    }

    return 0;
}
