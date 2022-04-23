#ifndef FORMAT_H
#define FORMAT_H
#include <iostream>
#include <vector>

using namespace std;

class Format
{
private:
    //declaring variables
    string Id;
    string Acc;
    string Gi;
    string Gb;
    string Desc;
    string Seq;
    vector<vector<string>> Vec;

public:
    //constructor
    Format();
    Format(string seq);
    Format(string id, string gi, string gb, string desc, string seq);
    Format(string id,string acc, string gi, string gb, string desc, string seq, vector<vector<string>> vec );

    //Mutator
    void setId(string newId); //id setter
    void setAcc(string newAcc); //accession no setter
    void setGi(string newGi); //gi setter
    void setGb(string newGb); //gb setter
    void setDesc(string newDesc); //description setter
    void setSeq(string newSeq); //sequence setter

    //Accessor
    string getId(); //id getter
    string getAcc(); //accession no getter
    string getGi(); //gi getter
    string getGb(); //gb getter
    string getDesc(); //description getter
    string getSeq(); //sequence getter
    vector<vector<string>> getVec(); //vec getter

    int getSeqLength(); //get sequence length function
    virtual void printFormat()=0; //virtual print format function

};
#endif //FORMAT_H
