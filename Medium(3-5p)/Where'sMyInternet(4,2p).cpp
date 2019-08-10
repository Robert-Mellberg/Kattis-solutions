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

//https://open.kattis.com/problems/wheresmyinternet



int findPointer(int point, vector<int> &pointers) {
    int thisPoint = pointers[point];
    if (thisPoint == -1) {
        return point;
    }
    int newPoint = findPointer(thisPoint, pointers);
    pointers[point] = newPoint;
    return newPoint;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int houses, connections;
    cin >> houses >> connections;

    vector<int> pointers(houses + 1, -1);

    for (int i = 0; i < connections; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        int rootNum1 = findPointer(num1, pointers);
        int rootNum2 = findPointer(num2, pointers);

        if (rootNum1 == rootNum2) {
            continue;
        }
        if (rootNum1 == 1) {
            pointers[rootNum2] = rootNum1;
        }
        else{
            pointers[rootNum1] = rootNum2;
        }
    }
    bool empty = true;
    for (int i = 1; i < pointers.size(); i++) {
        if (findPointer(i, pointers) != 1) {
            cout << i << "\n";
            empty = false;
        }
    }

    if (empty) {
        cout << "Connected";
    }
    

    
    
    return 0;
}
