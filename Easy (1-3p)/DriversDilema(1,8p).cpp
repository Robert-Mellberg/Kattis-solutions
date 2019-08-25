#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

//https://open.kattis.com/problems/driversdilemma

struct datan {
    int hastighet;
    double milesPerGallon;
};

int main()
{
    double tank;
    cin >> tank;
    tank = (tank / 2)-0.000001;
    double lackage;
    cin >> lackage;
    double avstand;
    cin >> avstand;

    vector<datan> tabell;
    for (int i = 0; i < 6; i++) {
        int hast;
        double milesPerG;
        cin >> hast;
        cin >> milesPerG;
        datan d1 = {hast, milesPerG};
        tabell.push_back(d1);
    }

    int minstaHastighet = 0;

    for (int j = 0; j < tabell.size(); j++) {
        int hast = tabell[j].hastighet;
        double milesPerG = tabell[j].milesPerGallon;
        double fuelLoss = (avstand / hast)*lackage;
        double nyKapacitet = tank - fuelLoss;
        if (nyKapacitet*milesPerG >= avstand) {
            minstaHastighet = hast;
        }
    }
    if (minstaHastighet == 0) {
        cout << "NO";
    }
    else {
        cout << "YES " << minstaHastighet;
    }

    return 0;
}
