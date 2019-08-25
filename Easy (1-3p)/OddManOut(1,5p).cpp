#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

//https://open.kattis.com/problems/oddmanout

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int numberOfGuests;
        cin >> numberOfGuests;
        unordered_set<unsigned int> guests;
        for (int j = 0; j < numberOfGuests; j++) {
            int read;
            cin >> read;
            if (guests.find(read) != guests.end()) {
                guests.erase(read);
            }
            else {
                guests.insert(read);
            }
        }
        cout << "Case #" << i + 1 << ": " << *guests.begin() << endl;
    }
    return 0;
}
