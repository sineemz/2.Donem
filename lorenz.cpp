#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib> 

using namespace std;


void lorenzSystem(const double y[], double f[]) {
    const double sigma = 10.0;
    const double rho = 28.0;
    const double beta = 8.0/3.0;
    
    f[0] = sigma * (y[1] - y[0]);
    f[1] = -y[0]*y[2] + rho*y[0] - y[1];
    f[2] = y[0]*y[1] - beta*y[2];
}


void rk4Step(double y[], double h, void (*system)(const double[], double[])) {
    const int n = 3; 
    double k1[n], k2[n], k3[n], k4[n], yTemp[n];
    
    
    system(y, k1);
    for (int i = 0; i < n; i++) {
        yTemp[i] = y[i] + h * k1[i] / 2.0;
    }
    
    
    system(yTemp, k2);
    for (int i = 0; i < n; i++) {
        yTemp[i] = y[i] + h * k2[i] / 2.0;
    }
    
    
    system(yTemp, k3);
    for (int i = 0; i < n; i++) {
        yTemp[i] = y[i] + h * k3[i];
    }
    
    
    system(yTemp, k4);
    
    
    for (int i = 0; i < n; i++) {
        y[i] += h * (k1[i] + 2.0*k2[i] + 2.0*k3[i] + k4[i]) / 6.0;
    }
}

int main() {
  
    const double h = 0.01;         
    const int steps = 10000;       
    double y[3] = {1.0, 1.0, 20.0}; 
    double t = 0.0;                
    
    
    vector<double> time(steps);
    vector<double> x(steps), y_vals(steps), z(steps);
    
    
    for (int i = 0; i < steps; i++) {
        time[i] = t;
        x[i] = y[0];
        y_vals[i] = y[1];
        z[i] = y[2];
        rk4Step(y, h, lorenzSystem);
        t += h;
    }
    
    
    ofstream outFile("lorenz_results.txt");
    outFile << fixed << setprecision(6);
    
    outFile << "Time\tX\t\tY\t\tZ\n";
    for (int i = 0; i < steps; i++) {
        outFile << time[i] << "\t" 
                << x[i] << "\t" 
                << y_vals[i] << "\t" 
                << z[i] << "\n";
    }
    outFile.close();
    
    cout << "Similasyon tamamlandi. Sonuclar 'lorenz_results.txt' dosyasina yazildi." << endl;
    
    
    ofstream gnuplotScript("plot.gnu");
    gnuplotScript << "set title 'Lorenz �ekicisi'\n"
                  << "set xlabel 'X'\n"
                  << "set ylabel 'Y'\n"
                  << "set zlabel 'Z'\n"
                  << "splot 'lorenz_results.txt' using 2:3:4 with lines title 'Lorenz'\n"
                  << "pause -1\n"; 
    gnuplotScript.close();

    
    system("gnuplot plot.gnu");

    return 0;
}
