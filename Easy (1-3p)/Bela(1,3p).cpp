#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
#include <random>
using namespace std;

//https://open.kattis.com/problems/bela

int main()
{
    int antalHand;
    cin >> antalHand;
    char suit;
    cin >> suit;

    int total = 0;
    for (int i = 0; i < antalHand * 4; i++) {
        string ord;
        cin >> ord;
        switch(ord[0]) {
        case 'A':
            total += 11;
            break;
        case '9':
            if (ord[1] == suit) {
                total += 14;
            }
            break;
        case 'K':
            total += 4;
            break;
        case 'Q':
            total += 3;
            break;
        case 'J':
            if (ord[1] == suit) {
                total += 20;
            }
            else
                total += 2;
            break;
        case 'T':
            total += 10;
            break;
        }
    }
    cout << total;

}
