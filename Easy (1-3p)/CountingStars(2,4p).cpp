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

//https://open.kattis.com/problems/countingstars

//Solve the problem by using a disjoing-set data structure
//The amount of stars is the same as the amount of disjoint subsets.

struct node {
    bool star;
    int root = -1;
};

int find(vector<node> &grid, int a) {
    if (grid[a].root == -1) {
        return a;
    }
    return find(grid, grid[a].root);
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int y, x;
    int caseNum = 0;
    while (cin >> y && cin >> x) {
        caseNum++;
        node n = {};
        vector<node> grid(x*y, n);

        for (int i = 0; i < y; i++) {
            for (int l = 0; l < x; l++) {
                char c;
                cin >> c;
                if (c == '-') {
                    grid[i*x+l].star = true;
                }
            }
        }

        for (int yy = 0; yy < y; yy++) {
            for (int xx = 0; xx < x; xx++) {
                int pos = yy * x + xx;
                if (!grid[pos].star) {
                    continue;
                }

                int root = find(grid, pos);
                if (xx != x - 1 && grid[pos + 1].star) {
                    int root1 = find(grid, pos + 1);
                    if (root != root1) {
                        grid[root1].root = root;
                    }
                }
                if (yy != 0 && grid[pos - x].star) {
                    int root1 = find(grid, pos - x);
                    if (root != root1) {
                        grid[root1].root = root;
                    }
                }
            }
        }

        unordered_set<int> roots;
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i].star) {
                int root = find(grid, i);
                if (roots.find(root) == roots.end()) {
                    count++;
                }
                roots.insert(root);
            }
        }
        cout << "Case " << caseNum << ": ";
        cout << count << "\n";


    }
    return 0;
}
