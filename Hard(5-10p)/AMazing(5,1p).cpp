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

//https://open.kattis.com/problems/amazing

struct square {
    stack<int> previousDirections;
    vector<int> directions = {0, 1, 2, 3};
};



int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> xDirections = { 1, 0, -1, 0 };
    vector<int> yDirections = { 0, -1, 0, 1 };
    vector<string> commands = {"right", "up", "left", "down"};

    int xCurr = 100, yCurr = 100;
    square squ = {};
    squ.previousDirections.push(-1);
    vector<square> row(201, squ);
    vector<vector<square>> maze(201, row);
    while (true) {
        square &currSquare = maze[yCurr][xCurr];
        int direction;
        bool goingBack = false;
        if (!currSquare.directions.empty()) {
            direction = currSquare.directions[0];
            currSquare.directions.erase(currSquare.directions.begin());
            cout << commands[direction] << endl;
        }
        else {
            int previousDirection = currSquare.previousDirections.top();
            currSquare.previousDirections.pop();
            if (previousDirection == -1) {
                cout << "no way out" << endl;
            }
            else {
                direction = previousDirection;
                cout << commands[direction] << endl;
                goingBack = true;
            }
        }

        string input;
        cin >> input;

        if (input == "ok") {
            xCurr += xDirections[direction];
            yCurr += yDirections[direction];
            int oppositeDirection = (direction + 2) % 4;
            if (!goingBack) {
                maze[yCurr][xCurr].previousDirections.push(oppositeDirection);
                vector<int>::iterator index = find(maze[yCurr][xCurr].directions.begin(), maze[yCurr][xCurr].directions.end(), oppositeDirection);
                //index always exists
                maze[yCurr][xCurr].directions.erase(index);
            }

        }
        else if (input == "wall") {
            // do nothing
        }
        else if (input == "solved" || input == "wrong") {
            break;
        }
    }
    
    return 0;
}
