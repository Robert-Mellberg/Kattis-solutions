#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/averageseasy

//Calculate the average IQ for economics and the average IQ for computer scientist
//Count the amount of computer students with higher IQ than eco average and lower IQ that computer average.

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int data, eko;
        cin >> data >> eko;
        double averageData = 0, averageEko = 0;
        vector<int> dataIQ;
        for (int j = 0; j < data; j++) {
            int read;
            cin >> read;
            averageData += read;
            dataIQ.push_back(read);
        }
        averageData /= data;
        for (int j = 0; j < eko; j++) {
            int read;
            cin >> read;
            averageEko += read;
        }
        averageEko /= eko;
        int count = 0;
        for (int IQ : dataIQ) {
            if (IQ > averageEko && IQ < averageData) {
                count++;
            }
        }
        cout << count << "\n";
    }



    return 0;
}
