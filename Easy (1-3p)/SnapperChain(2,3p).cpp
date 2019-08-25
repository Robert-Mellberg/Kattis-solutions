#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/snapperhard

int main()
{
    vector<int> table;

    //compute table
    table.push_back(1);
    for (int i = 1; i < 30; i++) {
        table.push_back(table[i - 1] * 2 + 1);
    }
    int cases;
    cin >> cases;
    for (int j = 0; j < cases; j++) {
        cout << "Case #" << j + 1 << ": ";
        int antalDevices, klappningar;
        cin >> antalDevices >> klappningar;
        int divider = table[antalDevices - 1]+1;
        if (klappningar%divider == divider - 1) {
            cout << "ON";
        }
        else {
            cout << "OFF";
        }
        cout << endl;
    }
    
    return 0;
}
