//
// Created by fanny on 18/01/2020.
//

#include "FileCacheManager.h"
FileCacheManager::FileCacheManager() {
    fstream file;
    string str;
    file.open("AllMatrixSolutions.txt", ios::in | ios::binary);
    if (!file) {
        ofstream file { "AllMatrixSolutions.txt" };
    }
    while (std::getline(file, str)) {
        if (str.size() > 0) {
            size_t pos = str.find(" ");
            string key = str.substr (0, pos);
            string s =  str.substr (pos + 1);
            this->addTohHashMap(key, s);
        }
    }
    file.close();
}

void FileCacheManager::createProblemFile(string obj) {
    // open file for new item
    fstream file;
    string name = to_string(hasher(obj)) + ".txt";
    file.open(name, ios::out | ios::binary);
    if (!file) {
        throw ("error - file didn't open");
    }
    // write matrix to file
    file << obj << "\r" << endl;
    // close file
    file.close();
}

void FileCacheManager::insertSolution(string key, string obj) {
    // name of solution file
    string file_name = to_string(hasher(key));
    file_name += "_sol.txt";
    // name of matrix file
    string mat = to_string(hasher(key)) + ".txt";
    // open file for new item
    fstream file;
    file.open(file_name, ios::out | ios::binary);
    if (!file) {
        throw ("error - file didn't open");
    }
    // add name of solution file to map
    CacheManager::addTohHashMap(mat, file_name);
    // write solution of matrix to file
    file << obj << "\r" << endl;
    // close file
    file.close();
}

string FileCacheManager::get(string key) {
    return this->getFromHashMap(key);
}

bool FileCacheManager::findSolution(string p) {
    unordered_map<string, string> tmpMap = this->getHashMap();
    unordered_map<string, string>::iterator it;
    for (it = tmpMap.begin(); it != tmpMap.end(); ++it) {
        if (it->first == p) {
            return true;
        }
    }
    return false;
}