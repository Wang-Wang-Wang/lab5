#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include "test.h"
using namespace std;

ostream & operator <<(ostream& out,const HugeInt& output)
{
out << output.c;

return out;
}//done

istream & operator >> (istream & in,HugeInt & input)
{
string temp;
in >> temp;
int size=temp.size();
for(int i=0;i<size;++i)
input.b.at(i)=temp.at(size-i);
input.c=temp;

return in;
}//done

HugeInt HugeInt::operator+( HugeInt& rv){
	HugeInt temp;
	int carry=0;
	if((*this).b.size()<rv.b.size()){
	rv.b.push_back(0);
	for(int i=0;i<rv.b.size()-(*this).b.size();++i){
		(*this).b.push_back(0);	
}
}
	if((*this).b.size()>rv.b.size()){
	(*this).b.push_back(0);
	for(int i=0;i<(*this).b.size()-rv.b.size();++i){
		rv.b.push_back(0);
}
}
	if((*this).b.size()==rv.b.size()){
	(*this).b.push_back(0);
	rv.b.push_back(0);
}//same size
	for(int i=0;i<((*this).b.size()<rv.b.size())?(rv.b.size()):((*this).b.size());++i){
		temp.b.at(i)=(*this).b.at(i)+rv.b.at(i)+carry;
		if(temp.b.at(i)>9){
			temp.b.at(i)%= 10;
			carry = 1;
}
		else carry=0;
}//add
	for(int i=0;i<(*this).b.size()-1;i++){
	if((*this).b.back()==0)
		(*this).b.pop_back();
	else break;
}	
	for(int i=0;i<rv.b.size()-1;i++){
	if(rv.b.back()==0)
		rv.b.pop_back();
	else break;
}//take 0 off
return temp;

}//+

HugeInt HugeInt::operator-( HugeInt& rv){
	HugeInt change;
	HugeInt temp;
	if((*this).b.size()<rv.b.size()|((*this).b.size()==rv.b.size()&&(*this).b.at(rv.b.size()-1)<rv.b.at(rv.b.size()-1))){
		change=(*this);
		(*this)=rv;
		rv=change;

	if((*this).b.size()>rv.b.size()){
	for(int i=0;i<(*this).b.size()-rv.b.size();++i){
		rv.b.push_back(0);
}
}//change//same size
		int carry=0;
		for(int i=0;i<(*this).b.size();++i){
			if((*this).b.at(i)-carry-rv.b.at(i)<0){
				temp=(*this).b.at(i)-rv.b.at(i)-carry+10;
				carry=1;		
}
			else{	temp=(*this).b.at(i)-rv.b.at(i)-carry;
				carry=0;
}
}//minus
	for(int i=0;i<(*this).b.size()-1;i++){
	if((*this).b.back()==0)
		(*this).b.pop_back();
	else break;
}	
	for(int i=0;i<rv.b.size()-1;i++){
	if(rv.b.back()==0)
		rv.b.pop_back();
	else break;
}//take 0 off
	for(int i=0;i<temp.b.size();++i){temp.c.at(i)=temp.b.at(temp.b.size()-i-1);}
	c='-'+c;
// turn to string
	change=rv;
	rv=(*this);
	(*this)=change;
//change back
}//end if
	else {
	if((*this).b.size()>rv.b.size()){
	for(int i=0;i<(*this).b.size()-rv.b.size();++i){
		rv.b.push_back(0);
}
}//same size
		int carry=0;
		for(int i=0;(*this).b.size();++i){
			if((*this).b.at(i)-carry-rv.b.at(i)-carry<0){
				temp=(*this).b.at(i)-rv.b.at(i)-carry+10;
				carry=1;		
}
			else{	temp=(*this).b.at(i)-rv.b.at(i)-carry;
				carry=0;
}//minus
}
	for(int i=0;i<(*this).b.size()-1;i++){
	if((*this).b.back()==0)
		(*this).b.pop_back();
	else break;
}	
	for(int i=0;i<rv.b.size()-1;i++){
	if(rv.b.back()==0)
		rv.b.pop_back();
	else break;
}//take 0 off
	for(int i=0;i<temp.b.size();++i){temp.c.at(i)=temp.b.at(temp.b.size()-i-1);}
// turn to string
}
return temp;

}//-

HugeInt& HugeInt::operator=(const HugeInt& rv){
(*this).b=rv.b;
(*this).c=rv.c;
return (*this);
}
