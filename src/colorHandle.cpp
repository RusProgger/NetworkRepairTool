#include "colorHandle.h"
#include <windows.h>

void colorHandle(int COLOR) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR);
}
