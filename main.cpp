#include <iostream>
#include "algorithms.h"

using namespace std;

void showBanner() {

    cout << "\n";
    cout << "=============================================\n";
    cout << "              ALGOSPHERE AI\n";
    cout << "     Intelligent DSA System & Assistant\n";
    cout << "=============================================\n";
}

void showMenu() {

    cout << "\n";
    cout << "--------------- MAIN MENU ------------------\n";

    cout << "1.  Array Analyzer\n";
    cout << "2.  Searching\n";
    cout << "3.  Sorting\n";
    cout << "4.  Two Pointer\n";
    cout << "5.  Sliding Window\n";
    cout << "6.  Hashing\n";
    cout << "7.  Linked List\n";
    cout << "8.  Stack\n";
    cout << "9.  Queue\n";
    cout << "10. Recursion\n";
    cout << "11. Complexity Analyzer\n";
    cout << "12. AI DSA Assistant\n";
    cout << "13. Exit\n";

    cout << "---------------------------------------------\n";
    cout << "Enter your choice: ";
}

int main() {

    showBanner();

    int choice;

    do {

        showMenu();

        cin >> choice;

        switch (choice) {

            case 1:
                arrayAnalyzer();
                break;

            case 2:
                searchingModule();
                break;

            case 3:
                sortingModule();
                break;

            case 4:
                twoPointerModule();
                break;

            case 5:
                slidingWindowModule();
                break;

            case 6:
                hashingModule();
                break;

            case 7:
                linkedListModule();
                break;

            case 8:
                stackModule();
                break;

            case 9:
                queueModule();
                break;

            case 10:
                recursionModule();
                break;

            case 11:
                showComplexity();
                break;

            case 12:
                aiAssistant();
                break;

            case 13:
                cout << "\nExiting AlgoSphere AI...\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 13);

    return 0;
}