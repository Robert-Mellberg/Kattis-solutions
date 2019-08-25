#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
using namespace std;

//https://open.kattis.com/problems/cetvrta

int main()
{
    bool forstaX = false;
    bool forstaY = false;
    int x1, x2, y1, y2;
    cin >> x1 >> y1;

    int read = 0;
    cin >> read;
    if (read == x1) {
        forstaX = true;
    }
    else {
        x2 = read;
    }

    cin >> read;
    if (read == y1) {
        forstaY = true;
    }
    else {
        y2 = read;
    }

    cin >> read;
    if (read == x1) {
        forstaX = true;
    }
    else {
        x2 = read;
    }

    cin >> read;
    if (read == y1) {
        forstaY = true;
    }
    else {
        y2 = read;
    }

    if (forstaX) {
        cout << x2;
    }
    else {
        cout << x1;
    }
    cout << " ";
    if (forstaY) {
        cout << y2;
    }
    else {
        cout << y1;
    }
    return 0;
}
