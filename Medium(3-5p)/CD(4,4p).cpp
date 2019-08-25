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

//https://open.kattis.com/problems/cd

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        int antal1, antal2;
        cin >> antal1 >> antal2;
        if (!antal1 && !antal2) {
            break;
        }
        unordered_set<int> jackCD;
        for (int i = 0; i < antal1; i++) {
            int read;
            cin >> read;
            jackCD.insert(read);
        }
        int count = 0;
        for (int i = 0; i < antal2; i++) {
            int read;
            cin >> read;
            if (jackCD.find(read) != jackCD.end()) {
                count++;
            }
        }
        cout << count << endl;
    }

    
    return 0;
}
