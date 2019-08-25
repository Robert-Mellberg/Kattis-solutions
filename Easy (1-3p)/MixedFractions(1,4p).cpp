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

//https://open.kattis.com/problems/mixedfractions

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (true) {
        unsigned int taljare, namnare;
        cin >> taljare >> namnare;
        if (!taljare) {
            break;
        }
        cout << taljare / namnare << " " << taljare % namnare << " / " << namnare << endl;
    }
    return 0;
}
