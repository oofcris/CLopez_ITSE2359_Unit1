#include <iostream>
#include <string>
using namespace std;

int main()
{
    int choice;
    bool keepRunning = true;

    // Character data
    string name;
    int charClass; // 1-Warrior, 2-Mage, 3-Rogue, 4-Cleric
    int strength, intelligence, dexterity, constitution;
    bool characterCreated = false;

    do
    {
        cout << "\n=== GAMESTAT CHARACTER MANAGER ===" << endl;
        cout << "1. Create New Character" << endl;
        cout << "2. View Character Stats" << endl;
        cout << "3. Calculate Combat Ratings" << endl;
        cout << "4. Level Up Character" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {

        // ================= CREATE CHARACTER =================
        case 1:
            cout << "\nEnter Character Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "\nChoose Character Class:" << endl;
            cout << "1. Warrior" << endl;
            cout << "2. Mage" << endl;
            cout << "3. Rogue" << endl;
            cout << "4. Cleric" << endl;
            cout << "Enter choice: ";
            cin >> charClass;

            // Class bonuses
            switch (charClass)
            {
            case 1: // Warrior
                strength += 2;
                constitution += 2;
                break;
            case 2: // Mage
                intelligence += 3;
                break;
            case 3: // Rogue
                dexterity += 3;
                break;
            case 4: // Cleric
                intelligence += 1;
                constitution += 2;
                break;
            default:
                cout << "Invalid class selected. No bonuses applied.\n";
            }

            characterCreated = true;
            cout << "\nCharacter created successfully!" << endl;
            break;

        // ================= VIEW STATS =================
        case 2:
            if (!characterCreated)
            {
                cout << "\nNo character created yet!" << endl;
            }
            else
            {
                cout << "\n=== CHARACTER STATS ===" << endl;
                cout << "Name: " << name << endl;
                cout << "Strength: " << strength << endl;
                cout << "Intelligence: " << intelligence << endl;
                cout << "Dexterity: " << dexterity << endl;
                cout << "Constitution: " << constitution << endl;
            }
            break;

        case 3:
            cout << "\n[Calculate Ratings - Coming Soon]" << endl;
            break;

        case 4:
            cout << "\n[Level Up - Coming Soon]" << endl;
            break;

        case 5:
            cout << "\nThanks for using GameStat! Goodbye!" << endl;
            keepRunning = false;
            break;

        default:
            cout << "\nInvalid choice! Please enter 1-5." << endl;
        }

    } while (keepRunning);

    return 0;
}
