/*
* Title: Request
* Author: Hacı Çakın
* ID: 21802641
* Section: 3
* Assignment: 3
* Description: This code is a Request h implementation that presents the printing requests
*/
#ifndef HW3_REQUEST_H
#define HW3_REQUEST_H


class Request {
public:
    Request();
    Request(int id,int priority,int arrivalTime,int timeTaken);
    int getId();
    void setId(int id);
    int getArrivalTime();
    void setArrivalTime(int arrival);
    int getTimeTaken();
    void setTimeTaken(int time);
    int getPriority();
    void setPriority(int priority);
private:
    int priority;
    int arrivalTime;
    int timeTaken;
    int id;
};


#endif //HW3_REQUEST_H
