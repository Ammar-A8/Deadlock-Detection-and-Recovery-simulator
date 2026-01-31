// ============================================================================
// FILE: DeadlockSystem.h
// PURPOSE: Class declaration and function prototypes
// ============================================================================

#ifndef DEADLOCK_SYSTEM_H
#define DEADLOCK_SYSTEM_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class DeadlockSystem {
private:
    int numProcesses;
    int numResources;
    vector<vector<int>> allocation;
    vector<vector<int>> max;
    vector<vector<int>> need;
    vector<int> available;
    vector<int> safeSequence;

    // Helper functions
    void waitForUser(const string& message = "Press Enter to continue...");
    void printPhaseSeparator(const string& phaseName);

public:
    // Constructor
    DeadlockSystem(int p, int r);

    // Phase 1: Initialization
    void inputData();
    void displayMatrices();

    // Resource Allocation Graph
    void displayRAG();

    // Phase 2: Banker's Algorithm
    bool bankersAlgorithm();
    // In DeadlockSystem.h - Add to public section

// Resource Request Algorithm (Banker's Algorithm)
    bool requestResources(int process, vector<int> request);

    // Phase 3: Deadlock Detection
    bool detectDeadlock(vector<int>& deadlockedProcesses);

    // Phase 4: Recovery Methods
    void recoverByPreemption(vector<int>& deadlockedProcesses);
    void recoverByRollback(vector<int>& deadlockedProcesses);
    void recoverByTermination(vector<int>& deadlockedProcesses);

    

    // Complete Simulation
    void runCompleteSimulation();
};

#endif