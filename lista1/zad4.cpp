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

void usun(lnode **l,int n){
    lnode* tmp=*l;
    if(n==0){
        *l=tmp->next;
        free(tmp);
        return;
    }    

    for(int i=0;tmp!=nullptr&&i<n-1;i++) tmp=tmp->next;
    if(tmp==nullptr||tmp->next==nullptr) return;
    lnode* next=tmp->next->next;
    free(tmp->next);
    tmp->next=next;
}

lnode* filter(lnode *L){
    lnode* head=L;
    int i=0;
    while(L!=nullptr){
        if(L->key<0){
            std::cout<<"ujemny: "<<i<<"\n";
            usun(&head,i);
            return new lnode();
            i--;
        }
        i++;
        L=L->next;
    }
    return new lnode();
    //return head;
}

int main(){
    lnode* l1=nullptr; 
    lnode* l2=nullptr;
    lnode* l3=nullptr;
    lnode* l4=nullptr;

    l1=new lnode(); 
    l2=new lnode(); 
    l3=new lnode(); 
    l4=new lnode();

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
    
    //zawiesza program :(
    //lnode* lista2=filter2l1);
    //std::cout<<nty(0,lista2)<<","<<nty(1,lista2)<<","<<nty(2,lista2)<<","<<nty(3,lista2)<<"\n";
    
    return 0;
}