/*
 * NewClass.hpp
 *
 *  Created on: Mar 27, 2017
 *      Author: sabinghimire
 */

#ifndef NEWCLASS_HPP_
#define NEWCLASS_HPP_
#include"Friendclass.hpp"
#include <string>
#include <iostream>

using namespace std;


class NewClass {
public:
    friend class FriendClass;
    NewClass();
    void PrintName();
    virtual ~NewClass();
private:
    friend void FriendClass::
    int ClassNumber;
    string classname;
};

#endif /* NEWCLASS_HPP_ */
