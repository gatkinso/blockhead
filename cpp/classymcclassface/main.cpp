//
//  main.cpp
//

#include <iostream>
#include <functional>

//------------------------------------ C++

class Classy {
public:
    Classy(){
         std::cerr << "I'm alive????? " << (int)value << std::endl;
    }
    Classy(int i = 1, char n = 0) : value(i), name(n) {
         std::cerr << "I'm alive! " << (int)value << std::endl;
    }
    Classy(const Classy& classy) {
        std::cerr << "I was copied! " << (int)value << std::endl;
        this->value = classy.value*10;
    }

    ~Classy() {
        std::cerr << "I was destroyed (by the Baltimore Ravens)! " << (int)value << std::endl;
    }

    int value = 0;
    char name = 0;
};

typedef std::function<int(const Classy& _a, const Classy& _b)> MYLAMBDA;

class MyCppInvoker {
public:
    static int invoke_fcn(const Classy& _a, const Classy& _b, MYLAMBDA fobj) {
        return fobj(_a, _b);
    }
};

typedef int (^MYBLOCK)(const Classy& _a, const Classy& _b);

//------------------------------------ main

int main(int argc, const char * argv[]) {

    Classy a(1, 1);
    Classy b(2, 2);
    __block Classy c(0, 3);
    Classy* pc = &c;
    Classy& d = c;

    MYBLOCK myblock = ^(const Classy& _a, const Classy& _b) {
        c.value = 3;
        //std::cerr << "   *c " << c.value << "  addr: " << &c << std::endl;
        return (_a.value * b.value) * c.value;
    };

    MYLAMBDA mylambda = [&d](const Classy& _a, const Classy& _b) -> int {
        d.value = 4;
        //std::cerr << "   *d " << d.value << "  addr: " << &d << std::endl;
        return (_a.value + _b.value) + d.value;
    };
    
    ////////////////////////////////////
   /* 
    std::cerr << "The block result: " << myblock(a, b) << std::endl;
    std::cerr << "a  " << a.value << "  addr: " << &a << std::endl; 
    std::cerr << "b  " << b.value << "  addr: " << &b << std::endl; 
    std::cerr << "c  " << c.value << "  addr: " << &c << std::endl;
    std::cerr << "d  " << d.value << "  addr: " << &d << std::endl; 

    ///////////////////////////////
    a.value = 1; 
    b.value = 2; 
    c.value = 0; 
    d.value = c.value; 
    
    std::cerr << "The lambda result: " << mylambda(a, b) << std::endl;
    std::cerr << "a  " << a.value << "  addr: " << &a << std::endl; 
    std::cerr << "b  " << b.value << "  addr: " << &b << std::endl; 
    std::cerr << "c  " << c.value << "  addr: " << &c << std::endl; 
    std::cerr << "d  " << d.value << "  addr: " << &d << std::endl; 

    ///////////////////////////////

    a.value = 1; 
    b.value = 2; 
    c.value = 0; 
    d.value = c.value; 
 */   
    std::cerr << "The invoked_fcn block result: " << MyCppInvoker::invoke_fcn(a, b, myblock) << std::endl;
    std::cerr << "a  " << a.value << "  addr: " << &a << std::endl; 
    std::cerr << "b  " << b.value << "  addr: " << &b << std::endl; 
    std::cerr << "c  " << c.value << "  addr: " << &c << std::endl; 
    std::cerr << "d  " << d.value << "  addr: " << &d << std::endl; 
/*
    ///////////////////////////////

    a.value = 1; 
    b.value = 2; 
    c.value = 0; 
    d.value = c.value; 

    std::cerr << "The invoked_fcn lambda result: " << MyCppInvoker::invoke_fcn(a, b, mylambda) << std::endl;
    std::cerr << "a  " << a.value << "  addr: " << &a << std::endl; 
    std::cerr << "b  " << b.value << "  addr: " << &b << std::endl; 
    std::cerr << "c  " << c.value << "  addr: " << &c << std::endl; 
    std::cerr << "d  " << d.value << "  addr: " << &d << std::endl; 

    // Shenanigans

    c.value = 0;
    std::cerr << "c  " << c.value << "  addr: " << &c << std::endl; 

    // char* e = (char*)&b - sizeof(b);
    // //std::cerr << "szb" << sizeof(b) << std::endl;
    // std::cerr << "e  " << (Classy)(*e).value << "  addr: " << &e << std::endl;

    // char* f = (char*)e - sizeof(b);
    // std::cerr << "f  " << (int)(*f).value << "  addr: " << &f << std::endl;

    std::cerr << "pc " << pc->value << "  addr: " << pc << std::endl; 
*/
    return 0;
}
