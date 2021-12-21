#include<iostream>
#include<vector>
#include<fstream>
#include<utility>
using namespace std;

int main(){
	ifstream f("DOITHONG.INP");
	string s;
	vector<vector<char>>photo(1000,vector<char>(1000));
	int x=0,count=0;
	while(!f.eof()){
		getline(f,s);
		copy(s.begin(),s.end(),photo[x].begin());
		++x;
	}
	f.close();
	for(int i=0;i<1000;++i){
		for(int j=0;j<1000;++j){
			if(photo[i][j]=='@'){
				if(i==0) count++;
				else if(j==0){
					if(photo[i-1][j]!='@'&&photo[i][j+1]!='@') count++;
				}
				else{
					if(photo[i-1][j]!='@'&&photo[i][j-1]!='@'&&photo[i][j+1]!='@') count++;
				}
			}
		}
	}
	ofstream f1("DOITHONG.OUTP");
	f1<<count;
	f1.close();
}
