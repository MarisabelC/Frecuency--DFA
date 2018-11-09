#ifndef TOKEN
#define TOKEN
#include <iostream>

using namespace std;

class Token{

public:

    Token();
    Token(string token,string type);
    Token (char token);
    Token (Token token, string type);
    bool empty();
    string getToken();
    string TokenType();
    friend ostream& operator <<(ostream& outs,const Token& t);


private:
    string _token;
    string _type;

};

#endif // TOKEN

Token::Token():_token(""),_type("empty"){}

Token::Token(string token, string type):_token(token),_type(type){
    _token.assign(token);
}

Token::Token (char token){
    _token.push_back(token);
}

Token::Token (Token token,string type):_type(type){
//    _token=token;
}

string Token::getToken(){
    return _token;
}

string Token::TokenType(){
    return _type;
}

bool Token::empty(){

    return _token.empty();

}

ostream& operator <<(ostream& outs,const Token& t){

    outs<<t._token/*<<","<<t._type*/<<endl;
    return outs;
}
