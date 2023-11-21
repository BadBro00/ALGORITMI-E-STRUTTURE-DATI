#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class GiocoQuindici{
private:
	vector<int> Numeri;
	fstream file;
public:
	GiocoQuindici(string nome_file){
		file.open(nome_file,ios::in);
	}
	fstream* GetFile(){return &file;}
	void LeggiNums();
	bool Check_Solution();
};

void GiocoQuindici::LeggiNums(){
	if(GetFile()->is_open()){
		cout << "File aperto\n";
	}
	int nums;
	while(*GetFile() >> nums){
		this->Numeri.push_back(nums);
	}
}
bool GiocoQuindici::Check_Solution(){
	vector<int>::iterator it;
	int i=0;
	for(it = Numeri.begin(); it != Numeri.end(); it++){
		//cout << *it << endl;
		if(*it != (i+1)){
			return false;
		}
		i++;
	}
	return true;
}
int main(){
	GiocoQuindici GQ("Quindici.txt");
	GQ.LeggiNums();
	if(GQ.Check_Solution()){
		cout << "La soluzione è corretta\n";
	}else{
		cout << "La soluzione non è corretta\n";
	}
}
