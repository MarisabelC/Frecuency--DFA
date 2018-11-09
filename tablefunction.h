#include "position.h"
#include "const.h"

void Fill(int **table, string type, int row, int value);
void Init(int** table);
int** Allocate(int row);
void print(char start,char end);
void print(int start,int end,int** table);
void FillSuccesTable(bool* table,int* success);



void Fill(int **table, string type, int row, int value){

    int size=type.length();

    for (int r=0;r<size;r++){

        table[row][type[r]]=value;

    }
}

int** Allocate(int row){

    int** temp=new int* [row];//Create a dynamic memory

    int** rwalker=temp;//rwalker poit to the same place that temp

    for (int i=0;i<row;i++,rwalker++){

        *rwalker=new int[SIZE+1];//Create a dynamic memory
    }

    return temp;
}

void Init(int** table){



    for (int r=0;r<ROW;r++){

        for (int c=0;c<SIZE;c++){

            table[r][c]=-1;
        }
    }
}


void print(int start,int end,int** table){

    for (int r=0;r<ROW;r++){

        for (int c=start;c<=end;c++){

            cout<<table[r][c]<<" ";
        }
        cout<<endl<<endl;
    }
    cout<<endl<<endl;
}


void print(char start,char end){

    char symb=start;

    while(symb>=start && symb<=end){

        cout<<symb<<"  ";
        symb=symb+1;
    }
        cout<<endl<<endl;

}


void FillSuccessTable(bool* table,int* success){

    for (int i=0;i<ROW;i++){

        if (*success==i){
            table[i]=true;
            success++;
        }
        else
            table[i]=false;
    }

}
