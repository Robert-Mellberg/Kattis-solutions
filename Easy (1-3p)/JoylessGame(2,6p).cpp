#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <sstream>
using namespace std;

//https://open.kattis.com/problems/joylessgame

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        string input;
        cin >> input;
        if (input.length() % 2 == 1) {
            if(input[0] != input[input.length()-1])
            cout << "Chikapu" << endl;
            else
                cout << "Bash" << endl;
        }
        else {
            if (input[0] != input[input.length() - 1])
            cout << "Bash" << endl;
            else
                cout << "Chikapu" << endl;
        }
    }

    return 0;
}
