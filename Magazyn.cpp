//
// Created by szymo on 11/19/2020.
//

#include <iostream>
#include <utility>
#include "Magazyn.h"
#include "TowarSypki.h"
#include "TowarCiekly.h"

Magazyn::Magazyn(int magazynId, std::string magazynName, std::vector<int> *towarIds, Paleciak *paleciak): magazynId(magazynId), magazynName(std::move(magazynName)), towarIds(towarIds), paleciak(paleciak) {}


void Magazyn::runMagazyn() {
    bool run = true;
    while(run) {
        printMagazynMenu();

        int choice;
        choice = read.readNum();
        switch(choice) {
            case 0:
                run = false;
                break;
            case 1:
                printMagazynState();
                break;
            case 2:
                initTowar();
                break;
            case 3:
                handleTowarChange(0);
                break;
            case 4:
                handleTowarChange(1);
                break;
            case 5:
                wydajTowar();
                break;
            case 6:
                przyjmijTowar();
                break;
            default:
                std::cout << "ERROR: Wprowadzono nie istniejacy numer operacji" << std::endl;
        }
    }
}

void Magazyn::initTowar() {
    std::cout << "Wprowadz nazwe towaru" << std::endl;
    std::string name;
    name = read.readString();
    std::cout << "Wprowadz typ towaru" << std::endl;
    std::cout << "1 - Towar na sztuki" << std::endl;
    std::cout << "2 - Towar sypki" << std::endl;
    std::cout << "3 - Towar ciekly" << std::endl;
    int type;
    type = read.readNum();

    switch (type) {
        case 1:
            magazyn.emplace_back(new Towar(name, 0, towarIds->size()));
            towarIds->emplace_back(towarIds->size());
            break;
        case 2:
            magazyn.emplace_back(new TowarSypki(name, 0, towarIds->size()));
            towarIds->emplace_back(towarIds->size());
            break;
        case 3:
            magazyn.emplace_back(new TowarCiekly(name, 0, towarIds->size()));
            towarIds->emplace_back(towarIds->size());
            break;
        default:
            std::cout << "Wprowadzono bledny numer operacji" << std::endl;
            break;
    }
}

void Magazyn::handleTowarChange(int choice) {
    if (magazyn.empty()) {
        std::cout << "ERROR: Magazyn jest pusty" << std::endl;
        return;
    }

    printMagazynState();

    int id;
    double amount;

    std::cout << "Wprowadz ID:";
    id = read.readNum();
    std::cout << "Wprowadz ilosc:";
    amount = read.readNum();

    if (!idExists(id)) {
        std::cout << "Podane id (" << id << ") nie istnieje w magazynie" << std::endl;
        return;
    }

    if (choice == 0) {
        addTowar(id, amount);
    } else {
        extractTowar(id, amount);
    }
}

void Magazyn::addTowar(int id, double amount) {
    if (amount > 0) {
        getProductById(id)->setAmount(getProductById(id)->getAmount() + amount);
    } else {
        std::cout << "ERROR: nie mozna dodac ujemnej ilosci towaru" << std::endl;
    }
}

void Magazyn::extractTowar(int id, double amount) {
    if (amount > 0) {
        if(getProductById(id)->getAmount() - amount < 0) {
            std::cout << "ERROR: nie mozna pobrac " << amount << " towaru z " << getProductById(id)->getAmount() << " towaru" << std::endl;
        } else {
            getProductById(id)->setAmount(getProductById(id)->getAmount() - amount);
        }
    } else {
        std::cout << "ERROR: nie mozna pobrac ujemnej ilosci towaru" << std::endl;
    }
}

void Magazyn::printMagazynState() {
    if (magazyn.empty()) {
        std::cout << char(218);      for(int i=0; i<31; i++){std::cout << char(196);}      std::cout << char(191) << std::endl;
        std::cout << char(179) << "\tMagazyn Pusty\t\t" << char(179) << std::endl;
    } else {
        std::cout << char(218);      for(int i=0; i<31; i++){std::cout << char(196);}      std::cout << char(191) << std::endl;
        std::cout << char(179) << "\tLista towarow\t\t" << std::endl;
        for (Product *p : magazyn) {
            std::cout << char(179) <<"- - - - - - - - - - - - - - - -" << std::endl;
            std::cout << char(179) << "\tID: " << p->getId() << std::endl;
            std::cout << char(179) << "\tNazwa: " << p->getName() << std::endl;
            std::cout << char(179) << "\tIlosc: " << p->getAmount() << " " << p->getUnit() << std::endl;
        }
    }
    std::cout << char(192);      for(int i=0; i<31; i++){std::cout << char(196);}      std::cout << char(217) << std::endl;
}

