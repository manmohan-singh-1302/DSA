#include <iostream>
#include <iomanip>

using namespace std;

// Structure to represent a country
struct Country {
    string name;
    int gold;
    int silver;
    int bronze;
};

// Function to display the table of countries
void printTable(const Country countries[], int size) {
    cout << left << setw(3) << "N" << setw(15) << "Country" << right << setw(10) << "Gold" << setw(10) << "Silver" << setw(10) << "Bronze" << setw(10) << "Total" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (int i = 0; i < size; ++i) {
        const Country& country = countries[i];
        cout << left << setw(3) << i + 1 << setw(15) << country.name << right << setw(10) << country.gold << setw(10) << country.silver << setw(10) << country.bronze << setw(10) << (country.gold + country.silver + country.bronze) << endl;
    }
}

// Function to update the medal counts
// Function to update the medal counts
void updateMedalCounts(Country countries[], int size, int countryNumber, char medalType){
    if (countryNumber >= 1 && countryNumber <= size) {
        Country& country = countries[countryNumber - 1];
        if (medalType == 'G') {
            country.gold++;
        } else if (medalType == 'S') {
            country.silver++;
        } else if (medalType == 'B') {
            country.bronze++;
        }
    }
}


// Function to determine the total number of medals awarded
int totalMedalsAwarded(const Country countries[], int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        const Country& country = countries[i];
        total += (country.gold + country.silver + country.bronze);
    }
    return total;
}

// Function to determine which country has the most gold medals
Country countryWithMostGold(const Country countries[], int size) {
    int maxGold = 0;
    Country mostGoldCountry;
    for (int i = 0; i < size; ++i) {
        const Country& country = countries[i];
        if (country.gold > maxGold) {
            maxGold = country.gold;
            mostGoldCountry = country;
        }
    }
    return mostGoldCountry;
}

int main() {
    // Initialize array of countries
    Country countries[8] = {
            {"Australia", 11, 14, 12},
            {"Canada", 5, 0, 1},
            {"China", 9, 14, 11},
            {"Great Britain", 8, 4, 8},
            {"Japan", 8, 10, 10},
            {"Netherlands", 7, 6, 7},
            {"Russia", 6, 10, 8},
            {"USA", 10, 6, 7}
    };
    int choice;
    char medalType;
    int totalMedals = totalMedalsAwarded(countries, 8);
    Country mostGoldCountry = countryWithMostGold(countries, 8);

    while(true) {
        printTable(countries, 8);
        cout << "Enter the country number (0 to quit): ";
        cin >> choice;
        if (choice == 0) {
            break;
        }
        cout << "Enter the medal type (G for gold, S for silver, B for bronze): ";
        cin >> medalType;
        updateMedalCounts(countries, 8, choice, medalType);
    }

    cout << "Total medals awarded to all countries: " << totalMedals << endl;
    cout << "Country with the most gold medals: " << mostGoldCountry.name << " - " << mostGoldCountry.gold << " gold medals" << endl;

    return 0;
}