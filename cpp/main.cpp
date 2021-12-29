//
//  main.cpp
//

#include <iostream>
#import <Foundation/Foundation.h>  //For NSObject

//------------------------------------ C++

typedef std::function<int(int, int)> MYLAMBDA;

class MyCppClass {
public:
    static int invoke_fcn(int a, int b, MYLAMBDA fobj) {
        return fobj(a, b);
    }
};

//------------------------------------ Objective C

typedef int (^MYBLOCK)(int param1, int param2);

@interface MyObjCClass:NSObject
/* method declaration */
+ (int)invoke_blk:(int)a_ b_:(int)b blk_:(MYBLOCK)blk;
@end

@implementation MyObjCClass
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
    
    int e = 5;
    int& f = e;
    
    MYBLOCK myblock = ^(int _a, int _b) {
        c = 3;
        return (_a * b) * c;
    };
    
    MYLAMBDA mylambda = [&d, &f](int _a, int _b) -> int {
        d = 4;
        f = 6;
        return (_a + _b) + d;
    };
    
    ////////////////////////////////////
    
    std::cout << "The block result: " << myblock(a, b) << std::endl;
    std::cout << "The lambda result: " << mylambda(a, b) << std::endl;
    
    std::cout << "a " << a << std::endl;
    std::cout << "b " << b << std::endl;
    std::cout << "c " << c << std::endl;
    int* pc = &c;
    std::cout << "pc" << *pc << std::endl;
    std::cout << "d " << d << std::endl;
    
    std::cout << "e " << e << std::endl;
    std::cout << "f " << f << std::endl;
    
    /////////////////////////////////////
    
    c = 0;
    d = 0;
    
    std::cout << "The invoked_fcn block result: " << MyCppClass::invoke_fcn(a, b, myblock) << std::endl;
    std::cout << "The invoked_fcn lambda result: " << MyCppClass::invoke_fcn(a, b, mylambda) << std::endl;
    
    std::cout << "a " << a << std::endl;
    std::cout << "b " << b << std::endl;
    std::cout << "c " << c << std::endl;
    pc = &c;
    std::cout << "pc" << *pc << std::endl;
    std::cout << "d " << d << std::endl;
    
    /////////////////////////////////////
    
    c = 0;
    d = 0;
    
    std::cout << "The invoked_blk block result: " << [MyObjCClass invoke_blk:a b_:b blk_:myblock] << std::endl;
    //std::cout << "The invoked_blk lambda result: " << [MyObjCClass invoke_blk:a b_:b blk_:mylambda] << std::endl;
    
    std::cout << "a " << a << std::endl;
    std::cout << "b " << b << std::endl;
    std::cout << "c " << c << std::endl;
    pc = &c;
    std::cout << "pc" << *pc << std::endl;
    std::cout << "d " << d << std::endl;
    
    return 0;
}
