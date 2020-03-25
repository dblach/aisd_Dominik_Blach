#include <iostream>

int iteracyjna(int t[],int n){
    int p=0;
    int x=t[--n];
    while(n--){
        p++;
        if(t[n]<x) x=t[n];
    }
    return p;
}

int rekurencyjna1(int t[],int n,int& p){
	p++;
    if(n==1){
        return t[0];
    }
	int max=rekurencyjna1(t,n-1,p);
    p++;
    if(max>t[n-1]){
        return max;
    }
    else{
        return t[n-1];
    }
}

int rekurencyjna2(int t[],int poczatek,int koniec,int& p){
    p++;
    if(poczatek==koniec){
        return t[koniec];
    }
    int srodek=(poczatek+koniec)/2;
    int max1=rekurencyjna2(t,poczatek,srodek,p);
    int max2=rekurencyjna2(t,srodek+1,koniec,p);
    p++;
    if(max1>max2){
        return max1;
    }
    else{
        return max2;
    }
}

void main(){
    int t[]={4,8,10,2,6,40,1,22,5,3};
    int n=sizeof(t)/sizeof(t[0]);

    int p_r1=0;
    rekurencyjna1(t,n,p_r1);

    int p_r2=0;
    rekurencyjna2(t,0,n-1,p_r2);

    std::cout<<"iteracyjna: "<<iteracyjna(t,n)<<" porownan\n";
    std::cout<<"rekurencyjna 1: "<<p_r1<<" porownan\n";
    std::cout<<"rekurencyjna 2: "<<p_r2<<" porownan\n";
}