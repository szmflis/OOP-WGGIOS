//
// Created by szymo on 12/18/2020.
//

#ifndef FLISSZYMON_ETAP1_TOWARCIEKLY_H
#define FLISSZYMON_ETAP1_TOWARCIEKLY_H


#include "Product.h"


class TowarCiekly: public Product {
public:
    TowarCiekly(std::string name, int amount, int id);

    Product *divide(int amount) override;

    void combine(Product *product) override;
};

#endif //FLISSZYMON_ETAP1_TOWARCIEKLY_H
