
add_executable(WeaponTEST Weapon_Test.cpp)

target_link_libraries(WeaponTEST
    gtest gtest_main weapon_lib
)

add_test(test_all WeaponTEST)
