#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void wczytaj(std::string nazwapliku,std::vector<int>& wspolczynniki){
    std::ifstream plik;
    std::string dane="";
    std::string tmp;

    plik.open(nazwapliku);
    getline(plik,dane);
    plik.close();

    for(int i=0;i<dane.size();i++){
        if(dane[i]!=' '){
            tmp+=dane[i];
        }
        else{
            wspolczynniki.push_back(stoi(tmp));
            tmp="";
        }
    }
    wspolczynniki.push_back(stoi(tmp));
    wspolczynniki.erase(wspolczynniki.begin()); 
}

void pomnoz(std::vector<int>& a,std::vector<int>& b,std::vector<int>& c){
    c[0]=a[0]+b[0];
    for(int i=1;i<a.size();i++){
        for(int j=1;j<b.size();j++){
            c[i+j-1]+=a[i]*b[j];
        }
    }
    c.pop_back();
}

void zapisz(std::string nazwapliku,std::vector<int>& c){
    std::ofstream plik;
    plik.open(nazwapliku);
    for(int i=0;i<c.size();i++) plik<<c[i]<<" ";
    plik.close();
}


int main(){
    std::vector<int> a(1);
    std::vector<int> b(1);
    wczytaj("zad6_a.txt",a);
    wczytaj("zad6_b.txt",b);
   
    std::vector<int> c(a.size()+b.size()-1);
    pomnoz(a,b,c);
    zapisz("zad6_c.txt",c);
   
    std::cout<<"a = ";
    for(int i=0;i<a.size();i++) std::cout<<a[i]<<" ";
    std::cout<<"\nb = ";
    for(int i=0;i<b.size();i++) std::cout<<b[i]<<" ";    
    std::cout<<"\na*b = ";
    for(int i=0;i<c.size();i++) std::cout<<c[i]<<" ";  
    return 0;
}

//ile mnożeń: suma ciągu arytmetycznego