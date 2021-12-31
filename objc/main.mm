//
//  main.mm
//

#include <iostream>
#import <Foundation/Foundation.h>  //For NSObject

//------------------------------------ C++

typedef std::function<int(int, int)> MYLAMBDA;

class MyCppInvoker {
public:
    static int invoke_fcn(int a, int b, MYLAMBDA fobj) {
        return fobj(a, b);
    }
};

//------------------------------------ Objective C

typedef int (^MYBLOCK)(int param1, int param2);

@interface MyObjCInvoker:NSObject
/* method declaration */
+ (int)invoke_blk:(int)a_ b_:(int)b blk_:(MYBLOCK)blk;
@end

@implementation MyObjCInvoker
+ (int)invoke_blk:(int)a_ b_:(int)b blk_:(MYBLOCK)blk {
    return blk(a_, b);
}
@end

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

    MYLAMBDA mylambda = [&](int _a, int _b) -> int {
        d = 4;
        std::cout << "*d " << d << "  addr: " << &d << std::endl;
        return (_a + _b) + d;
    };
    
    ////////////////////////////////////
    
    std::cout << "The block result: " << myblock(a, b) << std::endl;
    std::cout << "a  " << a << "  addr: " << &a << std::endl; 
    std::cout << "b  " << b << "  addr: " << &b << " sizeof(b) " << sizeof(b) << std::endl; 
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
    
    std::cout << "The C++ invoked_fcn block result: " 
              << MyCppInvoker::invoke_fcn(a, b, myblock) << std::endl;
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

    std::cout << "The C++ invoked_fcn lambda result: " 
              << MyCppInvoker::invoke_fcn(a, b, mylambda) << std::endl;
    std::cout << "a  " << a << "  addr: " << &a << std::endl; 
    std::cout << "b  " << b << "  addr: " << &b << std::endl; 
    std::cout << "c  " << c << "  addr: " << &c << std::endl; 
    pc = &c;
    std::cout << "pc " << *pc << "  addr: " << pc << std::endl; 
    std::cout << "d  " << d << "  addr: " << &d << std::endl; 
    
    //////////////////////////////
    a = 1; 
    b = 2; 
    c = 0; 
    d = c; 
    
    std::cout << "The obj-C invoked_blk block result: " 
              << [MyObjCInvoker invoke_blk:a b_:b blk_:myblock] << std::endl;
    //std::cout << "The invoked_blk lambda result: "
    //            << [MyObjCInvoker invoke_blk:a b_:b blk_:mylambda] << std::endl;
    
    std::cout << "a  " << a << "  addr: " << &a << std::endl; 
    std::cout << "b  " << b << "  addr: " << &b << std::endl; 
    std::cout << "c  " << c << "  addr: " << &c << std::endl; 
    pc = &c;
    std::cout << "pc " << *pc << "  addr: " << pc << std::endl; 
    std::cout << "d  " << d << "  addr: " << &d << std::endl;
    
    return 0;
}
