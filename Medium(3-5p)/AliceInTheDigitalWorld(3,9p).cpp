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
using namespace std;

//https://open.kattis.com/problems/alicedigital

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {

        int leftSum = 0, rightSum = 0;
        int antal, minstaSiffra;
        cin >> antal >> minstaSiffra;
        int maxWeight = 0;
        bool containsMinstaSiffra = false;
        for (int j = 0; j < antal; j++) {
            int read;
            cin >> read;

            if (read == minstaSiffra) {
                if (containsMinstaSiffra) {
                    if (leftSum + rightSum > maxWeight) {
                        maxWeight = leftSum + rightSum;
                    }
                    leftSum = rightSum;
                }
                containsMinstaSiffra = true;
                rightSum = 0;
            }
            else if (read < minstaSiffra) {
                if (containsMinstaSiffra) {
                    if (leftSum + rightSum > maxWeight) {
                        maxWeight = leftSum + rightSum;
                    }
                }
                leftSum = 0;
                rightSum = 0;
                containsMinstaSiffra = false;
            }
            else {
                if (containsMinstaSiffra) {
                    rightSum += read;
                }
                else {
                    leftSum += read;
                }
            }
        }
        if (containsMinstaSiffra) {
            if (leftSum + rightSum > maxWeight) {
                maxWeight = leftSum + rightSum;
            }
        }
        cout << maxWeight + minstaSiffra << endl;
    }
    return 0;
}
