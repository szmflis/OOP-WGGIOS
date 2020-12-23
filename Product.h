//
// Created by szymo on 12/17/2020.
//

#include <string>

#ifndef FLISSZYMON_ETAP1_PRODUCT_H
#define FLISSZYMON_ETAP1_PRODUCT_H

class Product {
public:
    Product(int id, std::string unit, std::string name, double amount);

    std::string getName();
    int getId() const;

    double getAmount () const;
    void setAmount (double newAmount);

    std::string getUnit() const;
    void printAmount() const;

    virtual Product* divide(int amount) = 0;
    virtual void combine(Product*) = 0;
private:
    int id;
    double amount;
    std::string name;
    std::string unit;
};

#endif //FLISSZYMON_ETAP1_PRODUCT_H
