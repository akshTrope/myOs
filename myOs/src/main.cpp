#include <iostream>
#include <string>
using namespace std;
#include "process_manager.h"
#include <sstream>
int main(){
    cout<<"--//--//--//--//--//--//--//"<<endl;
    cout<<"Welcome to myOs"<<endl;
    cout<<"--//--//--//--//--//--//--//"<<endl;
    processManager pm;
    string com;
    while(true){
        cout<<"myOs> ";
        getline(cin, com);
        if(com == "exit"){
            cout<<"Exiting myOs..."<<endl;
            break;
        }
        else if(com == "help"){
            cout<<"Available commands:"<<endl;
            cout<<"- help: Show this help message"<<endl;
            cout<<"- exit: Exit the operating system"<<endl;
            cout<<"- clear: Clear the screen"<<endl;
            cout<<"- create [name] [arrival_time] [burst_time] [priority]: Create a new process"<<endl;
            cout<<"- list: List all processes"<<endl;
            cout<<"- terminate [pid]: Terminate a process by PID"<<endl;
            cout<<"- change-priority [pid] [new_priority]: Change the priority of a process"<<endl;
            cout<<"- change-state [pid] [new_state]: Change the state of a process"<<endl;
        }
        else if (com=="system info") {
            cout <<"myOs version: 0.1\n";
            cout <<"Architecture: C++ user-space simulator\n";
        }
        else if(com == "clear"){
            system("clear");
        }
        else if(com.rfind("create ", 0) == 0){
            string name;
            int arrival_time, burst_time, priority;
            stringstream ss(com);
            string command;
            if(ss >> command >> name >> arrival_time >> burst_time >> priority){
                pm.createProcess(name, arrival_time, burst_time, priority);
            }
            else{
                cout<<"Invalid command format for create."<<endl;
            }
        }
        else if(com == "list"){
            pm.listProcesses();
        }
        else if(com.rfind("terminate ", 0) == 0){
            int pid;
            stringstream ss(com);
            string command;
            if(ss >> command >> pid){
                pm.terminateProcess(pid);
            }
            else{
                cout<<"Invalid command format for terminate."<<endl;
            }
        }
        else if(com.rfind("change-priority ", 0) == 0){
            int pid, new_priority;
            stringstream ss(com);
            string command;
            if(ss >> command >> pid >> new_priority){
                pm.changePriority(pid, new_priority);
            }
            else{
                cout<<"Invalid command format for change-priority."<<endl;
            }
        }
        else if(com.rfind("change-state ", 0) == 0){
            int pid;
            string new_state;
            stringstream ss(com);
            string command;
            if(ss >> command >> pid >> new_state){
                pm.changeState(pid, new_state);
            }
            else{
                cout<<"Invalid command format for change-state."<<endl;
            }
        }
        else{
            cout<<"Unknown command: "<<com<<endl;
        }
    }
    return 0;
}
