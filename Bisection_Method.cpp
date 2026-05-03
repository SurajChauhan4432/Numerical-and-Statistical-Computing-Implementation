#include <iostream>
#include <cmath>
using namespace std;

double calFunValue(double x){
    return pow(x,3) -x -11;
}
int main(){
    double a,b;
    cout<<"Enter interval."<<endl;
    cout<<"Enter the first value: ";
    cin>>a;
    cout<<"Enter the second value: ";
    cin>>b;

    double average;
    for(int i=0; i<10; i++){
        average=(a+b)/2;
        if(calFunValue(average)==0){
            cout<<"Root at iteration "<<i+1<<": "<<average<<endl;
            break;
        }else if(calFunValue(average)<0){
            cout<<"Root at iteration "<<i+1<<": "<<average<<endl;
            a=average;
        }else{
            cout<<"Root at iteration "<<i+1<<": "<<average<<endl;
            b=average;
        }
    }

    cout<<"Final root: "<<average<<endl;
    return 0;
}