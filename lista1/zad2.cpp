#include <iostream>

double f(double x){
     return (5*x)-3;
}

double bisect(double a,double b){
    if(f(a)*f(b)>=0){
        std::cout<<"niepoprawne a i b";
        return 0;
    }
    double c=a;
    while ((b-a)>=0.001){
        c=(a+b)/2;
        if(f(c)==0.0) break;
        else if(f(c)*f(a)<0) b=c;
        else a=c;
    }
    return c;
}

int main(){
    double a=-4;
    double b=4;
    std::cout<<bisect(a,b)<<"\n";
    return 0;
}
