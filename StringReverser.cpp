//
// Created by noa on 17/01/2020.
//

#include <algorithm>
#include "StringReverser.h"
// reverses given string
string StringReverser::solve(string p) {
    reverse(p.begin(), p.end());
    return p;
}
