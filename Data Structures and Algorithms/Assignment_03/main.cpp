#include <iostream>
#include "DeliveryApp.h"

using namespace std;

int main() {
    int hashSize = 10;
    DeliveryApp app(hashSize);

   
    app.insertShipment(1001, "Ali", "Hassan", "Lahore", "Karachi");
    
    app.insertShipment(2045, "Fatima", "Zara", "Lahore", "Multan");
    
    app.insertShipment(3090, "Ahmed", "Bilal", "Islamabad", "Karachi");

    cout << "\n--- Route Map ---\n";
    app.printMap();

    cout << "\n--- Testing Features ---\n";
    app.findRouteForShipment(2045);
    app.findRouteForShipment(1001);
    app.findRouteForShipment(3090);
    
    app.findRouteForShipment(9999);

    return 0;
}