//
// Created by szymo on 11/19/2020.
//

#include "Towar.h"

#include <utility>
#include <iostream>

Towar::Towar(std::string name, int amount, int id): Product(id, "Sztuk", std::move(name), amount) {}

Product *Towar::divide(int amount) {
    Towar *newTowarptr = new Towar(getName(), amount, getId());
    setAmount(getAmount() - amount);
    return newTowarptr;
}

void Towar::combine(Product *product) {
    setAmount(getAmount() + product->getAmount());
    delete product;
    product = nullptr;
}