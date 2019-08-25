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

//https://open.kattis.com/problems/pet

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int bastaIndex, hogstaScore = 0;
    for (int l = 1; l <= 5; l++) {
        int total = 0;
        for (int o = 0; o < 4; o++) {
            int read;
            cin >> read;
            total += read;
        }
        if (total > hogstaScore) {
            hogstaScore = total;
            bastaIndex = l;
        }
        
    }
    cout << bastaIndex << " " << hogstaScore;
    return 0;
}
