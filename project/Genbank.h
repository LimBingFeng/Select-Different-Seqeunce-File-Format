#ifndef GENBANK_H
#define GENBANK_H
#include <iostream>
#include <vector>
#include "Format.h"

using namespace std;

class Genbank : public Format
{
public:
    Genbank (string id,string acc, string gi, string gb, string desc, string seq, vector<vector<string>> vec ); //constructor

    void baseCount(); //count and print number of nucleotide base
    void printSeq(); //print sequence in format
    void printVector(); //print features and value
    void printFormat(); //print format function

};


#endif // GENBANK_H
