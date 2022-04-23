#include "Plain.h"
#include <iostream>

using namespace std;

Plain :: Plain(string seq): Format(seq){} //constructor

void Plain::printFormat() //print format for plain
{
    cout << "\n--------------------------------------------------------------------------------" << endl;
    cout << "\nSequence in Plain Format:\n" << endl;
    cout << getSeq() << endl;
    cout << endl;
}
