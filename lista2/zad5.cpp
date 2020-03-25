#include <iostream>

//funkcje z pliku lista2020.cc z panoramixa

template <class T> 
class list // lista jednokierunkowa (kołowa)
{ 
   struct node // węzeł listy jednokierunkowej (zapętlonej)
   { 
      T key;       // klucz
      node* next;  // adres następnego węzła

      node(T key0,node* next0=nullptr)
         :key(key0),next(next0)
      {
         if(next==nullptr)   
            next=this;
      }

      void insertafter(T k){
         next=new node(k,next);
      }
   }; 

   node *last; // last jest ostatnim elementem listy a last->next pierwszym

    public:   
    
    list():last(0){
    }   
    
    ~list(){
        while (!empty()) 
            pop_front();
    }
    
    void put_front(T k){
        if(last) 
            last->insertafter(k);
        else 
            last=new node(k);
    }
    
    void put_back(T k){
        put_front(k);
        last=last->next;
    }

    T front(){   // pierwszy element    
        return last->next->key;  // ostatni wskazuje na piewrszy, bo lista jest kołowa
    }
    
    T back() {   // ostatni element
        return last->key;
    }
    
    bool empty(){   // czy lista jest pusta ?
        return last==nullptr;  
    }
    
    void pop_front(){    // usuń pierwszy element
            if(!last)      // jeśli lista pusta 
                return;     // nic nie rób

            if(last->next==last){ // jeśli lista jednoelementowa
                delete last;       // usuń ostatni element  = pierwszy element 
                last=nullptr;      // wyzruj adres ostaniego elementi
            }
            else{
                node* drugi=last->next->next; // adres drugiego
                delete last->next;            // usuń pierwszy element
                last->next=drugi;             // teraz drugie będzi pierwszy
            }
    }
    T get_front(){  // usuń i zwróć pierszy element
        T k=front(); // zapamiętaj pierwszy klucz
        pop_front(); // usuń pierwszy węzeł 
        return k;    // zwróć wartość jaka w nim była
    }
       
    void reverse(){
        node* current=last;
        node *prev=NULL, *next=NULL;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
        
            prev=current;
            current=next;
        }
      last=prev;
   }
};

template<typename T> void wyswietl(list<T>& l,int n){
    list<T> tmp_l;
    for(int i=0;i<n;i++){
        T tmp_e=l.get_front();
        std::cout<<tmp_e<<",";
        tmp_l.put_back(tmp_e);
    }
    std::cout<<"\n";
    for(int i=0;i<n;i++) l.put_back(tmp_l.get_front());
}

void main(){
    int n=6;
    list<int> l;
    for(int i=0;i<n;i++) l.put_back(i);
    wyswietl(l,n);
    l.reverse();
    wyswietl(l,n);
}