#include <iostream>

template <class T>
void insertionsort_ss (T *p, T*k, int& n_por){
    T y=p[-1]; 
    p[-1]=std::numeric_limits<T>::min();
    
    for(T *s=p+1;s<k;s++){
        T x=*s;
        T *s1=s;
        while( *(--s1) >x){
            *(s1+1)=*s1;
            n_por++;
        }
        *(s1+1)=x;
    }  
    p[-1]=y; 
}

int* utworz_tablice(int n){
    int* tab=new int[n];
    int i=0;
    while(i<n){
        tab[i]=i+2;
        tab[i+1]=i+1;
        i+=2;
    }
    return tab;
}

void main(){
    std::cout<<"n\tk\tn_porownan\n";
    for(int i=4;i<10000;i+=200){
        int n=i;
        int k=n/2;
        int np=0;
        int* tab=utworz_tablice(n);
        insertionsort_ss(tab,tab+n,np);
        std::cout<<n<<"\t"<<k<<"\t"<<np<<"\n";
    }
}

//z działania programu wynika, ze dla zbioru zawierającego k inwersji będzie wykonane k porównań;
//dla zbioru o rozmiarze n liczba porównań to k=n/2