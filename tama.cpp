#include <iostream>
#include <algorithm>
#include <chrono>
#include <limits>


using namespace std;

void updateHunger(int& hunger, time_t& lastUpdate) {
    time_t now = time(nullptr);

    while (now - lastUpdate >= 10) {
        if (hunger > 0) {
            hunger--;
        }
        lastUpdate += 10;
    }
}

int main() {
    cout << "\n\n\n\nThis is your Tamagotchi!!!!\n\n";
    cout << " _._     _,-'\"\"`-._\n"
         << "(,-.`._,'(       |\\-/|\n"
         << "    `-.-' \\ )-`( , o o)\n"
         << "          `-    \\`_`\"'- \n\n";

    int hunger = 5;
    auto lastDecay = chrono::steady_clock::now();

    time_t lastUpdate = time(nullptr);

    while (true) {
        updateHunger(hunger, lastUpdate);

        cout << "\n1. Check hunger\n"
             << "2. Feed\n"
             << "3. Quit\n"
             << "Choose an option: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter 1, 2, or 3.\n";
            continue;
        }

        if (choice == 1) {
            updateHunger(hunger, lastUpdate);
            cout << "Current hunger: " << hunger << "/5\n";
        } else if (choice == 2) {
            updateHunger(hunger, lastUpdate);
            hunger = min(5, hunger + 1);
            cout << "You fed your Tamagotchi! Hunger: "
                 << hunger << "/5\n";
                 cout << " _._     _,-'\"\"`-._\n"
                     << "(,-.`._,'(       |\\-/|      THANK YOU!\n"
                     << "    `-.-' \\ )-`( , o o)\n"
                     << "          `-    \\`_`\"'- \n\n";
        } else if (choice == 3) {
            break;
        } else {
            cout << "Please choose 1, 2, or 3.\n";
        }
        if(hunger == 0) {
            cout << "Your Tamagotchi has starved! Game over.\n";
            cout << " _._     _,-'\"\"`-._\n"
         << "(,-.`._,'(       |\\-/|       NOO!!\n"
         << "    `-.-' \\ )-`( , x x)\n"
         << "          `-    \\`_`\"'- \n\n";
            break;
        }
    }
    while(true){
    cout << "Thanks for playing!\n";
    
        cout << "-----------------------------------------------\n"
            << "----------------------------------------------------\n"
            << "--------------------------------------------------------\n"
            << "----------game over------------------------------------\n";
              cout << R"(⠀      ,-=-.       ______     _
        /  +  \     />----->  _|1|_
        | ~~~ |    // -/- /  |_ H _|
        |R.I.P|   //  /  /     |S|
    \vV,,|_____|V,//_____/VvV,v,|_|/,,vhjwv/,)";

    
    cout << "\nquit the game? (y/n): ";
    char quitChoice;
    cin >> quitChoice;
    if (quitChoice == 'y' || quitChoice == 'Y') {
        break;
    }
    }

    return 0;
}