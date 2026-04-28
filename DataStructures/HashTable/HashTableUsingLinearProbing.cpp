// using linear probing

#include <iostream>
#include <vector>

using namespace std;

enum State { EMPTY, OCCUPIED, DELETED }; // DELETED to mark the cell as empty, but not corupt when searching

struct HashNode {
    int key;
    int value;
    int probe;
    State state;

    HashNode() {
        key = 0;
        value = 0;
        probe = 0;
        state = EMPTY;
    }
};

class HashTable {
    private:
        int capacity;
        int size;
        vector<HashNode> table;

    public:
        HashTable(){
            capacity = 0;
            size = 0;
        }

        HashTable(int capacity){
            this->capacity = capacity;
            size = 0;
            table.assign(capacity, HashNode());
        }

        int hashFunction(int key) {
            return (key % capacity + capacity) % capacity;
        }

        int search(int key){
            int startIndex = hashFunction(key);
            int index = startIndex;

            while(table[index].state != EMPTY){
                if(table[index].state == OCCUPIED && table[index].key == key){
                    return table[index].value;
                }

                index = (index +1) % capacity;

                if (index == startIndex) break;
            }

            return 0; //not found
        }

        void insert(int key, int count = 1){
            int index = hashFunction(key);
            int probeCount = 0; 

            while(table[index].state == OCCUPIED){
                if (table[index].key == key){
                    table[index].value = table[index].value + count;
                    return;
                }
                index = (index +1) % capacity;
                probeCount++;
            }

            // if new element
            table[index].key = key;
            table[index].value = count;
            table[index].state = OCCUPIED;
            table[index].probe = probeCount;
            size++;
        }

        void remove(int key){
            int startIndex = hashFunction(key);
            int index = startIndex;

            while(table[index].state != EMPTY){

                if(table[index].state == OCCUPIED && table[index].key == key){
                    table[index].state = DELETED;
                    size--;
                    return;
                }

                index = (index +1) % capacity;
                if (index == startIndex) break;
            }
        }

        void printTable() {
            cout << "--- Hash Table ---" << endl;
            for (int i = 0; i < capacity; i++) {
                cout << "[" << i << "] ";
                if (table[i].state == OCCUPIED) {
                    cout << "Key: " << table[i].key 
                        << ", Val: " << table[i].value 
                        << ", Probe: " << table[i].probe << endl;
                } else if (table[i].state == DELETED) {
                    cout << "<DELETED>" << endl;
                } else {
                    cout << "<EMPTY>" << endl;
                }
            }
            cout << "---------------------" << endl;
        }
};


int main(){
    vector<int> arr = {2, -5, 10, 2, 7, -5, 2, 8, 10, 10, 17};

    HashTable ht(15); 

    for (int num : arr) {
        ht.insert(num);
    }

    ht.printTable(); 

    cout << "\nTan suat cua 2: " << ht.search(2) << endl;
    cout << "Tan suat cua 10: " << ht.search(10) << endl;
    cout << "Tan suat cua -5: " << ht.search(-5) << endl;

    cout << "\n--- Dang xoa so 2 ---\n";
    ht.remove(2);
    ht.printTable();

    cout << "\nTan suat cua 2 sau khi xoa: " << ht.search(2) << endl;
    cout << "Tan suat cua 10 sau khi xoa 2: " << ht.search(10) << endl; 

    return 0;
}