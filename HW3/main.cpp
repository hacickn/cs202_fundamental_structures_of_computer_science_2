/*
* Title: Main Class
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 3
* Description: This code is a main function
*/
#include "Request.h"
#include "Simulator.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/**
 * It is a main method
 * @param argc is for inputs
 * @param argv is for inputs
 * @return 0
 */
int main(int argc, char* argv[]) {
    ifstream input;
    input.open(argv[1]);
    int maxAverageWaitingTime = stoi(argv[2]);

    if(!input)
        cout << "Unable to open file " << endl;

    int numberOfFiles;
    input >> numberOfFiles;
    Request* requests = new Request[numberOfFiles];
    int tempId;
    int tempPriority;
    int tempArrival;
    int tempTimeTaken;
    for(int i = 0; i < numberOfFiles; i++){
        input >> tempId >> tempPriority >> tempArrival >> tempTimeTaken;
        requests[i] = Request(tempId,tempPriority,tempArrival,tempTimeTaken);
    }

    Simulator simulator(requests,numberOfFiles,maxAverageWaitingTime);
    simulator.runSimulator();
    delete [] requests;
    return 0;
}
