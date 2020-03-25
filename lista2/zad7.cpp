/*
    Powstałe drzewo będzie niezrównoważone (wszystkie elementy zostaną wstawione po prawej stronie).
    Wysokość drzewa będzie wynosiła n.
    Ilość porównań jest zależna od ilości elementów wstawianych do drzewa, np.:
        n       h       p
        1       1       0
        2       2       1
        3       3       3
        4       4       6
        5       5       10
        6       6       15
        7       7       21
        8       8       28
        9       9       36
        10      10      45
        11      11      55
        12      12      66
        13      13      78
        14      14      91
        15      15      105
        16      16      120
        17      17      136
        18      18      153
        19      19      171
        20      20      190
        21      21      210
        22      22      231
        23      23      253
        24      24      276
        25      25      300
        26      26      325
        27      27      351
        28      28      378
        29      29      406
        30      30      435
*/

#include <iostream>
#include <algorithm>
int p;

// funkcje z pliku tree-2019.cc z panoramixa

struct node{ 
	int x;
	node* left;
	node* right;
	
	node(int x0, node* l=nullptr, node* r=nullptr)
		:x(x0), left(l), right(r)
	{}
};

void insert(node *& t, int x){
	node **t1=&t;
	while(*t1){
        p++; //dodany licznik porównań
		if(x<(*t1)->x)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
    }
	*t1=new node(x);
}  

int h(node* t){
	return !t ? 0 : 1+std::max(h(t->left),h(t->right));
}

void display(node *t,char z1=' ',char z2=' '){
	if(t)
	{
		std::cout<<z1;
		display(t->left,'(',')');
		std::cout<<t->x;
		display(t->right,'[',']');
		std::cout<<z2;
	}
}

void main(){
    std::cout<<"n\th\tp\n";
    for(int i=1;i<=30;i++){
        node* t=nullptr;
        p=0;
        for(int j=1;j<=i;j++) insert(t,j);
        std::cout<<i<<"\t"<<h(t)<<"\t"<<p<<"\n";
    }

}