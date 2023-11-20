#include<iostream>
#include<vector>
using namespace std;

class RocketLauncher {
private:
    string mesto;
    vector<string> rockets;

public:
    RocketLauncher(string mesto) : mesto(mesto) {}

    void NewRocket(string nameRocket) {
        rockets.push_back(nameRocket);
        cout << "New rocket added, rocket name: " << nameRocket << endl;
        for (unsigned i = 0; i < rockets.size(); i++) {
            cout << rockets[i] << endl;
        }
    }

    string RocketLaunch(string nameRocket) {
        for (unsigned i = 0; i < rockets.size(); i++) {
            if (nameRocket == rockets[i]) {
                if (rockets.size() == 1) {
                    cout << "Rocket launched, rocket name: " << nameRocket << endl;
                    rockets.erase(rockets.begin());
                }
                else {
                    cout << "Rocket launched, rocket name: " << nameRocket << endl;
                    rockets.erase(rockets.begin() + i);
                    return "";
                }
            }
        }
    }

    void ChangeLocation(string location) {
        mesto = location;
        cout << "Successfully changed location to: " << location << endl;
    }
};

int main() {
    string mesto = "";
    RocketLauncher launchRocket(mesto);

    while (true) {
        char action;
        cout << "Action\n1. New rocket\n2. Change location\n3. Launch rocket\n";
        cout << "P.s: action input a letter";
        cin >> action;
        cout << endl;

        switch (action) {
        case 'n': {
            string newRocket;
            cout << "Name rocket: ";
            cin >> newRocket;
            cout << endl;
            launchRocket.NewRocket(newRocket);
            break;
        }
        case 'l': {
            string nameRocket;
            cout << "Name rocket: ";
            cin >> nameRocket;
            launchRocket.RocketLaunch(nameRocket);
            break;
        }
        case 'c': {
            string newLocation;
            cout << "New location: ";
            cin >> newLocation;
            cout << endl;
            launchRocket.ChangeLocation(newLocation);
            break;
        }
        }
    }

    return 0;
}
