#ifndef FTOKENIZER
#define FTOKENIZER
#include "Stokenizer.h"
#include <fstream>

class ftokenize{

public:

    const int MAX=10;

    ftokenize(string _file);
    //postcondition: number of paragraph is set to 1 and the number
    //of file is set to 0. The array is copy to the private member _f

    ftokenize (string _file[]);
    //precondition: the last element of the array must be string()
    //Ex. array[]={file1.txt,file2,string()}

    //postcondition: number of paragraph is set to 1 and the number
    //of file is set to 0. The array is copy to the private member _f

    //Accessor

    int getNumPara();
    //postcondition: return number of paragraph

    int getNumFile();
     //postcondition: return number of file in the array

    bool more();
    //postcondition: return true if exist more token in the file

    Token nextToken();
    //Postcondition: return the next token

    friend Token & operator>>(ftokenize& s,Token &t);
    //Postcondition: Return the next token

    int getTotalFiles();

private:

    bool getNewParagraph();//get the new paragraph
    bool getNewFile();//get the new file
    string* _f=new string[MAX];//array of file
    ifstream file;
    STokenizer _stk;
    int total_files;
    int num_file;
    int num_paragraph;
    void init();//Initialize each element of _f to string()

};



ftokenize::ftokenize(string _file):num_file(0),num_paragraph(0){
    init();
    _f[0]=_file;
    getNewFile();
    getNewParagraph();
    total_files = 1;

}

void ftokenize::init(){

    for(int i=0;i<MAX;i++)
        _f[i]=string();
}

ftokenize::ftokenize (string _file[]):num_file(0),num_paragraph(0){
    int i;

    init();
    total_files = TOTAL_FILES;
    for (i=0;/*_file[i]!=string()*/ i < total_files;++i){
        _f[i]=_file[i];
    }

    getNewFile();
    getNewParagraph();

}

//Accessor
int ftokenize::getNumPara(){

    return num_paragraph;

}

int ftokenize::getNumFile(){

    return num_file;
}

int ftokenize::getTotalFiles(){
    return total_files;
}

bool ftokenize::more(){
    if(_f[num_file]!=string())
        return true;
    return false;
}


Token ftokenize::nextToken(){

    Token t;
    bool New=true;

    if (!_stk.more()){
        if (!getNewParagraph()){
            file.close();
            num_file++;
            New=getNewFile();
            getNewParagraph();
        }
    }

    if (New && _stk.more()){
        _stk>>t;
        return t;
    }

}

bool ftokenize::getNewParagraph(){

    string text,line;

    if (!file.eof()){
        do{
            getline(file,line);
            int len=line.length();
            if(len>0)
                line.insert(len," ");
            text+= line;
        } while(line != ""&& !file.eof());

        _stk=text;
        num_paragraph++;
        return true;
    }
    return false;

}

bool ftokenize::getNewFile(){
    if (/*_f[num_file]!=string()*/num_file < total_files){
        file.open(_f[num_file]);
        if(file.fail()){
            cout<<"File Opening failed\n";
            exit(0);
        }
        num_paragraph=0;
        return true;
    }
    return false;
}

Token & operator>>(ftokenize& s,Token &t){

    t=s.nextToken();

    return t;
}



#endif // FTOKENIZER
