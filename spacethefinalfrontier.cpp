#include<iostream>
#include<string>

using namespace std;

class Ship

{
public:
   Ship();

    void reportStatus() const;
    int fuelLevel{};
    string name = "Barthold";
private:
};

Ship::Ship()
{
    fuelLevel = 100;
}

void Ship::reportStatus() const
{
    cout << "Welcome aboard this is captain " << name << " reporting our fuel level is " << fuelLevel << "\n";
}

int main()
{
    Ship landia;
    Ship noland;

    cout << "landia ship fuel level is at " << landia.fuelLevel << "\n";
    cout << "noland ship fuel level is at " << noland.fuelLevel << "\n";
    noland.fuelLevel = 80;
    cout << "noland ship fuel level is at " << noland.fuelLevel << "\n";

    landia.fuelLevel = 60;
    cout << "landia ship fuel level is at " << landia.fuelLevel << "\n";
    noland.reportStatus();
    landia.reportStatus();

    return 0;
}