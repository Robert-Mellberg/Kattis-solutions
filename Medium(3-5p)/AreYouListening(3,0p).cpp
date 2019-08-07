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

//https://open.kattis.com/problems/areyoulistening

//The distances to a listening device can be calculated with pythagoras theorem
//The maximum range you can have without being detected by a listening device is the distance - listening device's range.
//Save all such ranges in an array and sort the array in ascending order,
//the third element in that array is the maximum range you can have without being detected.

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int x, y, n;
    cin >> x >> y >> n;

    vector<double> ranges;
    for (int i = 0; i < n; i++) {
        int xx, yy, r;
        cin >> xx >> yy >> r;
        double distance = sqrt((xx - x)*(xx - x) + (yy - y)*(yy - y));
        ranges.push_back(distance - r);
    }
    sort(ranges.begin(), ranges.end());
    double range = ranges[2];
    if (range < 0) {
        cout << 0;
    }
    else {
        cout << (int)range;
    }
    return 0;
}
