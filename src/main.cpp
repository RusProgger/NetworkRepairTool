#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

// #include "intro.h"
#include "warningMessage.h"
#include "colorHandle.h"
#include "messageInfo.h"


int main() {

    // Author message
    // getIntro("NetWork Repair Tool", "01/06/2026", "1.00.1", "Ruslan Voronenko");

    // Message info
    messageInfo();

    // message running as administrator
    if (!warningMessage()) {
        std::cout << "\nPress Enter to exit...";
        std::cin.get();
        return 1;
    } else {

    }





    // std::cout << "\nProgram finished successfully.\n";
    // std::cout << "Press Enter to exit...\n";

    std::cin.ignore();
    std::cin.get();
}