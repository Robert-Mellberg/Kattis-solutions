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

//https://open.kattis.com/problems/zanzibar

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int amountOfTurtles, previous;
        cin >> previous;
        int total = 0;
        while (cin >> amountOfTurtles) {
            if (amountOfTurtles == 0) {
                break;
            }
            int maxNativeTurtles = 2 * previous;
            if (maxNativeTurtles < amountOfTurtles) {
                total += amountOfTurtles - maxNativeTurtles;
            }

            previous = amountOfTurtles;
        }
        cout << total << endl;
    }
    return 0;
}
