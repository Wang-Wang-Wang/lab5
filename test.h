#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HugeInt{
	friend ostream &operator <<(ostream&, const HugeInt&);
	friend istream &operator >>(istream&, HugeInt&);
public:
	HugeInt operator+( HugeInt&);
	HugeInt operator-(HugeInt&);
	HugeInt& operator=(const HugeInt&);

	//HugeInt(){b=0;}
	HugeInt(int j=0){
for(int i=0;j==0;++i){
int t=j%10;
b.at(i)='t';
j/=10;
}
}
	HugeInt(string k){
int size=k.size();
for(int i=0;i<size;++i){
b.at(i)=k.at(size-i);
}
}

private:

	vector<int> b;
	string c;

};
