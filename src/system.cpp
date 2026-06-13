#include "system.h"
#include <windows.h>
#include <iostream>

bool runCommand(const std::string& command) {
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;

    ZeroMemory(&pi, sizeof(pi));

    std::string fullCommand = "cmd.exe /C " + command;

    char cmdLine[1024];
    strcpy_s(cmdLine, fullCommand.c_str());

    if (!CreateProcessA(
        NULL,
        cmdLine,
        NULL,
        NULL,
        FALSE,
        CREATE_NO_WINDOW,
        NULL,
        NULL,
        &si,
        &pi
    )) {
        std::cout << "Error: " << GetLastError() << "\n";
        return false;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return true;
}


// tools function

void releaseIp() {
    runCommand("ipconfig /release");
}

void renewIp() {
    runCommand("ipconfig /renew");
}


void flushDns() {
    runCommand("ipconfig /flushdns");
}

void registerDns() {
    runCommand("ipconfig /registerdns");
}


void resetNetbios() {
    runCommand("nbtstat -R");
}

void resetNetbiosReloaded() {
    runCommand("nbtstat -RR");
}


void showRouteTable() {
    runCommand("route -f");
}

void resetWinsock() {
    runCommand("netsh winsock reset");
}

void resetTcpIp() {
    runCommand("netsh int ip reset");
}

void clearArpCache() {
    runCommand("arp -d *");
}

void resetIPv6() {
    runCommand("netsh interface ipv6 reset");
}

void resetFirewall() {
    runCommand("netsh advfirewall reset");
}

void clearTempFiles() {
    runCommand("cmd /C del /f /s /q %temp%\\*");
}

// full reset 
void fullNetworkReset() {
    releaseIp();
    renewIp();

    flushDns();
    registerDns();

    resetNetbios();
    resetNetbiosReloaded();

    resetWinsock();
    resetTcpIp();

    clearArpCache();
    resetIPv6();
    resetFirewall();

    clearTempFiles();
}