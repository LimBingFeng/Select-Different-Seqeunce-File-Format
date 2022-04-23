#ifndef FASTA_H
#define FASTA_H
#include "Format.h"


class Fasta : public Format
{

public:
    Fasta(string id, string gi, string gb, string desc, string seq); //constructor

    void printFormat(); //print format function
};


#endif // FASTA_H
