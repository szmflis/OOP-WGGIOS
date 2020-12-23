//
// Created by szymo on 11/19/2020.
//

#ifndef UNTITLED_MAGAZYN_H
#define UNTITLED_MAGAZYN_H

#include <string>
#include <vector>
#include "Towar.h"
#include "Paleciak.h"
#include "Read.h"

class Magazyn {
public:
    Magazyn(int magazynId, std::string magazynName, std::vector<int> *towarIds, Paleciak *paleciak);

    void addTowar(int id, double amount);

    void extractTowar(int id, double amount);

    void printMagazynState();

    void printMagazynMenu();

    void handleTowarChange(int choice);

    void initTowar();

    void runMagazyn();

    int getId() const;

    Product* getProductById(int productId);

    std::string getName() const;

    int getSize() const;

    bool idExists(int id);

    void wydajTowar();

    void przyjmijTowar();

private:
    std::vector<Product*> magazyn;
    std::vector<int> *towarIds;
    std::string magazynName;
    int magazynId;
    Paleciak *paleciak;
    Read read;
};
#endif //UNTITLED_MAGAZYN_H
