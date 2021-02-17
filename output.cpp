#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<sstream>
#include<fstream>

using namespace std;

class Compare
{
public:
	bool operator()(pair<int,int>pair1,pair<int,int>pair2){
		return pair1.first>pair2.first;
	}

}; 

string ToString(int in){
        stringstream stream;
        stream<<in;
        return stream.str();
};


void Sort_Output(int *values,int size,int NumberOfGroup){
	sort(values,values+size);
	string OutputFileName="output"+ToString(NumberOfGroup)+".txt";
	ofstream OutputFile(OutputFileName.c_str());//outputfile
	for(int i=0;i<size;i++){
		OutputFile<<values[i]<<'\n';
	}
	OutputFile.close();
};

string FileMerge(int counter){
	std::priority_queue<pair<int,int>,std::vector<pair<int,int>>,Compare>minHeap;
	ifstream* deal=new ifstream[counter];

	for(int i=1;i<=counter;i++){
		string SortedInputFile="output"+ToString(i)+".txt";
		deal[i-1].open(SortedInputFile.c_str());
		int firstValue;
		deal[i-1]>>firstValue;
		minHeap.push(pair<int,int>(firstValue,i-1));//second value in pair keeps
	}
	
	string OutputFileName="output.txt";
	ofstream OutputFile(OutputFileName.c_str());
	while(minHeap.size()>0){
		pair<int,int>minPair=minHeap.top();
		minHeap.pop();
		OutputFile<<minPair.first<<'\n';
		int nextValue;
		flush(OutputFile);
		if(deal[minPair.second]>>nextValue){
			minHeap.push(pair<int,int>(nextValue,minPair.second));
		}
	}
	for(int i=1;i<=counter;i++){
		deal[i-1].close();
	}
	OutputFile.close();
	delete[] deal;

	return OutputFileName;

}

int main(){
	int NumberOfGroup=1;//divide into how many group
	int GroupSize=10000000;
	int *inputValues=new int[GroupSize];
	int readValue=0;
	int CurrentCount=0;
	bool unprocessedGroup=true;
	ifstream InputFile("input.txt");

	while(InputFile>>readValue){
		unprocessedGroup=true;
		inputValues[CurrentCount++]=readValue;
		if(CurrentCount==GroupSize){
			Sort_Output(inputValues,CurrentCount,NumberOfGroup);
			NumberOfGroup++;
			CurrentCount=0;
			unprocessedGroup=false;
		}
	}

	if(unprocessedGroup){
		Sort_Output(inputValues,CurrentCount,NumberOfGroup);
	}
	else{
		NumberOfGroup--;
	}
	
	InputFile.close();
	delete[] inputValues;
	if(NumberOfGroup!=0){
		std::priority_queue<pair<int,int>,std::vector<pair<int,int>>,Compare>minHeap;
		cout<<"output is in file:"<<FileMerge(NumberOfGroup);
	}
		

	return 0;
}
