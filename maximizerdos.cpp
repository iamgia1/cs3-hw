#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main() {
    vector < int > numbers;
    string input;
    cout << "Enter in any amount of numbers separated by new lines. Enter -1 to stop." << "\n";
    // creating a bool to know if the user is done entering the numbers
    bool done = false;
    while (!done) {
        cin >> input;
        if (input == "-1") {
            done = true;
        } else {
            numbers.insert(numbers.end(), stoi(input));
        }
    }
    int multiplicand;
    int multiplier;
    int maxProduct = 0;
    for (int i = 0; i < numbers.size() - 1; i++) {
        // creating the product by every 2 numbers that are next to each other in the vector
        int product = numbers.at(i) * numbers.at(i + 1);
        // checking to see if that product is greater than the max product
        if (product > maxProduct) {
            maxProduct = product;
            multiplier = numbers.at(i);
            multiplicand = numbers.at(i + 1);
        }
    }
    cout << multiplicand << " x " << multiplier << " = " << maxProduct;
}