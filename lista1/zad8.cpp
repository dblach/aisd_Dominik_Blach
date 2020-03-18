#include <iostream>

bool* sito_erastotenesa(int n){
    bool *prime;
    for(int i=0;i<n+1;i++) prime[i]=1;

    for (int i=2;i*i<=n;i++){ 
        if (prime[i]){ 
            for(int j=i*i;j<=n;j+=i) 
                prime[j]=false; 
        } 
    } 

    return prime;
}

int main(){
    std::cout<<"\n";
    int n=100;

    bool* liczby=sito_erastotenesa(n);
    for(int i=0;i<n;i++) std::cout<<i<<"\t"<<liczby[i]<<"\n";

    return 0;
}