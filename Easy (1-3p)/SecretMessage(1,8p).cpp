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

//https://open.kattis.com/problems/secretmessage

int main()
{
    int cases;
    cin >> cases;
    for (int p = 0; p < cases; p++) {

        string word;
        cin >> word;
        int num, square;
        for (int i = 0; i < 102; i++) {
            num = i;
            square = i * i;
            if (square >= word.length()) {
                break;
            }
        }
        for (int l = 0; l < square - word.length(); l++) {
            word += '*';
        }

        for (int minus = num; minus >= 1; minus--) {
            for (int i = square - minus; i >= 0; i -= num) {
                if (word[i] != '*')
                    cout << word[i];
            }
        }
        cout << endl;
    }
    return 0;
}
