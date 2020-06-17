#include <iostream>
#include <string>

int h(std::string s){ //djb2
    const char *n=s.c_str();
    int hash=5381;
    int c;
    while(c=*n++) hash=((hash<<5)+hash)+c;
    return hash;
}

int main(){
    std::string napis1="test";
    std::string napis2="hehe";
    
    std::cout<<napis1<<"\t"<<h(napis1)<<"\n";
    std::cout<<napis2<<"\t"<<h(napis2)<<"\n";

    return 0;
}