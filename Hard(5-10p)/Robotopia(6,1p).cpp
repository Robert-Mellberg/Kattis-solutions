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
using namespace std;

//https://open.kattis.com/problems/robotopia

//Solve an equation system;
// x*l1+y*l2 = lt
// x*a1+y*a2 = at
// solve for x, y. e.g with gauss-elimination

struct trippel {
    long long a;
    long long b;
    long long c;
};

trippel gotSingleSolution(trippel equation) {
    int count = 0, xx, yy;
    for (int x = 1; x <= 10000; x++) {
        if (equation.a*x >= equation.c) {
            break;
        }
        int z = equation.c - equation.a*x;
        if (z%equation.b == 0 && z >= equation.b) {
            count++;
            if (count == 1) {
                xx = x;
                yy = z / equation.b;
            }
        }
    }
    if (count == 1) {
        return { 1, xx, yy };
    }
    else {
        return { 0, 0, 0 };
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        long long l1, a1, l2, a2, lt, at;
        cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;
        trippel equation1 = { l1, l2, lt };
        trippel equation2 = { a1, a2, at };
        equation2.a *= equation1.a;
        equation2.b *= equation1.a;
        equation2.c *= equation1.a;

        int difference = equation2.a / equation1.a;
        equation2.a = 0;
        equation2.b -= equation1.b * difference;
        equation2.c -= equation1.c * difference;

        if (equation2.b == 0 && equation2.c != 0) {
            cout << "?\n";
            continue;
        }
        else if (equation2.b == 0 && equation2.c == 0) {
            trippel solution = gotSingleSolution(equation1);
            if (solution.a == 0) {
                cout << "?\n";
            }
            else {
                cout << solution.b << " " << solution.c << "\n";
            }
            continue;
        }
        if (equation2.c%equation2.b != 0) {
            cout << "?\n";
            continue;
        }
        int y = equation2.c / equation2.b;
        equation1.c -= y * equation1.b;
        if (equation1.c%equation1.a != 0) {
            cout << "?\n";
            continue;
        }
        int x = equation1.c / equation1.a;
        if (x < 1 || y < 1) {
            cout << "?\n";
            continue;
        }

        cout << x << " " << y << "\n";

    }

    return 0;
}
