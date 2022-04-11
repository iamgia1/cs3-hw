#include<iostream>
#include<string>
#include<vector>


using namespace std;

// TODO 2D Vector of strings

// TODO to ask the user for player one input

// TODO draw the board with their input

// TODO check if there is a winner

// TODO repeat with player two

vector<vector<string>> grid {
    {" "," "," "},
    {" "," "," "},
    {" "," "," "}
};
string winner() {
return " ";
}
void drawGrid() {
    for (int i = 0; i < grid.size();i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (j % 2 != 0) {
                    cout << " | " << grid[i][j] << " | ";
                } else {
                    cout << grid[i][j];
                }
            }
            if (i != grid.size() -1) {
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
    string winner = " ";
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
            if(rowX < 0 || rowX > 2){
                cout << "input out of bounds\n";
                continue;
            }
        } else {
            cout << "invalid X \n";
            continue;
        }
        if (checkInteger(inputStrY)) {
            colY = stoi(inputStrY);
            if(colY < 0 || colY > 2) {
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
        winner = ::winner();
        if (winner == "X" || winner == "Y") {
            done = true;
        } else {
            if (currentPlayer == "X") {
                currentPlayer = "Y";
            } else {
                currentPlayer = "X";
            }
        }

    }
}