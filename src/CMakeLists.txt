
set(weapon_lib_files
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
set(exception_lib_files
    Custom_Exception.cpp
    Insufficient_Money_Exception.cpp
    Full_Team_Exception.cpp
    Friendly_Fire_Exception.cpp
    Out_Of_Time_Exception.cpp
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

if(${generate_libraries})

    add_library(weapon_lib
                ${weapon_lib_files}
    )

    add_library(exception_lib
                ${exception_lib_files}
    )

    add_library(player_lib
                ${player_lib_files}
    )

    add_library(game_lib
             ${game_lib_files}
    )   

endif()

add_executable(main
            main.cpp
            ${weapon_lib_files}
            ${exception_lib_files} 
            ${player_lib_files} 
            ${game_lib_files}   
)
