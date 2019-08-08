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
#include <queue>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/rats

//The hardest part of the problem is to decide how to store the numbers since they won't fit in a double.
//I stored it in a vector of size 10 where int[n] denotes how many digits of n the numbers contains.

//sum calculates according to the RATS function.
//after each calculation, check if the result is already in a set, if so it has repeated, otherwise insert it. 


//The sum function works by adding each digit from the number with the corresponding digit from the reversed number from right to left.
vector<int> sum(vector<int> num) {
    vector<int> result(10, 0);

    //lowNum is the current digit of the reversed number
    int lowNum = 1;
    //highNum is the current digit of the number
    int highNum = 9;
    //lowInd is the index of the digit of the reversed number, the index starts at 1 for each digit
    int lowInd = 1;
    //highInd is the index of the digit of the number, the index starts at 1 for each digit
    int highInd = 1;

    int rest = 0;
    while (lowNum != 10) {
        //all digits of lowNum has already been added, reset index and increase lowNum to the next digit
        if (lowInd > num[lowNum]) {
            lowInd = 1;
            lowNum++;
            continue;
        }
        //all digits of highNum has already been added, reset index and increase highNum to the next digit
        if (highInd > num[highNum]) {
            highInd = 1;
            highNum--;
            continue;
        }
        int sum = highNum + lowNum+rest;
        result[sum % 10]++;
        rest = sum / 10;

        lowInd++;
        highInd++;
    }
    result[rest]++;
    return result;
}

string calcValue(vector<int> num) {
    string total = "";
    for (int i = 1; i <= 9; i++) {
        total += (num[i]+'0');
        total += ',';
    }
    return total;
}
bool is12334444(vector<int> num) {
    for (int i = 5; i <= 9; i++) {
        if (num[i] != 0) {
            return false;
        }
    }
    if (num[1] == 1 && num[2] == 1 && num[3] >= 2 && num[4] == 4) {
        return true;
    }
    return false;
}
bool is55667777(vector<int> num) {
    for (int i = 8; i <= 9; i++) {
        if (num[i] != 0) {
            return false;
        }
    }
    for (int i = 1; i <= 4; i++) {
        if (num[i] != 0) {
            return false;
        }
    }
    if (num[5] == 2 && num[6] >= 2 && num[7] == 4) {
        return true;
    }
    return false;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        int casenum;
        cin >> casenum;
        cout << casenum << " ";

        int antal;
        cin >> antal;
        string num;
        vector<int> numArr(10, 0);
        cin >> num;

        for (char c : num) {
            numArr[c - '0']++;
        }

        unordered_set<string> prev;
        bool brek = false;
        for (int ind = 1; ind < antal; ind++) {
            string totNum = calcValue(numArr);
            if (prev.find(totNum) != prev.end()) {
                cout << "R " << ind << "\n";
                brek = true;
                break;
            }
            prev.insert(totNum);

            if (is12334444(numArr) || is55667777(numArr)) {
                cout << "C " << ind << "\n";
                brek = true;
                break;
            }

            numArr = sum(numArr);
        }
        if (brek) {
            continue;
        }
        string totNum = calcValue(numArr);
        if (prev.find(totNum) != prev.end()) {
            cout << "R " << antal << "\n";
            continue;
        }
        if (is12334444(numArr) || is55667777(numArr)) {
            cout << "C " << antal << "\n";
            continue;
        }
        for (int i = 1; i < 10; i++) {
            for (int l = 0; l < numArr[i]; l++) {
                cout << i;
            }
        }
        cout << "\n";

    }
    return 0;
}
