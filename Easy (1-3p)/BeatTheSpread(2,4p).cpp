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

//https://open.kattis.com/problems/beatspread


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int sum, diff;
        cin >> sum >> diff;
        if (sum < diff || sum-diff & 1) {
            cout << "impossible" << endl;
        }
        else {
            int secondScore = (sum - diff) / 2;
            int firstScore = sum - secondScore;
            cout << firstScore << " " << secondScore << endl;
        }
    }
    return 0;
}
