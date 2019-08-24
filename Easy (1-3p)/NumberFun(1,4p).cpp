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

//https://open.kattis.com/problems/numberfun

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        double num1, num2, num3;
        cin >> num1 >> num2 >> num3;
        if (num1 + num2 == num3) {
            cout << "Possible" << endl;
            continue;
        }
        if (num1 - num2 == num3) {
            cout << "Possible" << endl;
            continue;
        }
        if (num1 / num2 == num3) {
            cout << "Possible" << endl;
            continue;
        }
        if (num1 * num2 == num3) {
            cout << "Possible" << endl;
            continue;
        }
        if (num2 - num1 == num3) {
            cout << "Possible" << endl;
            continue;
        }
        if (num2 / num1 == num3) {
            cout << "Possible" << endl;
            continue;
        }
        cout << "Impossible" << endl;
    }
    return 0;
}
