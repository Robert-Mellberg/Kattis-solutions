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

//https://open.kattis.com/problems/humancannonball2

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        double hast, vinkel, x, h1, h2;
        cin >> hast >> vinkel >> x >> h1 >> h2;
        double t = x / (hast*cos(vinkel*3.1415926535 / 180));
        double y = hast * t*sin(vinkel*3.1415926535 / 180) - 9.81*t*t / 2;
        if (y - h1 >= 1 && h2 - y >= 1) {
            cout << "Safe" << endl;
        }
        else {
            cout << "Not Safe" << endl;
        }
    }
    return 0;
}
