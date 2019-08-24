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

//https://open.kattis.com/problems/cups

int main()
{
    map<int, string> colorsInOrder;

    int cases;
    cin >> cases;
    cin.ignore();
    for (int i = 0; i < cases; i++) {
        string command;
        getline(cin, command);
        stringstream ss(command);
        int radius;
        string color;
        //number first
        if ((int)command[0] < 58) {
            ss >> radius >> color;
            radius /= 2;
        }
        else {
            ss >> color >> radius;
        }
        colorsInOrder[radius] = color;
    }
    for (auto i : colorsInOrder) {
        cout << i.second << endl;
    }
    return 0;
}
