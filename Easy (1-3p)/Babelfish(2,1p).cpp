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

//https://open.kattis.com/problems/babelfish

int main()
{
    unordered_map<string, string> dictionary;
    string translation;

    while (getline(cin, translation)) {
        if (translation == "") {
            break;
        }
        stringstream ss(translation);
        string engWord, weirdWord;
        ss >> engWord >> weirdWord;
        dictionary[weirdWord] = engWord;
    }
    string weirdWord;
    while (getline(cin, weirdWord)) {
        //not in list
        if (dictionary.find(weirdWord) == dictionary.end()) {
            cout << "eh" << endl;
        }
        else {
            cout << dictionary[weirdWord] << endl;
        }
    }
    return 0;
}
