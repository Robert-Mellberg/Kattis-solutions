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
#include <queue>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/bus

//Solve by approaching the problem from the end. At the last stop there are 0 people, the stop before that (0+0,5)*2 = 1,
//the stop before that (1+0,5)*2 etc.
int main()
{
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        
        int initialPassengers = 0;
        int stops;
        cin >> stops;
        for (int p = 0; p < stops; p++) {
            initialPassengers = initialPassengers * 2 + 1;
        }
        cout << initialPassengers << "\n";
    }
    
    return 0;
}
