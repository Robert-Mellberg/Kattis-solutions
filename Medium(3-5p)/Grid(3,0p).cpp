#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/grid

//Can be solved by using Dijkstra's and treat the grid as an undirected graph where every axis weighs 1.

struct square {
    int num = 0;
    int visited = 10000000;
};

bool inrange(int m, int n, int x, int y) {
    if (x >= m || y >= n || y < 0 || x < 0) {
        return false;
    }
    return true;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    square sq = {};
    vector<square> empty(m, sq);
    vector<vector<square>> grid(n, empty);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            char num;
            cin >> num;
            grid[y][x].num = num - '0';
        }
    }


    stack<int> xPositions;
    stack<int> yPositions;
    xPositions.push(0);
    yPositions.push(0);

    int level = 0;
    while (!xPositions.empty()) {
        level++;
        vector<int> newX;
        vector<int> newY;
        while (!xPositions.empty()) {
            int x = xPositions.top();
            int y = yPositions.top();
            xPositions.pop();
            yPositions.pop();

            int val = grid[y][x].num;
            int newXVal = x + val;
            int newYVal = y;
            if (inrange(m, n, newXVal, newYVal) && level < grid[newYVal][newXVal].visited) {
                grid[newYVal][newXVal].visited = level;
                newX.push_back(newXVal);
                newY.push_back(newYVal);
            }
            newXVal = x - val;
            if (inrange(m, n, newXVal, newYVal) && level < grid[newYVal][newXVal].visited) {
                grid[newYVal][newXVal].visited = level;
                newX.push_back(newXVal);
                newY.push_back(newYVal);
            }
            newXVal = x;
            newYVal = y + val;
            if (inrange(m, n, newXVal, newYVal) && level < grid[newYVal][newXVal].visited) {
                grid[newYVal][newXVal].visited = level;
                newX.push_back(newXVal);
                newY.push_back(newYVal);
            }
            newYVal = y - val;
            if (inrange(m, n, newXVal, newYVal) && level < grid[newYVal][newXVal].visited) {
                grid[newYVal][newXVal].visited = level;
                newX.push_back(newXVal);
                newY.push_back(newYVal);
            }
        }
        for (int x : newX) {
            xPositions.push(x);
        }
        for (int y : newY) {
            yPositions.push(y);
        }
    }


    if (grid[n - 1][m - 1].visited == 10000000) {
        cout << -1;
    }
    else {
        cout << grid[n - 1][m - 1].visited;
    }
    return 0;
}
