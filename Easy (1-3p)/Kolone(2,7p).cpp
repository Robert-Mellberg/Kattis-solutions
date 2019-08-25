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

//https://open.kattis.com/problems/kolone

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int sizeRow1, sizeRow2;
    cin >> sizeRow1 >> sizeRow2;
    int positionRow1 = 0;
    int positionRow2 = sizeRow1 * 2 - 1;
    string row1, row2;
    int forskjutning;
    cin >> row1 >> row2 >> forskjutning;
    positionRow1 = forskjutning;
    positionRow2 -= forskjutning;
    map<int, char> lista;
    for (int i = 0; i < sizeRow1; i++) {
        lista[positionRow1 + 2 * i] = row1[row1.size()-1-i];
    }
    for (int i = 0; i < sizeRow2; i++) {
        lista[positionRow2 + 2 * i] = row2[i];
    }
    for (auto i : lista) {
        cout << i.second;
    }

    return 0;
}
