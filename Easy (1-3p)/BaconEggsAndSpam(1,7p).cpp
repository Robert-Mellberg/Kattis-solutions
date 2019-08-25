#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
#include <random>
using namespace std;

//https://open.kattis.com/problems/baconeggsandspam

int main()
{
    int antalOrders;
    cin >> antalOrders;
    while (antalOrders != 0) {
        map<string, set<string>> itemPeopleList;
        string namn;
        while(true) {
            string read;
            cin >> read;
            //letter
            if ((int)read[0] >= 65) {
                //lowercase
                if ((int)read[0] >= 97) {
                    itemPeopleList[read].insert(namn);
                }
                else {
                    namn = read;
                }
            }
            else {
                antalOrders = atoi(read.c_str());
                break;
            }
        }
        //print
        for (auto i : itemPeopleList) {
            cout << i.first << " ";
            for (string namn : i.second) {
                cout << namn << " ";
            }
            cout << endl;
        }
        cout << endl;
        

    }
}
