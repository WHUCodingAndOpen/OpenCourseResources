//
// Created by Jake Jia on 2023/11/2.
//
#include <iostream>
#include "classes.h"

using namespace std;

void Y::g(X *obj) {
    obj->i += 1;
}

void Z::f(X *obj) {
    obj->i += 5;
}

void h(X *obj) {
    obj->i += 10;
}

