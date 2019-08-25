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

//https://open.kattis.com/problems/friday

int main()
{
    int antalTest;
    cin >> antalTest;
    for (int i = 0; i < antalTest; i++) {
        int antalManader;
        cin >> antalManader >> antalManader;
        int count = 0;
        int dag = 0;
        for (int k = 0; k < antalManader; k++) {
            int antalDagar;
            cin >> antalDagar;
            if (dag == 0 && antalDagar >= 13) {
                count++;
            }
            dag = (dag + antalDagar) % 7;
        }
        cout << count << endl;
    }
}
