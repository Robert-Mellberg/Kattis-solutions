#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <stack>
using namespace std;

//https://open.kattis.com/problems/loowater

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {

        int antalHuvud, antalKnight;
        cin >> antalHuvud >> antalKnight;
        if (antalHuvud == 0) {
            break;
        }

        map<int, int> knights;
        multiset<int> huvud;
        for (int i = 0; i < antalHuvud; i++) {
            int read;
            cin >> read;
            huvud.insert(read);
        }
        for (int i = 0; i < antalKnight; i++) {
            int read;
            cin >> read;
            knights[read]++;
        }
        int cost = 0;
        bool impossible = false;
        for (int i : huvud) {
            set<int> remove;
            if (knights.size() == 0) {
                impossible = true;
                break;
            }
            int minus = -1;
            for (auto kn : knights) {
                if (kn.first < i) {
                    remove.insert(kn.first);
                }
                else {
                    cost += kn.first;
                    
                    if (kn.second == 1) {
                        remove.insert(kn.first);
                    }
                    else {
                        minus = kn.first;
                    }
                    break;
                }
            }
            if (minus != -1) {
                knights[minus]--;
            }
            for (int rem : remove) {
                knights.erase(rem);
            }
        }
        if (impossible) {
            cout << "Loowater is doomed!" << endl;
        }
        else {
            cout << cost << endl;
        }
    }
    
    return 0;
}
