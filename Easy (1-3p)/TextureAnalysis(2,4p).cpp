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
using namespace std;

//https://open.kattis.com/problems/textureanalysis

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 1; i <= 2001; i++) {
        string line;
        getline(cin, line);
        if (line == "END") {
            break;
        }
        if (line.length() == 1) {
            cout << i << " " << "EVEN" << endl;
            continue;
        }
        bool first = true;
        int count = 0;
        int previousCount = 0;
        bool correct = true;
        for (int k = 1; k < line.length(); k++) {
            if (line[k] == '*'){
                if (count != previousCount && !first) {
                    correct = false;
                }
                previousCount = count;
                count = 0;
                first = false;
            }
            else {
                count++;
            }
        }
        if (correct) {
            cout << i << " " << "EVEN" << endl;
        }
        else {
            cout << i << " " << "NOT EVEN" << endl;
        }
    }
    return 0;
}
