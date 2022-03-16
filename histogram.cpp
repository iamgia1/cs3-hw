#include <iostream>
#include<random>
#include<ctime>
#include<vector>

using namespace std;

int main() {
    mt19937 generator(time(nullptr));

    int totalNumbers;
    string UI = " ";

    vector < string > histogramSheet = {
            "0-9",
            "10-19",
            "20-29",
            "30-39",
            "40-49",
            "50-59",
            "60-69",
            "70-79",
            "80-89",
            "90-99",
            "100"
    };
    // number of stars that going to add
    vector < int > histogramCount = {
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
    };
    // user enter which histogram they want
    cout << "Enter Distribution, 1: Normal, 2: Uniform, 3: Geometric:" << endl;
    cin >> UI;
    cout << "Enter how many numbers you want in the distribution (0-99)" << endl;
    cin >> totalNumbers;
    if (UI == "1") {
        // TODO fix int dist for normal dist to be larger mean and larger stand dev(randomly generated?)
        // Mean and standard deviation are distribution parameters of Normal distribution. mean=5 and standard deviation=2
        normal_distribution < double > intDist(50, 15);
        for (int i = 0; i < totalNumbers; i++) {
            double val = intDist(generator);
            //  int(val / 10) is matching up to the index of histogramCount
            // ++ is adding one to histogramCount
            histogramCount[int(val / 10)]++;
        }

    } else if (UI == "2") {
        // TODO Create the uniform distribution
    } else if (UI == "3") {
        // TODO Create the geometric distribution
    } else {
        cout << "You fucked up";
    }
    cout << "\n";
    for (int i = 0; i < histogramSheet.size(); i++) {
        cout << histogramSheet[i] << ":\t";
        for (int j = 0; j < histogramCount[i]; j++) {
            cout << "*";
        }
        cout << "\n";

    }
}
