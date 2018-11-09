#ifndef SUCCESS_TABLE
#define SUCCESS_TABLE
#include "tablefunction.h"

class STable{

public:
    STable();
    bool& operator[](int index);

private:

    bool success[ROW];
};

#endif // SUCCESS_TABLE

STable::STable(){

    FillSuccessTable(success,RSUCCESS);
}

bool& STable::operator[](int index){
    return success[index];
}
