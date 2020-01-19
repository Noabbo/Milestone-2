cmake_minimum_required(VERSION 3.15)
project(Milestone_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Milestone_2 main.cpp Solver.cpp Solver.h ClientHandler.cpp ClientHandler.h
        MyTestClientHandler.cpp MyTestClientHandler.h StringReverser.cpp StringReverser.h Searcher.cpp Searcher.h
        Searchable.cpp Searchable.h State.cpp State.h BFSAlgorithm.cpp BFSAlgorithm.h Matrix.cpp Matrix.h
        MatrixSearcher.cpp MatrixSearcher.h MatrixSolver.cpp MatrixSolver.h  CacheManager.h CacheManager.cpp
        FileCacheManager.cpp FileCacheManager.h Server.h Server.cpp MySerialServer.h
        MySerialServer.cpp MyParallelServer.cpp MySerialServer.h)