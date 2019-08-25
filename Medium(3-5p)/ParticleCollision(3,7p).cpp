#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
#include <random>
using namespace std;

//https://open.kattis.com/problems/particlecollision

double calculateT(double x2, double x1, double xv, double y2, double y1, double yv, double r) {
    double p = 0;
    double q = 0;
    double x3 = x2 - x1;
    double y3 = y2 - y1;
    double t2Term = xv*xv+yv*yv;
    p = (-2*x3*xv-2*y3*yv)/t2Term;
    q = (x3*x3+y3*y3-4*r*r)/t2Term;
    if ((pow(p / 2, 2) - q) < 0) {
        return -1;
    }
    return (-p/2)-sqrt(pow(p / 2, 2)-q);
}

int main()
{
    bool oneCollideTwo = false;
    double x1, y1, x2, y2, x3, y3;
    double xv, yv, r;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> xv >> yv >> r;
    double t;
    double avstandX2 = calculateT(x2, x1, xv, y2, y1, yv, r);
    double avstandX3 = calculateT(x3, x1, xv, y3, y1, yv, r);
    if (avstandX2 < avstandX3 || avstandX3 < 0) {
        t = calculateT(x2, x1, xv, y2, y1, yv, r);
        //1 krocka med 2
        if (t > 0) {
            double newXV = x2-(x1 + t * xv);
            double newYV = y2 - (y1 + t * yv);
            t = calculateT(x3, x2, newXV, y3, y2, newYV, r);
            //2 krocka med 3
            if (t > 0) {
                cout << 1;
                return 0;
            }
            cout << 3;
            return 0;
        }

        t = calculateT(x3, x1, xv, y3, y1, yv, r);
        //1 krocka med 3
        if (t > 0) {
            double newXV = x3 - (x1 + t * xv);
            double newYV = y3 - (y1 + t * yv);
            t = calculateT(x2, x3, newXV, y2, y3, newYV, r);
            //3 krocka med 2
            if (t > 0) {
                cout << 2;
                return 0;
            }
            cout << 4;
            return 0;
        }
    }



    else {
        t = calculateT(x3, x1, xv, y3, y1, yv, r);
        //1 krocka med 3
        if (t > 0) {
            double newXV = x3 - (x1 + t * xv);
            double newYV = y3 - (y1 + t * yv);
            t = calculateT(x2, x3, newXV, y2, y3, newYV, r);
            //3 krocka med 2
            if (t > 0) {
                cout << 2;
                return 0;
            }
            cout << 4;
            return 0;
        }

        t = calculateT(x2, x1, xv, y2, y1, yv, r);
        //1 krocka med 2
        if (t > 0) {
            double newXV = x2 - (x1 + t * xv);
            double newYV = y2 - (y1 + t * yv);
            t = calculateT(x3, x2, newXV, y3, y2, newYV, r);
            //2 krocka med 3
            if (t > 0) {
                cout << 1;
                return 0;
            }
            cout << 3;
            return 0;
        }
    }

    cout << 5;

    return 0;
}
