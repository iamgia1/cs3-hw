#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    string input;
    vector < int > numbers;
    // ask user to enter 10 numbers
    cout << "Enter 10 numbers: " << "\n";
    for (int i = 0; i < 10; i++) {
        cin >> input;
        numbers.insert(numbers.end(), stoi(input));
    }
    std::sort(numbers.begin(), numbers.end());
    // print out a sorted list multiplied by the biggest number
    for (int i = 0; i < 10; i++) {
        cout << numbers.at(i) * numbers.at(9) << " ";
    }
}