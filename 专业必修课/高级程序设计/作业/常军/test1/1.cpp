#include <bits/stdc++.h>

class Tree{
    private:
    int ages;

    public:
    Tree(int a){
        ages = a;
    }

    void grow(int years){
        ages += years;
    }

    void age(){
        std::cout << ages;
    }

};

int main(){
    int a,b;
    std::cin >> a >> b;
    Tree tree(a);
    tree.grow(b);
    tree.age();
}