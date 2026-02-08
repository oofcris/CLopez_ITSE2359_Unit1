// Cristian Lopez
// Assignment- Week 4 Gamestat console app Final submission
// This program is a basic console where the player can create and look at their character

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int choice;
    bool keepRunning = true;

    string name, charClass;
    int level = 1;
    int str = 0, intl = 0, dex = 0, con = 0;
    bool characterCreated = false;

    int hp = 0, mp = 0;
    double attack = 0;
    int defense = 0;

    int stats[4] = {str, intl, dex, con};
    string statNames[4] = {"Strength", "Intelligence", "Dexterity", "Constitution"};

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

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input!\n";
            continue;
        }

        switch (choice)
        {

        case 1:
        {
            cout << "\nEnter Character Name: ";
            cin >> name;

            cout << "Choose Class (1-Warrior 2-Mage 3-Rogue 4-Cleric): ";
            int classChoice;
            cin >> classChoice;

            switch (classChoice)
            {
            case 1:
                charClass = "Warrior";
                break;
            case 2:
                charClass = "Mage";
                break;
            case 3:
                charClass = "Rogue";
                break;
            case 4:
                charClass = "Cleric";
                break;
            default:
                cout << "Invalid class selection." << endl;
                break;
            }

            for (int i = 0; i < 4; ++i)
            {
                while (stats[i] < 1 || stats[i] > 20)
                {
                    cout << "Enter " << statNames[i] << " (1-20): ";
                    cin >> stats[i];
                }
            }

            switch (classChoice)
            {
            case 1:
                stats[0] += 2; // Warrior
                break;
            case 2:
                stats[1] += 2; // Mage
                break;
            case 3:
                stats[2] += 2; // Rogue
                break;
            case 4:
                stats[3] += 2; // Cleric
                break;
            }

            characterCreated = true;
            cout << "\nCharacter Created Successfully!" << endl;
            break;
        }

        // Stats
        case 2:
            if (!characterCreated)
            {
                cout << "\nCreate a character first!" << endl;
                break;
            }

            cout << "\n=== CHARACTER PROFILE ===" << endl;
            cout << "Name: " << name << endl;
            cout << "Class: " << charClass << endl;
            cout << "Level: " << level << endl;

            cout << "\nBase Stats:" << endl;
            for (int i = 0; i < 4; ++i)
            {
                cout << "  " << statNames[i] << ": " << stats[i] << endl;
            }

            cout << "\nCombat Stats:" << endl;
            cout << "  Health Points: " << hp << endl;
            cout << "  Mana Points:   " << mp << endl;
            cout << "  Attack Power:  " << attack << endl;
            cout << "  Defense:       " << defense << endl;
            break;

        case 3:
            if (!characterCreated)
            {
                cout << "\nCreate a character first!" << endl;
                break;
            }

            // Hp and Mp
            hp = (stats[3] * 10) + (level * 5);
            mp = (stats[1] * 10) + (level * 3);

            // Class bonuses
            if (charClass == "Warrior")
                hp += 20;
            if (charClass == "Mage")
                mp += 30;

            // Attack power of the classes
            if (charClass == "Warrior")
                attack = stats[0] * 1.5;
            else if (charClass == "Mage")
                attack = stats[1] * 1.3;
            else if (charClass == "Rogue")
                attack = stats[2] * 1.4;
            else if (charClass == "Cleric")
                attack = (stats[0] + stats[1]) * 0.8;

            // Defense of the character
            defense = (stats[3] + stats[2]) / 2;

            cout << "\nCombat Ratings Calculated!" << endl;
            break;

        case 4:
            if (!characterCreated)
            {
                cout << "\nCreate a character first!" << endl;
                break;
            }

            if (level >= 10)
            {
                cout << "\nMax level reached!" << endl;
                break;
            }

            cout << "\nLEVEL UP" << endl;
            cout << "Before Level: " << level << endl;

            level++;

            for (int i = 0; i < 4; ++i)
            {
                stats[i]++;
            }

            cout << "After Level: " << level << endl;

            // Recalculate stats
            hp = (stats[3] * 10) + (level * 5);
            mp = (stats[1] * 10) + (level * 3);
            defense = (stats[3] + stats[2]) / 2;

            cout << "Stats updated!" << endl;
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
