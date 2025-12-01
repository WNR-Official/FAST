#include <iostream>
#include <algorithm> // for std::swap

using namespace std;

const int TABLE_SIZE = 10;

struct Entry {
    int key;
    int psl; // Probe Sequence Length
    bool occupied; // Flag to check if slot is empty

    Entry() {
        key = -1;
        psl = 0;
        occupied = false;
    }
};

Entry hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int currentPSL = 0; // The PSL of the key we are trying to insert
    int probeCount = 0; // Safety break to prevent infinite loops

    // We continue until we find an empty spot or swap all the way
    while (probeCount < TABLE_SIZE) {
        
        // CASE 1: Spot is empty. Drop it in.
        if (!hashTable[index].occupied) {
            hashTable[index].key = key;
            hashTable[index].psl = currentPSL;
            hashTable[index].occupied = true;
            return;
        }

        // CASE 2: Spot is taken. Check who is "Poorer".
        // If the key we are holding has a higher PSL than the key in the slot,
        // we SWAP. The key in the slot is kicked out.
        if (currentPSL > hashTable[index].psl) {
            // Swap Keys
            swap(key, hashTable[index].key);
            // Swap PSLs (The kicked out key picks up the PSL of the current slot)
            swap(currentPSL, hashTable[index].psl);
        }

        // Move to next index (Linear Probing logic)
        index = (index + 1) % TABLE_SIZE;
        currentPSL++; // We moved one step further from home
        probeCount++;
    }
    cout << "Error: Table is full!" << endl;
}

void printTable() {
    cout << "Index | Key | PSL" << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].occupied) {
            cout << "  " << i << "   |  " << hashTable[i].key << "  |  " << hashTable[i].psl << endl;
        } else {
            cout << "  " << i << "   |  -  |  -" << endl;
        }
    }
}

int main() {
    // Example from the explanation
    // A(0), B(1), C(0)
    
    cout << "Inserting 10 (Hash 0)..." << endl;
    insert(10); 
    
    cout << "Inserting 11 (Hash 1)..." << endl;
    insert(11);
    
    cout << "Inserting 20 (Hash 0)..." << endl;
    insert(20); 

    printTable();
    
    return 0;
}