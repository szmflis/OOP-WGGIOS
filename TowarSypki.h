//
// Created by szymo on 12/18/2020.
//

#ifndef FLISSZYMON_ETAP1_TOWARSYPKI_H
#define FLISSZYMON_ETAP1_TOWARSYPKI_H

#include "Product.h"

class TowarSypki: public Product {
public:
    TowarSypki(std::string name, int amount, int id);

    Product *divide(int amount) override;

    void combine(Product *product) override;
};


#endif //FLISSZYMON_ETAP1_TOWARSYPKI_H
