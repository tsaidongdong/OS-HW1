#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream read;
    read.open("record6.txt",ios::in);
    fstream write;
    write.open("CPU_MEM_two1.txt",ios::out);
    char buffer[80];
    if(!read){
        cout<<"no!!\n";
    }
    int i,j,k;
    /*for(i=0;i<7;++i){
        read.getline(buffer,sizeof(buffer));

    }
    read.getline(buffer,sizeof(buffer));
    cout<<buffer<<endl;
    cout<<buffer[3]<<buffer[4]<<buffer[5]<<buffer[6];
    if(buffer[3]=='2' && buffer[4]=='4' && buffer[5]=='9' && buffer[6]=='9'){
        cout<<"\nyes\n";
    }*/
    /*for(i=0;i<184;++i){
        read.getline(buffer,sizeof(buffer));
    }
    for(i=0;i<7;++i){
        read.getline(buffer,sizeof(buffer));

    }
    read.getline(buffer,sizeof(buffer));
    cout<<buffer<<endl;*/

    //write<<buffer<<endl;
    while(true){
        if(read.eof()==true){
            break;
        }
        read.getline(buffer,sizeof(buffer));
        if(buffer[3]=='8' && buffer[4]=='6' && buffer[5]=='3' && buffer[6]=='6'){
            cout<<buffer<<endl;
            write<<buffer<<endl;
        }
        //write<<buffer<<endl;
    }
    read.close();
    write.close();
    return 0;
}
