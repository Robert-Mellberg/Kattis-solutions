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

//https://open.kattis.com/problems/oddgnome

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int amountOfGnomes;
        cin >> amountOfGnomes;
        int gnomePosition;
        int previous;
        cin >> previous;
        for (int j = 1; j < amountOfGnomes; j++) {
            int read;
            cin >> read;
            if (read - previous != 1) {
                gnomePosition = j;
            }
            previous = read;
        }
        cout << gnomePosition << endl;
    }
    return 0;
}
