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

//https://open.kattis.com/problems/mandelbrot

//Save the given C-value and the r-value(maximum amount of iterations)
//initialize x and y as 0 and compute x and y through the recursive function r times
//check if x and y have diverged
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    double cx, cy, r;
    int num = 0;
    while (cin >> cx >> cy >> r) {
        num++;
        string msg = "IN";
        double x = 0, y = 0;
        for (int i = 1; i <= r+1; i++) {
            if (sqrt(x*x + y * y) >= 2) {
                msg = "OUT";
                break;
            }
            double tempx = x;
            double tempy = y;
            
            x = tempx * tempx - tempy * tempy+cx;
            y = 2 * tempx*tempy + cy;
        }
        cout << "Case " << num << ": " << msg << endl;

    }
    return 0;
}
