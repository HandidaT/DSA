#include <iostream>
extern "C"{
  #include "sqlite3.h"
}

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
  
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
  
    printf("\n");
    return 0;
}

int main(){
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("icd1553.db", &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, "ATTACH DATABASE ':memory:' AS ramdb;", NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, "create table ramdb.rins_icd as select * from ins_icd", NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, "select * from ramdb.rins_icd where MESSAGE_BLOCK_ID like 'C_01'", callback, 0, &messaggeError);
  
    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;
    sqlite3_close(DB);
    return (0);
}
