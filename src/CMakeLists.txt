
add_library(weapon_lib
            Weapon_Bundle.cpp
            Weapon.cpp
            Pistol.cpp
            Heavy_Gun.cpp
            Knife.cpp
)

add_library(exception_lib
            Custom_Exception.cpp
            Insufficient_Money_Exception.cpp
            Full_Team_Exception.cpp
            Friendly_Fire_Exception.cpp
            Dead_Player_Exception.cpp
            Dead_Buyer_Exception.cpp
            Dead_Attacker_Exception.cpp
            Dead_Attacked_Exception.cpp
            Invalid_Attribute_Exception.cpp
            Invalid_UserName_Exception.cpp
            Invalid_GunType_Exception.cpp
            Invalid_GunCategory_Exception.cpp
            Duplicate_Attribute_Exception.cpp
            Duplicate_UserName_Exception.cpp
            Duplicate_WeaponType_Exception.cpp
            Duplicate_Heavy_Gun_Exception.cpp
            Duplicate_Pistol_Exception.cpp
)
