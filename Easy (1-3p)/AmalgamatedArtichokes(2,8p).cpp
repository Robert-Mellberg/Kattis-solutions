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

//https://open.kattis.com/problems/artichoke


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    double p, a, b, c, d, n;
    cin >> p >> a >> b >> c >> d >> n;

    double max = 0;
    double maxDifference = 0;
    for (int k = 1; k <= n; k++) {
        double funcValue = p*(sin(a*k + b) + cos(c*k + d) + 2);

        if (funcValue > max) {
            max = funcValue;
        }
        else if (max - funcValue > maxDifference) {
            maxDifference = max - funcValue;
        }
    }
    printf("%.10f", maxDifference);
    return 0;
}
