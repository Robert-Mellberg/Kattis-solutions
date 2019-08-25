#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

//https://open.kattis.com/problems/busnumbers


vector<vector<int>> map;
int sokTyp;

int main()
{
    set<int> bussNummer;
    int antal;
    cin >> antal;
    for (int j = 0; j < antal; j++) {
        int nummer;
        cin >> nummer;
        bussNummer.insert(nummer);
    }
    vector<vector<int>> list;
    int gammal = -5;
    for (int i : bussNummer) {
        if (i - gammal == 1) {
            list[list.size() - 1].push_back(i);
        }
        else
        {
            vector<int> vekt;
            vekt.push_back(i);
            list.push_back(vekt);
        }
        gammal = i;
    }
    
    for (vector<int> lista : list) {
        if (lista.size() == 1) {
            cout << lista[0] << " ";
        }
        else if (lista.size() == 2) {
            cout << lista[0] << " " << lista[1] << " ";
        }
        else {
            cout << lista[0] << "-" << lista[lista.size() - 1] << " ";
        }
    }
    return 0;
    //int antalRad;
    //int antalKolumn;
    //cin >> antalRad >> antalKolumn;

    //for (int j = 0; j < antalRad; j++) {
    //  vector<int> rad;
    //  for (int k = 0; k < antalKolumn; k++) {
    //      int num;
    //      cin >> num;
    //      rad.push_back(num);
    //  }
    //  map.push_back(rad);
    //}

    return 0;
}
