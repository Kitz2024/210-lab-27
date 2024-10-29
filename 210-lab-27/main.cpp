// Kit Pollinger
//  210 - Lab - 27 | Villager Map
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

// Tuple to store Villager Data: Friendship level , species and catchphrases
typedef tuple<int, string, string> VillagerData;
typedef map<string, VillagerData> VillagerMap;

// print details of all villagers
void printVillagers(const VillagerMap& villagers)
{
    cout << "Villager details \n";
    for (const auto& [name, data] : villagers)
    {
        const auto& [friendship, species, catchphrase] = data;
        cout << name << "[" << friendship << ", " << species << ", " << catchphrase << "]\n";
    }
}

int main()
{

    // declarations
    VillagerMap villagers;

    while (true){
        cout << "\nMenu\n";
        cout << "1. Add Villager\n";
        cout << "2. Delete Villagern";
        cout << "3. Increase Friendship\n";
        cout << "4. Decrease Friendship\n";
        cout << "5. Search for Villager\n";
        cout << "6. Exit\n";
        cout << "Enter your Choice: ";
        int choice;
        cin >> choice;

        switch (choice){
            case 1: {
                string name, species, catchphrase;
                int friendship;
                cout << "Enter Villager name: ";
                cin >> name;
                cout << "Enter friendship level (0-10): ";
                cin >> friendship;
                cout << "Enter species: ";
                cin >> species;
            }
        }
    }

    /*

    //std::Map Demo Code

       // declarations
     map<string, vector<string>> villagerColors;
    / // insert elements into the map
     // note how the right-hand side of the assignment are the vector elements
     villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
     villagerColors["Raymond"] = {"Black", "Gray", "White"};
     villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

     // access the map using a range-based for loop
     cout << "Villagers and their favorite colors (range-based for loop):" << endl;
     for (auto pair : villagerColors) {
         cout << pair.first << ": ";
         for (auto color : pair.second)
             cout << color << " ";
         cout << endl;
     }

     // access the map using iterators
     cout << "\nVillagers and their favorite colors (iterators):" << endl;
     for (map<string, vector<string>>::iterator it = villagerColors.begin();
                                                it != villagerColors.end(); ++it) {
         cout << it->first << ": ";
         for (auto color : it->second) {
             cout << color << " ";
         }
         cout << endl;
     }

     // delete an element
     villagerColors.erase("Raymond");

     // search for an element using .find() to avoid errors
     string searchKey = "Audie";
     auto it = villagerColors.find(searchKey);
     if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                        // if searchKey is not found
         cout << "\nFound " << searchKey << "'s favorite colors: ";
         for (auto color : it->second)  // range loop to traverse the value/vector
             cout << color << " ";
         cout << endl;
     } else
         cout << endl << searchKey << " not found." << endl;

     // report size, clear, report size again to confirm map operations
     cout << "\nSize before clear: " << villagerColors.size() << endl;
     villagerColors.clear();
     cout << "Size after clear: " << villagerColors.size() << endl;
 */
    return 0;
}