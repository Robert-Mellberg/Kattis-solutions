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




int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int antal, euroLimit;
    cin >> antal >> euroLimit;
    int half = euroLimit / 2;

    int maxLower = 0, minHigher = 1000000001, count = 0;
    for (int i = 0; i < antal; i++) {
        int num;
        num;
        cin >> num;
        if (num <= half) {
            count++;
            if (num > maxLower) {
                maxLower = num;
            }
        }
        else {
            if (num < minHigher) {
                minHigher = num;
            }
        }
    }

    if (minHigher != 1000000001) {
        if (minHigher <= euroLimit - maxLower) {
            count++;
        }
    }
    if (count == 0) {
        count++;
    }
    cout << count;

}
