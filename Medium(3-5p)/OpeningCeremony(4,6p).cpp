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

//https://open.kattis.com/problems/ceremony

//Vertical charges will remove 1 tower per charge
//Horizontal should therefore only be used when n charges will remove more than n towers

//Sort all towers' heights in an array in ascending order. Loop through the array from lowest to highest tower
//For each tower chech, if the n'th tower's height is lower than the amount of towers (still standing) lower than the n'th tower.
//Then use the horizontal charge as many times as the n'th tower's height.

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<int> heights;
    //antal keeps track of how many towers there are
    int antal;
    cin >> antal;

    for (int i = 0; i < antal; i++) {
        int read;
        cin >> read;
        heights.push_back(read);
    }
    sort(heights.begin(), heights.end());
    //horizontal is the amount of times the horizontal charge has been used, count is the amount of towers destroyed from horizontal charge
    int horizontal = 0, count = 0;
    for (int i = 1; i <= heights.size(); i++) {
    // i - count is the amount of towers (still standing) lower than tower i
    // heights[i - 1] - horizontal is the height of tower i after using the horizontal charges.
    // if the amount of towers lower than tower i is greater or equal to the height of tower i, increaes amount of horizontal charges.
        if (i - count >= heights[i - 1] - horizontal) {
            count = i;
            horizontal = heights[i - 1];
        }
    }
    //antal - count is the amount of times vertical charges were used
    int total = horizontal + antal - count;
    cout << total;
    return 0;
}
