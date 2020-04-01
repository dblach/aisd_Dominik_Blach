#include <iostream>
#include <vector>

unsigned poprzedni(unsigned i,unsigned k,unsigned size){
    k=k%size;
    k=size-k;
    return (i+k)%size;
}

void przesun_w_prawo_wzgl_pierw(std::vector<int>& v,int k){
    if (v.size()<=1) return;
    auto size=v.size();

    unsigned indeks_kopiowanego_elementu=0;
    unsigned indeks_zamazywanego_elementu=k%size;
    unsigned pierwsza_zamazywana=v[indeks_zamazywanego_elementu];
    for(unsigned i=0;i<size;i++){
        v[indeks_zamazywanego_elementu]=v[indeks_kopiowanego_elementu];
        indeks_zamazywanego_elementu=indeks_kopiowanego_elementu;
        indeks_kopiowanego_elementu=poprzedni(indeks_kopiowanego_elementu,k,size);
    }
    v[2*k%size]=pierwsza_zamazywana;
}

int main(){
    std::vector<int> v{1,2,3,4,5,6};
    przesun_w_prawo_wzgl_pierw(v,3);
    for(int i=0;i<v.size();i++) std::cout<<v[i]<<" ";
    return 0;
}