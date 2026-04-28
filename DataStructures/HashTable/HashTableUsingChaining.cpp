//using open hashing with linked list

#include <iostream>
#include <vector>
#include <list>
using namespace std;


class HashTable {
    private:
        int capacity; // size of hash table
        int size;   // number elememts
        list<pair<int, int>>* table; // array of list chain

    public:
        HashTable(){
            capacity = 0;
            size = 0;
            table = NULL;
        }

        HashTable(int capacity){
            this->capacity = capacity;
            size = 0;
            table = new list<pair<int, int>>[capacity];
        }

        ~HashTable(){
            delete[] table;
        }

        int hashFunction(int key){
            int index = (key % capacity + capacity) % capacity;
            return index;
        }

        //best: O(1), worst: O(n)
        int search(int key){ // return the frequence
            int index = hashFunction(key);
            list<pair<int, int>> &list = table[index];

            for (auto it = list.begin(); it != list.end(); ++it){
                if (it->first == key){
                    return it->second;
                }
            }

            return 0; // not found
        }

        //if only unique element: O(1)
        void insert(int key, int count = 1){ //count is used for rehashing
            int index = hashFunction(key);
            list<pair<int, int>> &list = table[index];

            //find if key exists
            for (auto it = list.begin(); it != list.end(); it++){
                if (it->first == key){
                    it->second = it->second + count;
                    return;
                }
            }

            //if key not in list
            table[index].push_back(make_pair(key, count));
            size++;

            return;
        }

        void rehashing(){
            int oldCapacity = capacity;
            list<pair<int, int>>* oldTable = table;

            capacity = capacity * 2;
            size = 0;
            table = new list<pair<int, int>>[capacity];
            
            for(int i = 0; i < oldCapacity; i++){
                list<pair<int, int>> &list = oldTable[i];
                for (auto it = list.begin(); it != list.end(); it++){
                    insert(it->first, it->second);
                }
            }

            delete[] oldTable;

            return;
        }

        //if only unique element: O(1)
        void remove(int key){
            int index = hashFunction(key);
            list<pair<int, int>> &list = table[index];

            for(auto it = list.begin(); it != list.end(); it++){
                if(it->first == key){
                    list.erase(it);
                    size--;
                    return;
                }
            }
        }

};

int main(){

    vector<int> arr = {2, -5, 10, 2, 7, -5, 2, 8, 10, 10, 10};

    HashTable ht(10); 

    for (int num : arr) {
        ht.insert(num);
    }

    cout << "Tan suat cua 2: " << ht.search(2) << endl;
    cout << "Tan suat cua 10: " << ht.search(10) << endl;
    cout << "Tan suat cua -5: " << ht.search(-5) << endl; 
    cout << "Tan suat cua 99: " << ht.search(99) << endl; // not found

    cout << "\n--- Dang xoa so 2 ---\n";
    ht.remove(2);
    cout << "Tan suat cua 2 sau khi xoa: " << ht.search(2) << endl;

    return 0;
}