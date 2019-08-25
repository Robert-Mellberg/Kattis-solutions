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

//https://open.kattis.com/problems/symmetricorder

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;
    while (true) {
        count++;
        int antal;
        cin >> antal;
        if (!antal) {
            break;
        }
        vector<string> names;
        for (int i = 0; i < antal; i++) {
            string namn;
            cin >> namn;
            names.push_back(namn);
        }
        cout << "SET " << count << endl;
        for (int i = 0; i < names.size(); i+=2) {
            cout << names[i] << endl;
        }
        for (int i = (int)(names.size() / 2) * 2 - 1; i >= 1; i -= 2) {
            cout << names[i] << endl;
        }
    }
    return 0;
}
