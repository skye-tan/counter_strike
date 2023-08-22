
if(${weapon_lib_test})

    add_executable(WeaponBundleTEST Weapon_Bundle_Test.cpp)
    target_link_libraries(WeaponBundleTEST
      gtest gtest_main weapon_lib exception_lib
    )

    add_executable(WeaponTEST Weapon_Test.cpp)
    target_link_libraries(WeaponTEST
        gtest gtest_main weapon_lib
    )

    add_executable(PistolTEST Pistol_Test.cpp)
    target_link_libraries(PistolTEST
        gtest gtest_main weapon_lib
    )

    add_executable(HeavyGunTEST Heavy_Gun_Test.cpp)
    target_link_libraries(HeavyGunTEST
        gtest gtest_main weapon_lib
    )

    add_executable(KnifeTEST Knife_Test.cpp)
    target_link_libraries(KnifeTEST
        gtest gtest_main weapon_lib
    )

    add_test(test_weapon
            WeaponTEST
            PistolTEST
            HeavyGunTEST
            KnifeTEST
    )

endif()

if(${exception_lib_test})

    add_executable(ExceptionsTEST Exceptions_Test.cpp)
    target_link_libraries(ExceptionsTEST
       gtest gtest_main exception_lib
    )

    add_test(test_exception
            ExceptionsTEST
    )

endif()

if(${game_lib_test})

    add_executable(TimerTEST Timer_Test.cpp)
    target_link_libraries(TimerTEST
        gtest gtest_main game_lib
    )

    add_test(test_game
            TimerTEST
    )

endif()