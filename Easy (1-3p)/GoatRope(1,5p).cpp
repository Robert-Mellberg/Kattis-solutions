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

//https://open.kattis.com/problems/goatrope


int main()
{
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);
    int goatX, goatY, house1X, house1Y, house2X, house2Y;
    cin >> goatX >> goatY >> house1X >> house1Y >> house2X >> house2Y;
    int avstandY = 0, avstandX = 0;
    if (goatY < house1Y) {
        avstandY = goatY - house1Y;
    }
    else if (goatY > house2Y) {
        avstandY = goatY - house2Y;
    }
    if (goatX < house1X) {
        avstandX = goatX - house1X;
    }
    else if (goatX > house2X) {
        avstandX = goatX - house2X;
    }
    printf("%.10f", sqrt(avstandX*avstandX + avstandY * avstandY));
    return 0;
}
