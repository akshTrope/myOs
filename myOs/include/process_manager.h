# pragma once
#include <string>
#include <vector>

struct process{
    int pid;
    std::string name;
    std::string state;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
};
 
class processManager{
private:
    std::vector<process> processes;
    int next_pid=1;
public:
    void createProcess(std::string name, int arrival_time, int burst_time, int priority);
    void listProcesses();
    void terminateProcess(int pid);
    void changePriority(int pid, int new_priority);
    void changeState(int pid, std::string new_state);
};