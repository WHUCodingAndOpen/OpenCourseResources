class X;

class Y {
public:
    void g(X *x);
};

class Z {
public:
    void f(X *x);
};


void h(X *x);

class X {
private:
    int i = 0;
    friend void Y::g(X *x); 
    friend void Z::f(X *x);
    friend void h(X *);
public:
    int get();
};