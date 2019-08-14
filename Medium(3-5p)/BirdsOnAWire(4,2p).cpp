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

//https://open.kattis.com/problems/birds


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int length, minDistance, antal;
    cin >> length >> minDistance >> antal;
    vector<int> positions;
    for (int i = 0; i < antal; i++) {
        int pos;
        cin >> pos;
        positions.push_back(pos);
    }
    sort(positions.begin(), positions.end());
    int count = 0;
    for (int ind = 0; ind < (int)positions.size() - 1; ind++) {
        int dist = positions[ind + 1] - positions[ind];
        count += (dist / minDistance)-1;
    }
    if (positions.size() == 0) {
        count += ((length - 12)/minDistance)+1;
    }
    else {
        count += (positions[0]-6)/minDistance;
        count += ((length - 6) - positions[positions.size() - 1])/minDistance;
    }
    cout << count;
    return 0;
}
