#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

//https://open.kattis.com/problems/bijele

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    vector<int> realNumbers = {1, 1, 2, 2, 2, 8};
    for (int l = 0; l < 6; l++) {

        int antal;
        cin >> antal;
        cout << realNumbers[l] - antal << " ";
    }
    return 0;
}
