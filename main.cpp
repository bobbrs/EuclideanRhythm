#include "Euclidean.hpp"

int main(int argc, const char * argv[]) {
    Euclidean euc;
    
    euc.Generate(17, 5, 0);
    assert(euc.str() == "10001001000100100");

    euc.Generate(9, 4, 2);

    group expected = {false, false, true, false, true, false, true, false, true};
    assert(euc.GetRhythm() == expected);
    
    return 0;
}
