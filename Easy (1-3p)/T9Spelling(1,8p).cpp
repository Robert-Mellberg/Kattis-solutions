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
using namespace std;


//https://open.kattis.com/problems/t9spelling


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    unordered_map<char, string> lista;
    lista['a'] = "2";
    lista['b'] = "22";
    lista['c'] = "222";
    lista['d'] = "3";
    lista['e'] = "33";
    lista['f'] = "333";
    lista['g'] = "4";
    lista['h'] = "44";
    lista['i'] = "444";
    lista['j'] = "5";
    lista['k'] = "55";
    lista['l'] = "555";
    lista['m'] = "6";
    lista['n'] = "66";
    lista['o'] = "666";
    lista['p'] = "7";
    lista['q'] = "77";
    lista['r'] = "777";
    lista['s'] = "7777";
    lista['t'] = "8";
    lista['u'] = "88";
    lista['v'] = "888";
    lista['w'] = "9";
    lista['x'] = "99";
    lista['y'] = "999";
    lista['z'] = "9999";
    lista[' '] = "0";

    int cases;
    cin >> cases;
    cin.ignore();
    for (int i = 1; i <= cases; i++) {
        string input;
        getline(cin, input);
        cout << "Case #" << i << ": ";
        string lastSeq = "A random message";
        for (char c : input) {
            string seq = lista[c];
            if (seq[0] == lastSeq[0]) {
                cout << " ";
            }
            cout << seq;
            lastSeq = seq;
        }
        cout << "\n";
    }
    return 0;
}
