#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <algorithm>
using namespace std;

//https://open.kattis.com/problems/sortofsorting

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int antal;
    cin >> antal;
    while (antal != 0) {
        map<string, vector<string>> namnLista;
        for (int i = 0; i < antal; i++) {
            string namn;
            cin >> namn;
            string kort = "";
            kort += namn[0];
            kort += namn[1];
            namnLista[kort].push_back(namn);
        }
        for (auto i : namnLista) {
            for (string namn : i.second) {
                cout << namn << endl;
            }
        }
        cout << endl;

        cin >> antal;
    }
    return 0;
}
