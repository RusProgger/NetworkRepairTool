#include <iostream>
#include <windows.h>
#include "warningMessage.h"

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
        std::cout << "Good: program is running as administrator\n";
        return true;
    } else {
        std::cout << "Warning: program is not running as administrator\n";
        return false;
    }
}