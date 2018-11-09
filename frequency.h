#ifndef FREQUENCY
#define FREQUENCY
#include "map.h";


class Frequency{

public:

    Frequency();

    Frequency(Map<string, int, DupAdd<string, int> > _list);

    Frequency freq(Map<string, int, DupAdd<string, int> > _list);

    friend ostream& operator<< (ostream& out,const Frequency list);



private:
    Map<string,int, DupAdd<string,int> >  list;
};



#endif // FREQUENCY


Frequency::Frequency(){}

Frequency::Frequency(Map<string,int,DupAdd<string,int> >_list){

    list=_list;
}

Frequency Frequency::freq(Map<string,int,DupAdd<string,int> >_list ){

    List<Pair<int,string>,DupNothing<int,string>,Bigger<int> > cpy;
    cpy=_list.SwapKeyValues();
    cout<<_list;


}




ostream& operator<< (ostream& out,const Frequency _list){

    out<<_list.list;
    return out;

}
