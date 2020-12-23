#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Towar.h"
#include "Read.h"
#include "Magazyn.h"
#include "MagazynList.h"

std::ifstream ifstream;

int main(int argc, char ** argv) {
    if (argc > 1) {
        ifstream.open(argv[1]);
        std::cout << argv[0] << argv[1] << std::endl;

        if (ifstream.good()) {
            std::cout << "Plik " << argv[1] << " zaladowano pomyslnie" << std::endl;
        }
    }

    auto* magazynList = new MagazynList();

    magazynList->runMagazynList();

    return 0;
}

double Read::readNum() {
    std::string string1;
    if(ifstream.is_open())
    {
        std::getline(ifstream, string1);
    }
    else {
        std::getline(std::cin, string1);
    }
    std::cout << string1 << std::endl;
    return atof(string1.c_str());
}

std::string Read::readString() {
    std::string string1;
    if(ifstream.is_open()) {
        std::getline(ifstream, string1);
    }
    else {
        std::getline(std::cin, string1);
    }
    std::cout << string1 << std::endl;
    return string1;
}