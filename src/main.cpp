#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <limits>

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
        colorHandle(7);

        while(true) {

            char choice;

            std::cin >> choice;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if(choice == 'Y' || choice == 'y') {
                std::cout << "continue...\n";
                break;
            }

            if (choice == 'N' || choice == 'n') {
                std::cout << "You exited the menu.\n";
                break;
            }

            std::cout << "Invalid input! Please enter Y or N..\nContinue: ";
        }
       
    }


    // std::cout << "\nProgram finished successfully.\n";
    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}