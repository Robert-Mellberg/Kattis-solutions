#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <stack>
using namespace std;

//https://open.kattis.com/problems/absurdistan3

struct island {
    bool utgaendeBro;
    int degree;
    vector<int> grannar;
};

void removeCirle(vector<island>& v, int start) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        for (int i = 0; i < v[curr].grannar.size(); i++) {
            int neighbor = v[curr].grannar[i];
            if (!v[neighbor].utgaendeBro) {
                s.push(neighbor);
                v[curr].utgaendeBro = true;
                cout << curr << " " << neighbor << endl;
                break;
            }
        }
    }

    // Reattach cycle
    for (int i = 0; i < v[start].grannar.size(); i++) {
        int neighbor = v[start].grannar[i];
        if (!v[neighbor].utgaendeBro) {
            cout << neighbor << " " << start << endl;
            break;
        }
    }
}

int main()
{
    int antalOar;
    cin >> antalOar;
    island tomO = { false, 0, {} };
    vector<island> oar(antalOar+1, tomO);

    for (int i = 0; i < antalOar; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        oar[n1].grannar.push_back(n2);
        oar[n1].degree++;
        oar[n2].grannar.push_back(n1);
        oar[n2].degree++;
    }

    stack<int> grad1;
    for (int j = 1; j < antalOar + 1; j++) {
        if (oar[j].degree == 1) {
            grad1.push(j);
        }
    }

    while (!grad1.empty()) {
        int intO = grad1.top();
        grad1.pop();
        for (int j = 0; j < oar[intO].grannar.size(); j++) {
            int nyO = oar[intO].grannar[j];
            if (!oar[nyO].utgaendeBro) {
                oar[nyO].degree--;
                if (oar[nyO].degree == 1) {
                    grad1.push(nyO);
                }
                oar[intO].utgaendeBro = true;
                cout << intO << " " << nyO << endl;
                break;
            }
        }
    }

    for (int j = 1; j < antalOar + 1; j++) {
        if (!oar[j].utgaendeBro) {
            removeCirle(oar, j);
        }
    }


    return 0;
}
