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

//https://open.kattis.com/problems/2048

void press(vector<vector<int>> &board) {

    for (int y = 0; y <= 3; y++) {
        int merge = -1;
        for (int x = 1; x <= 3; x++) {
            if (board[y][x] == 0)
                continue;
            for (int l = x - 1; l >= 0; l--) {
                if (board[y][x] == board[y][l] && l != merge) {
                    board[y][l] += board[y][l];
                    board[y][x] = 0;
                    merge = l;
                    break;
                }
                else if ((board[y][x] != board[y][l] && 0 != board[y][l]) || l == merge) {
                    board[y][l + 1] = board[y][x];
                    if(l+1 != x)
                    board[y][x] = 0;
                    break;
                }
                else if (l == 0) {
                    board[y][l] = board[y][x];
                    board[y][x] = 0;
                    break;
                }
            }
        }
    }
}

int main()
{
    vector<vector<int>> board;
    for (int i = 0; i < 4; i++) {
        board.push_back({});
        for (int j = 0; j < 4; j++) {
            int read;
            cin >> read;
            board[i].push_back(read);
        }
    }

    int direction;
    cin >> direction;

    vector<vector<int>> angledBoard;
    if (direction == 0) {
        angledBoard = board;
        press(angledBoard);
        for (int y = 0; y <= 3; y++) {
            for (int x = 0; x <= 3; x++) {
                cout << angledBoard[y][x] << " ";
            }
            cout << endl;
        }

    }
    else if (direction == 1) {
        for (int x = 3; x >= 0; x--) {
            angledBoard.push_back({});
            for (int y = 0; y <= 3; y++) {
                angledBoard[3-x].push_back(board[y][x]);
            }
        }
        press(angledBoard);
        for (int x = 0; x <= 3; x++) {
            for (int y = 3; y >= 0; y--) {
                cout << angledBoard[y][x] << " ";
            }
            cout << endl;
        }
    }
    else if (direction == 2) {
        for (int y = 0; y <= 3; y++) {
            angledBoard.push_back({});
            for (int x = 3; x >= 0; x--) {
                angledBoard[y].push_back(board[y][x]);
            }
        }
        press(angledBoard);
        for (int y = 0; y <= 3; y++) {
            for (int x = 3; x >= 0; x--) {
                cout << angledBoard[y][x] << " ";
            }
            cout << endl;
        }
    }
    else if (direction == 3) {
        for (int x = 0; x <= 3; x++) {
            angledBoard.push_back({});
            for (int y = 3; y >= 0; y--) {
                angledBoard[x].push_back(board[y][x]);
            }
        }

        press(angledBoard);
        for (int x = 3; x >= 0; x--) {
            for(int y = 0; y <= 3; y++) {
                cout << angledBoard[y][x] << " ";
            }
            cout << endl;
        }
    }


    return 0;
}
