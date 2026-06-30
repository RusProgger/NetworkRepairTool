#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <limits>

// #include "intro.h"
#include "warningMessage.h"
#include "colorHandle.h"
#include "messageInfo.h"
#include "system.h"


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
                colorHandle(12);
                std::cout << "\n\nWARNING! During the network reset process, it is recommended not to use the computer.\nInternet connection may be temporarily unavailable - this is normal!\n\n";
                std::this_thread::sleep_for(std::chrono::seconds(3));
                colorHandle(7);

                colorHandle(13);
                std::cout << "\n\n";
                std::cout << "========================================\n";
                std::cout << "              PROCESSING                \n";
                std::cout << "     Please wait, do not close app      \n";
                std::cout << "========================================\n\n";
                colorHandle(7);

                // testing

                // releasing ip address
                std::cout << "Releasing IP address...";
                std::this_thread::sleep_for(std::chrono::seconds(2));
                releaseIp();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                // Flushing DNS cache
                std::cout << "Flushing DNS cache...";
                std::this_thread::sleep_for(std::chrono::seconds(3));
                flushDns();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                // resetNetbios
                std::cout << "Resetting NetBIOS cache...";
                std::this_thread::sleep_for(std::chrono::seconds(5));
                resetNetbios();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                // resetNetbiosReloaded
                std::cout << "Reloading NetBIOS names...";;
                std::this_thread::sleep_for(std::chrono::seconds(5));
                resetNetbiosReloaded();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                //resetWinsock

                std::cout << "Resetting Winsock catalog...";
                std::this_thread::sleep_for(std::chrono::seconds(5));
                resetWinsock();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                // resetTcpIp

                

                break;
            }

            if (choice == 'N' || choice == 'n') {
                colorHandle(12);
                std::cout << "You exited the menu.\n";
                colorHandle(7);
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