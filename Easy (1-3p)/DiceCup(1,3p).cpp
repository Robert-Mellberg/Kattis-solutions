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

//https://open.kattis.com/problems/dicecup

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tarn1, tarn2;
    cin >> tarn1 >> tarn2;
    int minn = min(tarn1, tarn2);
    int maxx = max(tarn1, tarn2);
    for (int i = minn+1; i <= maxx + 1; i++) {
        cout << i << endl;
    }
    return 0;
}
