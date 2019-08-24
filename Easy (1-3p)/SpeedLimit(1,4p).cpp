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

//https://open.kattis.com/problems/speedlimit

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int read;
    cin >> read;
    while (read != -1) {
        vector<int> time = { 0 };
        vector<int> speed = { 0 };
        for (int p = 0; p < read; p++) {
            int speedInt, hour;
            cin >> speedInt >> hour;
            time.push_back(hour);
            speed.push_back(speedInt);
        }
        int total = 0;
        for (int i = 1; i < time.size(); i++) {
            total += (time[i] - time[i - 1])*speed[i];
        }
        cout << total << " miles" << endl;
        cin >> read;
    }
    

    return 0;
}
