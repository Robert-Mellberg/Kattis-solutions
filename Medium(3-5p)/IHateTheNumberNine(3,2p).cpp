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

//https://open.kattis.com/problems/nine

//The first digit can have any of the numbers 1-9
//The rest of the digits can have any of the numbers 0-9
//The total amount of numbers will therefore be 8*9^(amount of digits-1).

//modPow uses exponentiation by squaring
long long modPow(long long base, long long exponent) {

    long long result = 1;

    while (exponent != 0) {
        if (exponent & 1) {
            result = (result * base) % 1000000007;
        }
        exponent /= 2;
        base = (base * base) % 1000000007;
    }

    return result;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        long long digits;
        cin >> digits;
        long long total = (8 * modPow(9, digits - 1)) % 1000000007;
        cout << total << "\n";
    }



    return 0;
}
