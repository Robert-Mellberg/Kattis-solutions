#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/datum

int main()
{
    vector<string> dagar = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
    vector<int> antalDagar = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int dag, manad;
    cin >> dag >> manad;
    dag -= 1;
    for (int i = 0; i < manad; i++) {
        dag += antalDagar[i];
    }
    cout << dagar[dag % 7];

    return 0;
}
