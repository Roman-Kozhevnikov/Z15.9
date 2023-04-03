#include "chat.h"
#include "iostream"
#include "string.h"

Chat::Chat() {
    
}

void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    
    if (ht.find(_login) >= 0) {
        std::cout << " login " << _login << " already done " << endl;
        return;
    }
     ht.add(_login, sha1(_pass, pass_length));
}
bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length) {

    uint* digest = nullptr;

    if (ht.find(_login) >= 0)
        digest = sha1(_pass, pass_length);
    else std::cout << " not find " << _login << endl;
   
    if (digest == nullptr)
        return false;

    bool cmpHashes = !memcmp(ht.findbyData(_login), digest, SHA1HASHLENGTHBYTES);
    if (!cmpHashes)
        std::cout << "wrong password " << _pass << " for login " << _login << endl;

    delete[] digest;

    return cmpHashes;
}

void Chat::show()
{
    ht.show();
}































