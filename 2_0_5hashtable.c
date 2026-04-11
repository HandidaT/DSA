#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 8
#define LOAD_FACTOR 0.75

typedef struct
{
    int key;
    int value;
    int status;
} HashNode;

typedef struct
{
    int size;
    int capacity;
    HashNode *table;
} HashTable;

enum ProbeType
{
    linear,
    quadratic,
    doubleHashing
};

int hash1 (int key, int capacity)
{
    return key % capacity;
}

int hash2 (int key, int capacity)
{
    return 1 + (key % (capacity-1));
}

HashTable* create_table()
{
    HashTable *ht = malloc(sizeof(*ht));
    ht->size = 0;
    ht->capacity = INITIAL_SIZE;

    ht->table = malloc(sizeof(*ht->table) * ht->capacity);

    for (int i = 0; i < ht->capacity; i++)
        ht->table[i].status = 0;

    return ht;
}

int linear_probing(int hash, int i, int capacity)
{
    return (hash + i) % capacity;
}

int quadratic_probing(int hash, int i, int capacity)
{
    return (hash + i * i) % capacity;
}

int double_hashing(int key, int i, int capacity)
{
    return (hash1(key, capacity) + i * hash2(key, capacity)) % capacity;
}

void rehash(HashTable *ht, int probe_type)
{
    int old_capacity = ht->capacity;
    HashNode *old_table = ht->table;

    ht->capacity = old_capacity * 2;
    ht->size = 0;

    ht->table = malloc(sizeof(*ht->table) * ht->capacity);

    for(int i = 0; i < ht->capacity; i++)
        ht->table[i].status = 0;

    for(int i = 0; i < old_capacity; i++)
    {
        if(old_table[i].status == 1)
        {
            int key = old_table[i].key;
            int value = old_table[i].value;
            int hash = hash1(key, ht->capacity);
            int j = 0;
            while(1)
            {
                int index;
                switch(probe_type)
                {
                    case linear:
                        index = linear_probing(hash, j, ht->capacity);
                        break;
                    case quadratic:
                        index = quadratic_probing(hash, j, ht->capacity);
                        break;
                    case doubleHashing:
                        index = double_hashing(key, j, ht->capacity);
                        break;
                }
                if (ht->table[index].status != 1)
                {
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

void insert (HashTable *ht, int key, int value, int probe_type)
{
    float lf = (float)ht->size / ht->capacity;
    if(lf >= LOAD_FACTOR)
        rehash(ht, probe_type);
    
    int hash = hash1(key, ht->capacity);
    int i = 0;

    while (i < ht->capacity)
    {
        int index;
        switch(probe_type)
        {
            case linear:
                index = linear_probing(hash, i, ht->capacity);
                break;
            case quadratic:
                index = quadratic_probing(hash, i, ht->capacity);
                break;
            case doubleHashing:
                index = double_hashing(key, i, ht->capacity);
                break;
        }

        if (ht->table[index].status == 0 || ht->table[index].status == 2)
        {
            ht->table[index].key = key;
            ht->table[index].value = value;
            ht->table[index].status = 1;

            ht->size++;
            return;
        }
        i++;
    }

    printf("\nInsertion failed\n");
}

void update (HashTable *ht, int key, int value, int probe_type)
{    
    int hash = hash1(key, ht->capacity);
    int i = 0;

    while (i < ht->capacity)
    {
        int index;
        switch(probe_type)
        {
            case linear:
                index = linear_probing(hash, i, ht->capacity);
                break;
            case quadratic:
                index = quadratic_probing(hash, i, ht->capacity);
                break;
            case doubleHashing:
                index = double_hashing(key, i, ht->capacity);
                break;
        }

        if(ht->table[index].status == 1 && ht->table[index].key == key)
        {
            ht->table[index].value = value;
            return;
        }
        i++;
    }

    printf("\nUpdate failed\n");
}

int search (HashTable *ht, int key, int probe_type)
{
    int hash = hash1(key, ht->capacity);

    int i = 0;

    while (i < ht->capacity)
    {
        int index;

        if (probe_type == linear)
            index = linear_probing(hash, i, ht->capacity);
        else if (probe_type == quadratic)
            index = quadratic_probing(hash, i, ht->capacity);
        else
            index = double_hashing(key, i, ht->capacity);

        if(ht->table[index].status == 0)
            return -1;

        if(ht->table[index].status == 1 && ht->table[index].key == key)
            return ht->table[index].value;
        
        i++;
    }

    return -1;
}

void delete_key (HashTable *ht, int key, int probe_type)
{
    int hash = hash1(key, ht->capacity);
    int i=0;

    while(i < ht->capacity)
    {
        int index;
        if(probe_type == linear)
            index = linear_probing(hash, i, ht->capacity);
        else if(probe_type == quadratic)
            index = quadratic_probing(hash, i, ht->capacity);
        else
            index = double_hashing(key, i, ht->capacity);

        if (ht->table[index].status == 1 && ht->table[index].key==key)
        {
            ht->table[index].status = 2;
            ht->size--;
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

/* =====================================================
   SEPARATE CHAINING HASH TABLE
   ===================================================== */

typedef struct ChainNode {
    int key;
    int value;
    struct ChainNode *next;
} ChainNode;

typedef struct {
    int capacity;
    int size;
    ChainNode **table;
} ChainHashTable;


/* ===============================
   Create Chaining Table
   =============================== */

ChainHashTable* create_chain_table(int capacity){

    ChainHashTable *cht = malloc(sizeof(*cht));

    cht->capacity = capacity;
    cht->size = 0;

    cht->table = malloc(sizeof(ChainNode*) * capacity);

    for(int i=0;i<capacity;i++)
        cht->table[i] = NULL;

    return cht;
}


/* ===============================
   Insert (Chaining)
   =============================== */

void insert_chain(ChainHashTable *cht, int key, int value){

    int index = hash1(key, cht->capacity);

    ChainNode *newNode = malloc(sizeof(*newNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if(cht->table[index] == NULL){
        cht->table[index] = newNode;
    } else {
        ChainNode *temp = cht->table[index];

        // update if key exists
        while(temp != NULL){
            if(temp->key == key){
                temp->value = value;
                free(newNode);
                return;
            }
            if(temp->next == NULL) break;
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cht->size++;
}


/* ===============================
   Search (Chaining)
   =============================== */

int search_chain(ChainHashTable *cht, int key){

    int index = hash1(key, cht->capacity);

    ChainNode *temp = cht->table[index];

    while(temp){
        if(temp->key == key)
            return temp->value;
        temp = temp->next;
    }

    return -1;
}


/* ===============================
   Delete (Chaining)
   =============================== */

void delete_chain(ChainHashTable *cht, int key){

    int index = hash1(key, cht->capacity);

    ChainNode *temp = cht->table[index];
    ChainNode *prev = NULL;

    while(temp){

        if(temp->key == key){

            if(prev == NULL)
                cht->table[index] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            cht->size--;

            printf("Key deleted (chaining)\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Key not found (chaining)\n");
}


/* ===============================
   Display (Chaining)
   =============================== */

void display_chain(ChainHashTable *cht){

    printf("\nChaining Hash Table\n");

    for(int i=0;i<cht->capacity;i++){

        printf("%d -> ", i);

        ChainNode *temp = cht->table[i];

        while(temp){
            printf("(%d,%d) -> ", temp->key, temp->value);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{

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

    printf("\n\n===== SEPARATE CHAINING =====\n");
    
    ChainHashTable *cht = create_chain_table(8);
    
    insert_chain(cht, 10, 100);
    insert_chain(cht, 18, 180);  // collision
    insert_chain(cht, 26, 260);  // collision
    
    display_chain(cht);
    
    printf("\nSearch 18 = %d\n", search_chain(cht, 18));
    
    delete_chain(cht, 18);
    
    display_chain(cht);

    return 0;
}