//
// Created by szymo on 12/17/2020.
//

#include "Product.h"

#include <utility>
#include <iostream>


Product::Product(int id, std::string unit, std::string name, double amount): id(id), unit(std::move(unit)), name(std::move(name)), amount(amount) {}

std::string Product::getName() {
    return name;
}

int Product::getId() const {
    return id;
}

double Product::getAmount() const {
    return amount;
}

std::string Product::getUnit() const {
    return unit;
}

void Product::setAmount(double newAmount) {
    amount = newAmount;
}

void Product::printAmount() const {
    std::cout << getAmount() << getUnit();
}
