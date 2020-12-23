//
// Created by szymo on 12/18/2020.
//

#include "TowarCiekly.h"

#include <utility>

TowarCiekly::TowarCiekly(std::string name, int amount, int id): Product(id, "Liters", std::move(name), amount) {}

Product *TowarCiekly::divide(int amount) {
    return nullptr;
}

void TowarCiekly::combine(Product *product) {}
