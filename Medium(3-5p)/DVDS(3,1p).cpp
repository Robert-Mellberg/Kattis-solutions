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

//https://open.kattis.com/problems/dvds

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int antal, next = 1, errors = 0;
        cin >> antal;
        for (int l = 0; l < antal; l++) {
            int read;
            cin >> read;
            if (read == next) {
                next++;
            }
            else {
                errors++;
            }
        }
        cout << errors << endl;
    }
    return 0;
}
