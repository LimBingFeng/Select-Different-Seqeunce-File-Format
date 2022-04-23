#include "Genbank.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

Genbank :: Genbank (string id, string acc, string gi, string gb, string desc, string seq, vector<vector<string>> vec): Format (id, acc, gi, gb, desc, seq, vec){} //constructor

void Genbank :: baseCount() //count and print number of nucleotide base
{
    string theSeq = getSeq(); //set private seq into theSeq
    int a=0, g=0,c=0, t=0, other=0; //declare variables

    for (int i = 0; i < getSeqLength(); i++) //add 1 when condition met
    {
        switch (theSeq[i])
        {
        case 'A':
            a=a+1;
            break;
        case 'G':
            g=g+1;
            break;
        case 'C':
            c=c+1;
            break;
        case 'T':
            t=t+1;
            break;
        default:
            other = other +1;
            break;
        }
    }

    //print base count
    cout << a << " A   ";
    cout << c << " C   ";
    cout << g << " G   ";
    cout << t << " T   ";
    cout << other<<" other   "  << endl;
}

void Genbank :: printSeq() //print sequence in format
{
    string theSeq = getSeq(); //set private Seq into theSeq

    theSeq = " " + theSeq; //adding space in front so that seq does not starts with 0 (1-10)
                           //avoid sequence being messed up when printing

    cout << "  1  "; //start with 1

    for(int i = 1; i <= getSeqLength(); i++)
    {

        cout << theSeq[i] ; //print char at i

        if (i%50 == 0&& i < 100) //when remainder = 0 go to next line and print number of 2 digits
        {
            cout << endl;
            cout <<" "<< i+1 << " ";
        }
        else if (i%50 == 0 && i < 1000) //when remainder = 0 go to next line and print number of 3 digits
        {
            cout << endl;
            cout << i+1 << " ";
        }


        if (i%10 == 0) //every 10 count separate by a space
        {

            cout << " " ;
        }
    }
}

void Genbank :: printVector() //print feature and value
{
    vector<vector<string>> theVec = getVec(); //set private Vec into theVec
                                              // example of 2D vector
                                              //{ {1,2,3}
                                              //  {4,5}
                                              //  {6,7,8,9} }
                                              // first column are all the feature
                                              // other columns are all the value
                                              // each row is a feature and its values

    for (int i = 0; i < theVec.size (); i++)
    {
        cout << theVec[i][0]<<"        "; //print feature

        for (int j = 1; j < theVec[i].size (); j++)
        {
            cout << theVec[i][j] << endl; //print 1st value for feature i

            for (int k = 2; k < theVec[i].size (); j++,k++)
            {
                cout <<"              "<< theVec[i][k] << endl; //print the remaining value for feature i
            }
        }

        if (theVec[i].size() == 1) //if only one feature, go to next line (avoid 2 feature printing on the same line)
            cout << endl;
    }
}

void Genbank :: printFormat() //print format for genbank
{
    cout << "\n--------------------------------------------------------------------------------" << endl;
    cout << "\nSequence in Genbank Format:\n" << endl;

    cout << "LOCUS      " << getId() << "     " << getSeqLength() << "bp     DNA" << endl;
    cout << "DEFINITION " << getDesc() << endl;
    cout << "ACCESSION  " << getAcc() << endl;
    cout << "VERSION    " << "Gi: " << getGi() << "   Gb: " << getGb() << endl;
    cout << "FEATURES" << setw(25) << "Location/Qualifiers" << endl;
    printVector();
    cout << "BASE COUNT ";
    baseCount();
    cout << "ORIGIN " << endl;
    printSeq();
    cout << endl;


}


