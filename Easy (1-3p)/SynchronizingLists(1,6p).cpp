#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

//https://open.kattis.com/problems/synchronizinglists


vector<vector<int>> map;
int sokTyp;

int main()
{
    int storlek;
    cin >> storlek;
    while (storlek != 0) {
    
        vector<int> lista1;
        vector<int> lista2;
        for (int i = 0; i < storlek; i++) {
            int read;
            cin >> read;
            lista1.push_back(read);
        }
        for (int j = 0; j < storlek; j++) {
            int read;
            cin >> read;
            lista2.push_back(read);
        }
        unordered_map<int, int> map;
        vector<int> lista1Sort = lista1;
        sort(lista1Sort.begin(), lista1Sort.end());
        sort(lista2.begin(), lista2.end());

        for (int l = 0; l < lista1Sort.size(); l++) {
            map[lista1Sort[l]] = lista2[l];
        }
        for (int i : lista1) {
            int k = map[i];
            cout << k << endl;
        }
        

        cin >> storlek;
        if (storlek != 0) {
            cout << endl;
        }
        
    }

    return 0;
}
