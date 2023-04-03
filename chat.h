#pragma once
#include "sha1.h"
#include "ht_close_resize.h"
#include "string.h"

#define SIZE 10
#define LOGINLENGTH 10
typedef unsigned int uint;

class Chat {
public:
    Chat();
    void reg(char _login[LOGINLENGTH], char _pass[], int pass_length);
    bool login(char _login[LOGINLENGTH], char _pass[], int pass_length);
    void show();

    //friend void test(Chat& c);
private:   
    
    HashTable ht;
};