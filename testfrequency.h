#ifndef TESTFREQUENCY
#define TESTFREQUENCY
#include "frequency.h"
#include "fstream"
//#include "../../Include/tokenizer.h"

void testFrequency(){

    Frequency<string,int> f;
    string _s;
    ifstream myFile;

    myFile.open("AlchemistBook.txt");

    if(myFile.fail()){
        cout<<"File Opening failed\n";
        exit(0);
    }

     while(!myFile.eof()){
        std::getline(myFile,_s);
//        cout<<_s;
        STokenizer t(_s);
        Token token;

        while(t.more()){
             t>>token;
//            if (token.getToken()!=SPACE)
//                f.Insert( token.getToken());

        }
     }

     myFile.close();

//     cout<<f.SwapKeyValues();
//     cout<<f;

}
#endif // TESTFREQUENCY

