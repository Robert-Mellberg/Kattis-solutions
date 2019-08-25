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

//https://open.kattis.com/problems/icpcawards

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int antal;
    cin >> antal;
    int count = 0;
    unordered_set<string> universities;
    for (int i = 0; i < antal; i++) {
        string uni, team;
        cin >> uni >> team;
        if (universities.find(uni) == universities.end()) {
            universities.insert(uni);
            count++;
            cout << uni << " " << team << endl;
            if (count == 12) {
                break;
            }
        }
    }
    
    return 0;
}
