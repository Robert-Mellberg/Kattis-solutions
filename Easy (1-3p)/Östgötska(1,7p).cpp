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

//https://open.kattis.com/problems/ostgotska

//Solve by counting the ae-words with string.find("ae") and the total amount of words.
//Calculate the percentage of ae-words
int main()
{
    int wordCount = 0, aeWordCount = 0;

    string word;
    while (cin >> word) {
        wordCount++;
        if (word.find("ae") != string::npos) {
            aeWordCount++;
        }
    }
    if ((double)aeWordCount / wordCount >= 0.4) {
        cout << "dae ae ju traeligt va";
    }
    else {
        cout << "haer talar vi rikssvenska";
    }
    return 0;
}
