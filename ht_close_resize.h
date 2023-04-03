#pragma once

#include <string.h>
#include "sha1.h"
#include <iostream>

#define NAMELENGTH 10 
#define DIGESTLENGTH 5
typedef unsigned int uint;

typedef char Login[NAMELENGTH];
typedef unsigned int Digest[DIGESTLENGTH];

class HashTable { 
public:

    HashTable();
    ~HashTable();
    void add(Login log, Digest dg);
    void del(Login log);
    int find(Login log);
    uint* findbyData(Login _log);
    void show() const;
    
private:

    enum class enPairStatus {
        free,
        engaged,
        deleted
    };

    struct Pair { 

        Pair() :
            log(),
            dg(),
            status (enPairStatus::free)
        {}
        Pair(Login _log, Digest _dg) :
            
            status(enPairStatus::engaged) {
            memcpy(dg, _dg, SHA1HASHLENGTHBYTES);
            strcpy_s(log,NAMELENGTH,_log);
        }
        Pair& operator = (const Pair& other) {
            memcpy(dg, other.dg, SHA1HASHLENGTHBYTES);
            strcpy_s(log,NAMELENGTH, other.log);
            status = other.status;

            return *this;
        }

        bool operator == (const Pair& other) {
            return  status == other.status &&
                (status != enPairStatus::engaged || 
                    (!memcmp(dg, other.dg, SHA1HASHLENGTHBYTES) && !strcmp(log, other.log)));
        }

        Login log;
        Digest dg;
        enPairStatus status;
        void dg_show() { for (auto d : dg) std::cout << d << " "; }
    };

    void resize();    
    int hash_func(Login log, int i);
    //int hash_func(Login log, int offset);

    Pair* array;
    int mem_size;
    int count;
};