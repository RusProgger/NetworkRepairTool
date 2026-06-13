#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

// #include "intro.h"
#include "warningMessage.h"
#include "colorHandle.h"
#include "messageInfo.h"


int main() {

    // Message info
    messageInfo();

    // message running as administrator
        if (!checkAdminOrExit()) {
        return 1;
    } else {
        std::cout << "\n\n";
        // menu
        std::cout << "========================================\n";
        std::cout << "                 MENU                  \n";
        std::cout << "========================================\n";
    }





    // std::cout << "\nProgram finished successfully.\n";
    // std::cout << "Press Enter to exit...\n";

    std::cin.ignore();
    std::cin.get();
}