
set(weapon_lib_files
            Weapon_Bundle.cpp
            Weapon.cpp
            Pistol.cpp
            Heavy_Gun.cpp
            Knife.cpp
)

set(invalid_exceptions
    Exceptions/Invalid_Attribute_Exception.cpp
    Exceptions/Invalid_UserName_Exception.cpp
    Exceptions/Invalid_GunType_Exception.cpp
    Exceptions/Invalid_GunCategory_Exception.cpp
)
set(dead_exceptions
    Exceptions/Dead_Player_Exception.cpp
    Exceptions/Dead_Buyer_Exception.cpp
    Exceptions/Dead_Attacker_Exception.cpp
    Exceptions/Dead_Attacked_Exception.cpp
)
set(duplicate_exceptions
    Exceptions/Duplicate_Attribute_Exception.cpp
    Exceptions/Duplicate_UserName_Exception.cpp
    Exceptions/Duplicate_WeaponType_Exception.cpp
    Exceptions/Duplicate_Heavy_Gun_Exception.cpp
    Exceptions/Duplicate_Pistol_Exception.cpp    
)
set(exception_lib_files
    Exceptions/Custom_Exception.cpp
    Exceptions/Insufficient_Money_Exception.cpp
    Exceptions/Full_Team_Exception.cpp
    Exceptions/Friendly_Fire_Exception.cpp
    Exceptions/Out_Of_Time_Exception.cpp
    ${invalid_exceptions}
    ${dead_exceptions}
    ${duplicate_exceptions}
)

set(player_lib_files
    Player_Statistics.cpp
    Player.cpp
    Team.cpp
)

set(game_lib_files
    Timer.cpp
    Game_Manager.cpp
    Command_Executer.cpp
)

if(${enable_testing})

    add_library(weapon_lib
                ${weapon_lib_files}
    )

    add_library(player_lib
                ${player_lib_files}
    )

    add_library(game_lib
                ${game_lib_files}
    )   

    add_library(exception_lib
                ${exception_lib_files}
    )

endif()

add_executable(main
            main.cpp
            ${weapon_lib_files}
            ${exception_lib_files} 
            ${player_lib_files} 
            ${game_lib_files}   
)
