#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/irepeatmyself

int main()
{
    int cases;
    cin >> cases;
    cin.ignore();
    for (int i = 0; i < cases; i++) {
        string input;
        getline(cin, input);
        for (int j = 1; j <= input.length(); j++) {
            string sub = input.substr(0, j);
            string total = "";
            for (int l = 0; l <= input.length() / j; l++) {
                total += sub;
            }
            if (total.substr(0, input.length()) == input) {
                cout << j << endl;
                break;
            }
        }
    }
    return 0;
}
