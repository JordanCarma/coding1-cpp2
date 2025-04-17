// Jordan Adrian Covarrubias
// Mr. Foster
// Coding 1
// 4/16/2025

// 12 Week Assignment

#include <iostream>
#include <string>

using namespace std;

class Human {
protected:
    string Name;
    int Health;
    int Damage;

public:
    Human(string name, int health, int baseDamage)
        : Name(name), Health(health), Damage(baseDamage) {
    }

    void SayHello() {
        cout << "Aye what's good, my name is " << Name << "!" << endl;
    }

    void SetHealth(int byAmount) {
        Health = byAmount;
    }

    void SetDamage(int givenDamage) {
        Damage = givenDamage;
    }

    int GetHealth() {
        return Health;
    }

    int GetDamage() {
        return Damage;
    }

    string GetName() {
        return Name;
    }
};

class Jordan : public Human {
private:
    int axeSwingPower;
    int energy;

public:
    Jordan(string name, int health, int baseDamage, int swingPower, int energyLevel)
        : Human(name, health, baseDamage), axeSwingPower(swingPower), energy(energyLevel) {
    }

    int GetTotalDamage() {
        if (energy >= 5) {
            return Damage + axeSwingPower;
        }
        return Damage; 
    }

    // This will help implement the consumption of energy swinging his axe
    void SwingAxe() {
        if (energy >= 5) {
            cout << Name << " swings their axe with mighty power!" << endl;
            energy -= 5;
            cout << "Energy exerted! Remaining energy: " << energy << endl;
        }
        else {
            cout << Name << " is too tired to swing the axe powerfully." << endl;
        }
    }

    // This will help implement the restoration of energy
    void Rest(int amount) {
        energy += amount;
        if (energy > 100) energy = 100;                           // This will have a capacity at 100
        cout << Name << " rests and gains " << amount << " energy. Total energy: " << energy << endl;
    }

    int GetEnergy() {
        return energy;
    }

    int GetAxeSwingPower() {
        return axeSwingPower;
    }
};

int main() {
    Human bob("Bob", 15, 3);
    bob.SayHello();
    cout << bob.GetName() << "'s health: " << bob.GetHealth() << endl;
    cout << bob.GetName() << "'s damage: " << bob.GetDamage() << endl << endl;

    Jordan jordan("Jordan", 20, 4, 10, 30);
    jordan.SayHello();
    cout << jordan.GetName() << "'s base damage: " << jordan.GetDamage() << endl;
    cout << jordan.GetName() << "'s axe swing power: " << jordan.GetAxeSwingPower() << endl;
    cout << jordan.GetName() << "'s current energy: " << jordan.GetEnergy() << endl << endl;

    cout << "Jordan attempts to swing his axe..." << endl;
    jordan.SwingAxe();
    cout << "Total damage Jordan can deal now: " << jordan.GetTotalDamage() << endl << endl;

    for (int i = 0; i < 3; i++) {
        jordan.SwingAxe();
        cout << "Energy after swing " << i + 1 << ": " << jordan.GetEnergy() << endl;
    }

    jordan.Rest(15);
    jordan.SwingAxe();

    return 0;
}