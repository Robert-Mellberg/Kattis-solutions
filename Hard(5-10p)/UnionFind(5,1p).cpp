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

//https://open.kattis.com/problems/unionfind

vector<int> allaTalPekare;
int findPointer(int index) {
    //index points to itself, return index
    if (allaTalPekare[index] == -1) {
        return index;
    }
    //find the root, update so this index points to root
    int root = findPointer(allaTalPekare[index]);
    allaTalPekare[index] = root;
    return root;
}


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int amountOfNumbers, operations;
    cin >> amountOfNumbers >> operations;
    allaTalPekare.resize(amountOfNumbers, -1);
    for (int i = 0; i < operations; i++) {
        char c;
        cin >> c;
        int num1, num2;
        cin >> num1 >> num2;
        if (c == '?') {
            //in the same set
            if (findPointer(num1) == findPointer(num2)) {
                cout << "yes\n";
            }
            else {
                cout << "no\n";
            }
        }
        else {
            //find which index num1 and num2 points at.
            int indexNum1 = findPointer(num1);
            int indexNum2 = findPointer(num2);
            //sets are already joined
            if (indexNum1 == indexNum2) {
                continue;
            }
            //set num1 to point to num2
            allaTalPekare[indexNum1] = findPointer(num2);
        }
    }
    return 0;
}
