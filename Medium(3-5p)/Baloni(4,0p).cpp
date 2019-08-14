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

//https://open.kattis.com/problems/baloni


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<int> currArrow(1000001, 0);
    int antal;
    cin >> antal;
    int count = 0;
    for (int i = 0; i < antal; i++) {
        int height;
        cin >> height;
        if (currArrow[height] > 0) {
            currArrow[height]--;
            currArrow[height - 1]++;
        }
        else {
            count++;
            currArrow[height - 1]++;
        }
    }
    cout << count;
    return 0;
}
