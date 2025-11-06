#include "array.hpp"
#include "clock.hpp"
#include "electronic_clock.hpp"


int main(){
    ElectronicClock aa("bob clock", 12.3, 4, 45, true);
    Clock bib("clocket", 34.4, 6);
    List<Clock> list{};
    list.insert(aa, 0);
    list.insert(bib, 1);
    std::cout << "bob: " << list.find([](Clock clock){return clock.getWeight() == 4;}) << std::endl;
    std::cout << list;
}

