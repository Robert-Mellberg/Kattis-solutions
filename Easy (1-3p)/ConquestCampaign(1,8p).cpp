#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

//https://open.kattis.com/problems/conquestcampaign

int row, column, occupied;
bool inrange(int row1, int column1) {
    if (row1 < 0 || column1 < 0 || row1 > row - 1 || column1 > column - 1) {
        return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> row >> column >> occupied;
    int totalAmount = row * column;

    vector<bool> empty(column, false);
    vector<vector<bool>> Map(row, empty);
    vector<pair<int, int>> lastlyOccupied;

    int countOccupied = 0, countDays = 0;
    for (int i = 0; i < occupied; i++) {
        int ro, co;
        cin >> ro >> co;
        lastlyOccupied.push_back(pair<int, int>(ro-1, co-1));
        Map[ro - 1][co - 1] = true;
        countOccupied++;
    }
    
    while (lastlyOccupied.size() != 0) {
        countDays++;
        vector<pair<int, int>> newList;
        for (pair<int, int> pos : lastlyOccupied) {
            if (inrange(pos.first+1, pos.second)) {
                if (!Map[pos.first+1][pos.second]) {
                    Map[pos.first + 1][pos.second] = true;
                    newList.push_back(pair<int, int>(pos.first + 1, pos.second));
                    countOccupied++;
                }
            }

            if (inrange(pos.first - 1, pos.second)) {
                if (!Map[pos.first - 1][pos.second]) {
                    Map[pos.first - 1][pos.second] = true;
                    newList.push_back(pair<int, int>(pos.first - 1, pos.second));
                    countOccupied++;
                }
            }

            if (inrange(pos.first, pos.second - 1)) {
                if (!Map[pos.first][pos.second - 1]) {
                    Map[pos.first][pos.second - 1] = true;
                    newList.push_back(pair<int, int>(pos.first, pos.second - 1));
                    countOccupied++;
                }
            }

            if (inrange(pos.first, pos.second + 1)) {
                if (!Map[pos.first][pos.second + 1]) {
                    Map[pos.first][pos.second + 1] = true;
                    newList.push_back(pair<int, int>(pos.first, pos.second + 1));
                    countOccupied++;
                }
            }
        }
        lastlyOccupied = newList;
    }
    cout << countDays;

    return 0;
}
