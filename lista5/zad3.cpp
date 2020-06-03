#include <iostream>
#include <string>
#include <algorithm>

void counting_sort(int t[], int n, int c){
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

int main(){
    return 0;
}