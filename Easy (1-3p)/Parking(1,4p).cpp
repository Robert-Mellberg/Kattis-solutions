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

//https://open.kattis.com/problems/parking2

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int antal;
        cin >> antal;
        int max = 0;
        int min = 1000;
        for (int j = 0; j < antal; j++) {
            int read;
            cin >> read;
            if (read < min) {
                min = read;
            }
            if (read > max) {
                max = read;
            }
        }
        cout << (max - min) * 2 << endl;
    }
    return 0;
}
