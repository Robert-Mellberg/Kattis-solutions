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

//https://open.kattis.com/problems/iforaneye

string getLowered(string a) {
    string ny = "";
    for (char c : a) {
        if (int(c) >= 65 && int(c) <= 90) {
            ny += (char)((int)c + 32);
        }
        else{
            ny += c;
        }
    }
    return ny;
}

char getChar(string subst, unordered_map<string, char> &umap) {
    char c = umap[getLowered(subst)];
    if ((int)c >= 97 && (int)c <= 122 && subst[0] >= 65 && subst[0] <= 90) {
        c = char((int)c - 32);
    }
    return c;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    unordered_map<string, char> wordToAbbreviation;
    wordToAbbreviation["at"] = '@';
    wordToAbbreviation["and"] = '&';
    wordToAbbreviation["one"] = '1';
    wordToAbbreviation["won"] = '1';
    wordToAbbreviation["two"] = '2';
    wordToAbbreviation["to"] = '2';
    wordToAbbreviation["too"] = '2';
    wordToAbbreviation["for"] = '4';
    wordToAbbreviation["four"] = '4';
    wordToAbbreviation["be"] = 'b';
    wordToAbbreviation["bee"] = 'b';
    wordToAbbreviation["bea"] = 'b';
    wordToAbbreviation["see"] = 'c';
    wordToAbbreviation["sea"] = 'c';
    wordToAbbreviation["eye"] = 'i';
    wordToAbbreviation["oh"] = 'o';
    wordToAbbreviation["owe"] = 'o';
    wordToAbbreviation["are"] = 'r';
    wordToAbbreviation["you"] = 'u';
    wordToAbbreviation["why"] = 'y';



    int cases;
    cin >> cases;
    cin.ignore();
    for (int i = 0; i < cases; i++) {
        string line;
        getline(cin, line);
        string total = "";

        int index = 0;
        while (index < line.length()) {
            if (index + 4 <= line.length()) {
                string subst = line.substr(index, 4);
                if (wordToAbbreviation.find(getLowered(subst)) != wordToAbbreviation.end()) {
                    total += getChar(subst, wordToAbbreviation);
                    index += 4;
                    continue;
                }
            }
            if (index + 3 <= line.length()) {
                string subst = line.substr(index, 3);
                if (wordToAbbreviation.find(getLowered(subst)) != wordToAbbreviation.end()) {
                    total += getChar(subst, wordToAbbreviation);
                    index += 3;
                    continue;
                }
            }
            if (index + 2 <= line.length()) {
                string subst = line.substr(index, 2);
                if (wordToAbbreviation.find(getLowered(subst)) != wordToAbbreviation.end()) {
                    total += getChar(subst, wordToAbbreviation);
                    index += 2;
                    continue;
                }
            }


            total += line[index];
            index++;
        }
        cout << total << endl;
    }
    return 0;
}
