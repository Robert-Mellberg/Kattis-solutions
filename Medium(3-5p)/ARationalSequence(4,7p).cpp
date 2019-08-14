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
        if (numerator == 1 && denominator == 1) {
            cout << "1/2" << endl;
            continue;
        }
        if (denominator == 1) {
            cout << denominator << "/" << numerator+1 << endl;
            continue;
        }


        long long upleft = numerator / denominator;
        numerator %= denominator;

        //go up right
        denominator -= numerator;

        // go down right
        numerator += denominator;

        // go down left as many times as go up left
        denominator += upleft * numerator;

        cout << numerator << "/" << denominator << endl;
    }

}
