#include "array.hpp"
#include "clock.hpp"
#include "electronic_clock.hpp"
#include <variant>


int main(){
    ElectronicClock aa("bob clock", 12.3, 4, 45, true);
    Clock bib("clocket", 34.4, 6);
    Array<Clock> array{};
    array.append(bib);
    array.append(aa);
    array.print();
}

