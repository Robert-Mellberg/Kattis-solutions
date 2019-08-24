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

//https://open.kattis.com/problems/plantingtrees


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int antal;
    cin >> antal;
    vector<int> allDays;
    for (int i = 1; i <= antal; i++) {
        int read;
        cin >> read;
        read *= -1;
        allDays.push_back(read);
    }
    sort(allDays.begin(), allDays.end());
    int max = 0;
    for (int i = 0; i < allDays.size(); i++) {
        if (allDays[i]-2-i < max) {
            max = allDays[i] - 2 - i;
        }
    }
    cout << -max;
    return 0;
}
