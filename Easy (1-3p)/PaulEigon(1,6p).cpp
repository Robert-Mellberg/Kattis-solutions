#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/pauleigon

int main()
{
    int antal, score1, score2;
    cin >> antal >> score1 >> score2;
    int totalScore = score1 + score2;
    if ((totalScore / antal) % 2 == 0) {
        cout << "paul";
    }
    else {
        cout << "opponent";
    }
    return 0;
}
