#include "process_manager.h"
using namespace std;
#include <iostream>

void processManager::createProcess(string name, int arrival_time, int burst_time, int priority){
    process new_process;
    new_process.pid = next_pid++;
    new_process.name = name;
    new_process.state = "ready";
    new_process.arrival_time = arrival_time;
    new_process.burst_time = burst_time;
    new_process.remaining_time = burst_time;
    new_process.priority = priority;
    processes.push_back(new_process);
    cout << "Process created: " << name << " (PID: " << new_process.pid << ")" << endl;
}

void processManager::listProcesses(){
    cout << "PID\tName\tState\tArrival Time\tBurst Time\tRemaining Time\tPriority" << endl;
    for(const auto& p : processes){
        cout << p.pid << "\t" << p.name << "\t" << p.state << "\t" << p.arrival_time << "\t" << p.burst_time << "\t" << p.remaining_time << "\t" << p.priority << endl;
    }
}

void processManager::terminateProcess(int pid){
    for(auto it = processes.begin(); it != processes.end(); ++it){
        if(it->pid == pid){
            cout << "Terminating process: " << it->name << " (PID: " << it->pid << ")" << endl;
            processes.erase(it);
            return;
        }
    }
    cout << "Process with PID " << pid << " not found." << endl;
}

void processManager::changePriority(int pid, int new_priority){
    for(auto& p : processes){
        if(p.pid == pid){
            cout << "Changing priority of process: " << p.name << " (PID: " << p.pid << ") from " << p.priority << " to " << new_priority << endl;
            p.priority = new_priority;
            return;
        }
    }
    cout<<"State change failed: Process with PID "<<pid<<" not found."<<endl;
}

void processManager::changeState(int pid, string new_state){
    for(auto& p : processes){
        if(p.pid == pid){
            cout << "Changing state of process: " << p.name << " (PID: " << p.pid << ") from " << p.state << " to " << new_state << endl;
            p.state = new_state;
            return;
        }
    }
    cout<<"State change failed: Process with PID "<<pid<<" not found."<<endl;
}
