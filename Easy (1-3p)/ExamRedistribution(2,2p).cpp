#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <sstream>
using namespace std;

//https://open.kattis.com/problems/redistribution

int main()
{
    multimap<int, int> roomsStudents;
    int rooms;
    cin >> rooms;
    int max = 0;
    for (int i = 0; i < rooms; i++) {
        int read;
        cin >> read;
        if (read > max) {
            max = read;
        }
        roomsStudents.insert(pair<int, int>(-read, i));
    }
    int total = 0;
    for (auto i : roomsStudents) {
        total += i.first;
    }
    if (total <= -max * 2) {
        for (auto i : roomsStudents) {
            cout << i.second+1 << " ";
        }
    }
    else {
        cout << "impossible";
    }
    return 0;
}
