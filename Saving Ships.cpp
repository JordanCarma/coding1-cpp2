// Jordan Adrian Covarrubias
// Brian Foster
// Coding 1
// 5/3/2025

// Saving Ships

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Ship {
private:
    string name;
    double fuel;
    string shipType;

public:
    // This is for Constructor
    Ship(string n, double f, string st) : name(n), fuel(f), shipType(st) {}

    // This is for Getters
    string getName() const { return name; }
    double getFuel() const { return fuel; }
    string getShipType() const { return shipType; }
};

// This would help the function to write ship details into a file
void writeShipToFile(const Ship& givenShip) {
    ofstream outFile("ship_data.txt");                            // This would help create the file or overwrites the file

    if (outFile.is_open()) {
        outFile << "Ship Name: " << givenShip.getName() << endl;
        outFile << "Fuel Level: " << givenShip.getFuel() << endl;
        outFile << "Ship Type: " << givenShip.getShipType() << endl;

        cout << "Ship data successfully written to file!" << endl;
        outFile.close();
    }
    else {
        cerr << "Unable to open file for writing!" << endl;
    }
}

int main() {
    // This would help create the ship object
    Ship myShip("Thruster Master81", 85.5, "Frighters");

    // This would help write the ship data into the file
    writeShipToFile(myShip);

    return 0;
}