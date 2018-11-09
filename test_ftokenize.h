#ifndef TEST_FTOKENIZE
#define TEST_FTOKENIZE


void testFtokenize(){

    string a[]={"1.txt","2.txt",string()};
    ftokenize ftk(a);
    Token t;

    while(ftk.more()){

        ftk>>t;
        cout<<t;
        cout<<"file:"<<ftk.getNumFile()<<endl;
        cout<<"para:"<<ftk.getNumPara()<<endl;
    }
}
#endif // TEST_FTOKENIZE

