#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main() {
    vector<int> numbers;
    mt19937 rand(time(nullptr));
    uniform_int_distribution<int> dist(1, 100);
    for (int i = 0; i < 20; i++) {
        numbers.insert(numbers.end(), dist(rand));
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

    for (int number : numbers) {
        cout << number << " ";
    }
}