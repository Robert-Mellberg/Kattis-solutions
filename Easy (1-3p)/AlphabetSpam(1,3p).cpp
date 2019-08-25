#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

//https://open.kattis.com/problems/alphabetspam

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    double antalLower = 0, antalUpper = 0, antalUnderScore = 0, antalSymbols = 0;
    for (int i = 0; i < input.size(); i++) {
        int value = (int)input[i];
        if (value == 95) {
            antalUnderScore++;
        }
        else if (value >= 65 && value <= 90) {
            antalUpper++;
        }
        else if (value >= 97 && value <= 122) {
            antalLower++;
        }
        else {
            antalSymbols++;
        }
    }
    cout << setprecision(10) <<  antalUnderScore/input.length() << endl << antalLower / input.length() << endl << antalUpper / input.length() << endl << antalSymbols / input.length();
    return 0;
}
