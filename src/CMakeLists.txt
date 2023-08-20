
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
)
