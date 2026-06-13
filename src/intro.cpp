#include <iostream>
#include <string>
#include <algorithm>
#include <initializer_list>
#include "intro.h"


void getIntro(const std::string& name, const std::string& date, const std::string& version, const std::string& author) {
    const std::string outName = "Name: " + name;
    const std::string outDate = "Date: " + date;
    const std::string outVersion = "Version: " + version;
    const std::string outAuthor = "Author: " + author;

    int width = std::max({outName.length(), outDate.length(), outVersion.length(), outAuthor.length()}) + 8;

    auto printLine = [&](const std::string& text)
    {
        int padding = width - text.length() - 2;
        int left = padding / 2;
        int right = padding - left;

        std::cout << "*"
                  << std::string(left, ' ')
                  << text
                  << std::string(right, ' ')
                  << "*\n";
    };

    std::cout << std::string(width, '*') << "\n";
    // padding top
    std::cout << "*" << std::string(width - 2, ' ') << "*\n";

    printLine(outName);
    printLine(outDate);
    printLine(outVersion);
    printLine(outAuthor);

    // padding bottom
    std::cout << "*" << std::string(width - 2, ' ') << "*\n";
    std::cout << std::string(width, '*') << "\n";
};