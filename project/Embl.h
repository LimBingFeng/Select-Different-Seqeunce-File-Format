#ifndef EMBL_H
#define EMBL_H
#include "Format.h"
#include <iostream>
using namespace std;

class Embl : public Format
{
public:
    Embl(string id,string acc, string gi, string gb, string desc, string seq, vector<vector<string> > vec ); //constructor

    void baseCount(); //count and print number of nucleotide base
    void printSeq(); //print sequence in format
    void printVector(); //print features and value
    void printFormat(); //print format function
};

#endif // EMBL_H
