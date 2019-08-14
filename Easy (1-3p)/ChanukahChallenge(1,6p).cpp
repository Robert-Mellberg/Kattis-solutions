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

//https://open.kattis.com/problems/chanukah


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int cAse;
        cin >> cAse;
        cout << cAse << " ";
        long long antalDagar;
        cin >> antalDagar;
        long long total = ((1 + antalDagar)*antalDagar)/2;
        total += antalDagar;

        cout << total << endl;
    }
    return 0;
}
