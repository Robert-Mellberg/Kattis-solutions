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

//https://open.kattis.com/problems/encodedmessage

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int cases;
    cin >> cases;
    for (int p = 0; p < cases; p++) {

        string word;
        cin >> word;
        int lengthSide = sqrt(word.length());

        string decodedWord = "";
        for (int i = lengthSide - 1; i >= 0; i--) {
            for (int j = 0; j < lengthSide; j++) {
                decodedWord += word[i + j * lengthSide];
            }
        }
        cout << decodedWord << endl;
    }

    return 0;
}
