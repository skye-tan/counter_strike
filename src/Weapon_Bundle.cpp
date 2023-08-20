
#include "Weapon_Bundle.h"

Weapon_Bundle::Weapon_Bundle() {
    pistol = NULL;
    heavy_gun = NULL;
    knife = new Knife();
}

void Weapon_Bundle::change_pistol(Pistol& pistol) {
    this->pistol = &pistol;
}

void Weapon_Bundle::change_heavy_gun(Heavy_Gun& heavy_gun) {
    this->heavy_gun = &heavy_gun;
}

Pistol Weapon_Bundle::get_pistol() const {
    return *pistol;
}

Heavy_Gun Weapon_Bundle::get_heavy_gun() const {
    return *heavy_gun;
}

Knife Weapon_Bundle::get_knife() const {
    return *knife;
}