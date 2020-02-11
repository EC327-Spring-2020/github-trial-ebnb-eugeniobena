#include <iostream>
using namespace std;

int main(){
	int looper=0;
	while(looper==0){
		int h=0;
		cout << "How tall is your ladder?";
		cin >> h;
		if (h==0){
			cout<<"The height can't be zero."<<endl;
		}
		while (h>0){
			if (h%2==0){
				cout<<"###"<<endl;
				h--;
			}
			else{
				cout<<"# #"<<endl;
				h--;
			}
		}
		if (h<0){
			cout<<"Invalid Input"<<endl;
			looper=1;
		}
	}

	return 0;
}		

