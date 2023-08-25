
#include "Weapon_Bundle.h"
#include "All_Exceptions.h"

Weapon_Bundle::Weapon_Bundle() {
    pistol = NULL;
    heavy_gun = NULL;
    knife = new Knife();
}

Weapon_Bundle::~Weapon_Bundle() {
    delete knife;
    delete pistol;
    delete heavy_gun;
}

void Weapon_Bundle::add_pistol(Pistol& pistol) {
    if (this->pistol != NULL) {
        throw Duplicate_Pistol_Exception();
    }
    this->pistol = &pistol;
}

void Weapon_Bundle::add_heavy_gun(Heavy_Gun& heavy_gun) {
    if (this->heavy_gun != NULL) {
        throw Duplicate_Heavy_Gun_Exception();
    }
    this->heavy_gun = &heavy_gun;
}

void Weapon_Bundle::remove_pistol() {
    this->pistol = NULL;
}

void Weapon_Bundle::remove_heavy_gun() {
    this->heavy_gun = NULL;
}

Pistol Weapon_Bundle::get_pistol() const {
    if (pistol == NULL) {
        throw Invalid_GunType_Exception();
    }
    return *pistol;
}

Heavy_Gun Weapon_Bundle::get_heavy_gun() const {
    if (heavy_gun == NULL) {
        throw Invalid_GunType_Exception();
    }
    return *heavy_gun;
}

Knife Weapon_Bundle::get_knife() const {
    return *knife;
}