//
// Created by fanny on 18/01/2020.
//

#include "FileCacheManager.h"

void FileCacheManager::createProblemFile(string obj) {
    // open file for new item
    fstream file;
    file.open(to_string(hasher(obj)), ios::out | ios::binary);
    if (!file) {
        throw ("error - file didn't open");
    }
    // write matrix to file
    file.write((char*)&obj, sizeof(string));
    // close file
    file.close();
}

void FileCacheManager::insertSolution(string key, string obj) {
    string file_name = to_string(hasher(key));
    file_name += "_sol";
    // open file for new item
    fstream file;
    file.open(file_name, ios::out | ios::binary);
    if (!file) {
        throw ("error - file didn't open");
    }
    // add name of solution file to map
    CacheManager::getHashMap().emplace(make_pair(to_string(hasher(key)), file_name));
    // write solution of matrix to file
    file.write((char*)&obj, sizeof(string));
    // close file
    file.close();
}

string FileCacheManager::get(string key) {
    return this->getHashMap().at(to_string(hasher(key)));
}

bool FileCacheManager::findSolution(string p) {
    unordered_map<string, string>::iterator it;
    for (it = this->getHashMap().begin(); it != this->getHashMap().end(); ++it) {
        if (it->first == to_string(hasher(p))) {
            return true;
        }
    }
    return false;
}
