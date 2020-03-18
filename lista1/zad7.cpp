#include <iostream>
#include <fstream>
#include <vector>

int main(int argc,char* argv[]){
	std::fstream plik;
	char ch;
	std::vector<int> wystapienia(255);
	std::fill(wystapienia.begin(),wystapienia.end(),0);

	plik.open(argv[1],std::ios::in);
	while(plik.get(ch)) wystapienia[ch]++;
	plik.close();

	for(int i=0;i<wystapienia.size();i++){
		if(wystapienia[i]>0) std::cout<<(char)i<<" ("<<i<<")\t: "<<wystapienia[i]<<"\n";
	}
}