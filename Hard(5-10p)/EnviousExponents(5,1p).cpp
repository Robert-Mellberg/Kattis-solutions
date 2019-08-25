#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <random>
using namespace std;

//https://open.kattis.com/problems/enviousexponents

vector<long long> varden;
int calculateK(long long a) {
    for (int ind = 0; ind <= 60; ind++) {
        if (varden[ind] > a) {
            return ind-1;
        }
    }
    return 0;

}

long long calculateSum(int k, int n) {
    return ((1-(1/pow(2,n)))*pow(2, k+1));
}

int main()
{
    set<long long> ingaendeTal;
    for (int i = 0; i <= 61; i++) {
        varden.push_back(pow(2, i));
    }
    long long minstaTal;
    int power;
    cin >> minstaTal >> power;
    long long skillnad = minstaTal + 1;

    for (int n = power; n > 0; n--) {
        if (n == 1) {
            power = 0;
        }
        int k = calculateK(skillnad);
        //k < 0 bugg
        long long sum = calculateSum(k, n);
        if (sum >= skillnad) {
            long long tal = varden[k];
            ingaendeTal.insert(tal);
            skillnad = skillnad - tal;
            if (skillnad < 0) {
                return 0;
            }
            if (skillnad == 0) {
                power = n - 1;
                break;
            }
        }
        else {
            ingaendeTal.insert(varden[k + 1]);
            power = n - 1;
            break;
        }
    }
    int count = 0;
    int index = 0;
    while (count != power) {
        if (index > 60) {
            break;
        }
        //finns inte i listan
        if (ingaendeTal.find(varden[index]) == ingaendeTal.end()) {
            count++;
            ingaendeTal.insert(varden[index]);
        }
        index++;
    }

    long long total = 0;
    for (long long i : ingaendeTal) {
        total += i;
    }
    cout << total;
    return 0;
}
