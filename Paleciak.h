//
// Created by szymo on 12/20/2020.
//

#ifndef FLISSZYMON_ETAP1_PALECIAK_H
#define FLISSZYMON_ETAP1_PALECIAK_H

#include <vector>
#include "Product.h"

class Paleciak {
private:
    int loadCapacity;
public:
    explicit Paleciak(int loadCapacity);
    Paleciak();

    std::vector<Product *> products;
    int getCapacity();
    double getCurrentLoad();
};

#endif //FLISSZYMON_ETAP1_PALECIAK_H
