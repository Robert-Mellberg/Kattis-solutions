#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

//https://open.kattis.com/problems/amultiplicationgame

void utvardera(long long maxTal)
{
    long long higherLimit = (maxTal - 1) * 2;
    long long lowerLimit = maxTal;
    while (true) {
        higherLimit = floor((long double)higherLimit / 2);
        lowerLimit = ceil((long double)lowerLimit / 9);
        //cout << higherLimit << "-" << lowerLimit << " Olle" << endl;
        if (lowerLimit <= 9) {
            if (lowerLimit > 2 || higherLimit < 9) {
                cout << "Stan wins." << endl;
            }
            else{
                cout << "Ollie wins." << endl;
            }

            break;
        }

        higherLimit = floor((double)higherLimit / 9);
        lowerLimit = ceil((double)lowerLimit / 2);
        //cout << higherLimit << "-" << lowerLimit << " Stan" << endl;
        if (higherLimit < 9)
            break;
    }
}

int main()
{

    long long maxTal;

    while (cin >> maxTal) {
        utvardera(maxTal);
    }
    return 0;
}
