#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to GuessTheNumber game!" << endl;
    cout << "Guess a number between 1 and 100." << endl;

    while (true) {
        cout << "Choose difficulty level: " << endl;
        cout << "1 - Easy\n2 - Medium\n3 - Hard\n0 - Exit\n";

        int difficultyChoice;
        cout << "Enter your choice: ";
        cin >> difficultyChoice;

        srand(time(0));
        int secretNumber = rand() % 100 + 1;
        int playerChoice;
        int attempts;

        switch (difficultyChoice) {
            case 1:
                attempts = 10;
                cout << "You have 10 chances to guess the number." << endl;
                break;
            case 2:
                attempts = 7;
                cout << "You have 7 chances to guess the number." << endl;
                break;
            case 3:
                attempts = 5;
                cout << "You have 5 chances to guess the number." << endl;
                break;
            case 0:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
        }

        for (int i = 0; i < attempts; i++) {
            cout << "Enter your guess: ";
            cin >> playerChoice;

            if (playerChoice == secretNumber) {
                cout << "Congratulations! You guessed the number!" << endl;
                break;
            } else if (playerChoice > secretNumber) {
                cout << "Wrong guess. Try a smaller number." << endl;
            } else {
                cout << "Wrong guess. Try a bigger number." << endl;
            }

            cout << "Chances left: " << attempts - i - 1 << endl;
        }

        if (playerChoice != secretNumber) {
            cout << "Sorry, you didn't guess the number. It was " << secretNumber << endl;
        }
    }

    return 0;
}
