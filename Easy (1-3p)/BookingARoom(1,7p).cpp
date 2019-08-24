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

//https://open.kattis.com/problems/bookingaroom

int main()
{
    int amountOfRooms, amountBooked;
    cin >> amountOfRooms >> amountBooked;
    if (amountOfRooms == amountBooked) {
        cout << "too late";
        return 0;
    }
    vector<bool> availableRooms(amountOfRooms, true);
    //remove booked rooms
    for (int i = 0; i < amountBooked; i++) {
        int room;
        cin >> room;
        availableRooms[room-1] = 0;
    }
    for (int k = 0; k < availableRooms.size(); k++) {
        if (availableRooms[k]) {
            cout << k + 1;
            return 0;
        }
    }
    return 0;
}
