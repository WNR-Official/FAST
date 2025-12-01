#include <iostream>

using namespace std;

// Define states for each slot to handle Deletion correctly (Tombstones)
enum State {
    EMPTY,
    OCCUPIED,
    DELETED
};

struct Entry {
    int key;
    State state;
};

class LinearProbingHT {
private:
    Entry* table;
    int size;
    int count;

public:
    // Constructor: Initialize table
    LinearProbingHT(int tableSize) {
        size = tableSize;
        count = 0;
        table = new Entry[size];
        
        // Initialize all slots as EMPTY
        for (int i = 0; i < size; i++) {
            table[i].key = -1;
            table[i].state = EMPTY;
        }
    }

    // Hash Function
    int hashFunction(int key) {
        return key % size;
    }

    // 1. INSERT FUNCTION
    // Greedily finds the first EMPTY or DELETED spot
    void insert(int key) {
        if (count == size) {
            cout << "Error: Table is full!" << endl;
            return;
        }

        int index = hashFunction(key);
        int i = 0;

        // Linear Probe
        while (i < size) {
            // Found a usable spot (Empty or a Tombstone)
            if (table[index].state == EMPTY || table[index].state == DELETED) {
                table[index].key = key;
                table[index].state = OCCUPIED;
                count++;
                cout << "Inserted " << key << " at Index " << index << endl;
                return;
            }
            
            // Check for duplicates (Optional)
            if (table[index].state == OCCUPIED && table[index].key == key) {
                cout << "Key " << key << " already exists." << endl;
                return;
            }

            // Move to next slot (Greedy step)
            index = (index + 1) % size;
            i++;
        }
    }

    // 2. SEARCH FUNCTION
    // Probes until found or hits an EMPTY spot. Skips DELETED spots.
    int search(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (i < size) {
            // If we hit an EMPTY spot, the key definitely isn't here
            // because it would have been inserted here (or earlier).
            if (table[index].state == EMPTY) {
                return -1;
            }

            // If we find the key and it is OCCUPIED
            if (table[index].state == OCCUPIED && table[index].key == key) {
                return index;
            }

            // If state is DELETED or key doesn't match, keep moving
            index = (index + 1) % size;
            i++;
        }
        return -1; // Not found after full loop
    }

    // 3. DELETE FUNCTION
    // Finds the key and marks it as DELETED (Tombstone)
    void remove(int key) {
        int index = search(key);

        if (index != -1) {
            table[index].state = DELETED;
            count--;
            cout << "Key " << key << " deleted from Index " << index << endl;
        } else {
            cout << "Key " << key << " not found. Cannot delete." << endl;
        }
    }

    // 4. DISPLAY FUNCTION
    void display() {
        cout << "\n--- Hash Table ---" << endl;
        cout << "Index | State    | Key" << endl;
        for (int i = 0; i < size; i++) {
            cout << "  " << i << "   | ";
            if (table[i].state == EMPTY) cout << "EMPTY    | -";
            else if (table[i].state == OCCUPIED) cout << "OCCUPIED | " << table[i].key;
            else cout << "DELETED  | -"; // We hide the key value for deleted spots
            cout << endl;
        }
        cout << "------------------\n" << endl;
    }

    // Destructor to clean up memory
    ~LinearProbingHT() {
        delete[] table;
    }
};

int main() {
    int tableSize, n, val;

    // 1. Get Table Size
    cout << "Enter the size of the Hash Table: ";
    cin >> tableSize;

    LinearProbingHT ht(tableSize);

    // 2. Get Input Numbers
    cout << "How many numbers do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> val;
        ht.insert(val);
    }
    
    ht.display();

    // 3. Interactive Search
    int searchKey;
    cout << "Enter a number to search: ";
    cin >> searchKey;
    int foundIdx = ht.search(searchKey);
    if (foundIdx != -1) 
        cout << "Found " << searchKey << " at index " << foundIdx << endl;
    else 
        cout << searchKey << " not found" << endl;

    // 4. Interactive Delete
    int deleteKey;
    cout << "\nEnter a number to delete: ";
    cin >> deleteKey;
    ht.remove(deleteKey);
    
    // Final Display
    ht.display();

    return 0;
}