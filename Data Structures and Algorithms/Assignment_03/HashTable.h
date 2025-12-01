#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>

using namespace std;


class Shipment {
public:
    int id;
    string sender;
    string receiver;
    string fromCity;
    string toCity;
    
    Shipment() { 
        id=-1; 
        sender=""; 
        receiver=""; 
        fromCity=""; 
        toCity="";     
    } 
};

class HashTable {
private:
    int SIZE;
    Shipment* table;   
    bool* occupied;       

public:
    HashTable(int hashSize);
    ~HashTable(); 

    int hashFunction(int key);
    void insertShipment(int id, string s, string r, string from, string to);
    Shipment* searchShipment(int id);
    void removeShipment(int id);
};

#endif