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

//https://open.kattis.com/problems/virtualfriends

struct node {
    int friends = 1;
    string pointer = "self";
};

string findPointer(string name, unordered_map<string, node> &nodes) {
    string namePoint = nodes[name].pointer;
    if (namePoint == "self") {
        return name;
    }
    string newPoint = findPointer(namePoint, nodes);
    nodes[name].pointer = newPoint;
    return newPoint;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {

        unordered_map<string, node> nodes;
        int antalNamn;
        cin >> antalNamn;

        for (int j = 0; j < antalNamn; j++) {
            string name1, name2;
            cin >> name1 >> name2;

            string name1Root = findPointer(name1, nodes);
            string name2Root = findPointer(name2, nodes);
            if (name1Root == name2Root) {
                cout << nodes[name1Root].friends << "\n";
                continue;
            }
            nodes[name1Root].friends += nodes[name2Root].friends;
            nodes[name2Root].friends = 0;
            nodes[name2Root].pointer = name1Root;

            cout << nodes[name1Root].friends << "\n";
        }
    }

    
    
    return 0;
}
