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
#include <stack>
using namespace std;

//https://open.kattis.com/problems/checkers

int sizeMap;

bool inRange(int y, int x) {
    return y >= 0 && x >= 0 && y < sizeMap && x < sizeMap;
}

bool checkBlackHorse(int y, int x, vector<vector<bool>> &whiteMap, vector<vector<bool>> &blackMap) {
    vector<bool> falsk(sizeMap, false);
    vector<vector<bool>> whiteMapVisited(sizeMap, falsk);
    stack<pair<int, int>> unCheckedNodes;
    vector<pair<int, int>> checkedNodes;
    unCheckedNodes.push(pair<int, int>(y, x));

    vector<int> noll(sizeMap, 0);
    vector<vector<int>> nodDegree(sizeMap, noll);
    while (!unCheckedNodes.empty()) {
        pair<int, int> position = unCheckedNodes.top();
        unCheckedNodes.pop();
        checkedNodes.push_back(position);
        int degree = 0;

        int nyY = position.first+2;
        int nyX = position.second+2;
        if (inRange(nyY, nyX) && whiteMap[nyY-1][nyX-1]) {
            if (!whiteMap[nyY][nyX]) {
                degree++;
                whiteMapVisited[nyY - 1][nyX - 1] = true;
                if (nodDegree[nyY][nyX] == 0) {
                    unCheckedNodes.push(pair<int, int>(nyY, nyX));
                    if (blackMap[nyY][nyX]) {
                        return 0;
                    }
                }

            }
            else {
                return 0;
            }
        }


        nyY = position.first - 2;
        nyX = position.second + 2;
        if (inRange(nyY, nyX) && whiteMap[nyY + 1][nyX - 1]) {
            if (!whiteMap[nyY][nyX]) {
                degree++;
                whiteMapVisited[nyY + 1][nyX - 1] = true;
                if (nodDegree[nyY][nyX] == 0) {
                    unCheckedNodes.push(pair<int, int>(nyY, nyX));
                    if (blackMap[nyY][nyX]) {
                        return 0;
                    }
                }

            }
            else {
                return 0;
            }
        }


        nyY = position.first - 2;
        nyX = position.second - 2;
        if (inRange(nyY, nyX) && whiteMap[nyY + 1][nyX + 1]) {
            if (!whiteMap[nyY][nyX]) {
                degree++;
                whiteMapVisited[nyY + 1][nyX + 1] = true;
                if (nodDegree[nyY][nyX] == 0) {
                    unCheckedNodes.push(pair<int, int>(nyY, nyX));
                    if (blackMap[nyY][nyX]) {
                        return 0;
                    }
                }

            }
            else {
                return 0;
            }
        }


        nyY = position.first + 2;
        nyX = position.second - 2;
        if (inRange(nyY, nyX) && whiteMap[nyY - 1][nyX + 1]) {
            if (!whiteMap[nyY][nyX]) {
                degree++;
                whiteMapVisited[nyY - 1][nyX + 1] = true;
                if (nodDegree[nyY][nyX] == 0) {
                    unCheckedNodes.push(pair<int, int>(nyY, nyX));
                    if (blackMap[nyY][nyX]) {
                        return 0;
                    }
                }

            }
            else {
                return 0;
            }
        }

        nodDegree[position.first][position.second] = degree;
    }


    for (int y = 0; y < sizeMap; y++) {
        for (int x = 0; x < sizeMap; x++) {
            if (whiteMap[y][x] != whiteMapVisited[y][x]) {
                return 0;
            }
        }
    }
    if (nodDegree[y][x] % 2 == 0) {
        for (int y = 0; y < sizeMap; y++) {
            for (int x = 0; x < sizeMap; x++) {
                if (nodDegree[y][x]%2 != 0) {
                    return 0;
                }
            }
        }
    }
    else {
        int ojamnCount = 0;
        for (int y = 0; y < sizeMap; y++) {
            for (int x = 0; x < sizeMap; x++) {
                if (nodDegree[y][x] % 2 != 0) {
                    ojamnCount++;
                    if (ojamnCount == 3) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> sizeMap;
    vector<bool> falsk(sizeMap, false);
    vector<vector<bool>> whiteMap(sizeMap, falsk);
    vector<vector<bool>> blackMap(sizeMap, falsk);

    char read;
    for (int y = 0; y < sizeMap; y++) {
        for (int x = 0; x < sizeMap; x++) {
            cin >> read;
            if (read == 'W') {
                whiteMap[y][x] = true;
            }
            else if (read == 'B') {
                blackMap[y][x] = true;
            }
        }
    }
    int count = 0;
    for (int y = 0; y < sizeMap; y++) {
        for (int x = 0; x < sizeMap; x++) {
            if (blackMap[y][x]) {
                count += checkBlackHorse(y, x, whiteMap, blackMap);
            }
        }
    }
    cout << count;

    return 0;
}
