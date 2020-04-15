#include <iostream>

struct list{
    int key;
    list* next=nullptr;
};

void add(list** root,int key){
    list* ptr=new list;
    ptr->key=key;
    ptr->next=*root;
    *root=ptr;
}

std::ostream& operator<<(std::ostream& out,const list* lista){
    while(lista!=nullptr){
        std::cout<<lista->key<<" ";
        lista=lista->next;
    }
    return out;
}

//---------------------------

void sortedInsert(list** lista, list* nowy){ 
    list* biezacy; 

    if (*lista==nullptr || (*lista)->key >= nowy->key){ 
        nowy->next=*lista; 
        *lista=nowy; 
    } 

    else{ 
        biezacy=*lista; 
        while (biezacy->next!=nullptr && biezacy->next->key < nowy->key){ 
            biezacy=biezacy->next; 
        }
        nowy->next=biezacy->next; 
        biezacy->next=nowy; 
    } 
} 

void insertion_sort(list** lista) 
{ 
    list *posortowane=nullptr; 
    list *biezacy=*lista; 
    while (biezacy!=nullptr){ 
        list *next=biezacy->next; 
        sortedInsert(&posortowane,biezacy); 
        biezacy=next; 
    } 
    *lista=posortowane; 
} 
  
void main(){
   list* l=nullptr;
   add(&l,3);
   add(&l,6);
   add(&l,4);
   add(&l,2);
   add(&l,1);
   std::cout<<l<<"\n";
   insertion_sort(&l);
   std::cout<<l<<"\n";
}