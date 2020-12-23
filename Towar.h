//
// Created by szymo on 11/19/2020.
//
#include <string>
#include "Product.h"

#ifndef UNTITLED_TOWAR_H
#define UNTITLED_TOWAR_H


class Towar: public Product {
public:
    Towar(std::string name, int amount, int id);

    Product *divide(int amount) override;
    void combine(Product *product) override;
};


#endif //UNTITLED_TOWAR_H
