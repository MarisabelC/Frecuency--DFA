#ifndef STOKENIZE
#define STOKENIZE
#include "token.h"

class Stokenize{

public:
    Stokenize();
    Stokenize(string s);
    Token GetNextToken();
    bool More();

private:

    char* str;
    int _pos;

};

Stokenize::Stokenize():str(NULL),_pos(0){}

Stokenize::Stokenize(string s):_pos(0){
    str=String2Cstring(s);
}


Token Stokenize::GetNextToken(){

    char* input=str+_pos,*walker=str+_pos;
    char* token=new char[20];
    *token='\0';
    if (S5(walker,token)){
        Token t(token,SPACE);
        _pos++;
        return t;
    }
    while(!S5(walker,token)){
       _pos++;
       walker++;
    }

    if(S1(input,token)){

        Token t(token,INTEGER);
        return t;
    }

    else if(S2(input,token)){

        Token t(token,ALPHA);
        return t;
    }

    else if(S6(input,token)){

        Token t(token,FLOAT);
        return t;
    }


}

bool Stokenize::More(){

    if(*str+_pos!=END_OF_LINE)
        return true;
    return false;
}


#endif // STOKENIZE

