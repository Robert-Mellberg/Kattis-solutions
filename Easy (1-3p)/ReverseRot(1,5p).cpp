#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <algorithm>
using namespace std;

//https://open.kattis.com/problems/reverserot

int main()
{
    
    while (true) {
        int forskjutning;
        cin >> forskjutning;
        if (forskjutning == 0) {
            break;
        }
        string coded;
        cin >> coded;
        vector<char> reverser;
        for (int k = coded.length() - 1; k >= 0; k--) {
            int charNumber = (int)coded[k];
            if (charNumber == 46) {
                charNumber = 64;
            }
            else if (charNumber == 95) {
                charNumber = 63;
            }

            charNumber += forskjutning;
            if (charNumber > 90) {
                charNumber -= 28;
            }
            if (charNumber == 64) {
                charNumber = 46;
            }
            else if (charNumber == 63) {
                charNumber = 95;
            }
            reverser.push_back((char)charNumber);
        }
        for (char c : reverser) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}
