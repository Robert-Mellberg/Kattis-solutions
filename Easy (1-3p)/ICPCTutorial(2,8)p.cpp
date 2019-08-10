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
using namespace std;

//https://open.kattis.com/problems/tutorial

long long factorial(long long num) {
    long long res = 1;
    for (int i = 2; i <= num; i++) {
        res *= i;
    }
    return res;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    long double limit, n, type;
    cin >> limit >> n >> type;

    if (type == 1) {
        if (n >= 13) {
            n = 1000000001;
        }
        else {
            n = factorial(n);
        }
    }
    else if (type == 2) {
        n = pow(2, n);
    }
    else if (type <= 5) {
        n = pow(n, 7 - type);
    }
    else if (type == 6) {
        n = n * log2(n);
    }
    if (n <= limit) {
        cout << "AC";
    }
    else {
        cout << "TLE";
    }
    return 0;
}
