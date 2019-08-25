#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <algorithm>
#include <sstream>
using namespace std;

//https://open.kattis.com/problems/sumoftheothers

int main()
{
    
    for (int i = 0; i < 200; i++) {
        vector<int> siffror;
        string input;
        getline(cin, input);
        stringstream stream(input);
        int n;
        while (stream >> n) {
            siffror.push_back(n);
        }

        for (int index = 0; index < siffror.size(); index++) {
            int sum = siffror[index];
            int total = 0;
            for (int k = 0; k < siffror.size(); k++) {
                if (k != index) {
                    total += siffror[k];
                }
            }
            if (sum == total) {
                cout << total << endl;
                break;
            }
        }
    }
    return 0;
}
