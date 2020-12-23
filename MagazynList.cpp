//
// Created by szymo on 12/19/2020.
//

#include "MagazynList.h"
#include "Read.h"
#include <iostream>

void MagazynList::runMagazynList() {
    bool run = true;
    while(run) {
        printMenu();
        int userChoice;
        userChoice = read.readNum();

        std::cout << userChoice << std::endl;

        switch (userChoice) {
            case 1:
                printMagazynList();
                break;
            case 2:
                handleMagazynAdd();
                break;
            case 3:
                enterMagazyn();
                break;
            case 0:
                run = false;
                break;
            default:
                std::cout << "ERROR: Wprowadzono nie istniejacy numer operacji" << std::endl;
        }
    }
}

void MagazynList::handleMagazynAdd() {
    std::string magazynName;
    std::cout << "Wprowadz nazwe magazynu:" << std::endl;
    magazynName = read.readString();
    std::cout << magazynName << std::endl;
    magazynList.emplace_back(Magazyn(magazynList.size(), magazynName, &towarIds, &paleciak));
}

void MagazynList::enterMagazyn() {
    if (magazynList.empty()){
        std::cout << "Lista magazynow jest pusta." << std::endl;
        return;
    }
    printMagazynList();
    int magazynId;
    std::cout << "Wprowadz id magazynu:" << std::endl;
    magazynId = read.readNum();
    std::cout << magazynId << std::endl;
    if (containsId(magazynId)) {
        magazynList[magazynId].runMagazyn();
    } else {
        std::cout << "Magazyn o podanym id nie istnieje" << std::endl;
    }
}

bool MagazynList::containsId(int idToCheck){
    for (const Magazyn& m : magazynList) {
        if (m.getId() == idToCheck) {
            return true;
        }
    }
    return false;
}

void MagazynList::printMenu() {
    std::cout << char(218);      for(int i=0; i<31; i++){std::cout << char(196);}      std::cout << char(191) << std::endl;
    std::cout << char(179) << "   Panel Sterownia Magazynami  " << char(179) << std::endl;
    std::cout << char(192);      for(int i=0; i<31; i++){std::cout << char(196);}      std::cout << char(217) << std::endl;
    std::cout << char(179) << "   Wprowadz:                   " << char(179) << std::endl;
    std::cout << char(179) << "   1. Lista magazynow          " << char(179) << std::endl;
    std::cout << char(179) << "   2. Dodaj magazyn            " << char(179) << std::endl;
    std::cout << char(179) << "   3. Wejdz do magazynu        " << char(179) << std::endl;
    std::cout << char(179) << "   0. Zakoncz                  " << char(179) << std::endl;
    std::cout << char(192);      for(int i=0; i<31; i++){std::cout << char(196);}      std::cout << char(217) << std::endl;

}

void MagazynList::printMagazynList() {
    if (magazynList.empty()) {
        std::cout << char(218);      for(int i=0; i<31; i++){std::cout << char(196);}      std::cout << char(191) << std::endl;
        std::cout << char(179) << "     Lista magazynow pusta\t" << char(179) << std::endl;
    } else {
        std::cout << char(218);      for(int i=0; i<31; i++){std::cout << char(196);}      std::cout << char(191) << std::endl;
        std::cout << char(179) << "\tLista magazynow\t\t" << std::endl;
        for (const Magazyn &m : magazynList) {
            std::cout << char(179) <<"- - - - - - - - - - - - - - - -" << std::endl;
            std::cout << char(179) << "\tID: " << m.getId() << std::endl;
            std::cout << char(179) << "\tNazwa: " << m.getName() << std::endl;
            std::cout << char(179) << "\tIlosc towarow: " << m.getSize() << std::endl;
        }
    }
    std::cout << char(192);      for(int i=0; i<31; i++){std::cout << char(196);}      std::cout << char(217) << std::endl;
}
