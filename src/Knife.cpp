
#include "Knife.h"

Knife* Knife::singleton_knife = NULL;

Knife* Knife::get_instance() {
    if (singleton_knife == NULL) {
        singleton_knife = new Knife();
    }
    return singleton_knife;
}

void Knife::delete_instance() {
    delete singleton_knife;
    singleton_knife = NULL;
}

Knife::Knife() : Weapon("Knife", 0, 43, 500) {}
