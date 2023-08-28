
set(weapon_lib_files
            WeaponBundle.cpp
            Weapon.cpp
            Pistol.cpp
            HeavyGun.cpp
            Knife.cpp
)

set(invalid_exceptions
    Exceptions/InvalidAttributeException.cpp
    Exceptions/InvalidUserNameException.cpp
    Exceptions/InvalidGunTypeException.cpp
    Exceptions/InvalidGunCategoryException.cpp
)
set(dead_exceptions
    Exceptions/DeadPlayerException.cpp
    Exceptions/DeadBuyerException.cpp
    Exceptions/DeadAttackerException.cpp
    Exceptions/DeadAttackedException.cpp
)
set(duplicate_exceptions
    Exceptions/DuplicateAttributeException.cpp
    Exceptions/DuplicateUserNameException.cpp
    Exceptions/DuplicateWeaponTypeException.cpp
    Exceptions/DuplicateHeavyGunException.cpp
    Exceptions/DuplicatePistolException.cpp    
)
set(exception_lib_files
    Exceptions/CustomException.cpp
    Exceptions/InsufficientMoneyException.cpp
    Exceptions/FullTeamException.cpp
    Exceptions/FriendlyFireException.cpp
    Exceptions/OutOfTimeException.cpp
    ${invalid_exceptions}
    ${dead_exceptions}
    ${duplicate_exceptions}
)

set(player_lib_files
    PlayerStatistics.cpp
    Player.cpp
    Team.cpp
)

set(game_lib_files
    Timer.cpp
    GameManager.cpp
    CommandExecuter.cpp
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
