#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;

string ToString(int val){
	stringstream stream;
	stream<<val;
	return stream.str();
}

int main(){

	int n=0;//set the number of number
	int output=0;
	int max=2147483647;
	int min=-2147483648;
	int test=0;
	cout<<"please input the number to generate"<<endl;
	cin>>n;
	string filename="input.txt";
	fstream fp;
       	fp.open(filename,ios::out);
	if(!fp){
                cout<<"Fail to open file: "<<endl;
	  }
        srand(time(NULL));//SET THE SEED
        for(int i=0;i<n;i++){
                output=rand()%(max-0+1)+0;
                test=rand()%(1-0+1)+0;
                if(test==0){
                        output=output*1;
                }
                else{
                        output=output*(-1);
                }
                fp<<output<<endl;
        }
        fp.close();
	return 0;
}
