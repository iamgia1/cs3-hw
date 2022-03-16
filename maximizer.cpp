#include <iostream>
#include<vector>

// TODO create an input/ ask the user to enter 10 numbers
// TODO print out the sorted list of numbers
// TODO multiply by the largest number the user enters in the list
using namespace std;

int main() {
    int user;
    vector<int> numbers;
    // ask user to enter 10 numbers
    cout << "Enter 10 numbers: " << "\n";
    cin >> user;
    // print out a sorted list
    for (int i = 0; i < 10; i++) {
        numbers.push_back(user);
        cout << numbers.at(i) << " ";
    }
    cout << "\n";

    for (int i = 1; i < numbers.size(); i++) {
        int key = numbers[i];
        for (int j = i - 1; j > -1; j--) {
            if (key < numbers[j]) {
                numbers[j + 1] = numbers[j];
                numbers[j] = key;
            } else break;
        }
    }

    for (int number: numbers) {
        cout << number << " ";
    }
}