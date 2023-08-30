
#include "WeaponBundle.h"
#include "AllExceptions.h"

WeaponBundle::WeaponBundle() {
    pistol = NULL;
    heavy_gun = NULL;
    knife = Knife::get_instance();
}

void WeaponBundle::add_pistol(Pistol& pistol) {
    if (this->pistol != NULL) {
        throw DuplicatePistolException();
    }
    this->pistol = &pistol;
}

void WeaponBundle::add_heavy_gun(HeavyGun& heavy_gun) {
    if (this->heavy_gun != NULL) {
        throw DuplicateHeavyGunException();
    }
    this->heavy_gun = &heavy_gun;
}

void WeaponBundle::remove_pistol() {
    this->pistol = NULL;
}

void WeaponBundle::remove_heavy_gun() {
    this->heavy_gun = NULL;
}

Pistol* WeaponBundle::get_pistol() const {
    if (pistol == NULL) {
        throw InvalidGunTypeException();
    }
    return pistol;
}

HeavyGun* WeaponBundle::get_heavy_gun() const {
    if (heavy_gun == NULL) {
        throw InvalidGunTypeException();
    }
    return heavy_gun;
}

Knife* WeaponBundle::get_knife() const {
    return knife;
}