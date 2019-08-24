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

//https://open.kattis.com/problems/phonelist

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int antalNummer;
        cin >> antalNummer;
        unordered_set<string> nummer;
        int rest = 0;
        for (int l = 0; l < antalNummer; l++) {
            string number;
            cin >> number;
            nummer.insert(number);
        }
        for (string num : nummer) {
            for (int j = 1; j < num.length(); j++) {
                if (nummer.find(num.substr(0, j)) != nummer.end()) {
                    rest = 1;
                }
            }
        }

        if (rest) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }

    }

    

    return 0;
}
