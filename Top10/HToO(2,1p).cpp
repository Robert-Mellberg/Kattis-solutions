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

//https://open.kattis.com/problems/htoo


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    unordered_map<char, int> ingredientsAvail;
    unordered_map<char, int> ingredientsNeed;

    string molecule;
    cin >> molecule;

    int antal = 0;
    char lastChar = molecule[0];
    for (int i = 1; i < molecule.length(); i++) {
        char c = molecule[i];
        if (int(c) >= 65) {
            if (antal == 0) {
                ingredientsAvail[lastChar]++;
            }
            else {
                ingredientsAvail[lastChar] += antal;
            }
            lastChar = c;
            antal = 0;
        }
        else {
            antal *= 10;
            antal += c - '0';
        }
    }
    if (antal == 0) {
        ingredientsAvail[lastChar]++;
    }
    else {
        ingredientsAvail[lastChar] += antal;
    }
    int antalMolecules;
    cin >> antalMolecules;

    string molecule1;
    cin >> molecule1;

    antal = 0;
    lastChar = molecule1[0];
    for (int i = 1; i < molecule1.length(); i++) {
        char c = molecule1[i];
        if (int(c) >= 65) {
            if (antal == 0) {
                ingredientsNeed[lastChar]++;
            }
            else {
                ingredientsNeed[lastChar] += antal;
            }
            lastChar = c;
            antal = 0;
        }
        else {
            antal *= 10;
            antal += c - '0';
        }
    }
    if (antal == 0) {
        ingredientsNeed[lastChar]++;
    }
    else {
        ingredientsNeed[lastChar] += antal;
    }

    int minAntal = 1000000000;
    for (auto ingred : ingredientsNeed) {
        int hogstaMojliga = (ingredientsAvail[ingred.first]*antalMolecules) / ingred.second;
        minAntal = min(minAntal, hogstaMojliga);
    }
    cout << minAntal;

    return 0;
}
