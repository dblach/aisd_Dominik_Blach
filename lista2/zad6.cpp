#include <iostream>

struct list{
    int key;
    list* next=nullptr;
};

void add(list*& root,int key){
    auto ptr=new list;
    ptr->key=key;
    ptr->next=root;
    root=ptr;
}

list* merge(list* l1, list* l2){
    if(l1==nullptr) return l2;
    if(l2==nullptr) return l1;
    if(l1==l2) throw std::invalid_argument("listy muszą być różne");

    if(l2->key < l1->key) std::swap(l1,l2);

    list* const head=l1;
    list* tail=head;
    l1=l1->next;

    while(l1!=nullptr && l2!=nullptr){
        list* old_tail=tail;
        if(l1->key < l2->key){
            tail=l1;
            l1=l1->next;
        }
        else{
            tail=l2;
            l2=l2->next;
        }
        old_tail->next=tail;
    }

    if(l1!=nullptr) tail->next=l1;
    if(l2!=nullptr) tail->next=l2;

    return head;
}

std::ostream& operator<<(std::ostream& out,const list* lista){
    while(lista!=nullptr){
        std::cout<<lista->key<<" ";
        lista=lista->next;
    }
    return out;
}

void main(){
    list* l1=nullptr;
    add(l1,7);
    add(l1,3);
    add(l1,5);
    add(l1,1);

    list* l2=nullptr;
    add(l2,8);
    add(l2,6);
    add(l2,4);
    add(l2,2);

    std::cout<<l1<<"\n";
    std::cout<<l2<<"\n";
    std::cout<<merge(l1,l2);

}