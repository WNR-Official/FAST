#include "HashTable.h"

// Constructor [cite: 47]
HashTable::HashTable(int hashSize) {
    SIZE = hashSize;
    table = new Shipment[SIZE];
    occupied = new bool[SIZE];
    
    for(int i = 0; i < SIZE; i++) {
        occupied[i] = false;
        table[i].id = -1; 
    }
}

// Destructor
HashTable::~HashTable() {
    delete[] table;
    delete[] occupied;
}

int HashTable::hashFunction(int key) {
    return key % SIZE;
}

void HashTable::insertShipment(int id, string s, string r, string from, string to) {
    int index = hashFunction(id);
    int originalIndex = index;
    int i = 0;

    while (occupied[index]) {
        if (table[index].id == id) {
            cout << "Duplicate ID " << id << " not allowed.\n";
            return;
        }
        index = (index + 1) % SIZE;
        i++;
        if (i == SIZE) {
            cout << "Hash Table is full!\n";
            return;
        }
    }

    table[index].id = id;
    table[index].sender = s;
    table[index].receiver = r;
    table[index].fromCity = from;
    table[index].toCity = to;
    occupied[index] = true;
    cout << "Shipment " << id << " inserted.\n";
}

Shipment* HashTable::searchShipment(int id) {
    int index = hashFunction(id);
    int i = 0;

    while (occupied[index] || i < SIZE) {
        if (occupied[index] && table[index].id == id) {
            return &table[index];
        }
        index = (index + 1) % SIZE;
        i++;
        if (i >= SIZE) break; 
    }
    return nullptr; 
}

void HashTable::removeShipment(int id) {
    int index = hashFunction(id);
    int i = 0;

    while (occupied[index] || i < SIZE) {
        if (occupied[index] && table[index].id == id) {
            occupied[index] = false;
            table[index].id = -1; 
            cout << "Shipment " << id << " removed.\n";
            return;
        }
        index = (index + 1) % SIZE;
        i++;
        if (i >= SIZE) break;
    }
    cout << "Shipment " << id << " not found to remove.\n";
}