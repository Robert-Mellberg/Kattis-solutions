#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
#include <random>
using namespace std;

//https://open.kattis.com/problems/hidingplaces

vector<vector<int>> brada;
int maxHopp = 0;

bool inrange(int x, int y) {
    if (y > 7 || y < 0 || x > 7 || x < 0) {
        return false;
    }
    return true;
}

void hoppa(vector<int> allaX, vector<int> allaY, int antalHopp) {
    maxHopp = max(antalHopp, maxHopp);
    vector<int> allaXHoppPlusEtt;
    vector<int> allaYHoppPlusEtt;
    for (int j = 0; j < allaX.size(); j++) {

        int nyX, nyY;
        int x = allaX[j];
        int y = allaY[j];
        nyX = x + 2;
        nyY = y + 1;
        if (inrange(nyX, nyY)) {
            if (brada[nyX][nyY] > antalHopp + 1) {
                brada[nyX][nyY] = antalHopp+1;
                allaXHoppPlusEtt.push_back(nyX);
                allaYHoppPlusEtt.push_back(nyY);
            }
        }

        nyX = x + 2;
        nyY = y - 1;
        if (inrange(nyX, nyY)) {
            if (brada[nyX][nyY] > antalHopp + 1) {
                brada[nyX][nyY] = antalHopp + 1;
                allaXHoppPlusEtt.push_back(nyX);
                allaYHoppPlusEtt.push_back(nyY);
            }
        }

        nyX = x - 2;
        nyY = y + 1;
        if (inrange(nyX, nyY)) {
            if (brada[nyX][nyY] > antalHopp + 1) {
                brada[nyX][nyY] = antalHopp + 1;
                allaXHoppPlusEtt.push_back(nyX);
                allaYHoppPlusEtt.push_back(nyY);
            }
        }

        nyX = x - 2;
        nyY = y - 1;
        if (inrange(nyX, nyY)) {
            if (brada[nyX][nyY] > antalHopp + 1) {
                brada[nyX][nyY] = antalHopp + 1;
                allaXHoppPlusEtt.push_back(nyX);
                allaYHoppPlusEtt.push_back(nyY);
            }
        }

        nyX = x - 1;
        nyY = y + 2;
        if (inrange(nyX, nyY)) {
            if (brada[nyX][nyY] > antalHopp + 1) {
                brada[nyX][nyY] = antalHopp + 1;
                allaXHoppPlusEtt.push_back(nyX);
                allaYHoppPlusEtt.push_back(nyY);
            }
        }

        nyX = x + 1;
        nyY = y + 2;
        if (inrange(nyX, nyY)) {
            if (brada[nyX][nyY] > antalHopp + 1) {
                brada[nyX][nyY] = antalHopp + 1;
                allaXHoppPlusEtt.push_back(nyX);
                allaYHoppPlusEtt.push_back(nyY);
            }
        }

        nyX = x - 1;
        nyY = y - 2;
        if (inrange(nyX, nyY)) {
            if (brada[nyX][nyY] > antalHopp + 1) {
                brada[nyX][nyY] = antalHopp + 1;
                allaXHoppPlusEtt.push_back(nyX);
                allaYHoppPlusEtt.push_back(nyY);
            }
        }

        nyX = x + 1;
        nyY = y - 2;
        if (inrange(nyX, nyY)) {
            if (brada[nyX][nyY] > antalHopp + 1) {
                brada[nyX][nyY] = antalHopp + 1;
                allaXHoppPlusEtt.push_back(nyX);
                allaYHoppPlusEtt.push_back(nyY);
            }
        }
    }
    if (antalHopp == 7)
    {
        return;
    }

    if(allaXHoppPlusEtt.size() != 0)
    hoppa(allaXHoppPlusEtt, allaYHoppPlusEtt, antalHopp+1);
}

int main()
{
    int antalCases;
    cin >> antalCases;
    for (int i = 0; i < antalCases; i++) {
        set<char> tomtset;
        vector<set<char>> results(8, tomtset);

        maxHopp = 0;
        vector<int> tom(8, 1000);
        vector<vector<int>> ny(8, tom);
        brada = ny;
        string read;
        cin >> read;
        int x = (int)read[0]-97;
        int y = (int)read[1] - 49;
        brada[x][y] = 0;
        hoppa({ x }, {y}, 0);
        cout << maxHopp;
        for (int xx = 0; xx < 8; xx++) {
            for (int yy = 0; yy < 8; yy++) {
                if (brada[xx][yy] == maxHopp) {
                    results[yy].insert((char)(xx + 97));
                }
            }
        }
        for (int i = 7; i >= 0; i--) {
            for (char c : results[i]) {
                cout << " " << c << i + 1;
            }
        }
        cout << endl;
    }
}
