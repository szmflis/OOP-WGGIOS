//
// Created by szymo on 12/19/2020.
//

#ifndef FLISSZYMON_ETAP1_MAGAZYNLIST_H
#define FLISSZYMON_ETAP1_MAGAZYNLIST_H

#include <string>
#include <vector>
#include "Magazyn.h"
#include "Paleciak.h"
#include "Read.h"

class MagazynList {
public:
    MagazynList() = default;

    void printMenu();

    void printMagazynList();

    bool containsId(int idToCheck);

    void handleMagazynAdd();

    void enterMagazyn();

    void runMagazynList();

private:
    std::vector<Magazyn> magazynList;
    std::vector<int> towarIds;
    Paleciak paleciak;
    Read read;
};


#endif //FLISSZYMON_ETAP1_MAGAZYNLIST_H
