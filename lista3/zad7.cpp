#include <iostream>

struct node  // drzewo bez wskaźnika na rodzica
{ 
	int x;
	node* left;
	node* right;
	
	node(int x0, node* l=nullptr, node* r=nullptr)
		:x(x0), left(l), right(r)
	{}
};

void insert(node *& t, int x) // wstawianie (nierekurencyjna)
{
	node **t1=&t;
	while(*t1)
		if(x<(*t1)->x)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
	*t1=new node(x);
}  

int poziom(node* t,int klucz){
	int h=0;
	while(t!=nullptr){
		h++;
		if(klucz==t->x){
			return h;
		}
		else if(klucz>t->x){
			t=t->right;
		}
		else if(klucz<t->x){
			t=t->left;
		}
	}
	return 0;
}

int main(){
    node* t=nullptr;
	insert(t,3);
	insert(t,4); 
	insert(t,1);
	insert(t,7);
	insert(t,9);
	insert(t,2);
    
	std::cout<<poziom(t,3)<<"\n"; //korzeń = 1
	std::cout<<poziom(t,9)<<"\n"; //ostatni (najgłębszy) element = 4
	std::cout<<poziom(t,5)<<"\n"; //nieistniejący = 0

    return 0;
}