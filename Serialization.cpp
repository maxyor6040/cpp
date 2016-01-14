//
// Created by Arye on 13/01/2016.
//

#include "Serialization.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using std::string;
using std::stringbuf;

string Serialization::serialize(Object &o) {
    string res;

    char * str = (char*)malloc(sizeof(char) * (1 + sizeof(void*)));
    sprintf(str, "%p", o.objectClass);

    res = "objectClass";
    res += "|";
    res += str;
    res += "|";
    Class * ptr;
    std::cout << str << std::endl;
    sscanf(str, "%p", &ptr);
    std::cout << ptr <<std::endl;
    std::cout << str << std::endl;

    return res;
}

Object *Serialization::deserialize(string s) {
    return nullptr;
}
