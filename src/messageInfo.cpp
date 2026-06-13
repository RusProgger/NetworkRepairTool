#include <iostream>
#include "messageInfo.h"
#include "colorHandle.h"

void messageInfo() {
     std::cout <<
        "========================================\n"
        "         NETWORK REPAIR TOOL            \n"
        "========================================\n\n";

    colorHandle(7);
    std::cout << "Version: ";

    colorHandle(10); // green (цифры)
    std::cout << "1000.1";

    colorHandle(7);
    std::cout << "\nAuthor: Ruslan Voronenko\n\n";
        

    std::cout <<
        "Network Repair Tool is a Windows utility\n"
        "designed to automatically diagnose and\n"
        "restore network functionality.\n\n";

    colorHandle(10); // green

    std::cout << "What the tool does:\n";

    colorHandle(7);

    std::cout <<
        " - Reset network communication components\n"
        " - Restore system network configuration\n"
        " - Clear corrupted DNS / cache data\n"
        " - Reinitialize network parameters\n\n";

    colorHandle(11);
    std::cout <<
        "========================================\n";

    colorHandle(7);
}