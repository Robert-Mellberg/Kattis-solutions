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
using namespace std;

//https://open.kattis.com/problems/almostunionfind

struct node {
    long long sum;
    int redirect;
    int parent = -1;
    int count = 1;
};

vector<node> nodes;
int getRoot(int index) {
    if (nodes[index].parent == -1) {
        return index;
    }
    int root = getRoot(nodes[index].parent);
    //shrink tree height
    nodes[index].parent = root;
    return root;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int antalInt, antalCommands;
    while (cin >> antalInt >> antalCommands) {
        //clear old nodes
        nodes.clear();
        //initialize nodes
        for (int j = 0; j <= antalInt; j++) {
            node nod = { j, j };
            nodes.push_back(nod);
        }
        for (int i = 0; i < antalCommands; i++) {
            int command, num1, num2;
            cin >> command >> num1;

            if (command == 3) {
                int rootNum1 = getRoot(nodes[num1].redirect);
                cout << nodes[rootNum1].count << " " << nodes[rootNum1].sum << "\n";
            }
            else {
                cin >> num2;
                int rootNum1 = getRoot(nodes[num1].redirect);
                int rootNum2 = getRoot(nodes[num2].redirect);
                //elements already in same set
                if (rootNum1 == rootNum2) {
                    continue;
                }
                if (command == 1) {
                    nodes[rootNum2].count += nodes[rootNum1].count;
                    nodes[rootNum2].sum += nodes[rootNum1].sum;
                    nodes[rootNum1].parent = rootNum2;
                }
                else {
                    nodes[rootNum2].count++;
                    nodes[rootNum2].sum += num1;

                    nodes[rootNum1].count--;
                    nodes[rootNum1].sum -= num1;
                    nodes[num1].redirect = rootNum2;
                }
            }
        }

    }

    return 0;
}
