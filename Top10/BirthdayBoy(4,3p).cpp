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

//https://open.kattis.com/problems/birthdayboy

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> daysMonth = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
    vector<int> knownBirthDays;

    int antal;
    cin >> antal;

    for (int i = 0; i < antal; i++) {
        string trash1;
        cin >> trash1;
        int manad, dag;
        char trash;
        cin >> manad >> trash >> dag;
        int antal = dag + daysMonth[manad];
        knownBirthDays.push_back(antal);
    }
    sort(knownBirthDays.begin(), knownBirthDays.end());

    int maxDifference = 0, daysAfterOct27 = 1000;
    for (int i = 1; i < knownBirthDays.size(); i++) {
        if (knownBirthDays[i] - knownBirthDays[i - 1] > maxDifference) {
            if (knownBirthDays[i] > 300+1) {
                daysAfterOct27 = knownBirthDays[i] - 300;
            }
            else {
                daysAfterOct27 = knownBirthDays[i] + 365 - 300;
            }
            maxDifference = knownBirthDays[i] - knownBirthDays[i - 1];
        }
        else if (knownBirthDays[i] - knownBirthDays[i - 1] == maxDifference) {
            int daysAfter;
            if (knownBirthDays[i] > 300+1) {
                daysAfter = knownBirthDays[i] - 300;
            }
            else {
                daysAfter = knownBirthDays[i] + 365 - 300;
            }
            if (daysAfter < daysAfterOct27) {
                daysAfterOct27 = daysAfter;
                maxDifference = knownBirthDays[i] - knownBirthDays[i - 1];
            }
        }
    }

    if (knownBirthDays[0] - knownBirthDays[knownBirthDays.size() - 1] + 365 > maxDifference) {
        if (knownBirthDays[0] > 300+1) {
            daysAfterOct27 = knownBirthDays[0] - 300;
        }
        else {
            daysAfterOct27 = knownBirthDays[0] + 365 - 300;
        }
        maxDifference = knownBirthDays[0] - knownBirthDays[knownBirthDays.size() - 1] + 365;
    }
    else if (knownBirthDays[0] - knownBirthDays[knownBirthDays.size() - 1] + 365 == maxDifference) {
        int daysAfter;
        if (knownBirthDays[0] > 300+1) {
            daysAfter = knownBirthDays[0] - 300;
        }
        else {
            daysAfter = knownBirthDays[0] + 365 - 300;
        }
        if (daysAfter < daysAfterOct27) {
            daysAfterOct27 = daysAfter;
            maxDifference = knownBirthDays[0] - knownBirthDays[knownBirthDays.size() - 1] + 365;
        }
    }
    

    int day = (300 + daysAfterOct27-1) % 365;
    if (day == 0) {
        cout << "12-31";
        return 0;
    }
    for (int man = 12; man > 0; man--) {
        if (day > daysMonth[man]) {
            day -= daysMonth[man];
            if (day == 0) {
                day = daysMonth[man] - daysMonth[man - 1];
                man--;
            }
            if (man < 10) {
                cout << "0";
            }
            cout << man << "-";
            if (day < 10) {
                cout << "0";
            }
            cout << day;
            return 0;
        }
    }
    return 0;
}
