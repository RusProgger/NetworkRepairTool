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
        std::cout << "Warning! Resetting TCP/IP may temporarily disrupt your Internet connection.\nAre you sure you want to continue?\nProceed? (Y/N):";
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
                std::this_thread::sleep_for(std::chrono::seconds(2));
                resetNetbiosReloaded();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                //resetWinsock
                std::cout << "Resetting Winsock catalog...";
                std::this_thread::sleep_for(std::chrono::seconds(4));
                resetWinsock();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                // resetTcpIp
                std::cout << "Resetting TCP/IP stack...";
                std::this_thread::sleep_for(std::chrono::seconds(5));
                resetTcpIp();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                // Clearing ARP cache
                std::cout << "Clearing ARP cache...";
                std::this_thread::sleep_for(std::chrono::seconds(5));
                clearArpCache();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                //resetIPv6
                std::cout << "Resetting IPv6 configuration...";
                std::this_thread::sleep_for(std::chrono::seconds(6));
                resetIPv6();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                //resetFirewall
                std::cout << "Resetting Windows Firewall settings...";
                std::this_thread::sleep_for(std::chrono::seconds(7));
                resetFirewall();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                //Cleaning temporary files...
                std::cout << "Cleaning temporary files...";
                std::this_thread::sleep_for(std::chrono::seconds(10));
                clearTempFiles();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                //showRouteTable
                std::cout << "Clearing route table...";
                std::this_thread::sleep_for(std::chrono::seconds(6));
                showRouteTable();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                //renewIp
                std::cout << "Renewing IP address...";
                std::this_thread::sleep_for(std::chrono::seconds(6));
                renewIp();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                //registerDns
                std::cout << "Registering DNS...";
                std::this_thread::sleep_for(std::chrono::seconds(3));
                registerDns();
                colorHandle(10);
                std::cout << "OK\n";
                colorHandle(7);

                // end
                colorHandle(10);
                std::cout << "\n";
                std::cout << "========================================\n";
                std::cout << "              COMPLETED                 \n";
                std::cout << " All operations completed successfully. \n";
                std::cout << " Please restart your computer to apply  \n";
                std::cout << "           all changes.                 \n";
                std::cout << "========================================\n\n";
                colorHandle(7);
                break;
            }

            if (choice == 'N' || choice == 'n') {
                colorHandle(12);
                std::cout << "You exited the menu.\n";
                colorHandle(7);
                break;
            }

            std::cout << "Invalid input! Please enter Y or N..\nContinue: (\"Y: Yes\")\"(N: Not)\"";
        }
       
    }

    // std::cout << "\nProgram finished successfully.\n";
    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}