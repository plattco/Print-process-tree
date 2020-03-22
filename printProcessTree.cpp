// copyright 2020 plattcr
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   plattcr_hw3.cpp
 * Author: plattcr
 *
 * Created on February 17, 2020, 9:43 PM
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>


using IntStrMap = std::unordered_map<int, std::string>;
using IntIntMap = std::unordered_map<int, int>;


/*
 * This method extracts the required info from the input into an istream
 */
void extractLineInfo(std::string line, std::string& cmd, int& pid, int& ppid) {
    std::istringstream is(line);
    std::string dummy;  // not used
    // extract needed values
    is >> dummy >> pid >> ppid >> dummy >> dummy >> dummy >> dummy;
    std::getline(is, cmd);
    // or like is >> dummy >> pid >> ppid >> dummy >> dummy >> dummy >> dummy >>
    // dummy >> cmd;    
}

/**
*This is a class which is used to create separate "processes" which can be used to perform actions and can be observed.
*/
class process {
public:
    IntIntMap pidPpid;  // contains pid and ppid
    IntStrMap pidCmd;  // contains pid and cmd

    void mappy(const std::string& passFile) {
        // process each line in file
        std::ifstream in(passFile);
        for (std::string line; std::getline(in, line);) {
            int pid, ppid;
            std::string cmd, dummy;
            // extract pid and ppid via helper method
            // like this?
            extractLineInfo(line, cmd, pid, ppid);
            // add to pidPpid
            pidPpid[pid] = ppid;
            pidCmd[pid] = cmd;  // the CMD input is not working properly. 
        }
    }   
    /**
    *This function prints the process tree, starting with the top-most process of the process tree.
    */
    void printProccessTree(int pid) {
        std::ostringstream os;
        if (pid == 1) {  // if it is 1 print only line 
            os << "PID" << "\t" << "PPID" << "\t" << "CMD" << std::endl
               << "1" << "\t" << "0" << "\t" << pidCmd[1] << std::endl;
        }       else {  // if it is > 1 then print the process of the ppid
            printProccessTree(pidPpid[pid]);
            os << pid << "\t" << pidPpid[pid] << "\t" << pidCmd[pid] 
               << std::endl;
            // print processed line
            // os << pid << pidPpid[pid] << pidCmd[pid];  
       }
        std::cout << os.str();
    }
};

// std::cout << "process tree for PID: " << pid << std::endl;

int main(int argc, char** argv) {    
     std::string filename;
     
     int x = atoi(argv[2]);
    filename = argv[1];
    
    process info;
  
    info.mappy(filename);
    
    int pid;  
    pid = x;
    
     std::cout << "Process tree for PID: " << pid << std::endl;
    
    info.printProccessTree(pid);  // for testing
    
    // receive pid as input
    // import data from files
    // create unordered maps using data using mappy
    // call on printProcesses to print processes
    
    return 0;
}




