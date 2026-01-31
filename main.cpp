// ============================================================================
// FILE: main.cpp
// PURPOSE: Main program entry point and menu system
// ============================================================================

#include "DeadlockSys.h"

void displayMainMenu() {
    cout << "\n";
    cout << "========================================================================\n";
    cout << "          DEADLOCK DETECTION & RECOVERY SIMULATOR\n";
    cout << "========================================================================\n";

    cout << "\n1. Run Complete Simulation (All Phases)\n";
    cout << "2. Display Resource Allocation Graph\n";
    cout << "3. Run Safety Algorithm (Check Safe State)\n";
    cout << "4. Request Resources (Banker's Algorithm)\n";
    cout << "5. Run Deadlock Detection\n";
    cout << "6. Display System State\n";
    cout << "7. Exit\n";
    cout << "\n========================================================================\n";
    cout << "Enter choice: ";
}

int main() {

    system("color 70");

  

    int numProcesses, numResources;

    cout << "\nSYSTEM CONFIGURATION:\n";
    cout << "Enter number of processes: ";
    cin >> numProcesses;

    cout << "Enter number of resource types: ";
    cin >> numResources;

    DeadlockSystem system(numProcesses, numResources);
    system.inputData();

    cin.ignore();

    int choice;
    do {
        displayMainMenu();
        cin >> choice;
        cin.ignore();

        vector<int> deadlockedProcesses;

        switch (choice) {
        case 1:
            system.runCompleteSimulation();
            break;

        case 2:
            system.displayRAG();
            cout << "\nPress Enter to continue...";
            cin.get();
            break;

        case 3:
            system.bankersAlgorithm();
            cout << "\nPress Enter to continue...";
            cin.get();
            break;

        case 4:  // Resource Request (NEW!)
        {
            int process;
            cout << "\n=== RESOURCE REQUEST ===\n";
            cout << "Enter process number (0-" << (numProcesses - 1) << "): ";
            cin >> process;


            // Validate process number
            if (process < 0 || process >= numProcesses) {
                cout << " Invalid process number!\n";
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            }

            vector<int> request(numResources);
            cout << "Enter resource request (" << numResources << " values, space-separated): ";
            for (int j = 0; j < numResources; j++) {
                cin >> request[j];
            }
            cin.ignore();

            system.requestResources(process, request);
            cout << "\nPress Enter to continue...";
            cin.get();
        }
        break;

        case 5:
            system.detectDeadlock(deadlockedProcesses);
            if (!deadlockedProcesses.empty()) {
                cout << "\nWould you like to attempt recovery? (y/n): ";
                char recover;
                cin >> recover;
                cin.ignore();
                if (recover == 'y' || recover == 'Y') {
                    cout << "\n1. Preemption\n2. Rollback\n3. Termination\n";
                    cout << "Choice: ";
                    int recChoice;
                    cin >> recChoice;
                    cin.ignore();

                    if (recChoice == 1)
                        system.recoverByPreemption(deadlockedProcesses);
                    else if (recChoice == 2)
                        system.recoverByRollback(deadlockedProcesses);
                    else if (recChoice == 3)
                        system.recoverByTermination(deadlockedProcesses);

                 
                }
            }
            cout << "\nPress Enter to continue...";
            cin.get();
            break;

        case 6:
            system.displayMatrices();
            cout << "\nPress Enter to continue...";
            cin.get();
            break;

        case 7:
            cout << "\n========================================================================\n";
            cout << "  Thank you for using the Deadlock Detection Simulator!\n";
            cout << "========================================================================\n\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
            cout << "\nPress Enter to continue...";
            cin.get();
        }

    } while (choice != 7);  // ✅ FIXED: Was != 6, now != 7

    return 0;
}