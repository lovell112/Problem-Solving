cmake_minimum_required(VERSION 3.30)
project(Problems)

set(CMAKE_CXX_STANDARD 26)

add_executable(Problems main.cpp
        PrefixSumArray/prefixSumArray.cpp
        PrefixSumArray/prefixSumArray.h
        Hackerrank/src/SalesByMatch.cpp
        Hackerrank/includes/SalesByMatch.h
        Hackerrank/src/MagicSquare.cpp
        Hackerrank/includes/MagicSquare.h
        Hackerrank/src/ClimbingTheLeaderboard.cpp
        Hackerrank/includes/ClimbingTheLeaderboard.h
        Hackerrank/src/RoadsAndLibraries.cpp
        Hackerrank/includes/RoadsAndLibraries.h
        Hackerrank/src/FrogInMaze.cpp
        Hackerrank/includes/FrogInMaze.h
        Hackerrank/includes/ThePowerSum.h
        Hackerrank/src/ThePowerSum.cpp
        Hackerrank/src/CrosswordPuzzle.cpp
        Hackerrank/includes/CrosswordPuzzle.h
        Hackerrank/src/RecursiveDigitSum.cpp
        Hackerrank/includes/RecursiveDigitSum.h
        Hackerrank/src/SimplifiedChessEngine.cpp
        Hackerrank/includes/SimplifiedChessEngine.h
        Interface/IProblem.h
        Application/ProblemProcessor.cpp
        Application/ProblemProcessor.h
        Upcoder/src/Trigonometry.cpp
        Upcoder/includes/Trigonometry.h
        Hackerrank/src/PasswordCracker.cpp
        Hackerrank/includes/PasswordCracker.h
        Hackerrank/src/StoneDivision.cpp
        Hackerrank/includes/StoneDivision.h)
