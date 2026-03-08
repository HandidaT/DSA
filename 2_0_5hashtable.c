#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 8
#define LOAD_FACTOR 0.75

/* ===============================
   Hash Node
   =============================== */

typedef struct {
    int key;
    int value;
    int status; 
    // 0 = empty
    // 1 = occupied
    // 2 = deleted
} HashNode;

/* ===============================
   Hash Table Structure
   =============================== */

typedef struct {
    int size;
    int capacity;
    HashNode *table;
} HashTable;

/* ===============================
   Hash Functions
   =============================== */

int hash1(int key, int capacity){
    return key % capacity;
}

int hash2(int key, int capacity){
    return 1 + (key % (capacity - 1));
}

/* ===============================
   Create Hash Table
   =============================== */

HashTable* create_table(){

    HashTable *ht = malloc(sizeof(HashTable));

    ht->size = 0;
    ht->capacity = INITIAL_SIZE;

    ht->table = malloc(sizeof(HashNode) * ht->capacity);

    for(int i=0;i<ht->capacity;i++)
        ht->table[i].status = 0;

    return ht;
}

/* ===============================
   Probing Strategies
   =============================== */

int linear_probe(int hash, int i, int capacity){
    return (hash + i) % capacity;
}

int quadratic_probe(int hash, int i, int capacity){
    return (hash + i*i) % capacity;
}

int double_hash_probe(int key, int i, int capacity){
    return (hash1(key,capacity) + i * hash2(key,capacity)) % capacity;
}

/* ===============================
   Rehashing
   =============================== */

void rehash(HashTable *ht){

    int old_capacity = ht->capacity;
    HashNode *old_table = ht->table;

    ht->capacity = ht->capacity * 2;
    ht->size = 0;

    ht->table = malloc(sizeof(HashNode) * ht->capacity);

    for(int i=0;i<ht->capacity;i++)
        ht->table[i].status = 0;

    for(int i=0;i<old_capacity;i++){

        if(old_table[i].status == 1){

            int key = old_table[i].key;
            int value = old_table[i].value;

            int hash = hash1(key, ht->capacity);
            int j = 0;

            while(1){

                int index = linear_probe(hash,j,ht->capacity);

                if(ht->table[index].status != 1){

                    ht->table[index].key = key;
                    ht->table[index].value = value;
                    ht->table[index].status = 1;

                    ht->size++;
                    break;
                }

                j++;
            }
        }
    }

    free(old_table);
}

/* ===============================
   Insert
   probe_type:
   1 = Linear
   2 = Quadratic
   3 = Double Hashing
   =============================== */

void insert(HashTable *ht, int key, int value, int probe_type){

    float lf = (float)ht->size / ht->capacity;

    if(lf >= LOAD_FACTOR)
        rehash(ht);

    int hash = hash1(key, ht->capacity);

    int i=0;

    while(i < ht->capacity){

        int index;

        if(probe_type==1)
            index = linear_probe(hash,i,ht->capacity);

        else if(probe_type==2)
            index = quadratic_probe(hash,i,ht->capacity);

        else
            index = double_hash_probe(key,i,ht->capacity);

        if(ht->table[index].status != 1){

            ht->table[index].key = key;
            ht->table[index].value = value;
            ht->table[index].status = 1;

            ht->size++;
            return;
        }

        i++;
    }

    printf("Insertion failed\n");
}

/* ===============================
   Search
   =============================== */

int search(HashTable *ht, int key, int probe_type){

    int hash = hash1(key, ht->capacity);

    int i=0;

    while(i < ht->capacity){

        int index;

        if(probe_type==1)
            index = linear_probe(hash,i,ht->capacity);

        else if(probe_type==2)
            index = quadratic_probe(hash,i,ht->capacity);

        else
            index = double_hash_probe(key,i,ht->capacity);

        if(ht->table[index].status == 0)
            return -1;

        if(ht->table[index].status==1 && ht->table[index].key==key)
            return ht->table[index].value;

        i++;
    }

    return -1;
}

/* ===============================
   Delete
   =============================== */

void delete_key(HashTable *ht, int key, int probe_type){

    int hash = hash1(key, ht->capacity);

    int i=0;

    while(i < ht->capacity){

        int index;

        if(probe_type==1)
            index = linear_probe(hash,i,ht->capacity);

        else if(probe_type==2)
            index = quadratic_probe(hash,i,ht->capacity);

        else
            index = double_hash_probe(key,i,ht->capacity);

        if(ht->table[index].status == 0)
            return;

        if(ht->table[index].status==1 && ht->table[index].key==key){

            ht->table[index].status = 2;
            ht->size--;
            printf("Key deleted\n");
            return;
        }

        i++;
    }
}

/* ===============================
   Display
   =============================== */

void display(HashTable *ht){

    printf("\nHash Table\n");

    for(int i=0;i<ht->capacity;i++){

        if(ht->table[i].status == 1)
            printf("%d -> (%d,%d)\n",i,ht->table[i].key,ht->table[i].value);

        else
            printf("%d -> NULL\n",i);
    }

}

/* ===============================
   MAIN
   =============================== */

int main(){

    HashTable *ht = create_table();

    int probe_type = 1; 
    // 1 = Linear
    // 2 = Quadratic
    // 3 = Double Hashing

    insert(ht,10,100,probe_type);
    insert(ht,20,200,probe_type);
    insert(ht,30,300,probe_type);
    insert(ht,40,400,probe_type);
    insert(ht,50,500,probe_type);
    insert(ht,60,600,probe_type);

    display(ht);

    printf("\nSearch key 30: %d\n",search(ht,30,probe_type));

    delete_key(ht,30,probe_type);

    display(ht);

    return 0;
}