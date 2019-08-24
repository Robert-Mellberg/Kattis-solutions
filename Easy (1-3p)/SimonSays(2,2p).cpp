#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

//https://open.kattis.com/problems/simon

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    cin.ignore();
    for (int i = 0; i < cases; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string word;
        ss >> word;
        if (word == "simon") {
            if (ss >> word && word == "says") {
                if (ss >> word) {
                    cout << word;
                    while (ss >> word) {
                        cout << " " << word;
                    }
                }
            }
        }
        cout << endl;
    }


    return 0;
}
