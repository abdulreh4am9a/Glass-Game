#include "Glass.h"

Glass::Glass()
{
    breakable = 'n';
}
void Glass::setBreakable(char b) {
    breakable = b;
}
char Glass::getBreakable()const {
    return breakable;
}
