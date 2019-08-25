#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <stack>
using namespace std;

//https://open.kattis.com/problems/8queens

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;
    bool valid = true;
    set<int> rad, kolumn, diagonal1, diagonal2;
    for (int y = 1; y <= 8; y++) {
        for (int x = 1; x <= 8; x++) {
            char read;
            cin >> read;
            if (read == '.') {
                continue;
            }
            count++;
            if (rad.find(x) != rad.end()) {
                valid = false;
            }
            rad.insert(x);

            if (kolumn.find(y) != kolumn.end()) {
                valid = false;
            }
            kolumn.insert(y);

            int diagonal1Int = y - x;
            if (diagonal1.find(diagonal1Int) != diagonal1.end()) {
                valid = false;
            }
            diagonal1.insert(diagonal1Int);

            int diagonal2Int = y+x;
            if (diagonal2.find(diagonal2Int) != diagonal2.end()) {
                valid = false;
            }
            diagonal2.insert(diagonal2Int);
        }
    }
    if (valid && count == 8) {
        cout << "valid";
    }
    else {
        cout << "invalid";
    }

    return 0;
}
