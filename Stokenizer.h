#ifndef STOKENIZER
#define STOKENIZER
#include "Token_function.h"
#include <iostream>
using namespace std;

class STokenizer{

public:

    //Constructor
    STokenizer();
    STokenizer(string s);

    bool more();
    //postcondition: return true if exist more token in the string

    //Mutator
    void operator=(string _string);
    //postcondition:Overloaded function. Set the private member equal to
    //string. Position is reset to zero.

    friend Token & operator>>(STokenizer& s,Token &t);
    //postcondition:Return the next token

    Token next(int start=*START);
    //postcondition: return a token

private:

    string token;
    int _pos;
    Table _table;
    STable success;
};

#endif // TOKENIZER

STokenizer::STokenizer():token(string()),_pos(0){

}

STokenizer::STokenizer(string s):_pos(0){
    token=s;
}

void STokenizer::operator=(string _string){

    token=_string;
    _pos=0;
}

bool STokenizer::more(){

    if(token[_pos]!='\0')
        return true;
    return false;
}

Token STokenizer::next(int start){
    Token t;
    switch (start){

    case 0://Number

        t=Process(_table,token,_pos,START[0],success,TYPE[0]);
        if (!t.empty())
            return t;

    case 1: //AlphaNumeric

        t=Process(_table,token,_pos,START[1],success,TYPE[1]);
        if (!t.empty())
            return t;

    case 2://Space

        t=Process(_table,token,_pos,START[2],success,TYPE[2]);
        if  (!t.empty())
            break;

    case 3: //OPERATOR
        t=Process(_table,token,_pos,START[3],success,TYPE[3]);
        if (!t.empty())
            return t;

    case 4: //PUNCTUATION

        t=Process(_table,token,_pos,START[4],success,TYPE[4]);
        if (!t.empty())
            return t;


    case 5: //UNKNOWN

        t=Process(_table,token,_pos,START[5],success,TYPE[5]);
        if (!t.empty())
            return t;

    default:
        _pos++;
        break;
    }

}

Token & operator>>(STokenizer& s,Token &t){

    t=s.next();

    return t;
}
