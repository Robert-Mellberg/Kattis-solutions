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

//https://open.kattis.com/problems/estimatingtheareaofacircle

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (true) {
        double r, points, pointsInCircle;
        cin >> r >> points >> pointsInCircle;
        if (r == 0 && points == 0 && pointsInCircle == 0) {
            break;
        }
        cout  << setprecision(10) << r * r*3.1415926535 << " " << (pointsInCircle/points)*4*r*r << endl;
    }
    return 0;
}
