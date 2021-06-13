/*
* Title: Simulator
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 3
* Description: This code is a Simulator h file implementation
*/
#ifndef HW3_SIMULATOR_H
#define HW3_SIMULATOR_H


#include "Request.h"

class Simulator {
public:
    Simulator(Request*& requests, int numberOfFiles, int maxAverageWaitingTime);
    void runSimulator();
private:
    int numberOfFiles;
    int maxAverageWaitingTime;
    Request* requests;
};


#endif //HW3_SIMULATOR_H
