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

//https://open.kattis.com/problems/flexible

int main()
{
    vector<int> locations = { 0 };
    int size, antal;
    cin >> size >> antal;
    for (int i = 0; i < antal; i++) {
        int read;
        cin >> read;
        locations.push_back(read);
    }
    locations.push_back(size);
    set<int> sizes;
    for (int j = 0; j < locations.size(); j++) {
        for (int i = j; i < locations.size(); i++) {
            sizes.insert(locations[i]-locations[j]);
        }
    }
    sizes.erase(0);
    for (int i : sizes) {
        cout << i << " ";
    }
    return 0;
}
