#include <iostream>
using namespace std;

//https://open.kattis.com/problems/licensetolaunch


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int days;
    cin >> days;
    int min = 1000000001, day = -1;
    for (int i = 0; i < days; i++) {
        int read;
        cin >> read;
        if (read < min) {
            min = read;
            day = i;
        }
    }
    cout << day;
    return 0;
}
