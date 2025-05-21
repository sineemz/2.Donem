#include<iostream>
#include<fstream>
using namespace std;

int main(){
    double L=0.1;
    double C=0.001;
    double R=5.0;
    double V0=15.0;
    
    double q=0.0;
    double i=0.0;
    double t=0.0;
    double dt=1.0;
    double t_max=1.0;
    ofstream outfile("rlc_data.txt");
    outfile<<"zaman(s)\tAkim(A)\tKapasitor Gerilim (V)"<<endl;
    
    while(t<=t_max){
    double Vc=q/C;
    double di_dt=(V0-R*i-Vc)/L;
    q+=i*dt;
    i+=di_dt*dt;
    t+=dt;
    cout<<t<<""<<i<<""<<Vc<<endl;
    outfile <<t<<"\t"<<i<<"\t"<<Vc<<endl;
    }
    outfile.close();
    cout<<"Simulasyon tamamlandi.Veriler 'rlc_data.txt'dosyasina kayit edildi."<<endl;
    return 0;
}