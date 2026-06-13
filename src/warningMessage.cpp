#include <iostream>
#include <windows.h>
#include "warningMessage.h"
#include "colorHandle.h"

bool isAdmin() {
    BOOL isAdmin = FALSE;
    PSID adminGroup = NULL;

    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;

    if (AllocateAndInitializeSid(
        &ntAuthority,
        2,
        SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS,
        0,0,0,0,0,0,
        &adminGroup)) {

        CheckTokenMembership(NULL, adminGroup, &isAdmin);
        FreeSid(adminGroup);
    }

    return isAdmin;
}

bool warningMessage() {
    if (isAdmin()) {
        colorHandle(10); // green
        std::cout << "Ok: Program is running as administrator\n";
        colorHandle(7); // reset
        return true;
    } else {
        colorHandle(12); // red
        std::cout << "Warning: Program is not running as administrator\n";
        colorHandle(7); // reset
        return false;
    }
}