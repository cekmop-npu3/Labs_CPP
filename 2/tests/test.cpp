#include "string.hpp"
#include <cassert>
#include <iostream>


void testAddition(){
    std::cout << "----Addition test" << std::endl;
    
    std::cout << "\tclass + class" << std::endl;
    String a("something");
    String b("else");
    String c = a + b;
    assert(c == "somethingelse");

    std::cout << "\tclass + literal" << std::endl;
    String d = a + "else";
    assert(d == "somethingelse");

    std::cout << "\tliteral + class" << std::endl;
    String e = "something" + b;
    assert(e == "somethingelse");

    std::cout << "----Passed\n" << std::endl;
}

void testIncrementation(){
    std::cout << "----Incrementation test" << std::endl;
    
    std::cout << "\tclass + class" << std::endl;
    String a("something");
    String b("else");
    a += b;
    assert(a == "somethingelse");

    std::cout << "\tclass + literal" << std::endl;
    b += "something";
    assert(b == "elsesomething");

    std::cout << "----Passed\n" << std::endl;
}

void testIndex(){
    std::cout << "----Index access test" << std::endl;

    String a("something");
    assert(a[0] == 's');
    //a[1] = 'a';
    //assert(a == "samething");


    std::cout << "----Passed\n" << std::endl;
}

void testSubstring(){
    std::cout << "----Substring test" << std::endl;

    String a("something");
    String sub = a(4, 8);
    assert(sub == "thing");

    std::cout << "----Passed\n" << std::endl;
}

void testIO(){
    std::cout << "----IO test" << std::endl;

    String a;
    std::cout << "Enter a string: something\n>>";
    std::cin >> a;
    std::cout << a;
    assert(a == "something");

    std::cout << "----Passed\n" << std::endl;
}


int main(){
    testAddition();
    testIncrementation();
    testIndex();
    testSubstring();
    //testIO();
    std::cout << "All tests have passed" << std::endl;
    return 0;
}
