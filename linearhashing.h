#ifndef LINEARHASHING_H
#define LINEARHASHING_H

#include <QPair>
#include "hashing.h"

class linearHashing : public hashing
{
private:
    // space to store key-value
    QPair<unsigned, unsigned>** _elem;

    void expand();

public:
    void Set(unsigned key, unsigned value);

    unsigned Get(unsigned key);

    void Delete(unsigned key);

    linearHashing(unsigned size = 10);

};

#endif // LINEARHASHING_H
