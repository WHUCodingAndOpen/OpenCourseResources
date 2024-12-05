#include "5-13.h"

int X::get(){
    return i;
}

void Y::g(X *x) {
    x->i++;
}

void Z::f(X *x) {
    x->i += 5;
}

void h(X *x) {
    x->i += 10;
}
