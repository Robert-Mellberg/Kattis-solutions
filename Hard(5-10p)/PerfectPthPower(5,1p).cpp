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

//https://open.kattis.com/submissions/3618900

//Loop p through every number from 32 to 1, check if ⌊x^(1/p)⌋^p = x or if ⌈x^(1/p)⌉^p
//If so, then there is an integer i such that i^p = x

//x can also be negative and there can therefore be an i < 0 such that i^p = x
//Loop p through every uneven number from -31 to -1 and check the same condition as before.

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long num;
    while (cin >> num && num) {
        if (num >= 2) {
            for (int p = 32; p >= 1; p--) {
                long long b = pow(num, (double)1 / p);
                long long b1 = b + 1;
                if (pow(b, p) == num || pow(b1, p) == num) {
                    cout << p << "\n";
                    break;
                }
            }
        }
        else {
            num *= -1;
            for (int p = 31; p >= 1; p-= 2) {
                long long b = pow(num, (double)1 / p);
                long long b1 = b + 1;
                if (pow(b, p) == num || pow(b1, p) == num) {
                    cout << p << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}
