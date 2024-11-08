/*================================================================
*  Copyright (C)2024 All rights reserved.
*  FileName : main.cc
*  Author   : dlkou
*  Email    : elonkou@ktime.cc
*  Date     : Thu 07 Nov 2024 11:23:47 PM CST
================================================================*/

#include <cstdlib>
#include <iostream>
#include <memory>

using namespace std;

struct Item {
    int   x;
    float y;
    Item() {
        x = 12;
        y = 0.02;
        std::cout << "init " << std::endl;
    }
    Item(int x_, float y_) {
        x = x_;
        y = y_;
        std::cout << "init " << std::endl;
    }
    ~Item() {}

    friend std::ostream& operator<<(std::ostream& os, const Item& it) {
        os << "x: " << it.x << std::endl;
        os << "y: " << it.y;
        return os;
    }
};

int main(int argc, char* argv[]) {

    int*  x   = (int*)malloc(20);                    // 分配20个字节
    Item* it1 = ::new (x)(Item);                     // 使用new或者::new都行（全局的new函数，而不是对象的new函数，因为对象的new函数有可能会被重载），在已经存在的内存上实例化对象
    Item* it2 = ::new ((void*)x + 8) Item(99, 23.2); // 使用new或者::new都行（全局的new函数，而不是对象的new函数，因为对象的new函数有可能会被重载），在已经存在的内存上实例化对象

    std::cout << *it1 << std::endl;
    std::cout << *it2 << std::endl;

    return 0;
}
