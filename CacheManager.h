//
// Created by fanny on 17/01/2020.
//

#ifndef MILESTONE_2_CACHEMANAGER_H
#define MILESTONE_2_CACHEMANAGER_H
#include <string>
#include <list>
#include <unordered_map>
#include <iostream>
#include <functional>
#include <fstream>

using namespace std;

template<typename T> class CacheManager {
public:
    CacheManager(int number);
    virtual  ~CacheManager();
    virtual void insert(string key, T obj);
    virtual T get(std::string key);
    virtual void foreach(const function<void(T&)> func);
};


#endif //MILESTONE_2_CACHEMANAGER_H
