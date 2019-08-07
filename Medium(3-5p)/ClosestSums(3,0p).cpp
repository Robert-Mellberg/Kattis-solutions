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

//https://open.kattis.com/problems/closestsums

//Save all integers in an array. For every query, loop through the array twice with two nested loops.
//Compute every sum possible within the two nested loops and save the closets sum.

//Each query will result in up to 500 000 iterations to compute all sums.
//Several optimizations could be applied, e.g sorting the array, then looping through the array to choose the first number
//and then choose the second number with the help of binary search.

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int antal, quer;
    int count = 0;
    while (cin >> antal) {
        count++;
        cout << "Case " << count << ":\n";
        vector<int> siffror;
        for (int i = 0; i < antal; i++) {
            int num;
            cin >> num;
            siffror.push_back(num);
        }
        sort(siffror.begin(), siffror.end());
        cin >> quer;
        for (int l = 0; l < quer; l++) {
            int num;
            cin >> num;
            int closestSum = 1000000000;
            for (int first = 0; first < siffror.size(); first++) {
                int close = 1000000000;
                int num1 = siffror[first];
                for (int sec = first + 1; sec < siffror.size(); sec++) {
                    int num2 = siffror[sec];
                    if (abs(num1 + num2 - num) < abs(close - num)) {
                        close = num1 + num2;
                    }
                    else {
                        break;
                    }
                }
                if (abs(close - num) < abs(closestSum - num)) {
                    closestSum = close;
                }
            }
            cout << "Closest sum to " << num << " is " << closestSum << ".\n";
        }
    }
    return 0;
}
