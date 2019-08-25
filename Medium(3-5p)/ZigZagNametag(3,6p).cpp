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
#include <stack>
using namespace std;

//https://open.kattis.com/problems/zigzag

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string word = "";
    int wordValue;
    cin >> wordValue;
    word += "a";
    if (wordValue <= 50) {
        if (wordValue <= 25) {
            word += (char)(97 + wordValue);
        }
        else {
            word += (char)(97 + ceil((double)wordValue / 2));
            if (wordValue % 2 == 0) {
                word += "a";
            }
            else {
                word += "b";
            }
        }
    }
    else {
        if (wordValue % 50 > 25 || wordValue % 50 == 0) {
            int difference = ceil((double)(wordValue % 50) / 2);
            if (difference != 0) {
                word += (char)(97 + difference);
                word += "a";
            }
            for (int az = 0; az < (wordValue / 50) - 1; az++) {
                word += "za";
            }
            if (wordValue % 2 == 0) {
                word += "za";
            }
            else {
                word += "zb";
            }
        }
        else {
            if ((wordValue % 50) != 0)
            {
                word += (char)(97 + ceil((double)((wordValue % 50) + 25) / 2));
                word += "a";
            }
            for (int az = 0; az < (wordValue / 50) - 1; az++) {
                word += "za";
            }
            if (wordValue % 2 == 1) {
                word += "z";
            }
            else {
                word += "y";
            }

        }
    }
    int test = 0;
    for (int i = 0; i < word.size() - 1; i++) {
        test += abs(word[i] - word[i + 1]);
        if (word[i] == word[i + 1]) {
            cout << "error " << wordValue;
        }
    }
    if (wordValue != test) {
        cout << "error " << wordValue;
    }
    cout << word << " " << endl;
    return 0;
}
