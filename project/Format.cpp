#include "Format.h"
#include <iostream>

using namespace std;
//constructor
Format :: Format():Id("No Id yet"), Gi("No gi yet"), Gb("No gb yet"),Desc("No description yet"), Seq("No seq yet") {}

Format :: Format(string seq): Seq(seq){};

Format :: Format(string id, string gi, string gb, string desc, string seq)
{
    Id = id;
    Gi = gi;
    Gb = gb;
    Desc = desc;
    Seq = seq;
}

Format :: Format (string id,string acc, string gi, string gb, string desc, string seq, vector<vector<string>> vec)
{
    Id = id;
    Acc = acc;
    Gi = gi;
    Gb = gb;
    Desc = desc;
    Seq = seq;
    Vec = vec;
}

//Mutator
void Format :: setId(string newId)
{
    Id = newId;
}

void Format :: setAcc(string newAcc)
{
    Acc = newAcc;
}

void Format :: setGi(string newGi)
{
    Gi = newGi;
}

void Format :: setGb(string newGb)
{
    Gb = newGb;
}

void Format :: setDesc(string newDesc)
{
    Desc = newDesc;
}

void Format :: setSeq(string newSeq)
{
    Seq = newSeq;
}

//accessor
string Format :: getId()
{
    return Id;
}

string Format :: getAcc()
{
    return Acc;
}

string Format :: getGi()
{
    return Gi;
}

string Format :: getGb()
{
    return Gb;
}

string Format :: getDesc()
{
    return Desc;
}

string Format :: getSeq()
{
     for (int i=0; i < Seq.length(); i++)
         Seq[i] = toupper(Seq[i]); //changing every character to upper case

    return Seq;
}

vector<vector<string>> Format :: getVec()
{
    return Vec;
}

int Format :: getSeqLength() //get sequence length
 {
     return Seq.length();
 }

