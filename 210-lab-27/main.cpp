//Kit Pollinger
// 210 - Lab - 27 | Villager Map
//std::Map Demo Code
#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

//tuple storing friendship level, species, and catchphrase
using VillagerInfo = tuple<int, string, string>;

// Function declarations
void displayVillagers(const map<string, VillagerInfo>& villagerData);
void addVillager(map<string, VillagerInfo>& villagerData);
void deleteVillager(map<string, VillagerInfo>& villagerData);
void increaseFriendship(map<string, VillagerInfo>& villagerData);
void decreaseFriendship(map<string, VillagerInfo>& villagerData);
void searchVillager(const map<string, VillagerInfo>& villagerData);

int main() {
    map<string, VillagerInfo> villagerData;
    int choice = 0;

    while (choice != 6) {
        cout << "\nMenu:\n";
        cout << "1. Add Villager\n";
        cout << "2. Delete Villager\n";
        cout << "3. Increase Friendship\n";
        cout << "4. Decrease Friendship\n";
        cout << "5. Search for Villager\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();  // Ignore the newline character after input

        switch (choice) {
            case 1:
                addVillager(villagerData);
                break;
            case 2:
                deleteVillager(villagerData);
                break;
            case 3:
                increaseFriendship(villagerData);
                break;
            case 4:
                decreaseFriendship(villagerData);
                break;
            case 5:
                searchVillager(villagerData);
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        // Display current villagers after each operation
        if (choice != 6) {
            displayVillagers(villagerData);
        }
        else {
            displayVillagers(villagerData);
        }
    }

    return 0;
}

void displayVillagers(const map<string, VillagerInfo>& villagerData) {
    cout << "\nVillager details:\n";
    for (const auto& pair : villagerData) {
        const string& name = pair.first;
        const VillagerInfo& info = pair.second;
        int friendshipLevel;
        string species, catchphrase;
        tie(friendshipLevel, species, catchphrase) = info;

        cout << name << " [" << friendshipLevel << ", " << species << ", " << catchphrase << "]\n";
    }
}
void addVillager(map<string, VillagerInfo>& villagerData) {
    string name, species, catchphrase;
    int friendshipLevel;

    cout << "Villager name: ";
    getline(cin, name);
    cout << "Friendship level (0-10): ";
    cin >> friendshipLevel;
    cin.ignore();  // Ignore the newline character after input
    cout << "Species: ";
    getline(cin, species);
    cout << "Catchphrase: ";
    getline(cin, catchphrase);

    villagerData[name] = make_tuple(friendshipLevel, species, catchphrase);
    cout << name << " added.\n";
}
void deleteVillager(map<string, VillagerInfo>& villagerData) {
    string name;
    cout << "Villager name to delete: ";
    getline(cin, name);

    if (villagerData.erase(name)) {
        cout << name << " deleted.\n";
    } else {
        cout << name << " not found.\n";
    }
}
void increaseFriendship(map<string, VillagerInfo>& villagerData) {
    string name;
    cout << "Villager name to increase friendship: ";
    getline(cin, name);

    auto it = villagerData.find(name);
    if (it != villagerData.end()) {
        int& friendshipLevel = get<0>(it->second);
        if (friendshipLevel < 10) friendshipLevel++;
        cout << name << "'s friendship level increased to " << friendshipLevel << ".\n";
    } else {
        cout << name << " not found.\n";
    }
}
void decreaseFriendship(map<string, VillagerInfo>& villagerData) {
    string name;
    cout << "Villager name to decrease friendship: ";
    getline(cin, name);

    auto it = villagerData.find(name);
    if (it != villagerData.end()) {
        int& friendshipLevel = get<0>(it->second);
        if (friendshipLevel > 0) friendshipLevel--;
        cout << name << "'s friendship level decreased to " << friendshipLevel << ".\n";
    } else {
        cout << name << " not found.\n";
    }
}
void searchVillager(const map<string, VillagerInfo>& villagerData) {
    string name;
    cout << "Villager name to search for: ";
    getline(cin, name);

    auto it = villagerData.find(name);
    if (it != villagerData.end()) {
        int friendshipLevel;
        string species, catchphrase;
        tie(friendshipLevel, species, catchphrase) = it->second;
        cout << "Found " << name << ": [" << friendshipLevel << ", " << species << ", " << catchphrase << "]\n";
    } else {
        cout << name << " not found.\n";
    }
}
