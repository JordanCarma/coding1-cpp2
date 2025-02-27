// Jordan A. Covarrubias
// Brian Foster
// Introduction to Digital Sounds
// 2/25/2025

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 

using namespace std;

int main() {
    srand(time(0));

    string favGames[10] = { "" }; 
    string input;
    int gameCount = 0; 

    while (true) {
        cout << "\nPlease enter a Command (Add, Edit, Remove, Show, Quit): ";
        getline(cin, input);

        if (input == "Add") {
            if (gameCount < 10) {
                cout << "Enter the name of the game to add to your favorite list: ";
                string gameName;
                getline(cin, gameName);
                favGames[gameCount] = gameName;
                gameCount++;
                cout << "The game has been added!\n";
            }
            else {
                cout << "The list is full! You cannot add more games.\n";
            }
        }
        else if (input == "Edit") {
            cout << "Enter the name of the game you want to edit (0-" << gameCount - 1 << "): ";
            int index;
            cin >> index;
            cin.ignore();

            if (index >= 0 && index < gameCount && favGames[index] != "") {
                cout << "Enter the new name for the game: ";
                string newName;
                getline(cin, newName);
                favGames[index] = newName;
                cout << "New game has been updated!\n";
            }
            else {
                cout << "Invalid name or empty slot. Please try again.\n";
            }
        }
        else if (input == "Remove") {
            cout << "Enter the name of the game you want to remove: ";
            string gameToRemove;
            getline(cin, gameToRemove);

            bool found = false;
            for (int i = 0; i < 10; i++) {
                if (gameToRemove == favGames[i]) {
                    favGames[i] = ""; 
                    cout << "The game has been Removed!\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "The Game you entered is not found in the list.\n";
            }
        }
        else if (input == "Show") {
            cout << "\n--- Your Favorite Games ---\n";
            for (int i = 0; i < 10; i++) {
                if (favGames[i] != "") {
                    cout << i << ". " << favGames[i] << "\n";
                }
            }
        }
        else if (input == "Quit") {
            cout << "Okie Dokie!!! Later Dude!!!\n";
            break;
        }
        else {
            cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}