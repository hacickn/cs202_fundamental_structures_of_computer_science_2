/*
* Title: Printer
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 3
* Description: This code is a Printer implementation that presents the printer object
*/
#include "Printer.h"

using namespace std;

/**
 * It is a default constructor
 */
Printer::Printer() {
    this->remainingTime = 0;
    this->id = -1;
}

/**
 * It is a constructor wiht id parameter
 * @param id is the printer id
 */
Printer::Printer(int id) {
    this->remainingTime = 0;
    this->id = id;
}

/**
 * It returns the whether printer is available or not
 * @return bool is current availability
 */
bool Printer::isAvailable() {
    return remainingTime == 0;
}

/**
 * It processes the request that take time of process
 * @param request is the request object whose process time will gotten
 * @param currentTime is the current time
 */
void Printer::processRequest(Request& request, int currentTime) {
    remainingTime = request.getTimeTaken();
}

/**
 * It is same previous method with extra of printing
 * @param request is the request object whose process time will gotten
 * @param currentTime is the current time
 */
void Printer::printProcess(Request& request, int currentTime) {
    remainingTime = request.getTimeTaken();
    cout << "Printer " << id << " takes file " << request.getId() << " at mins ";
    cout << currentTime << " (wait: " << currentTime - request.getArrivalTime() << " mins)" << endl;
}

/**
 * It is method that continues to count
 */
void Printer::progress() {
    if(remainingTime > 0)
        remainingTime--;
}


