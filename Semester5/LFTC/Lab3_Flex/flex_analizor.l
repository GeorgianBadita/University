%{
    
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define COUNT_PREDEF 33

char PREDEF_TABLE[][20]  = {
    "ID", "CONST", "#include", "<iostream>", "using", "namespace", "std", "int", "main", "float", "return",
    "cin", "cout", "while", "if", "+", ";", ",", "{", "}", "[", "]", "(", ")", "-", "%", "/", ">>", "<<",
    "=", "<", ">", "*"
};

/**
 * Function for searching an element into the predef table
 * @param elem - element to be found
 * @return: the position if the element exists, -1 otherwise
 **/ 
int findInPredef(char* elem){
    for(int i = 0; i<COUNT_PREDEF; i++){
        if(strcmp(PREDEF_TABLE[i], elem) == 0){
            return i;
        }
    }
    return -1;
}

/**
 * Struct for table entry
 * @param hash: hashCode of element
 * @param key: element's key
 * @param value: element's value
 **/
struct TableEntry{
    int hash;
    int key;
    char* value;
};
typedef struct TableEntry TableEntry;

/**
 * Structure for HashTable - open addressing
 * @param DEFAULT_SIZE - starting size of the hashTable
 * @param EMPTY_VALUE - empty value of the hashTable
 * @param DELETED_VALUE - deleted value of the hashTable
 * @param LOAD_FACTOR - load factor of the hashTable
 * @param MIN_FACTOR - minimum load factor of the hashTable
 * @param container - container to store TableEntries
 **/
struct HashTable{
    int DEFAULT_SIZE;
    TableEntry* EMPTY_VALUE;
    TableEntry* DELETED_VALUE;
    double LOAD_FACTOR;
    double MIN_FACTOR;
    int size;
    int containerSize;
    int deletedSize;
    TableEntry** container;
};

typedef struct HashTable HashTable;

/**
 * Function to insert a new element into a hashtable
 * @param table - table to insert into
 * @param key - key of the element
 * @param value - value of the element
 * @return:
 */
int put(HashTable* table, int key, char* value);

/**
 * Function to delete an element from the HashTable
 * @param key - key to be deleted
 * @return - 0 if the element is deleted, -1 it there is no element with that key
 */
int delete(HashTable* table, int key);

/**
 * Function to calculate a hash based on a key
 * @param key- key whose hash must be calculated
 * For simplicty we'll consider hash(key) = key
 **/
int getHash(int key){
    return key;
}


/**
 * Function to create an empty TableEntry
 * @return: pointer to TableEntry
 **/
TableEntry* createEmptyEntry(){
    TableEntry* entry = (TableEntry*)malloc(sizeof(TableEntry));
    entry->hash = -1;
    entry->key = -1;
    char* tmp = (char*)malloc(2* sizeof(char));
    strcpy(tmp, "-1");
    entry->value = tmp;
    return entry;
}

/**
 * Function to create a deleted TableEntry
 * @return: pointer TableEntry
 */
TableEntry* createDeletedEntry(){
    TableEntry* entry = (TableEntry*)malloc(sizeof(TableEntry));
    entry->hash = -2;
    entry->key = -2;
    char* tmp = (char*)malloc(2* sizeof(char));
    strcpy(tmp, "-2");
    entry->value = tmp;
    return entry;
}

/**
 * Function to create an entry given a key and a value
 * @param key - entry key
 * @param value - entry value
 */
TableEntry* createEntry(int key, char* value){
    TableEntry* tmp = (TableEntry*)malloc(sizeof(TableEntry));
    tmp->key = key;
    tmp->hash = getHash(key);
    char* tmpChar = (char*)malloc(strlen(value)* sizeof(char));
    strcpy(tmpChar, value);
    tmp->value = tmpChar;
    return tmp;
}

/**
 * Function to check if two table entries are equal
 * @param e1 - first entry
 * @param e2 - second entry
 * @return - 1 if the entries are equal, 0 otherwise
 */
int equalsEntry(TableEntry* e1, TableEntry* e2){
    if(0 == strcmp(e1->value, e2->value) && e1->key == e2->key && e1->hash == e2->hash){
        return 1;
    }
    return 0;
}


/**
 * Function to copy an entry
 * @param entry - entry to be copied
 * @return - new entry
 */
TableEntry* copyEntry(TableEntry* entry){
    TableEntry* newEntry = (TableEntry*)malloc(sizeof(TableEntry));
    newEntry->key = entry->key;
    newEntry->hash = entry->hash;
    char* tmp = (char*)malloc(sizeof(char)*strlen(entry->value));
    strcpy(tmp, entry->value);
    newEntry->value = tmp;
    return newEntry;
}

/**
 * Function to print a TableEntry
 * @param entry - enrey to be printed
 */
void printEntry(TableEntry* entry){
    printf("%d : %s", entry->key, entry->value);
}

/**
 * Function to destroy a table entry
 * @param tmp - TableEntry
 **/
void destroyEntry(TableEntry* tmp){
    free(tmp);
}

/**
 * Function to create a HashTable
 * @return: pointer to Hashtable
 **/
HashTable* createHashtable(){
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->DEFAULT_SIZE = 8;
    hashTable->DELETED_VALUE = createDeletedEntry();
    hashTable->EMPTY_VALUE = createEmptyEntry();
    hashTable->LOAD_FACTOR = (double)2/3;
    hashTable->MIN_FACTOR = (double) 1/3;
    hashTable->size = 0;
    hashTable->containerSize = hashTable->DEFAULT_SIZE;
    hashTable->deletedSize = 0;
    TableEntry** tmp = (TableEntry**)malloc(hashTable->DEFAULT_SIZE*sizeof(TableEntry*));
    for(int i = 0; i<hashTable->DEFAULT_SIZE; i++){
        TableEntry* tmpEntry;
        tmpEntry = createEmptyEntry();
        tmp[i] = tmpEntry;
    }
    hashTable->container = tmp;
    return hashTable;
}

/**
 * Function to check if the hashtable contains a given key
 * @param key - key to be searched
 * @param table - hashTable to be searched into
 * @return - 1 if the key is in the hashtable, 0 otherwise
 */
int contains(HashTable* table, int key){
    int hashCode = getHash(key);
    int rootIndex = hashCode;
    for(int offset = 0; offset < table->containerSize; ++offset){
        int index = (rootIndex + offset) % table->containerSize;
        TableEntry* element = table->container[index];
        if(element->hash == hashCode && element->key == key){
            return 1;
        }
    }
    return 0;
}

/**
 * Function to get the insert position of a new element into the hashtable
 * @param table - Hashtable to insert into
 * @param key - key to insert
 * @return: integer - representing the position to insert
 */
int getInsertPos(HashTable* table, int key){
    int hashCode = getHash(key);
    int rootIndex = hashCode;
    for(int offset = 0; offset < table->containerSize; ++offset){
        int index = (rootIndex + offset) % table->containerSize;
        TableEntry* element = table->container[index];
        if(1 == equalsEntry(element, table->EMPTY_VALUE)){
            return index;
        }
    }
    return -1;
}

/**
 * Function to copy the content of a hashTable into a new table
 * @param dest - new table
 * @param table - old table
 */
TableEntry**  copyContainer(HashTable* table){
    TableEntry** newTabale = (TableEntry**)malloc(table->containerSize* sizeof(TableEntry*));
    for(int i = 0; i<table->containerSize; i++){
        newTabale[i] = copyEntry(table->container[i]);
    }
    return newTabale;
}


/**
 * Function to resize a hashTable
 * @param table - hashTable to be resized
 */
void resize(HashTable* table){
    TableEntry** oldContainer = copyContainer(table);
    int oldContainerSize = table->containerSize;
    for(int i = 0; i<table->containerSize; ++i){
        destroyEntry(table->container[i]);
    }
    free(table->container);
    int oldSize = table->size;
    table->containerSize = oldSize/table->MIN_FACTOR;
    TableEntry** tmp = (TableEntry**)malloc(table->containerSize*sizeof(TableEntry*));
    for(int i = 0; i<table->containerSize; i++){
        tmp[i] = createEmptyEntry();
    }
    table->container = tmp;
    for(int i = 0; i<oldContainerSize; i++){
        if(0 == equalsEntry(oldContainer[i], table->DELETED_VALUE) && 0 == equalsEntry(oldContainer[i], table->EMPTY_VALUE)) {
            put(table, oldContainer[i]->key, oldContainer[i]->value);
        }
        destroyEntry(oldContainer[i]);
    }
    free(oldContainer);
}

/**
 * Function to insert a new element into a hashtable
 * @param table - table to insert into
 * @param key - key of the element
 * @param value - value of the element
 * @return:
 */
int put(HashTable* table, int key, char* value){
    if(0 == contains(table, key)){
        int index = getInsertPos(table, key);
        if(-1 != index){
            table->container[index] = createEntry(key, value);
            table->size ++;
        }
    }
    double factor = (double)(table->deletedSize + table->size) / table->containerSize;
    if(factor > table->LOAD_FACTOR){
        resize(table);
    }
}

/**
 * Function to delete an element from a hashTable
 * @param table - table to delete from
 * @param key - key to be deleted
 */
int delete(HashTable* table, int key){
    if(1 == contains(table, key)){
       int index = -1;
       for(int i = 0; i<table->containerSize; i++){
           if(table->container[i]->key == key){
               index = i;
               break;
           }
       }
       if(index != -1){
           table->container[index] = table->DELETED_VALUE;
           table->size --;
           table->deletedSize ++;
       }
    }
    return -1;
}


/**
 * Function to print a hashtable
 * @param table - table to be printed
 */
void printTable(HashTable* table){
    printf("{\n");
    for(int i = 0; i<table->containerSize; i++){
        if(0 == equalsEntry(table->container[i], table->EMPTY_VALUE) && 0 == equalsEntry(table->container[i], table->DELETED_VALUE)) {
            printEntry(table->container[i]);
            printf("\n");
        }
    }
    printf("}");
}


/**
 * Function to destroy a hashTable
 * @param table - HashTable to be destroyed
 **/
void destroyHashtable(HashTable* table){
    for(int i = 0; i<table->size; i++){
        destroyEntry(table->container[i]);
    }
    destroyEntry(table->EMPTY_VALUE);
    destroyEntry(table->DELETED_VALUE);
    free(table);
}


/**
 * Function to calculate the ascii sum of a string
 * @param str - string whose ascii sum we need to calculate
 * @return - integer representing ascii sum of str characters
 */
int asciiSum(char* str){
    int sum = 0;
    for(int i = 0; i<strlen(str); ++i){
        sum += (str[i] - 'a') + 97;
    }
    return sum;
}

enum{INTEGER, FLOAT, IDENTIFIER, CONSTANT};

%}

digit [0-9]*
integer 0|([1-9])[0-9]*
character [a-zA-Z]


%%
{integer}|{integer}\.{digit}+ {return CONSTANT;}
{character}|{character}({character}{digit})* {return IDENTIFIER;}
%%

int yywrap(){
    return 1;
}

main(){
    int result;
    int running = 1;
    while(running){
        result = yylex();   
        switch(result){
            case CONSTANT: printf("constant"); break;
            case IDENTIFIER: printf("identifier"); break;
        }
    }
}