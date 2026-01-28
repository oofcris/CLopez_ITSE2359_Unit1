#include <iostream>
using namespace std;
 
int main() {
    int choice;
    bool keepRunning = true;
    
    // Main menu loop
    do {
        // Display menu
        cout << "\n=== GAMESTAT CHARACTER MANAGER ===" << endl;
        cout << "1. Create New Character" << endl;
        cout << "2. View Character Stats" << endl;
        cout << "3. Calculate Combat Ratings" << endl;
        cout << "4. Level Up Character" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        // Process menu choice
        switch (choice) {
            case 1:
                cout << "\n[Create Character - Coming Soon]" << endl;
                // Your code here
                break;
                
            case 2:
                cout << "\n[View Stats - Coming Soon]" << endl;
                // Your code here
                break;
                
            case 3:
                cout << "\n[Calculate Ratings - Coming Soon]" << endl;
                // Your code here
                break;
                
            case 4:
                cout << "\n[Level Up - Coming Soon]" << endl;
                // Your code here
                break;
                
            case 5:
                cout << "\nThanks for using GameStat! Goodbye!" << endl;
                keepRunning = false;
                break;
                
            default:
                cout << "\nInvalid choice! Please enter 1-5." << endl;
                break;
        }
        
    } while (keepRunning);
    
    return 0;
}