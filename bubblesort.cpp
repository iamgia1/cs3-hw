#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main() {
    vector < int > numbers;
    mt19937 rand(time(nullptr));
    uniform_int_distribution < int > dist(1, 100);
    for (int i = 0; i < 20; i++) {
        numbers.insert(numbers.end(), dist(rand));
        cout << numbers.at(i) << " ";
    }
    cout << "\n";

    for (int i = numbers.size(); i >= 1; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
}