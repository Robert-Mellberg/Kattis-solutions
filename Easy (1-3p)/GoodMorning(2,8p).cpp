#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <algorithm>
using namespace std;

//https://open.kattis.com/problems/goodmorning

vector<int> allNumbers;
void getAllNumbers(int total) {
    if (total >= 100) {
        return;
    }
    int ental = total % 10;
    total *= 10;
    if (ental == 0) {
        allNumbers.push_back(total);
        getAllNumbers(total);
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (i >= ental && (i - 1) % 3 >= (ental - 1) % 3) {
            allNumbers.push_back(total+i);
            getAllNumbers(total + i);
        }
    }
    if (ental != 3 && ental != 6 && ental != 9) {
        allNumbers.push_back(total);
        getAllNumbers(total);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i <= 9; i++) {
        getAllNumbers(i);
        allNumbers.push_back(i);
    }
    sort(allNumbers.begin(), allNumbers.end());

    int Cases;
    cin >> Cases;
    for (int l = 0; l < Cases; l++) {
        int num;
        cin >> num;
        int closestNum = 1000;
        for (int i : allNumbers) {
            if (abs(i - num) <= abs(num - closestNum)) {
                closestNum = i;
            }
            else {
                break;
            }
        }
        cout << closestNum << endl;

    }



    return 0;
}
