#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
using namespace std;

//https://open.kattis.com/problems/abandonedanimal

int inf = 1 << 30;
int main()
{
    int antalSalj;
    cin >> antalSalj >> antalSalj;
    
    unordered_map<string, set<int>> availableLocations;

    for (int j = 0; j < antalSalj; j++) {
        string item;
        int location;
        cin >> location >> item;
        availableLocations[item].insert(location);
    }
    
    int antalItems;
    cin >> antalItems;
    vector<string> items;

    for (int j = 0; j < antalItems; j++) {
        string item;
        cin >> item;
        items.push_back(item);
    }

    //remove items before min
    int minAllowed = *(availableLocations[items[0]].begin());
    for (int j = 1; j < items.size(); j++) {

        vector<int> remove;
        string location = items[j];

        for (int loc : availableLocations[location]) {
            if (loc < minAllowed) {
                remove.push_back(loc);
            }
        }

        for (int rem : remove) {
            availableLocations[location].erase(rem);
        }
        if (availableLocations[location].size() > 0) {
            minAllowed = *availableLocations[location].begin();
        }
    }

    int maxAllowed = 100000;
    for (int j = antalItems-1; j >= 0; j--) {

        vector<int> remove;
        string location = items[j];
        for (int loc : availableLocations[location]) {
            if (loc > maxAllowed) {
                remove.push_back(loc);
            }
        }

        for (int rem : remove) {
            availableLocations[location].erase(rem);
        }
        
        if (availableLocations[location].size() > 0) {
            maxAllowed = *availableLocations[location].rbegin();
        }
    }
    
    bool works = true;
    bool ambig = false;
    for (auto i : items) {
        if (availableLocations[i].size() < 1) {
            works = false;
        }
        if (availableLocations[i].size() > 1) {
            ambig = true;
        }
    }

    // Print answer
    if (!works) {
        cout << "impossible" << endl;
    }
    else if (ambig) {
        cout << "ambiguous" << endl;
    }
    else {
        cout << "unique" << endl;
    }

    return 0;
}
