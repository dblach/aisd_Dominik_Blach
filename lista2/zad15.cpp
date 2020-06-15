#include <iostream>
#include <algorithm>

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

int height(node* t) {
    if(t==nullptr) return 0;
    else{
        int l=height(t->left);
        int p=height(t->right);
        return std::max(l,p)+1;
    }
}

int main(){
    node *t=nullptr;
    insert(t,2);
    insert(t,1);
    insert(t,10);
    insert(t,5);
    insert(t,20);
    std::cout<<"h="<<height(t);
    return 0;
}