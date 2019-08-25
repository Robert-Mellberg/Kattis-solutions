#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
using namespace std;

//https://open.kattis.com/problems/recount

int main()
{
    unordered_map<string, int> voteCount;
    string namn;
    while (true) {
        getline(cin, namn);
        if (namn == "***") {
            break;
        }
        voteCount[namn] = voteCount[namn] + 1;

    }
    bool runoff = false;
    string winner = "";
    int votecount = -1;
    for (auto i : voteCount) {
        if (i.second > votecount) {
            votecount = i.second;
            winner = i.first;
            runoff = false;
        }
        else if (i.second == votecount) {
            runoff = true;
        }
    }
    if (runoff) {
        cout << "Runoff!";
    }
    else {
        cout << winner;
    }
    return 0;
}
