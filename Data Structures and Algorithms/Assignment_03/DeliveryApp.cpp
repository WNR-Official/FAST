#include "DeliveryApp.h"

DeliveryApp::DeliveryApp(int hashSize) : shipments(hashSize) {
    
    
   
    graph.addRoute(0, 1, 380);  
    graph.addRoute(0, 3, 350);  
    graph.addRoute(1, 2, 1400); 
    graph.addRoute(2, 3, 900);  
    graph.addRoute(1, 4, 180); 
}

void DeliveryApp::insertShipment(int id, string sender, string receiver, string src, string dest) {
    shipments.insertShipment(id, sender, receiver, src, dest);
}

void DeliveryApp::printMap() {
    graph.printRouteMap();
}

// Find logic [cite: 109]
void DeliveryApp::findRouteForShipment(int shipmentID) {
    cout << "\nProcessing Shipment ID: " << shipmentID << "...\n";
    
    Shipment* s = shipments.searchShipment(shipmentID);
    
    if (s == nullptr) {
        cout << "Error: Shipment ID " << shipmentID << " not found.\n";
        return;
    }

    cout << "Shipment Found: " << s->sender << " sending to " << s->receiver << endl;
    
    int u = graph.getCityIndex(s->fromCity);
    int v = graph.getCityIndex(s->toCity);

    if (u == -1 || v == -1) {
        cout << "Error: Invalid city names in shipment.\n";
        return;
    }

    graph.findShortestRoute(u, v);
}