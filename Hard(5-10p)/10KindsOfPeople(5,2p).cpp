#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

//https://open.kattis.com/problems/10kindsofpeople

int hittaPekare(vector<int> &connections, int locationA) {
    int nyPekare = connections[locationA];
    if (nyPekare == -1) {
        return locationA;
    }
    return hittaPekare(connections, nyPekare);
}

void connect(vector<int> &connections, int locationA, int locationB) {
    int locationAPointer = hittaPekare(connections,locationA);
    int locationBPointer = hittaPekare(connections, locationB);

    //pekar på samma element
    if (locationAPointer == locationBPointer) {
        return;
    }

    connections[locationBPointer] = locationAPointer;
}

vector<vector<char>> map;
int main()
{
    
        
    int antalRad;
    int antalKolumn;
    cin >> antalRad >> antalKolumn;
    
    for (int j = 0; j < antalRad; j++) {
        vector<char> rad;
        string wholeNumber;
        cin >> wholeNumber;
        for (int k = 0; k < antalKolumn; k++) {
            int num = wholeNumber[k];
            rad.push_back(num);
        }
        map.push_back(rad);
    }
    vector<int> connections((antalRad)*(antalKolumn),-1);
    for (int y = 0; y < antalRad; y++) {
        for (int x = 0; x < antalKolumn; x++) {
            if (x != antalKolumn-1) {
                if(map[y][x] == map[y][x+1])
                connect(connections, x*antalRad+y, (x+1)*antalRad + y);
            }
            if (y != antalRad-1) {
                if (map[y][x] == map[y+1][x])
                connect(connections, x*antalRad + y, x*antalRad + y+1);
            }
        }
    }
    //for (vector<char> test1 : map) {
    //  cout << endl;
    //  for (char test2 : test1) {
    //      cout << " " << test2;
    //  }
    //}

    int antalMatpunkter;
    cin >> antalMatpunkter;

    for (int i = 0; i < antalMatpunkter; i++) {
        int r1, k1, r2, k2;
        cin >> r1 >> k1 >> r2 >> k2;
        //om de pekar på samma element
        if (hittaPekare(connections, (k1-1)*antalRad + r1-1) == hittaPekare(connections, (k2-1)*antalRad + r2-1)) {
            if (map[r1-1][k1-1] == '0') {
                cout << "binary" << endl;
            }
            else {
                cout << "decimal" << endl;
            }
        }
        else {
            cout << "neither" <<  endl;
        }
    }
    return 0;
}
