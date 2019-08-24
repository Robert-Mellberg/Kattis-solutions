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

//https://open.kattis.com/problems/tri

int main()
{
    double num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    if (num1 + num2 == num3) {
        cout << num1 << "+" << num2 << "=" << num3;
    }
    else if (num1 - num2 == num3) {
        cout << num1 << "-" << num2 << "=" << num3;
    }
    else if (num1 * num2 == num3) {
        cout << num1 << "*" << num2 << "=" << num3;
    }
    else if (num1 / num2 == num3) {
        cout << num1 << "/" << num2 << "=" << num3;
    }
    else if (num1 == num2 / num3) {
        cout << num1 << "=" << num2 << "/" << num3;
    }
    else if (num1 == num2 * num3) {
        cout << num1 << "=" << num2 << "*" << num3;
    }
    else if (num1 == num2 + num3) {
        cout << num1 << "=" << num2 << "+" << num3;
    }
    else if (num1 == num2 - num3) {
        cout << num1 << "=" << num2 << "-" << num3;
    }
    return 0;
}
