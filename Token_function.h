#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;
#include "stack.h"
#include"token.h"
#include "statetable.h"

bool IsSuccess(STable table, int row);

Token Process(Table table,string t,int& pos,int state,STable success,string type);

string createToken(STable table, Stack<Pos*> token,int& pos);



string createToken(STable table, Stack<Pos*> token,int& pos){

    string s;

         while (!token.empty() && !IsSuccess(table,token.top()->getRow())){

             pos=token.pop()->getPos();
         }

         if (!token.empty())

             s.append(token.pop()->getToken());


         while (!token.empty()){

             token.pop();
         }

         return s;
}

Token Process(Table table,string t,int& pos,int state,STable success,string type){

    Pos* item;
    Stack<Pos*> token;
    string s;

    while(state!=-1){

        state=table[state][t[pos]];
        s.push_back(tolower(t[pos]));
        item=new Pos(state,s,pos);
        token.push(item);
        pos++;
    }

    Token temp(createToken(success,token,pos),type);

    return temp;

}

bool IsSuccess(STable table,int row){

    return table[row];
}



