#include "chat.h"
#include "sha1.h"
#include <iostream>
#include <iomanip>

int main()
{
    char login1[LOGINLENGTH] = "User1"; char password1[NAMELENGTH] = "Qwerty1";
    char login2[LOGINLENGTH] = "User2"; char password2[NAMELENGTH] = "Qwerty2"; 
    char login3[LOGINLENGTH] = "User3"; char password3[NAMELENGTH] = "Qwerty3";
    char login4[LOGINLENGTH] = "User4"; char password4[NAMELENGTH] = "Qwerty4";
    char login5[LOGINLENGTH] = "User5"; char password5[NAMELENGTH] = "Qwerty5";// одинаковый пароль с 1-м - возможно
    char login6[LOGINLENGTH] = "User6"; char password6[NAMELENGTH] = "Qwerty6"; // не регистрируем
    
    Chat ch;

    ch.reg(login1, password1, NAMELENGTH);
    ch.reg(login1, password2, NAMELENGTH); // повторная регистрация
    ch.reg(login3, password3, NAMELENGTH);
    ch.reg(login4, password4, NAMELENGTH);
    ch.reg(login5, password5, NAMELENGTH);

    ch.show();
    
    if (ch.login(login1, password1, NAMELENGTH))
        std::cout << login1 << " - entered" << std::endl;
    else std::cout << login1 << " - no access " << std::endl;

    if (ch.login(login2, password2, NAMELENGTH))          // незарегистрированный пользователь
        std::cout << login2 << " - entered" << std::endl;
    else std::cout << login2 << " - no access " << std::endl;

    if (ch.login(login3, password3, NAMELENGTH))         
        std::cout << login3 << " - entered" << std::endl;
    else std::cout << login3 << " - no access" << std::endl;    
    
    if (ch.login(login6, password3, NAMELENGTH))          // незарегистрированный пользователь
        std::cout << login6 << " - entered" << std::endl;
    else std::cout << login6 << " - no access" << std::endl;

    if (ch.login(login4, password1, NAMELENGTH))           // не верный пароль
        std::cout << login4 << " - entered" << std::endl;
    else std::cout << login4 << " - no access" << std::endl;

    if (ch.login(login5, password5, NAMELENGTH))
        std::cout << login5 << " - entered" << std::endl;
    else std::cout << login5 << " - no access" << std::endl;

    
    
    
    std::cout << endl;
    std::cout << "Done!";
    
    return 0;
}