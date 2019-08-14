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

//https://open.kattis.com/problems/rationalsequence3


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cases;
    cin >> cases;

    for (int i = 1; i <= cases; i++) {
        long long numerator = 1, denominator = 1, n;
        int testCase;
        cin >> testCase >> n;
        cout << testCase << " ";

        long long lower, higher;
        int level = 0;
        while (true) {
            level++;
            lower = pow(2, level-1);
            higher = pow(2, level) - 1;

            if (n <= higher) {
                break;
            }
        }

        for (int currLevel = 1; currLevel < level; currLevel++) {
            long long middle = (lower + higher) / 2;
            if (n <= middle) {
                higher = middle;
                denominator += numerator;
            }
            else {
                lower = middle + 1;
                numerator += denominator;
            }
        }


        cout << numerator << "/" << denominator << endl;
    }

}
