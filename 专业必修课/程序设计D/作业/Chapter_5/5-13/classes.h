//
// Created by Jake Jia on 2023/11/2.
//

#ifndef INC_5_13_CLASSES_H
#define INC_5_13_CLASSES_H

class X;

class Y {
public:
    static void g(X *obj);
};

class Z {
public:
    static void f(X *obj);
};

class X {
public:
    X() : i(0) {}

    int getI() const { return i; }

    ~X() = default;

    friend void h(X *obj);

    friend void Y::g(X *obj);

    friend class Z;

private:
    int i;
};

#endif //INC_5_13_CLASSES_H
