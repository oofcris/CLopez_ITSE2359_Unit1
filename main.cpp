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

            while (str < 1 || str > 20)
            {
                cout << "Enter Strength (1-20): ";
                cin >> str;
            }
            while (intl < 1 || intl > 20)
            {
                cout << "Enter Intelligence (1-20): ";
                cin >> intl;
            }
            while (dex < 1 || dex > 20)
            {
                cout << "Enter Dexterity (1-20): ";
                cin >> dex;
            }
            while (con < 1 || con > 20)
            {
                cout << "Enter Constitution (1-20): ";
                cin >> con;
            }

            switch (classChoice)
            {
            case 1:
                str += 2;
                break; // Warrior
            case 2:
                intl += 2;
                break; // Mage
            case 3:
                dex += 2;
                break; // Rogue
            case 4:
                con += 2;
                break; // Cleric
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
            cout << "  Strength:     " << str << endl;
            cout << "  Intelligence: " << intl << endl;
            cout << "  Dexterity:    " << dex << endl;
            cout << "  Constitution: " << con << endl;

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
            hp = (con * 10) + (level * 5);
            mp = (intl * 10) + (level * 3);

            // Class bonuses
            if (charClass == "Warrior")
                hp += 20;
            if (charClass == "Mage")
                mp += 30;

            // Attack Power of the classes
            if (charClass == "Warrior")
                attack = str * 1.5;
            else if (charClass == "Mage")
                attack = intl * 1.3;
            else if (charClass == "Rogue")
                attack = dex * 1.4;
            else if (charClass == "Cleric")
                attack = (str + intl) * 0.8;

            // Defense of the character
            defense = (con + dex) / 2;

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

            cout << "\n LEVEL UP " << endl;
            cout << "Before Level: " << level << endl;

            level++;
            str++;
            intl++;
            dex++;
            con++;

            cout << "After Level: " << level << endl;

            // Recalculate stats
            hp = (con * 10) + (level * 5);
            mp = (intl * 10) + (level * 3);
            defense = (con + dex) / 2;

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
