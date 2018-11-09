#ifndef POSITION
#define POSITION
#include <iostream>
using namespace std;

class Pos{

public :

    Pos();
    Pos(int nextRow,string token,int nextPos);
    int getRow();
    int getPos();
    string getToken();

    friend ostream& operator<< (ostream& out,const Pos p);

private:

    int Next;
    int Row;
    string _token;


};

#endif // POSITION

Pos::Pos():Next(0),Row(0),_token(""){ }

Pos::Pos(int nextRow, string token, int nextPos):Next(nextPos),Row(nextRow){
    _token.append(token);
}

int Pos::getRow(){
    return Row;
}

int Pos::getPos(){
    return Next;
}

string Pos::getToken(){
    return _token;
}


ostream& operator<< (ostream& out,const Pos p){

    out<<"Row:"<<p.Row<<" "<<p._token<<" pos:"<<p.Next<<endl;
}
