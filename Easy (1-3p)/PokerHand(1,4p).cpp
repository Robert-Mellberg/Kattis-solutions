#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/pokerhand

int main()
{
    map<char, int> lista;
    int max = 0;
    for (int i = 0; i < 5; i++) {
        string input;
        cin >> input;
        lista[input[0]]++;
        if (lista[input[0]] > max) {
            max = lista[input[0]];
        }
    }
    cout << max;
    return 0;
}
