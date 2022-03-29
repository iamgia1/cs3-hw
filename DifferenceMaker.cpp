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
    int subtrahend;
    int minuend;
    int maxDifference = 0;
    for (int i = 0; i < numbers.size() - 1; i++) {
        // creating the difference by every 2 numbers that are next to each other in the vector
        int Difference = numbers.at(i) - numbers.at(i + 1);
        // checking to see if that difference is smaller than the max product
        if (Difference < maxDifference) {
            maxDifference = Difference;
            minuend = numbers.at(i);
            subtrahend = numbers.at(i + 1);
        }
    }
    cout << minuend << "-" << subtrahend <<  "=" << maxDifference;
}