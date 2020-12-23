//
// Created by szymo on 12/20/2020.
//

#include "Paleciak.h"

Paleciak::Paleciak(int loadCapacity): loadCapacity(loadCapacity) {}

Paleciak::Paleciak(): loadCapacity(500) {}

double Paleciak::getCurrentLoad() {
    double currentLoad = 0;
    for (Product *p : products) {
        currentLoad += p->getAmount();
    }
    return currentLoad;
}

int Paleciak::getCapacity() {
    return loadCapacity;
}
