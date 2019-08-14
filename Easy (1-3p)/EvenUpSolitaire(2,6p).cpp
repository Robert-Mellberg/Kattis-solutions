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

//https://open.kattis.com/problems/evenup


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cases;
    cin >> cases;
    int total = cases;
    int num;
    cin >> num;
    num %= 2;
    int lastnum = num;
    int sequenceSize = 1;
    int rest = 0;
    for (int i = 1; i < cases; i++) {
        cin >> num;
        num %= 2;
        if (num == lastnum) {
            sequenceSize++;
        }
        else {
            lastnum = num;
            total -= (sequenceSize / 2)*2;
            if (sequenceSize % 2 == 1) {
                rest++;
                sequenceSize = 1;
            }
            else {
                sequenceSize = 1;
                if (rest > 0) {
                    sequenceSize++;
                    rest--;
                }
            }
        }
    }
    total -= (sequenceSize / 2)*2;
    cout << total;
    return 0;
}
