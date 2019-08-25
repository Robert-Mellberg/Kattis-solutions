#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
using namespace std;

//https://open.kattis.com/problems/haiku

bool calculateValue(vector<vector<int>> &ordLangder, int antalSyllables, int index, int total) {
    vector<int> &currentList = ordLangder[index];
    if (index == ordLangder.size() - 1) {
        for (int i = 0; i < currentList.size(); i++) {
            int total1 = total + currentList[i];
            if (total1 > antalSyllables) {
                continue;
            }
            if (total1 == antalSyllables)
                return true;
        }
        return false;
    }
    else {
        for (int i = 0; i < currentList.size(); i++) {
            int total1 = total + currentList[i];
            if (total1 > antalSyllables) {
                continue;
            }
            if (calculateValue(ordLangder, antalSyllables, index + 1, total1))
                return true;
        }
        return false;
    }
}

vector<string> syllables;
bool wordWithXSyllables(int sizeWord, string total, string comparison, int level) {
    if (sizeWord != level) {
        for (int i = 0; i < syllables.size(); i++) {
            string total1 = total + syllables[i];
            if (total1.length() >= comparison.length()) {
                continue;
            }
            if (total1 != comparison.substr(0, total1.length())) {
                continue;
            }
            if (wordWithXSyllables(sizeWord, total1, comparison, level + 1))
                return true;
        }
        return false;
    }
    else {
        for (int i = 0; i < syllables.size(); i++) {
            string total1 = total + syllables[i];
            if (total1 == comparison)
                return true;
        }
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int antalOrd;
    cin >> antalOrd;
    for (int j = 0; j < antalOrd; j++) {
        string ord;
        cin >> ord;
        syllables.push_back(ord);
    }
    vector<vector<int>> ordLangder;
    cin.ignore();

    string ord;
    string mening;
    getline(cin, mening);
    stringstream ss(mening);
    while (ss >> ord) {
        vector<int> ordLangd;
        for (int i = 1; i <= 5; i++) {
            if (wordWithXSyllables(i, "", ord, 1)) {
                ordLangd.push_back(i);
            }
        }
        ordLangder.push_back(ordLangd);
    }
    if (!calculateValue(ordLangder, 5, 0, 0)) {
        cout << "come back next year" << endl;
        return 0;
    }

    ordLangder.clear();
    getline(cin, mening);
    stringstream sss(mening);
    while (sss >> ord) {
        vector<int> ordLangd;
        for (int i = 1; i <= 7; i++) {
            if (wordWithXSyllables(i, "", ord, 1)) {
                ordLangd.push_back(i);
            }
        }
        ordLangder.push_back(ordLangd);
    }
    if (!calculateValue(ordLangder, 7, 0, 0)) {
        cout << "come back next year" << endl;
        return 0;
    }

    ordLangder.clear();
    getline(cin, mening);
    stringstream ssss(mening);
    while (ssss >> ord) {
        vector<int> ordLangd;
        for (int i = 1; i <= 5; i++) {
            if (wordWithXSyllables(i, "", ord, 1)) {
                ordLangd.push_back(i);
            }
        }
        ordLangder.push_back(ordLangd);
    }
    if (!calculateValue(ordLangder, 5, 0, 0)) {
        cout << "come back next year" << endl;
        return 0;
    }
    cout << "haiku";
    return 0;
}
