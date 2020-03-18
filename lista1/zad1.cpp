#include <iostream>

//a
long pot_rek(long a,long b){
	if(b==0) return 1;
	long c=pot_rek(a,b/2);
	if(b%2==1) return c*c*a; else return c*c;
}

//b
long pot(long a,long b){
	long c=1;
	while(b>0){
		if(b%2==1) c*=a;
		a*=a;
		b>>=1;
	}
	return c;
}

int main(){
	std::cout<<pot_rek(2,3)<<"\n";
	std::cout<<pot(2,3)<<"\n";
}