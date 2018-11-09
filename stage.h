#ifndef STAGE
#define STAGE
#include <iostream>
#include <string>
#include <cstring>
#include "tokentype.h"

using namespace std;

char* String2Cstring(string input);

bool S1(char* input, char *&token);//Start

bool S2(char* input,char* token);//Alpha

bool S3(char* input,char* token);//Period

bool S4(char* input, char *&token);//Integer

bool S5(char* input, char *&token);//Space

bool S6(char* input,char* token);//Float

bool S7(char* input,char* token);//Negative

bool Search(char found,char* list);

int getSize(char *size);

#endif // STAGE


char* String2Cstring(string input){


    char* cstr = new char [input.length()+1];

    strcpy (cstr, input.c_str());

    return cstr;
}

bool S1(char* input,char*& token){

    char*walker=token;

    if (*input==END_OF_LINE)
        return false;
    while(*input!=END_OF_LINE){

        switch(*input){

        case'1':
        case'2':
        case'3':
        case'4':
        case'5':
        case'6':
        case'7':
        case'8':
        case'9':
        case'0':

            *walker=*input;
            walker++;
            input++;

            if (S4(input,walker)){
                *walker=*input;
                walker++;
            }
            else if(*input!=END_OF_LINE)
                return false;
        break;


        case'-':

            if (S7(input,walker)){
                *walker=*input;
                walker++;

            }
            else
                return false;

            break;
        case ' ':
            if(*token!='\0')
                return true;
        break;

        case'\0':
            return false;
        default:
            return false;
            break;

        }
        input++;
    }

    *walker='\0';

    return true;
}

bool S2(char *input, char *token){

    char*walker=token;
    if (*input==END_OF_LINE)
        return false;
    while(*input!=END_OF_LINE){

        *input=tolower(*input);

        switch(*input){

        case'a':
        case'b':
        case'c':
        case'd':
        case'e':
        case'f':
        case'g':
        case'h':
        case'i':
        case'j':
        case'k':
        case'l':
        case'm':
        case'n':
        case'o':
        case'p':
        case'q':
        case'r':
        case's':
        case't':
        case'u':
        case'v':
        case'w':
        case'x':
        case'y':
        case'z':
            *walker=*input;
        break;

        case ' ':
            if(*token!='\0')
                return true;
        break;
        case'\0':
            return false;
        default:
        return false;
        break;

        }
        walker++;
        input++;
    }
    *walker='\0';

    return true;
}


bool S3(char *input, char *token){

    switch (*input){

    case'.':
        input++;
        if(!Search(*input,token))
            return true;
        return false;
            break;
    default:
        return false;
    }
    return false;
}

bool S4(char* input,char*& token){

    switch(*input){
    case'1':
    case'2':
    case'3':
    case'4':
    case'5':
    case'6':
    case'7':
    case'8':
    case'9':
    case'0':
        *token=*input;
        return true;
        break;

    case'\0':
        return false;

    default:
        return false;
        break;

    }
    return false;

}

bool S7(char* input,char* token){

    switch (*input){

    case'-':
        input++;
        if (*token!=END_OF_LINE)
            return false;
        return (S4(input,token));
    default:
        return false;
        break;

    }
    return false;
}
bool S5(char* input,char*& token){

    switch(*input){

    case' ':
        *token=*input;
        return true;
    default :
        return false;
    }
}

bool S6(char *input, char *token){

    char* walker=token;
    while(*input!=END_OF_LINE){

        switch(*input){

        case'1':
        case'2':
        case'3':
        case'4':
        case'5':
        case'6':
        case'7':
        case'8':
        case'9':
        case'0':

            *walker=*input;
            walker++;
            input++;

            if (S4(input,walker)){
                *walker=*input;
                walker++;
                *walker='\0';
            }
            else if (S3(input,walker)){
                *walker=*input;
                walker++;
                *walker='\0';
            }

            break;

        case'-':

            if (S7(input,walker)){
                *walker=*input;
                walker++;
                *walker='\0';

            }
            else
                return false;

            break;
        case'.':
            if (!S3(input,walker)){
                *walker=*input;
                walker++;
                *walker='\0';
            }
            else
                return false;
            break;

        case ' ':
            if(*token!='\0')
                return true;
        break;

        case'\0':
            return false;
        default:
            return false;
            break;

        }
        input++;
    }

    *walker='\0';

    return true;
}

bool Search(char found,char* list){

    while(*list!=END_OF_LINE){
        if (*list==found){
            return true;
        }
        list++;
    }
    return false;
}

int getSize(char* size){

    char* walker=size;
    int _size=0;

    while (*walker!='\0'){
        _size++;
        walker++;
    }

    return _size;
}
