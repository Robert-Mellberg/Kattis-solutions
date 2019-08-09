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


//https://open.kattis.com/problems/mravi#

//Represent the given tree from the problem where every node has a variable that stores how much water that node needs.
//For every leaf node, set the parent node's water need to the (leaf nodes water need)^(0.5)/(the percentage of the pipe) and remove the leaf node
//The parent node's water need should never be decreased.

struct node {
    int parent;
    long double waterNeed;
    int parentPercentage;
    bool parentSuperPipe;
    int amountOfChildren;
    
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<node> allNodes;
    stack<node> noChildrenNodes;

    node empty = { -1, -1, -1, false, 0};
    int antalNodes;
    cin >> antalNodes;
    allNodes.resize(antalNodes+1, empty);

    for (int i = 0; i < antalNodes - 1; i++) {
        int parent, child, percentage;
        bool superPower;
        cin >> parent >> child >> percentage >> superPower;

        allNodes[parent].amountOfChildren++;
        allNodes[child].parent = parent;
        allNodes[child].parentPercentage = percentage;
        allNodes[child].parentSuperPipe = superPower;
        
    }

    for (int i = 1; i <= antalNodes; i++) {
        double waterNeed;
        cin >> waterNeed;
        if (waterNeed == -1) {
            continue;
        }
        allNodes[i].waterNeed = waterNeed;
        noChildrenNodes.push(allNodes[i]);
    }

    while (!noChildrenNodes.empty()) {
        node curr = noChildrenNodes.top();
        noChildrenNodes.pop();
        if (curr.parent == -1) {
            break;
        }

        long double waterNeed = curr.waterNeed;
        if (waterNeed < 0) {
            throw new exception();
        }
        if (waterNeed > 1 && curr.parentSuperPipe) {
            waterNeed = sqrt(waterNeed);
        }
        waterNeed = (waterNeed * 100) / curr.parentPercentage;
        if (waterNeed > allNodes[curr.parent].waterNeed) {
            allNodes[curr.parent].waterNeed = waterNeed;
        }
        allNodes[curr.parent].amountOfChildren--;
        if (allNodes[curr.parent].amountOfChildren == 0) {
            noChildrenNodes.push(allNodes[curr.parent]);
        }
        
    }

    cout << std::fixed << allNodes[1].waterNeed;

    return 0;
}