void Magazyn::printMagazynMenu() {
    std::cout << char(218);      for(int i=0; i<31; i++){std::cout << char(196);}      std::cout << char(191) << std::endl;
    std::cout << char(179) << "   Panel Sterownia Magazynem   " << char(179) << std::endl;
    std::cout << char(192);      for(int i=0; i<31; i++){std::cout << char(196);}      std::cout << char(217) << std::endl;
    std::cout << char(179) << "   Wprowadz:                   " << char(179) << std::endl;
    std::cout << char(179) << "   1. Stan magazynu            " << char(179) << std::endl;
    std::cout << char(179) << "   2. Dodaj rodzaj towaru      " << char(179) << std::endl;
    std::cout << char(179) << "   3. Przyjecie towaru         " << char(179) << std::endl;
    std::cout << char(179) << "   4. Odbierz towar            " << char(179) << std::endl;
    std::cout << char(179) << "   5. Wydaj towar              " << char(179) << std::endl;
    std::cout << char(179) << "   6. Przymij towar            " << char(179) << std::endl;
    std::cout << char(179) << "   0. Zakoncz                  " << char(179) << std::endl;
    std::cout << char(192);      for(int i=0; i<31; i++){std::cout << char(196);}      std::cout << char(217) << std::endl;
}

bool Magazyn::idExists(int id) {
    bool exists = false;
    for (Product *p : magazyn) {
        if(p->getId() == id) {
            exists = true;
        }
    }
    return exists;
}

std::string Magazyn::getName() const {
    return magazynName;
}

int Magazyn::getId() const {
    return magazynId;
}

int Magazyn::getSize() const {
    return magazyn.size();
}

void Magazyn::wydajTowar() {
    if (magazyn.empty()) {
        std::cout << "Brak towarow na sztuki do wydania" << std::endl;
        return;
    }
    int iterator = 0;
    for (Product *p : magazyn) {
        if (p->getUnit() == "Sztuk") {
            iterator++;
            std::cout << "ID: " << p->getId() << " Nazwa: " << p->getName() << " Ilosc: " << p->getAmount() << std::endl;
        }
    }
    if (iterator == 0) {
        std::cout << "Brak towarow na sztuki do wydania" << std::endl;
        return;
    }

    int id;
    double amount;
    std::cout << "Wprowadz ID towaru do wydania:";
    id = read.readNum();
    std::cout << "Wprowadz ilosc:";
    amount = read.readNum();

    if (idExists(id) && amount > 0 && amount <= getProductById(id)->getAmount()){
        if (paleciak->getCurrentLoad() + amount > paleciak->getCapacity()) {
            std::cout << "Podana ilosc towaru przekracza ladownosc paleciaka" << std::endl;
            std::cout << "Ladownosc paleciaka: " << paleciak->getCapacity() << std::endl;
            std::cout << "Aktualna ilosc towaru na paleciaku: " << paleciak->getCurrentLoad() << std::endl;
            std::cout << "Zadana wartosc: " << amount << " + " << paleciak->getCurrentLoad() << " > " << paleciak->getCapacity() << std::endl;
        } else {
            paleciak->products.emplace_back(getProductById(id)->divide(amount));
        }
    } else {
        std::cout << "Towar o podanym ID nie istnieje lub wprowadzono bledna ilosc towaru" << std::endl;
    }
}



Product* Magazyn::getProductById(int productId) {
    for (Product *p : magazyn) {
        if (p->getId() == productId) {
            return p;
        }
    }
}

void Magazyn::przyjmijTowar() {
    if (paleciak->products.empty()) {
        std::cout << "Paleciak pusty, brak towarow do przyjecia" << std::endl;
    } else {
        for (Product *p : paleciak->products) {
            std::cout << p->getName() << p->getId() << p->getAmount() << std::endl;
            if (idExists(p->getId())) {
                getProductById(p->getId())->combine(p);
            } else {
                magazyn.emplace_back(new Towar(p->getName(),  p->getAmount(), towarIds->size()));
                towarIds->emplace_back(towarIds->size());
            }
            paleciak->products.clear();
        }
    }
}
