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

//https://open.kattis.com/problems/pivot


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int antal;
    cin >> antal;
    vector<int> allaTal;
    set<int> partitions;

    int minInt = 0;
    cin >> minInt;
    allaTal.push_back(minInt);
    partitions.insert(minInt);
    for (int i = 1; i < antal; i++) {
        int read;
        cin >> read;
        allaTal.push_back(read);
        if (read > minInt) {
            minInt = read;
            partitions.insert(read);
        }
    }

    int maxInt = allaTal[allaTal.size() - 1];
    for (int i = antal-2; i >= 0; i--) {
        int read = allaTal[i];
        if (read > maxInt) {
            partitions.erase(read);
        }
        maxInt = min(maxInt, read);
    }
    cout << partitions.size();
    return 0;
}
