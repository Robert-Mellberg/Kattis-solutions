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

//https://open.kattis.com/problems/kemija08

int main()
{
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    string input;
    getline(cin, input);
    int index = 0;
    while (index < input.length()) {
        cout << input[index];
        //if vowel, skip next two letters.
        if (vowels.find(input[index]) != vowels.end()) {
            index += 3;
        }
        else {
            index++;
        }
    }
    return 0;
}
