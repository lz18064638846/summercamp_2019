#include "linearhashing.h"
#include "memory.h"

linearHashing::linearHashing(unsigned size)
    :hashing(size)
{
    _elem = new QPair<unsigned, unsigned>*[_size];
    memset(_elem, NULL, sizeof(QPair<unsigned, unsigned>*) * _size);
}

unsigned linearHashing::Get(unsigned key)
{
    unsigned hash = hash_value(key);
    unsigned boundary = _size + hash;
    for (unsigned i = hash; i < boundary; i++) {
        if(_elem[i] && _elem[i]->first == key) {
            return _elem[i]->second;
        }
    }
    return NULL;
}

void linearHashing::Set(unsigned int key, unsigned int value)
{
    unsigned hash = hash_value(key);
    unsigned boundary = _size + hash;
    for(unsigned i = 0; i < boundary; i++) {
        if(!_elem[i]) {
           _elem[i] = new QPair<unsigned, unsigned>(key, value);
        } else if(_elem[i]->first == key) {
            _elem[i]->second = value;
        }
    }
    if(++_used > _size / 2) {
        expand();
    }
}

void linearHashing::Delete(unsigned int key)
{
    unsigned hash = hash_value(key);
    unsigned boundary = _size + hash;
    for(unsigned i = hash; i < boundary; i++) {
        if(_elem[i] && _elem[i]->first == key) {
            delete _elem[i];
            memset(&_elem[i], 0, sizeof(QPair<unsigned, unsigned>*));
        }
    }
}
