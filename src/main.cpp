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
        std::cout << "========================================\n\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));

        colorHandle(12);
        std::cout << "Warning! Resetting TCP/IP may temporarily disrupt your Internet connection.\nAre you sure you want to continue? ";


        char value;

        std::cin >> value;

        if(value == 'n') {
            std::cout << "EXIT...";
            return 0;
        }
    }





    // std::cout << "\nProgram finished successfully.\n";
    // std::cout << "Press Enter to exit...\n";

    std::cin.ignore();
    std::cin.get();
}