/*
* Title: Request
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 3
* Description: This code is a Request implementation that presents the printing requests
*/
#include "Request.h"
/**
 * It is a default constructor
 */
Request::Request() {

}

/**
 * It is a constructor with parameters
 * @param id is the request id
 * @param priority is the request priority level
 * @param arrivalTime is the request arrival time
 * @param timeTaken is the time that taken from the request
 */
Request::Request(int id, int priority, int arrivalTime, int timeTaken) {
    this->id = id;
    this->priority = priority;
    this->arrivalTime = arrivalTime;
    this->timeTaken = timeTaken;
}

/**
 * It is a method that gives id of the object
 * @return int is id of the request
 */
int Request::getId() {
    return id;
}

/**
 * It is a method that gives arrival time of the object
 * @return int is arrival time of the request
 */
int Request::getArrivalTime() {
    return arrivalTime;
}

/**
 * It is a method that gives priority of the object
 * @return int is priority of the request
 */
int Request::getPriority() {
    return priority;
}

/**
 * It is a method that gives timeTaken of the object
 * @return int is timeTaken of the request
 */
int Request::getTimeTaken() {
    return timeTaken;
}

/**
 * It is a method that set the arrival time
 * @param arrival is the int for the arrival time
 */
void Request::setArrivalTime(int arrival) {
    this->arrivalTime = arrival;
}

/**
 * It is a method that set the priority
 * @param arrival is the int for the priority
 */
void Request::setPriority(int priority) {
    this->priority = priority;
}

/**
 * It is a method that set the time
 * @param arrival is the int for the time
 */
void Request::setTimeTaken(int time) {
    this->timeTaken = time;
}

/**
 * It is a method that set the id
 * @param arrival is the int for the id
 */
void Request::setId(int id) {
    this->id = id;
}