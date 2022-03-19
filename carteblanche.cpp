#include<string>
#include<iostream>
#include<vector>

using namespace std;
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
    int expectedTime;
    string input;
    vector < string > directions;
    cout << "Enter in the directions seperated by new lines. Enter the number the maximum number minutes your walk should take." << "\n";
    bool done = false;
    while (!done) {
        cin >> input;
        if (checkInteger(input)) {
            expectedTime = stoi(input);
            done = true;
        } else if (input == "N" || input == "n" || input == "S" || input == "s" || input == "W" || input == "w" ||
                   input == "E" || input == "e") {
            std::transform(input.begin(), input.end(), input.begin(), ::tolower);
            directions.insert(directions.end(), input);
        }
    }
    int northTracker = 0;
    int westTracker = 0;
    int time = 0;
    for (auto & direction: directions) {
        time += 1;
        if (direction == "n") {
            northTracker += 1;
        } else if (direction == "s") {
            northTracker -= 1;
        } else if (direction == "w") {
            westTracker += 1;
        } else if (direction == "e") {
            westTracker -= 1;
        }
    }
    if (time <= expectedTime && northTracker == 0 && westTracker == 0) {
        cout << "true";
    } else {
        cout << "false";
    }
}