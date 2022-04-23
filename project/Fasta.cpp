#include "Fasta.h"
#include <iostream>

using namespace std;
Fasta :: Fasta (string id, string gi, string gb, string desc, string seq): Format(id, gi, gb, desc, seq){} //constructor

void Fasta :: printFormat() //print format funtion for fasta
{
    cout << "\n--------------------------------------------------------------------------------" << endl;
    cout << "\nSequence in Fasta Format:\n" << endl;
    cout << ">gi|" << getGi()<< "|gb|" << getGb();
    cout << "|" << getId() << " " << getDesc() << endl;
    cout << getSeq() << endl;
    cout << endl;
}
