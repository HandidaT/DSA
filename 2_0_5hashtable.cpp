#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define INITIAL_CAPACITY 8
#define LOAD_FACTOR 0.75

/* =========================================
   HASH NODE
   ========================================= */

struct Node {
    int key;
    int value;
};

/* =========================================
   HASH TABLE CLASS
   ========================================= */

class HashTable {

private:

    int capacity;
    int size;

    vector<Node*> table;          // for open addressing
    vector<list<Node>> chain;     // for separate chaining

public:

    /* =========================================
       Constructor
       ========================================= */

    HashTable() {

        capacity = INITIAL_CAPACITY;
        size = 0;

        table.resize(capacity, nullptr);
        chain.resize(capacity);
    }

    /* =========================================
       Hash Functions
       ========================================= */

    int hash1(int key) {
        return key % capacity;
    }

    int hash2(int key) {
        return 1 + (key % (capacity - 1));
    }

    /* =========================================
       Probing Methods
       ========================================= */

    int linearProbe(int hash, int i) {
        return (hash + i) % capacity;
    }

    int quadraticProbe(int hash, int i) {
        return (hash + i * i) % capacity;
    }

    int doubleHash(int key, int i) {
        return (hash1(key) + i * hash2(key)) % capacity;
    }

    /* =========================================
       Rehashing
       ========================================= */

    void rehash() {

        int oldCapacity = capacity;
        capacity = capacity * 2;

        vector<Node*> oldTable = table;

        table.clear();
        table.resize(capacity, nullptr);

        size = 0;

        for (int i = 0; i < oldCapacity; i++) {

            if (oldTable[i] != nullptr) {
                insertLinear(oldTable[i]->key, oldTable[i]->value);
            }
        }
    }

    /* =========================================
       LOAD FACTOR CHECK
       ========================================= */

    void checkLoadFactor() {

        float lf = (float)size / capacity;

        if (lf >= LOAD_FACTOR)
            rehash();
    }

    /* =========================================
       INSERT (LINEAR PROBING)
       ========================================= */

    void insertLinear(int key, int value) {

        checkLoadFactor();

        int hash = hash1(key);

        int i = 0;

        while (i < capacity) {

            int index = linearProbe(hash, i);

            if (table[index] == nullptr) {

                Node* node = new Node{key,value};
                table[index] = node;

                size++;
                return;
            }

            i++;
        }
    }

    /* =========================================
       INSERT (QUADRATIC PROBING)
       ========================================= */

    void insertQuadratic(int key, int value) {

        checkLoadFactor();

        int hash = hash1(key);

        int i = 0;

        while (i < capacity) {

            int index = quadraticProbe(hash, i);

            if (table[index] == nullptr) {

                Node* node = new Node{key,value};
                table[index] = node;

                size++;
                return;
            }

            i++;
        }
    }

    /* =========================================
       INSERT (DOUBLE HASHING)
       ========================================= */

    void insertDoubleHash(int key, int value) {

        checkLoadFactor();

        int i = 0;

        while (i < capacity) {

            int index = doubleHash(key, i);

            if (table[index] == nullptr) {

                Node* node = new Node{key,value};
                table[index] = node;

                size++;
                return;
            }

            i++;
        }
    }

    /* =========================================
       INSERT (SEPARATE CHAINING)
       ========================================= */

    void insertChaining(int key, int value) {

        int index = hash1(key);

        chain[index].push_back({key,value});
    }

    /* =========================================
       SEARCH (OPEN ADDRESSING)
       ========================================= */

    int search(int key) {

        int hash = hash1(key);

        int i = 0;

        while (i < capacity) {

            int index = linearProbe(hash, i);

            if (table[index] == nullptr)
                return -1;

            if (table[index]->key == key)
                return table[index]->value;

            i++;
        }

        return -1;
    }

    /* =========================================
       SEARCH (CHAINING)
       ========================================= */

    int searchChaining(int key) {

        int index = hash1(key);

        for (auto &node : chain[index]) {

            if (node.key == key)
                return node.value;
        }

        return -1;
    }

    /* =========================================
       DELETE (OPEN ADDRESSING)
       ========================================= */

    void deleteKey(int key) {

        int hash = hash1(key);

        int i = 0;

        while (i < capacity) {

            int index = linearProbe(hash, i);

            if (table[index] == nullptr)
                return;

            if (table[index]->key == key) {

                delete table[index];
                table[index] = nullptr;

                size--;
                return;
            }

            i++;
        }
    }

    /* =========================================
       DELETE (CHAINING)
       ========================================= */

    void deleteChaining(int key) {

        int index = hash1(key);

        chain[index].remove_if([key](Node n){
            return n.key == key;
        });
    }

    /* =========================================
       DISPLAY OPEN ADDRESSING
       ========================================= */

    void display() {

        cout << "\nHash Table\n";

        for(int i=0;i<capacity;i++){

            if(table[i]!=nullptr)
                cout<<i<<" -> ("<<table[i]->key<<","<<table[i]->value<<")\n";
            else
                cout<<i<<" -> NULL\n";
        }
    }

    /* =========================================
       DISPLAY CHAINING
       ========================================= */

    void displayChaining() {

        cout<<"\nSeparate Chaining Table\n";

        for(int i=0;i<capacity;i++){

            cout<<i<<" : ";

            for(auto &node : chain[i])
                cout<<"("<<node.key<<","<<node.value<<") -> ";

            cout<<"NULL\n";
        }
    }
};


/* =========================================
   MAIN FUNCTION
   ========================================= */

int main(){

    HashTable ht;

    cout<<"Linear Probing\n";

    ht.insertLinear(10,100);
    ht.insertLinear(20,200);
    ht.insertLinear(30,300);
    ht.insertLinear(40,400);

    ht.display();

    cout<<"\nSearch 30 = "<<ht.search(30)<<endl;

    ht.deleteKey(30);

    ht.display();


    cout<<"\nSeparate Chaining Example\n";

    ht.insertChaining(1,10);
    ht.insertChaining(11,20);
    ht.insertChaining(21,30);

    ht.displayChaining();

}