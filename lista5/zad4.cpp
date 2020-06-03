#include <iostream>
#include <string>
#include <algorithm>

void counting_sort(int t[],int n,int c){
    int d=std::stoi('1'+std::string(c-1,'0'));

    int* wynik=new int[n];
    int a[10]={0};

    for(int i=0;i<n;i++) a[(t[i]/d)%10]++;
    for(int i=1;i<10;i++) a[i]+=a[i-1];
    for(int i=n-1;i>=0;i--){
        wynik[a[(t[i]/d)%10]-1]=t[i];
        a[(t[i]/d)%10]--;
    }
    for(int i=0;i<n;i++) t[i]=wynik[i];
}

void sort(int t[],int n){
    std::string max_digits=std::to_string(*std::max_element(t,t+n));
    for(int c=1;c<=max_digits.length();c++) counting_sort(t,n,c);
}

int main(){
    int t[]={1,34,123,321,432,132,543,651,91,32,987,910,643,641,12,342,498,987,965,122,121,431,350};
    int n=sizeof(t)/sizeof(int);
    
    std::cout<<"Przed sortowaniem:\n";
    for(int i=0;i<n;i++) std::cout<<t[i]<<" ";
    
    sort(t,n);
    
    std::cout<<"\nPo sortowaniu:\n";
    for(int i=0;i<n;i++) std::cout<<t[i]<<" ";
    
    return 0;
}