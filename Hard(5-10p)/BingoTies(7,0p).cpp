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
#include <queue>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/bingoties

//The solution is to compare every bingo card with every other bingo card.
//Then check every row in the first bingo card with every row in the second card.
//If any two rows contains a common digit, then they can tie.
//They can tie by calling up every number (up to 8) on the both rows and lastly calling the common digit.

//There is one exception where that would not work.
//If at least 5 of the (up to) 8 numbers being called up before the common digit exists on a row in another board
//then that bingo card will have bingo before the cards with the common digit will and they will not tie.


struct bingocard {
    int num;
    vector<vector<int>> board;
};
vector<bingocard> cards;

//Check to see if there is a row on any board where vector<int> compare contains all the row's numbers.
bool findDisproof(vector<int> &compare) {
    for (bingocard b : cards) {
        for (vector<int> row : b.board) {
            int count = 0;
            for (int num : row) {
                for (int num1 : compare) {
                    if (num == num1) {
                        count++;
                        break;
                    }
                }
            }
            if (count == 5) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int antal;
    cin >> antal;
    for (int a = 0; a < antal; a++) {
        cards.push_back({});
        for (int i = 0; i < 5; i++) {
            cards[a].board.push_back({});
            for (int j = 0; j < 5; j++) {
                int read;
                cin >> read;
                cards[a].board[i].push_back(read);
            }
        }
    }
    
    //loop through all the cards, rows and numbers to find a common number.
    for (int firstCard = 0; firstCard < cards.size(); firstCard++) {
        bingocard &card1 = cards[firstCard];
        for (int secondCard = firstCard+1; secondCard < cards.size(); secondCard++) {
            bingocard &card2 = cards[secondCard];
            for (int row1Ind = 0; row1Ind < 5; row1Ind++) {
                vector<int> &row1 = card1.board[row1Ind];
                for (int row2Ind = 0; row2Ind < 5; row2Ind++) {
                    vector<int> &row2 = card2.board[row2Ind];
                    for (int num1 = 0; num1 < 5; num1++) {
                        for (int num2 = 0; num2 < 5; num2++) {
                            if (row1[num1] == row2[num2]) {

                                //compareArray contains all the digits that needs to be read before the common digit for them to tie.
                                vector<int> compareArray;
                                for (int i = 0; i < 5; i++) {
                                    if (row1[i] != row1[num1]) {
                                        bool exists = false;
                                        for (int it : compareArray) {
                                            if (it == row1[i]) {
                                                exists = true;
                                                break;
                                            }
                                        }
                                        if (!exists) {
                                            compareArray.push_back(row1[i]);
                                        }
                                    }
                                    if (row2[i] != row2[num2]) {
                                        bool exists = false;
                                        for (int it : compareArray) {
                                            if (it == row2[i]) {
                                                exists = true;
                                                break;
                                            }
                                        }
                                        if (!exists) {
                                            compareArray.push_back(row2[i]);
                                        }
                                    }
                                }

                                if (!findDisproof(compareArray)) {
                                    cout << firstCard + 1 << " " << secondCard + 1;
                                    return 0;
                                }

                            }
                        }
                    }
                }
            }
        }
    }
    cout << "no ties";
    return 0;
}
