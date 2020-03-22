/*
 * This source file contains the definition for the process class. This class
 * provides a way to import process data and automatically complete the process
 * tracing of the process data.
 */

/* 
 * File:   plattcr_hw3.h
 * copyright 2020 plattcr
 *
 * Created on February 19, 2020, 6:28 PM
 */

#include <string>;

#ifndef PLATTCR_HW3_H
#define PLATTCR_HW3_H

class process {
    void printProcessTree(int pid);
    /** This method uses recursion in order to print the process hierarchy from 
     *  top to bottom. This is the print function of the process tracing.
     * 
     * @param passFile This is the file in question
     */
    
    
    void mappy(const std::string& passFile);
    /** This imports process data from a txt file into two unordered maps line 
     * by line. One map is for pid==ppid connection and another is for pid==cmd
     * info. 
     */    
};

#endif /* PLATTCR_HW3_H */

