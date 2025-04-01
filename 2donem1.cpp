#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double const PI=3.141593;
int main(){
	float h=1.0;
	float x=PI/4;
	float ilt,gt,simt,tt;
	tt=cos(x);
	ilt=(sin(x+h)-sin(x-h)/(2*h));
	cout<<setw(15)<<"h degeri"<<setw(15)<<"ileri turev"<<setw(15)<<"geri turev"<<setw(15)<<"simetrik turev"<<setw(15)<<"tam turev"<<setw(15)<<"hata"<<endl;
	cout<<setw(15)<<h <<setw(15)<<ilt<<setw(15)<<gt<<setw(15)<<simt<<setw(15)<<tt-simt<<endl;
	while (h>1e-10){
		h=h/10;
		ilt=(sin(x+h)-sin(x)/h);
		gt=(sin(x)-sin(x-h)/h);
		simt=(sin(x+h)-sin(x-h)/(2*h));
		cout<<setw(15)<<h <<setw(15)<<ilt<<setw(15)<<gt<<setw(15)<<simt<<setw(15)<<tt-simt<<endl;
		
	}
	return 0;
}