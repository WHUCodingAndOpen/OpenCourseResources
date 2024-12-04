#include <bits/stdc++.h>

class Monkey{
    public:
    int id;
    Monkey* next_monkey;
    Monkey* last_monkey;
    Monkey(int id){
        this->id = id;
        this->next_monkey = NULL;
    }

    ~Monkey(){
        this->last_monkey->next_monkey = this->next_monkey;
        this->next_monkey->last_monkey = this->last_monkey;
    }


};

int main(){
    int n,m,q;
    std::cin >> n >> m >> q;

    Monkey* head = new Monkey(1);
    Monkey* current = head;
    for (int i = 2;i <=n;i++){
        Monkey* new_monkey = new Monkey(i);
        new_monkey->last_monkey = current;
        current->next_monkey = new_monkey;
        current = new_monkey;
    }
    current->next_monkey = head;
    head->last_monkey = current;

    while(current->id != q){
        current = current->next_monkey;
    }

    int i=1;
    while(current->last_monkey != current){
        if(i!=m){
            i++;
            current = current->next_monkey;
        }else{
            i = 1;
            current = current->next_monkey;
            delete current->last_monkey;
        }
    }

    std::cout << current->id << std::endl;


}