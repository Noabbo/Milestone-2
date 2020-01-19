//
// Created by fanny on 18/01/2020.
//

#ifndef MILESTONE_2_FILECACHEMANAGER_H
#define MILESTONE_2_FILECACHEMANAGER_H

#include "CacheManager.h"

template<typename T> class FileCacheManager : public CacheManager<T> {
public:
    //Constructor
    FileCacheManager(int number) {
        this->capacity = number;
        this->cache =  new unordered_map<string, typename list<pair<string, T>>::iterator>;
    }
    //Destructor
    ~FileCacheManager() {
        delete this->cache;
    }

    //Insert new element to our our cache depending of the lru order
    void insert(string key, T obj) {
        string file_name = T::class_name + key;
        fstream disk_memory {file_name, ios::out | ios::binary};

        //File doesn't exist
        if (!disk_memory) {
            throw "Error, file doesn't open";

        } else {
            //Create our list of pair
            list<pair<string, T>> *list_pair = new list<pair<string, T>>;
            list_pair->push_back(make_pair(key, obj));
            // The key is already in the cache
            if (this->cache->find(key) != this->cache->end()) {
                this->cache->at(key) = list_pair->begin();
            }
            //insert element in the cache, depending of the order in our lru
            this->cache->insert({key, list_pair->begin()});
            disk_memory.seekg(0);
            disk_memory.write((char*) &obj, sizeof(obj));
            disk_memory.close();
        }
    }

    //Get our key from our cache
    T get(std::string key) {

        string file_name = T::class_name + key;
        T obj;
        fstream disk_memory {file_name, ios::in | ios::binary};
        //Check if the key has been entered.
        if (!disk_memory) {
            throw "an error";
        } else {
            //find the key in the file and add it to the cache
            disk_memory.read((char*)&obj, sizeof(obj));
            list<pair<string, T>> *list_pair = new list<pair<string, T>>;
            list_pair->push_back(make_pair(key, obj));
            this->cache->insert({key, list_pair->begin()});
            disk_memory.close();
        }
        obj = this->cache->at(key)->second;
        return obj;
    }

private:
    unordered_map<string, typename list<pair<string, T>>::iterator> *cache;
};


#endif //MILESTONE_2_FILECACHEMANAGER_H

