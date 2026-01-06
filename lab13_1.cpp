#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double a[],int n,double b[])
{

    for(int i = 0;i<n;i++) b[0] += a[i]/n;


    double devsum=0;
    for(int j = 0;j<n;j++) devsum += pow(a[j]-b[0],2);
    b[1] = sqrt(devsum/n);


    double kun =1.0;
    for(int k = 0;k<n;k++) kun *= a[k];
    b[2] = pow(kun,1.0/n);


    double harn = 0;
    for(int l = 0;l<n;l++) harn += 1.0/a[l];
    b[3] = n/harn;

       
    int m=1;
    double max= a[0];
    double min = a[0];
    while (m<n){
    if(a[m]>max) max = a[m];
    if(a[m]<min) min = a[m];
    m++;
    }
    b[4] = max;
    b[5] = min;
}