#include <iostream>
using namespace std;

const string DIGIT="0123456789";
const string PUN=".:;!?,";
const string ALPHA="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string OPERATOR= "-+/*^";
const string DOT=".";
const string SPACE=" ";
const string APOSTROPHES="'";
const string SYMBOL="<>=";
const string UNKNOWN="`~@#$%&|'“_-()[]{}";
const string TYPE[]={"NUMBER","ALPHANUMERIC","SPACE","OPERATOR","PUNCTUATION","UNKNOWN","END"};
const string END="\0";
int SIZE=255;
const int ROW=20;
int RSUCCESS[]={1,3,5,7,9,11,13,15,17};
int START[]={0,4,8,10,12,14,16};



