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
/*
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
    */
    //example : x#5#y#56#z#11#obj1#<y#2#D#3>#obj2#<a#1#b#4#myobj1#<a#33#f#32>#myobj2#<b#23#5#v#66>#>#
    //TODO: add class pointer(?) to serialization
    //TODO: maybe add "setAccessible(true)" at the beginning of the function and revert the changes at the end
    map<string, int> &intFields = o.intFields;
    string res = "";
    for (map<string, int>::const_iterator it = intFields.begin(); it != intFields.end(); ++it) {
        res += it->first + "#" + std::to_string(it->second) + "#";
    }

    map<string, Object *> &objectFields = o.objectFields;
    for (map<string, Object *>::const_iterator it = objectFields.begin(); it != objectFields.end(); ++it) {
        res += it->first + "#<" + serialize(*(it->second)) + ">#";
    }
    std::cout << std::endl << "serialization result:    " << res << std::endl;//TODO: remove this
    return res;
}

Object *Serialization::deserialize(string s) {
    return deserialize_aux(s);
}

Object *Serialization::deserialize_aux(string &s) {
    //TODO: add class pointer(?) to deserialization
    //TODO: maybe add "setAccessible(true)" at the beginning of the function and revert the changes at the end
    map<string, int> *intFields = new map<string, int>();
    map<string, Object *> *objectFields = new map<string, Object *>();
    std::size_t firstIndex;
    string fieldName;
    string fieldIntValue;
    Object *fieldObjValue;
    while (s.length() != 0) {
        if (s[0] == '>') {//end of object
            s.erase(0, 2);
            return new Object(nullptr /*TODO: add objectClass instead*/, *objectFields, *intFields);
        }
        firstIndex = s.find("#");
        fieldName = s.substr(0, firstIndex);
        s.erase(0, firstIndex + 1);
        if (s[0] == '<') {//value is object
            s.erase(0, 1);
            fieldObjValue = deserialize_aux(s);
            (*objectFields)[fieldName] = fieldObjValue;
        }
        else {//value is int
            firstIndex = s.find("#");
            fieldIntValue = s.substr(0, firstIndex);
            s.erase(0, firstIndex + 1);
            (*intFields)[fieldName] = atoi(fieldIntValue.c_str());
        }
    }
    std::cout << std::endl << "deserialization result:    " <<
    serialize(*new Object(nullptr, *objectFields, *intFields)) << std::endl;//TODO: remove this
    return new Object(nullptr /*TODO: add objectClass instead*/, *objectFields, *intFields);
}
