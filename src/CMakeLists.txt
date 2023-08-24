
add_library(weapon_lib
            Weapon_Bundle.cpp
            Weapon.cpp
            Pistol.cpp
            Heavy_Gun.cpp
            Knife.cpp
)

set(invalid_exceptions
    Invalid_Attribute_Exception.cpp
    Invalid_UserName_Exception.cpp
    Invalid_GunType_Exception.cpp
    Invalid_GunCategory_Exception.cpp
)
set(dead_exceptions
    Dead_Player_Exception.cpp
    Dead_Buyer_Exception.cpp
    Dead_Attacker_Exception.cpp
    Dead_Attacked_Exception.cpp
)
set(duplicate_exceptions
    Duplicate_Attribute_Exception.cpp
    Duplicate_UserName_Exception.cpp
    Duplicate_WeaponType_Exception.cpp
    Duplicate_Heavy_Gun_Exception.cpp
    Duplicate_Pistol_Exception.cpp    
)
add_library(exception_lib
            Custom_Exception.cpp
            Insufficient_Money_Exception.cpp
            Full_Team_Exception.cpp
            Friendly_Fire_Exception.cpp
            Out_Of_Time_Exception.cpp
            ${invalid_exceptions}
            ${dead_exceptions}
            ${duplicate_exceptions}
)

add_library(player_lib
            Player_Statistics.cpp
            Player.cpp
            Team.cpp
)

add_library(game_lib
            Timer.cpp
)