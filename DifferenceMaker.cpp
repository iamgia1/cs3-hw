#include<iostream>
#include<string>
#include<vector>


using namespace std;

int main() {
    string input;
    vector < int > numbers;
//TODO For this problem the user will enter N numbers
    cout << "Enter 10 numbers: " << "\n";
    for (int i = 0; i < 10; i++) {
        cin >> input;
        numbers.insert(numbers.end(), stoi(input));
    }
    std::sort(numbers.begin(), numbers.end());
// TODO you should print out the pair of numbers with the smallest difference between them.
    int subtrahend = 0;
    int minuend = 0;
    int minDifference = 2147483647;
    for (int i = 0; i < numbers.size() - 1; i++) {
        // creating the difference by every 2 numbers that are next to each other in the vector
        int difference = numbers.at(i + 1) - numbers.at(i);
        // checking to see if that difference is smaller than the max product
        if (difference < minDifference) {
            minDifference = difference;
            minuend = numbers.at(i);
            subtrahend = numbers.at(i + 1);
        }
    }
    cout << subtrahend << "-" << minuend <<  "=" << minDifference;
}