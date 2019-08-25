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

//https://open.kattis.com/problems/airconditioned

int main()
{
    multimap<int, int> preferenser;
    multimap<int, int> latLista;
    int antalMinion;
    cin >> antalMinion;

    for (int i = 0; i < antalMinion; i++) {
        int min, max;
        cin >> min >> max;
        preferenser.insert(pair<int, int>(max, min));
    }
    int count = 0;
    while (preferenser.size() != 0) {
        latLista.clear();
        int maxRoomValue = preferenser.begin()->first;
        count++;
        for (auto i : preferenser) {
            if (i.second > maxRoomValue) {
                latLista.insert(pair<int, int>(i.first, i.second));
            }
        }
        preferenser = latLista;
    }
    cout << count;
    return 0;
}
