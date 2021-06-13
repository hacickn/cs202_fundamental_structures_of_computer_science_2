/*
* Title: Simulator
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 3
* Description: This code is a Simulator implementation that it finds suitable number o printer according to given parameters
*/

#include "Simulator.h"
#include "Printer.h"
#include "PriorityQueue.h"

/**
 * It is a constructor with parameters
 * @param requests is the all the request dataset
 * @param numberOfFiles is the total number of request
 * @param maxAverageWaitingTime is the accepting max waiting time
 */
Simulator::Simulator(Request*& requests, int numberOfFiles, int maxAverageWaitingTime) {
    this->requests = requests;
    this->numberOfFiles = numberOfFiles;
    this->maxAverageWaitingTime = maxAverageWaitingTime;
}

/**
 * It is a method that run simulation, it finds the minimum number of printer that satisfies the wanted conditions
 */
void Simulator::runSimulator() {
    int timeCounter;
    int lastArrival = 0;
    int numberOfPrinter = 1;
    int expectedAverageTime;
    bool isFounded = false;
    bool isFoundedCheck = true;

    for (int i = 0; i < numberOfFiles; i++) {
        if (requests[i].getArrivalTime() > lastArrival)
            lastArrival = requests[i].getArrivalTime();
    }

    do {
        timeCounter = 0;
        expectedAverageTime = 0;
        Printer printers[numberOfPrinter];
        if (isFounded)
            isFoundedCheck = false;

        for (int a = 0; a < numberOfPrinter; a++) {
            printers[a] = Printer(a);
        }

        PriorityQueue priorityQueue(numberOfFiles);
        bool isPrintersAllAvailable;

        do {
            for (int i = 0; i < numberOfFiles; i++) {
                if (timeCounter == requests[i].getArrivalTime()) {
                    priorityQueue.pqInsert(requests[i]);
                }
            }

            for (int a = 0; a < numberOfPrinter; a++) {
                if (printers[a].isAvailable() && !priorityQueue.pqIsEmpty()) {
                    if (isFounded)
                        printers[a].printProcess(priorityQueue.getPriorOne(), timeCounter);
                    else
                        printers[a].processRequest(priorityQueue.getPriorOne(), timeCounter);
                    expectedAverageTime =
                            expectedAverageTime + (timeCounter - priorityQueue.getPriorOne().getArrivalTime());
                    priorityQueue.pqDelete(priorityQueue.getPriorOne());
                }
            }

            for (int a = 0; a < numberOfPrinter; a++) {
                printers[a].progress();
            }

            isPrintersAllAvailable = true;
            for (int a = 0; a < numberOfPrinter; a++) {
                if (!printers[a].isAvailable()) {
                    isPrintersAllAvailable = false;
                    break;
                }

            }
            timeCounter++;
        } while (!priorityQueue.pqIsEmpty() || !isPrintersAllAvailable || lastArrival > timeCounter);
        if ((expectedAverageTime / numberOfFiles) < maxAverageWaitingTime)
            isFounded = true;
        else
            numberOfPrinter++;
    } while (isFoundedCheck);

    cout << ((double) expectedAverageTime / (double) numberOfFiles) << " expected average time " << endl;

}