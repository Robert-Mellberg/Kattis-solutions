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

//https://open.kattis.com/problems/onechicken

int main()
{
    int guests, amountOfChicken, difference;
    cin >> guests >> amountOfChicken;
    difference = amountOfChicken - guests;
    string pieces = " pieces";
    if (abs(difference) == 1) {
        pieces = " piece";
    }
    if (difference > 0) {
        cout << "Dr. Chaz will have " << difference << pieces << " of chicken left over!";
    }
    else {
        cout << "Dr. Chaz needs " << abs(difference) << " more" <<  pieces << " of chicken!";
    }
    return 0;
}
