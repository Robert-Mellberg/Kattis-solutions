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

//https://open.kattis.com/problems/trainpassengers


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long capacity, antal;
    cin >> capacity >> antal;

    long long currPass = 0;
    for (int i = 0; i < antal; i++) {
        int left, enter, wait;
        cin >> left >> enter >> wait;
        currPass -= left;
        if (currPass < 0) {
            cout << "impossible";
            return 0;
        }
        currPass += enter;
        if (currPass > capacity) {
            cout << "impossible";
            return 0;
        }
        if (wait != 0 && currPass < capacity) {
            cout << "impossible";
            return 0;
        }
    }
    if (currPass != 0) {
        cout << "impossible";
        return 0;
    }
    cout << "possible";

    return 0;
}
