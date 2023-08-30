
add_executable(WeaponBundleTEST WeaponBundleTest.cpp)
target_link_libraries(WeaponBundleTEST
  gtest gtest_main weapon_lib exception_lib
)

add_executable(WeaponTEST WeaponTest.cpp)
target_link_libraries(WeaponTEST
    gtest gtest_main weapon_lib
)

add_executable(PistolTEST PistolTest.cpp)
target_link_libraries(PistolTEST
    gtest gtest_main weapon_lib
)

add_executable(HeavyGunTEST HeavyGunTest.cpp)
target_link_libraries(HeavyGunTEST
    gtest gtest_main weapon_lib
)

add_executable(KnifeTEST KnifeTest.cpp)
target_link_libraries(KnifeTEST
    gtest gtest_main weapon_lib
)

add_test(test_weapon
        WeaponTEST
        PistolTEST
        HeavyGunTEST
        KnifeTEST
)

add_executable(ExceptionsTEST ExceptionsTest.cpp)
target_link_libraries(ExceptionsTEST
   gtest gtest_main exception_lib
)

add_test(test_exception
        ExceptionsTEST
)

add_executable(TimerTEST TimerTest.cpp)
target_link_libraries(TimerTEST
    gtest gtest_main game_lib
)

add_test(test_game
        TimerTEST
)

add_executable(PlayerStatisticsTEST PlayerStatisticsTest.cpp)
target_link_libraries(PlayerStatisticsTEST
    gtest gtest_main player_lib exception_lib
)

add_executable(PlayerTEST PlayerTest.cpp)
target_link_libraries(PlayerTEST
    gtest gtest_main player_lib weapon_lib exception_lib game_lib
)

add_executable(TeamTEST TeamTest.cpp)
target_link_libraries(TeamTEST
    gtest gtest_main player_lib weapon_lib exception_lib game_lib
)

add_test(test_player
    PlayerStatisticsTEST
    PlayerTEST
    TeamTEST
)