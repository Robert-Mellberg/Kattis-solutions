#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/rollcall

int main()
{
    multimap<string, string> namnLista;
    set<string> forstaGang;
    set<string> andraGang;
    string forNamn;
    string efterNamn;
    while (cin >> forNamn >> efterNamn) {
        namnLista.insert(pair<string, string>(efterNamn + " " + forNamn, forNamn));
        if (forstaGang.find(forNamn) == forstaGang.end()) {
            forstaGang.insert(forNamn);
        }
        else {
            andraGang.insert(forNamn);
        }
    }
    for (auto i : namnLista) {
        if (andraGang.find(i.second) == andraGang.end()) {
            cout << i.second << endl;
        }
        else {
            stringstream ss(i.first);
            string efternamn, fornamn;
            ss >> efternamn >> fornamn;
            cout << fornamn << " " << efternamn << endl;;
        }
    }
    return 0;
}
