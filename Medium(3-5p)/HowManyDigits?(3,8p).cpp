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

//https://open.kattis.com/problems/howmanydigits


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> antalDigits(1000001, 0);
    antalDigits[0] = 1;
    long double currFactor = 1;
    int lengthFaculty = 0;
    int currLengthNum = 0;
    for (int i = 1; i <= 1000000; i++) {

        if (i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000) {
            currLengthNum++;
        }
        long double shortFactor = (long double)i / (pow(10, currLengthNum));
        currFactor *= shortFactor;
        lengthFaculty += currLengthNum;

        if (currFactor > 10) {
            currFactor /= 10;
            lengthFaculty++;
        }
        antalDigits[i] = lengthFaculty + 1;
    }
    int num;
    while (cin >> num) {
        cout << antalDigits[num] << endl;
    }
    return 0;
}
