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

//https://open.kattis.com/problems/anothercandies

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        unsigned long long total = 0;
        int numOfChilden;
        cin >> numOfChilden;
        for (int j = 0; j < numOfChilden; j++) {
            unsigned long long read;
            cin >> read;
            total = (total + read)%numOfChilden;
        }
        if (total) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
