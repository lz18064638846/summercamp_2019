#ifndef HASHING_H
#define HASHING_H

class hashing
{
protected:
    unsigned _size;

    unsigned _used;

    virtual void expand();

    inline unsigned hash_value(unsigned key) {
        return key % _size;
    }

public:
    virtual unsigned Get(unsigned key);

    virtual void Set(unsigned key, unsigned value);

    virtual void Delete(unsigned key);

    virtual ~hashing();

    hashing(unsigned size = 10) : _size(size), _used(0) {}
};

#endif // HASHING_H
