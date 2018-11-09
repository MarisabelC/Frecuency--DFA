#ifndef STATETABLE
#define STATETABLE
#include "success_table.h"


class Table{

public:

    Table();//Constructor
    //Allocate a double pointer.The number of columns are 255
    void FillTable();//
    int*& operator[](int pos);

private:

    int **table;
};

#endif // STATETABLE


Table::Table(){

    table=Allocate(ROW);
    Init(table);
    FillTable();


}


void Table::FillTable(){


    Fill(table,DIGIT,0,1);
    Fill(table,DIGIT,1,1);
    Fill(table,DOT,1,2);
    Fill(table,DOT,0,2);
    Fill(table,DIGIT,2,3);
    Fill(table,DIGIT,3,3);
    Fill(table,ALPHA,4,5);
    Fill(table,ALPHA,5,5);
    Fill(table,DIGIT,5,5);
    Fill(table,APOSTROPHES,5,6);
    Fill(table,ALPHA,6,7);
    Fill(table,ALPHA,7,7);
    Fill (table,SPACE,8,9);
    Fill (table,OPERATOR,10,11);
    Fill (table,PUN,12,13);
    Fill (table,UNKNOWN,14,15);
    Fill (table,END,16,17);


}


int*& Table::operator[](int pos){

    return table[pos];
}
