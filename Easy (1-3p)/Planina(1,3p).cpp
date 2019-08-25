#include <iostream>
using namespace std;

//https://open.kattis.com/problems/planina

int main()
{
    int side = 2;
    int i;
    cin >> i;
    for (int k = 0; k < i; k++) {
        side += side - 1;
    }
    cout << side * side;
    return 0;
}
