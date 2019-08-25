#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/iboard

int main()
{
    string input;
    while (getline(cin, input)) {
        int antalEtt = 0;
        int antalNoll = 0;
        for (int bok = 0; bok < input.length(); bok++) {
            bitset<8> x(input[bok]);
            for (int i = 0; i < 7; i++) {
                if (x[i] == 1) {
                    antalEtt++;
                }
                else if (x[i] == 0) {
                    antalNoll++;
                }
            }
        }
        if (antalEtt % 2 == 0 && antalNoll % 2 == 0) {
            cout << "free" << endl;
        }
        else {
            cout << "trapped" << endl;
        }
    }

    return 0;
}
