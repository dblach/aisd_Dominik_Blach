#include <iostream>

struct lnode{
    int key;
    lnode *next;
};

int nty(int n, lnode* root){
    if(root==nullptr) return 0;
    for(int i=0;i<n;i++){
        root=root->next;
        if(root==nullptr) return 0;
    }
    return root->key;
}

int suma(lnode *L){
    int s=0;
    while(L!=nullptr){
        s+=L->key;
        L=L->next;
    }
    return s;
}

lnode* filter(lnode *L){
    lnode* a=new lnode();
    lnode* h=a;
    while(L!=nullptr){
        if(L->key>0){
            a->key=L->key;
            a->next=new lnode();
            a=a->next;
        }
        L=L->next;
    }
    return h;
}

int main(){
    lnode* l1=new lnode();
    lnode* l2=new lnode();
    lnode* l3=new lnode();
    lnode* l4=new lnode();
    
    l1->key=1;
    l1->next=l2;
    l2->key=-1;
    l2->next=l3;
    l3->key=2;
    l3->next=l4;
    l4->key=-2;
    l4->next=nullptr;

    std::cout<<nty(0,l1)<<","<<nty(1,l1)<<","<<nty(2,l1)<<","<<nty(3,l1)<<"\n";
    std::cout<<"s="<<suma(l1)<<"\n";
    
    lnode* lista2=filter(l1);
    std::cout<<nty(0,lista2)<<","<<nty(1,lista2)<<","<<nty(2,lista2)<<","<<nty(3,lista2)<<"\n";

    return 0;
}