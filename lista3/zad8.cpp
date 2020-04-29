#include <iostream>
#include <cassert>
//#include <exception>
//#include <vector>

struct BST_tree{
    int key;
    int size; // +
    BST_tree* left_child=nullptr;
    BST_tree* right_child=nullptr;
    BST_tree(int key, int size, BST_tree* left_child=nullptr, BST_tree* right_child=nullptr) : key{key}, size{size}, left_child{left_child}, right_child{right_child} {}
};

void insert(BST_tree*& tree, int value){
    if(tree==nullptr){
        tree=new BST_tree{value,1,nullptr,nullptr};
        return;
    }
    tree->size++;
    const auto& key=tree->key;
    if(value<key) insert(tree->left_child,value); else insert(tree->right_child,value);
}

void display(BST_tree* t, char z1=' ', char z2=' '){
    if(t){
        std::cout<<z1;
        display(t->left_child,'(',')');
        std::cout<<t->key;
        display(t->right_child,'[',']');
        std::cout<<z2;
    }
}

std::ostream& operator<<(std::ostream& out, BST_tree* t){
    display(t);
    return out;
}

BST_tree* ity(BST_tree* tree, int value){
    if(tree==nullptr) return nullptr;
    if(tree->left_child!=nullptr){
        if(value <= tree->left_child->size) return ity(tree->left_child,value);
        else if(value == tree->left_child->size+1) return tree;
        else return ity(tree->right_child, value-tree->left_child->size-1);
    }
    if(value==1) return tree;
    return ity(tree->right_child, value-1);
}

int min (BST_tree* t)  // minimalny klucz (bez rekurencji)
{
	assert(t);
	while(t->left_child)
		t=t->left_child;
	return t->key;
}

void remove_recursive(BST_tree *&t, int x)  // usuwanie elementu z drzewa (rekurencja)
{
	if(t==nullptr) return;
	if(t->key==x)
	{
		if(t->left_child==nullptr)
		{
			BST_tree *d=t->right_child;
			delete t;
			t=d;
            t->size--;
		}
		else
		if(t->right_child==nullptr)
		{
		    BST_tree *d=t->left_child;	
			delete t;
			t=d;
            t->size--;
		}
		else
		{  t->key=min(t->right_child);
		   remove_recursive(t->right_child,t->key); // tail recursion
	    } 
	}
	else
	if(x < t->key)
		remove_recursive(t->left_child,x); // tail recursion
	else	 
		remove_recursive(t->right_child,x); // tail recursion
}

int main(){
    BST_tree* tree=nullptr;
    insert(tree,7);
    insert(tree,3);
    insert(tree,1);
    insert(tree,4);
    insert(tree,6);
    insert(tree,8);
    insert(tree,5);
    insert(tree,15);
    insert(tree,12);
    insert(tree,0);
    insert(tree,2);
    insert(tree,10);
    insert(tree,9);

    std::cout<<"Drzewo: "<<tree<<"\n";
    
    auto size=tree->size;
    for(int i=1;i<=size;i++){
        auto ptr=ity(tree,i);
        if(ptr!=nullptr) std::cout<<ptr->key<<"\n"; else std::cout<<"Error, unexpected nullptr\n";
    }
    
    auto ptr=ity(tree,size+1);
    if(ptr!=nullptr) std::cout<<"Error, expecting nullptr\n"; else std::cout<<"OK\n";

    //usuwanie
    std::cout<<"\n\n\nUsuwanie:\n";
    remove_recursive(tree,4);
    
    std::cout<<"Drzewo: "<<tree<<"\n";

    size=tree->size;
    for(int i=1;i<=size;i++){
        auto ptr=ity(tree,i);
        if(ptr!=nullptr) std::cout<<ptr->key<<"\n"; else std::cout<<"Error, unexpected nullptr\n";
    }
    
    ptr=ity(tree,size+1);
    if(ptr!=nullptr) std::cout<<"Error, expecting nullptr\n"; else std::cout<<"OK\n";

    return 0;
}