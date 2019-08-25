#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/guess

int main()
{
    int lower = 1;
    int higher = 1000;
    int guess;
    while (true) {
        guess = (higher + lower) / 2;
        cout << guess << endl;
        string result;
        cin >> result;
        if (result == "lower") {
            higher = guess - 1;
        }
        else if (result == "higher") {
            lower = guess + 1;
        }
        else if(result == "correct"){
            break;
        }
    }

    return 0;
}
