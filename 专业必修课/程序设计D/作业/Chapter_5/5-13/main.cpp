//
// Created by Jake Jia on 2023/11/2.
//
#include "classes.h"
#include <iostream>

using namespace std;

int main() {
    X xObj;
    Y yObj;
    Z zObj;

    cout << "initial point " << xObj.getI() << endl;

    Y::g(&xObj);
    cout << "After Y::g(): " << xObj.getI() << endl;

    Z::f(&xObj);
    cout << "After z::f(): " << xObj.getI() << endl;

    h(&xObj);
    cout << "After f() " << xObj.getI() << endl;

    return 0;
}
