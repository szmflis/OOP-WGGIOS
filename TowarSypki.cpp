//
// Created by szymo on 12/18/2020.
//

#include "TowarSypki.h"
TowarSypki::TowarSypki(std::string name, int amount, int id): Product(id, "Kilograms", std::move(name), amount) {}

Product *TowarSypki::divide(int amount) {
    return nullptr;
}

void TowarSypki::combine(Product *product) {

}
