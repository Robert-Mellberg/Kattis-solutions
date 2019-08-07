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

//https://open.kattis.com/problems/compoundwords

//Solve by inserting all strings into a array. Loop through the array twice with two nested for loops.
//Create all possible word combinations in the for loops and add them to a set<string> that will automatically sort and remove duplicates.
int main()
{
    vector<string> words;
    set<string> compoundWords;

    string word;
    while (cin >> word) {
        words.push_back(word);
    }

    for (string word1 : words) {
        for (string word2 : words) {
            if (word1 == word2) {
                continue;
            }
            string compoundWord = word1 + word2;
            compoundWords.insert(compoundWord);
        }
    }

    for (string compoundWord : compoundWords) {
        cout << compoundWord << endl;
    }
    return 0;
}
