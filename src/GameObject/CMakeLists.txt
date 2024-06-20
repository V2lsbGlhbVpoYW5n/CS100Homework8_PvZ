cmake_minimum_required(VERSION 3.16)

add_library(
        GameObject
        STATIC
        GameObject.hpp
        GameObject.cpp
        Background.hpp
        Background.cpp
        Plant/Plant.hpp
        Plant/Plant.cpp
        Plant/Sunflower.hpp
        Plant/Sunflower.cpp
        Interface/SunProducer.hpp
        Interface/SunProducer.cpp
        PlantingSpot.hpp
        PlantingSpot.cpp
        Sun.hpp
        Sun.cpp
        Interface/Attacker.hpp
        Interface/Attacker.cpp
        HandHoldObject/HandHoldObject.cpp
        HandHoldObject/HandHoldObject.hpp
        HandHoldObject/Seed/Seed.cpp
        HandHoldObject/Seed/Seed.hpp
        HandHoldObject/Seed/SunflowerSeed.cpp
        HandHoldObject/Seed/SunflowerSeed.hpp
)

target_link_libraries(
        GameObject
        Framework
)

target_include_directories(
        GameObject
        PUBLIC
        ${CMAKE_SOURCE_DIR}/src/
        ${CMAKE_SOURCE_DIR}/src/Framework/
        ${CMAKE_SOURCE_DIR}/src/GameWorld/
        ${CMAKE_SOURCE_DIR}/src/GameObject/
)
