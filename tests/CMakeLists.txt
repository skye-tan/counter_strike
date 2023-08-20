
add_executable(WeaponBundleTEST Weapon_Bundle_Test.cpp)

target_link_libraries(WeaponBundleTEST
    gtest gtest_main weapon_lib
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

add_test(test_all
        WeaponTEST
        PistolTEST
        HeavyGunTEST
        KnifeTEST
)
