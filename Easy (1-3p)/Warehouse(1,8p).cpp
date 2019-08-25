#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <sstream>
using namespace std;

//https://open.kattis.com/problems/warehouse

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int antalVaror;
        cin >> antalVaror;
        map<string, int> provLista;
        map<int, set<string>> lista;
        for (int j = 0; j < antalVaror; j++) {
            string namn;
            int varde;
            cin >> namn >> varde;
            provLista[namn] += varde;
        }
        cout << provLista.size() << endl;
        for (auto l : provLista) {
            lista[-l.second].insert(l.first);
        }
        for (auto i : lista) {
            for (string namn : i.second) {
                cout << namn << " " << -i.first << endl;
            }
        }
    }

    return 0;
}
