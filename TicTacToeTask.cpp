#include<iostream>

#include<string>

#include<vector>


using namespace std;
vector < vector < string >> grid {
        {
                " ",
                " ",
                " "
        }, {
                " ",
                " ",
                " "
        }, {
                " ",
                " ",
                " "
        }
};
bool winner(string player) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] != player) {
                //  the for loop goes as long as j < grid i.size
                j = grid[i].size();
            } else if (j == grid.size() - 1) {
                return true;
            }
        }
    }
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[j][i] != player) {
                j = grid[i].size();
            } else if (j == grid.size() - 1) {
                return true;
            }
        }
    }
    // diagonals
    if (grid.at(0).at(0) == player && grid.at(1).at(1) == player && grid.at(2).at(2) == player) {
        return true;
    }
    if (grid.at(2).at(0) == player && grid.at(1).at(1) == player && grid.at(0).at(2) == player) {
        return true;
    }
    return false;
}
void drawGrid() {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (j % 2 != 0) {
                cout << " | " << grid[i][j] << " | ";
            } else {
                cout << grid[i][j];
            }
        }
        if (i != grid.size() - 1) {
            cout << "\n- + - + -\n";
        }
    }
    cout << "\n";
}
bool checkInteger(string input) {
    // credit * https://java2blog.com/check-if-input-is-integer-in-cpp/?msclkid=165fc59da7cf11ecb9b0d45227fb2985
    int itr = 0;
    if (input.empty())
        return false;
    if (input[0] == '-') {
        itr = 1;
    }

    for (int i = itr; i < input.size(); i++) {
        if (!isdigit(input[i]))
            return false;
    }
    return true;
}
int main() {
    int rowX;
    int colY;
    string inputStrX;
    string inputStrY;
    string currentPlayer = "X";
    bool done = false;
    cout << "To choose a position enter in the row number then in the column number 0,2 :" << "\n";
    while (!done) {
        cout << "Player " << currentPlayer << " move: \n";
        cin >> inputStrX;
        cin >> inputStrY;
        // gives the coordinates that the player wants to position
        if (checkInteger(inputStrX)) {
            rowX = stoi(inputStrX);
            if (rowX < 0 || rowX > 2) {
                cout << "input out of bounds\n";
                continue;
            }
        } else {
            cout << "invalid X \n";
            continue;
        }
        if (checkInteger(inputStrY)) {
            colY = stoi(inputStrY);
            if (colY < 0 || colY > 2) {
                cout << "input out of bounds\n";
                continue;
            }
        } else {
            cout << "invalid Y \n";
            continue;
        }
        // checking if there is a space there and filling that space with current player
        if (grid.at(rowX).at(colY) == " ") {
            grid.at(rowX).at(colY) = currentPlayer;
        } else {
            cout << "move already taken \n";
            continue;
        }
        // draw a board with the players input
        drawGrid();
        // detect the winner
        if (::winner(currentPlayer)) {
            done = true;
            cout << "The winner is " << currentPlayer;
        } else {
            if (currentPlayer == "X") {
                currentPlayer = "Y";
            } else {
                currentPlayer = "X";
            }
        }

    }
}