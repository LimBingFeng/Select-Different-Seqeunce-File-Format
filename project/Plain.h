#ifndef PLAIN_H
#define PLAIN_H
#include "Format.h"
#include <iostream>

using namespace std;

class Plain : public Format
{
public:
    Plain(string seq); //constructor

    void printFormat(); //print format function
};

#endif // PLAIN_H
