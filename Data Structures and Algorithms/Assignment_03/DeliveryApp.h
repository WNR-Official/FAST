#ifndef DELIVERYAPP_H
#define DELIVERYAPP_H

#include "Graph.h"
#include "HashTable.h"

class DeliveryApp {
private:
    Graph graph;
    HashTable shipments;

public:
    DeliveryApp(int hashSize);
    void insertShipment(int id, string sender, string receiver, string src, string dest);
    void findRouteForShipment(int shipmentID);
    void printMap();
};

#endif