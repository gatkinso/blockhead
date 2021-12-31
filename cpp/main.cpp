//
//  main.cpp
//

#include <iostream>
#include <functional>

//------------------------------------ C++

typedef std::function<int(int, int)> MYLAMBDA;

class MyCppInvoker {
public:
    static int invoke_fcn(int a, int b, MYLAMBDA fobj) {
        return fobj(a, b);
    }
};

typedef int (^MYBLOCK)(int param1, int param2);

//------------------------------------ main

int main(int argc, const char * argv[]) {

    int a = 1;
    int b = 2;
    __block int c = 0;
    int& d = c;

    MYBLOCK myblock = ^(int _a, int _b) {
        c = 3;
        std::cout << "*c " << c << "  addr: " << &c << std::endl;
        return (_a * b) * c;
    };

    MYLAMBDA mylambda = [&d](int _a, int _b) -> int {
        d = 4;
        std::cout << "*d " << d << "  addr: " << &d << std::endl;
        return (_a + _b) + d;
    };
    
    ////////////////////////////////////
    
    std::cout << "The block result: " << myblock(a, b) << std::endl;
    std::cout << "a  " << a << "  addr: " << &a << std::endl; 
    std::cout << "b  " << b << "  addr: " << &b << std::endl; 
    std::cout << "c  " << c << "  addr: " << &c << std::endl; 
    int* pc = &c;
    std::cout << "pc " << *pc << "  addr: " << pc << std::endl; 
    std::cout << "d  " << d << "  addr: " << &d << std::endl; 

    ///////////////////////////////
    a = 1; 
    b = 2; 
    c = 0; 
    d = c; 
    
    std::cout << "The lambda result: " << mylambda(a, b) << std::endl;
    std::cout << "a  " << a << "  addr: " << &a << std::endl; 
    std::cout << "b  " << b << "  addr: " << &b << std::endl; 
    std::cout << "c  " << c << "  addr: " << &c << std::endl; 
    pc = &c;
    std::cout << "pc " << *pc << "  addr: " << pc << std::endl; 
    std::cout << "d  " << d << "  addr: " << &d << std::endl; 

    ///////////////////////////////

    a = 1; 
    b = 2; 
    c = 0; 
    d = c; 
    
    std::cout << "The invoked_fcn block result: " << MyCppInvoker::invoke_fcn(a, b, myblock) << std::endl;
    std::cout << "a  " << a << "  addr: " << &a << std::endl; 
    std::cout << "b  " << b << "  addr: " << &b << std::endl; 
    std::cout << "c  " << c << "  addr: " << &c << std::endl; 
    pc = &c;
    std::cout << "pc " << *pc << "  addr: " << pc << std::endl; 
    std::cout << "d  " << d << "  addr: " << &d << std::endl; 

    ///////////////////////////////

    a = 1; 
    b = 2; 
    c = 0; 
    d = c; 

    std::cout << "The invoked_fcn lambda result: " << MyCppInvoker::invoke_fcn(a, b, mylambda) << std::endl;
    std::cout << "a  " << a << "  addr: " << &a << std::endl; 
    std::cout << "b  " << b << "  addr: " << &b << std::endl; 
    std::cout << "c  " << c << "  addr: " << &c << std::endl; 
    pc = &c;
    std::cout << "pc " << *pc << "  addr: " << pc << std::endl; 
    std::cout << "d  " << d << "  addr: " << &d << std::endl;

    // Shenanigans

    c = 0;

    char* e = (char*)&b - sizeof(b);
    //std::cout << "szb" << sizeof(b) << std::endl;
    std::cout << "e  " << (int)(*e) << "  addr: " << (int*)e << std::endl;

    char* f = (char*)e - sizeof(b);
    std::cout << "f  " << (int)(*f) << "  addr: " << (int*)f << std::endl;

    return 0;
}
