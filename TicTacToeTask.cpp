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
int winner() {

}
void drawGrid() {
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
    int inputX;
    int inputY;
    string inputStrX;
    string inputStrY;
    string currentPlayer = "X";
    bool done = false;
    cout << "Moves are in the format \"x y\" with x being columns and y being rows" << endl;
    cout << "Choose whether to play Player X or Player Y:" ;
    while (!done) {
        cout << "Player " << currentPlayer << " move: \n";
        cin >> inputStrX;
        cin >> inputStrY;
        // gives the coordinates that the player wants to position
        if (checkInteger(inputStrX.substr(0, 1))) {
            inputX = stoi(inputStrX.substr(0, 1));
        } else {
            continue;
        }
        if (checkInteger(inputStrY.substr(1, 2))) {
            inputY = stoi(inputStrY.substr(1, 2));
        } else {
            continue;
        }
        if (grid.at(inputX).at(inputY) != " ") {
            grid.at(inputX).at(inputY) = currentPlayer;
        }
        // function to check once a turn is over to move onto Player Y

        // draw a board with the players input
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                cout << grid[j][i] << " ";
                cout << "\n";
            }
        }
        drawGrid();
        done = true;
    }
}