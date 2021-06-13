/*
* Title: Printer
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 3
* Description: This code is a Printer h file implementation that presents the printer object
*/

#ifndef HW3_PRINTER_H
#define HW3_PRINTER_H
#include "Request.h"
#include <iostream>
class Printer {
private:
    int id;
    int remainingTime;

public:

    Printer(int id);
    void processRequest(Request &request, int currentTime);
    bool isAvailable();
    void printProcess(Request &request, int currentTime);
    void progress();

    Printer();
};


#endif //HW3_PRINTER_H
