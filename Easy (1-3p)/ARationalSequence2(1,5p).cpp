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




int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cases;
    cin >> cases;

    for (int i = 1; i <= cases; i++) {
        long long numerator, denominator;
        char trash;
        int testCase;
        cin >> testCase >> numerator >> trash >> denominator;
        cout << testCase << " ";

        vector<char> directions;
        while (denominator != 1 || numerator != 1) {
            if (denominator > numerator) {
                denominator -= numerator;
                directions.push_back('L');
            }
            else {
                numerator -= denominator;
                directions.push_back('R');
            }
        }

        int n = 1;
        for (int j = directions.size() - 1; j >= 0; j--) {
            if (directions[j] == 'L') {
                n *= 2;
            }
            else {
                n = (n * 2) + 1;
            }
        }
        cout << n << endl;
    }

}
