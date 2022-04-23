#include <iostream>
#include <vector>
#include "Format.h"
#include "Fasta.h"
#include "Plain.h"
#include "Genbank.h"
#include "Embl.h"

using namespace std;

//Declare global variable
string id, acc, gi, gb, desc, seq, feature, value;
vector<vector<string>> vec;

//Function Prototype
void simpleFormat();
void richFormat();
void bothFormat();

void fastaFile();
void plainFile();
void bothSimpleFormat();
void genbankFile();
void emblFile();
void bothRichFormat();
void b1();
void b2();
void b3();
void b4();
void b5();
void b6();
void b7();
void b8();
void b9();

//Input function for simple format
namespace simp
{
void input()
{
    cout << "\nEnter the sequence details: " << endl;
    cout << "Id: ";
    cin >> id; //input id
    cout << "Version: gi: ";
    cin >> gi; //input gi
    cout << "         gb: ";
    cin >> gb; //input gb
    cout << "Description: ";
    getline(cin>> ws,desc); // input description
    cout << "Sequence: ";
    cin >> seq; //input sequence
}
}

//Input fucntion for rich format
namespace rich
{
void input()
{
    // variables to control loop
    bool addFeatures = true;
    bool addValue = true;
    string choiceFeature, choiceValue;

    cout << "\nEnter the sequence details: " << endl;
    cout << "Id: ";
    cin >> id; //input id
    cout << "Accesion No.: ";
    cin >> acc; //input accession no.
    cout << "Version: gi: ";
    cin >> gi; //input gi
    cout << "         gb: ";
    cin >> gb; //input gb
    cout << "Description: ";
    getline(cin>> ws,desc); //input description
    cout << "Sequence: ";
    cin >> seq; //iniput sequence

    while(addFeatures) //while true
    {
        cout << "\nEnter features? Press 'Y' or 'N'" << endl;
        cout << "Option: " ;
        cin >> choiceFeature; //input choice for adding feature
        vector<string> row; // recreate vector row every loop

        if(choiceFeature == "Y")
        {
            addValue = true;

            cout << "Feature: ";

            getline(cin >> ws, feature); //input feature


            row.push_back(feature); //add feature into vector row

            cout << endl;


            while(addValue) //while true
            {
                cout << "Add value? Press 'Y' or 'N'" << endl;
                cout << "Option: ";
                cin >> choiceValue; //input choice for adding value



                if(choiceValue == "Y" )
                {
                    cout << "Value: " ;

                    getline(cin >> ws, value); //input value
                    row.push_back(value); //adding value to the vector after the feature


                    cout << endl;
                }
                else if (choiceValue == "N")
                {
                    addValue = false; //quit adding value
                }
                else
                {
                    cout << "Invalid Input" << endl;
                    cout << endl; //invalid and loop to input value again
                }
            }
            vec.push_back(row);

        }
        else if(choiceFeature == "N")
        {
            addFeatures = false; //quit adding feature
        }
        else
        {
            cout << "Invalid Input" << endl;
            cout << endl; //invalid and loop to input feature again
        }
    }
}
}


int main()
{
    bool restart = true; //control loop
    int choice, fileType, fileFormat; //choices

    while(restart) //while true
    {
        cout << "Choose the sequence file format:" << endl;
        cout << "1 - Simple Format" << endl;
        cout << "2 - Rich Format" << endl;
        cout << "3 - Both Format" << endl;
        cout << "Options: ";
        cin >> fileType; //input fileType choice

        if (fileType == 1)
        {
            simpleFormat(); //call function for simple format
        }
        else if (fileType == 2)
        {
            richFormat(); //call function for rich format
        }
        else if (fileType == 3)
        {
            bothFormat(); //call function for both format
        }
        else
        {
            cout << "\nInvalid Input!" << endl; //invalid input
        }

        cout << "\nDo you want to restart?" << endl;
        cout << "1 - Restart" << endl;
        cout << "Others - Terminate Program" << endl;
        cout << "Options: ";
        cin >> choice; //input choice to restart

        if(choice == 1)
        {
            restart == true;
            cout << endl; //restart
        }
        else
        {
            break; //end program
        }
    }
}

void simpleFormat() //fuinction to choose simple file format
{
    int fileFormat; //choice for simple file format

    cout << "\nChoose the simple file format:" << endl;
    cout << "1 - Plain Format" << endl;
    cout << "2 - FASTA Format" << endl;
    cout << "3 - Both Format" << endl;
    cout << "Options: ";
    cin >> fileFormat; //input choice

    if (fileFormat == 1)
    {
        plainFile(); //call function for plain format
    }
    else if (fileFormat == 2)
    {
        fastaFile(); //call function for fasta format
    }
    else if (fileFormat == 3)
    {
        bothSimpleFormat(); //call function for both plain and fasta format
    }
    else
    {
        cout << "\nInvalid Input!" << endl; //invalid
    }

}

void richFormat() //function to choose rich file format
{
    int fileFormat; //choice for rich file format

    cout << "\nChoose the rich file format:" << endl;
    cout << "1 - Genbank Format" << endl;
    cout << "2 - EMBL Format" << endl;
    cout << "3 - Both Format" << endl;
    cout << "Options: ";
    cin >> fileFormat; //input choice

    if (fileFormat == 1)
    {
        genbankFile(); //call function for genbank format
    }
    else if (fileFormat == 2)
    {
        emblFile(); //call function for embl format
    }
    else if (fileFormat == 3)
    {
        bothRichFormat(); //call function for both genbank and embl format
    }
    else
    {
        cout << "\nInvalid Input!" << endl; //invalid
    }
}

void bothFormat() //function to choose simple and rich file format
{
    int fileFormat; //choice for both simple and rich format

    cout << "\nChoose a combination file format:" << endl;
    cout << "1 - Plain + Genbank" << endl;
    cout << "2 - Plain + EMBL" << endl;
    cout << "3 - Plain + Genbank + EMBL" << endl;
    cout << "4 - FASTA + Genbank" << endl;
    cout << "5 - FASTA + EMBL" << endl;
    cout << "6 - FASTA + Genbank + EMBL" << endl;
    cout << "7 - Plain + FASTA   + Genbank" << endl;
    cout << "8 - Plain + FASTA   + EMBL" << endl;
    cout << "9 - Plain + FASTA   + Genbank + EMBL" << endl;
    cout << "Options: ";
    cin >> fileFormat; //input choice

    if (fileFormat == 1)
    {
        b1(); //call function b1
    }
    else if (fileFormat == 2)
    {
        b2(); //call function b2
    }
    else if (fileFormat == 3)
    {
        b3(); //call function b3
    }
    else if (fileFormat == 4)
    {
        b4(); //call function b4
    }
    else if (fileFormat == 5)
    {
        b5(); //call function b5
    }
    else if (fileFormat == 6)
    {
        b6(); //call function b6
    }
    else if (fileFormat == 7)
    {
        b7(); //call function b7
    }
    else if (fileFormat == 8)
    {
        b8(); //call function b8
    }
    else if (fileFormat == 9)
    {
        b9(); //call function b9
    }
    else
    {
        cout << "\nInvalid Input!" << endl; //invalid
    }
}

void plainFile() //display sequence details in plain format
{
    cout << "\nEnter the sequence details: " << endl;
    cout << "Sequence: ";
    cin >> seq; //input sequence
    Format *type; //create object pointer type
    Plain plain(seq); //create object plain
    type = &plain; //assign pointer type to plain
    type -> printFormat(); //print format
}

void fastaFile() //display sequence details in fasta format
{
    simp::input(); //call simple input function
    Format *type; //create object pointer type
    Fasta fasta(id, gi, gb, desc, seq); //create object plain
    type = &fasta; //assign pointer type to fasta
    type -> printFormat();//print format
}

void bothSimpleFormat() //display sequence details in both plain and fasta format
{
    simp::input(); //call simple input function
    Format *type; //create object pointer type

    Plain plain(seq); //create object plain
    type = &plain; //assign pointer type to plain
    type -> printFormat(); //print format

    Fasta fasta(id, gi, gb, desc, seq); //create object plain
    type = &fasta; //assign pointer type to fasta
    type -> printFormat(); //print format
}

void genbankFile() //display sequence details in Genbank format
{

    rich::input(); //call rich input function
    Format *type; //create object pointer type
    Genbank genbank(id, acc, gi, gb, desc,seq, vec); //create object genbank
    type = &genbank; //assign pointer type to genbank
    type -> printFormat(); //print format

    vec.clear(); //clear vector vec
}

void emblFile() //display sequence details in EMBL format
{
    rich::input(); //call rich input function
    Format *type; //create object pointer type
    Embl embl(id, acc, gi, gb, desc,seq, vec); //create object embl
    type = &embl; //assign pointer type to embl
    type -> printFormat(); //print format

    vec.clear(); //clear vector vec
}

void bothRichFormat() //display sequence details in both Genbank and EMBL format
{
    rich::input(); //call rich input function
    Format *type; //create object pointer type
    Genbank genbank(id, acc, gi, gb, desc,seq, vec); //create object genbank
    type = &genbank; //assign pointer type to genbank
    type -> printFormat(); //print format

    Embl embl(id, acc, gi, gb, desc,seq, vec); //create object embl
    type = &embl; //assign pointer type to embl
    type -> printFormat(); //print format

    vec.clear(); //clear vector vec
}

void b1() //display sequence details in Plain + Genbank
{
    rich::input(); //call rich input function
    Format *type; //create object pointer type
    Plain plain(seq); //create object plain
    type = &plain; //assign pointer type to plain
    type -> printFormat(); //print format

    Genbank genbank(id, acc, gi, gb, desc,seq, vec); //create object genbank
    type = &genbank; //assign pointer type to genbank
    type -> printFormat(); //print format

    vec.clear(); //clear vector vec
}
void b2() //display sequence details in Plain + EMBL
{
    rich::input(); //call rich input function
    Format *type; //create object pointer type
    Plain plain(seq); //create object plain
    type = &plain; //assign pointer type to plain
    type -> printFormat();

    Embl embl(id, acc, gi, gb, desc,seq, vec); //create object embl
    type = &embl; //assign pointer type to embl
    type -> printFormat(); //print format

    vec.clear(); //clear vector vec
}
void b3() //display sequence details in Plain + Genbank + EMBL
{
    rich::input(); //call rich input function
    Format *type; //create object pointer type
    Plain plain(seq); //create object plain
    type = &plain; //assign pointer type to plain
    type -> printFormat(); //print format

    Genbank genbank(id, acc, gi, gb, desc,seq, vec); //create object genbank
    type = &genbank; //assign pointer type to genbank
    type -> printFormat(); //print format

    Embl embl(id, acc, gi, gb, desc,seq, vec); //create object embl
    type = &embl; //assign pointer type to embl
    type -> printFormat(); //print format

    vec.clear(); //clear vector vec

}
void b4() //display sequence details in FASTA + Genbank
{
    rich::input(); //call rich input function
    Format *type; //create object pointer type
    Fasta fasta(id, gi, gb, desc, seq); //create object plain
    type = &fasta; //assign pointer type to fasta
    type -> printFormat(); //print format

    Genbank genbank(id, acc, gi, gb, desc,seq, vec); //create object genbank
    type = &genbank; //assign pointer type to genabank
    type -> printFormat(); //print format

    vec.clear(); //clear vector vec
}
void b5() //display sequence details in FASTA + EMBL
{
    rich::input(); //call rich input function
    Format *type; //create object pointer type
    Fasta fasta(id, gi, gb, desc, seq); //create object plain
    type = &fasta; //assign pointer type to fasta
    type -> printFormat(); //print format

    Embl embl(id, acc, gi, gb, desc,seq, vec); //create object embl
    type = &embl; //assign pointer type to embl
    type -> printFormat(); //print format

    vec.clear(); //clear vector vec


}
void b6() //display sequence details in FASTA + Genbank + EMBL
{
    rich::input(); //call rich input function
    Format *type; //create object pointer type
    Fasta fasta(id, gi, gb, desc, seq); //create object plain
    type = &fasta; //assign pointer type to fasta
    type -> printFormat(); //print format

    Genbank genbank(id, acc, gi, gb, desc,seq, vec); //create object genbank
    type = &genbank; //assign pointer type to genbank
    type -> printFormat(); //print format

    Embl embl(id, acc, gi, gb, desc,seq, vec); //create object embl
    type = &embl; //assign pointer type to embl
    type -> printFormat(); //print format

    vec.clear(); //clear vector vec
}
void b7() //display sequence details in Plain + FASTA + Genbank
{
    rich::input(); //call rich input function
    Format *type; //create object pointer type
    Plain plain(seq); //create object plain
    type = &plain; //assign point34 type to plain
    type -> printFormat(); //print format

    Fasta fasta(id, gi, gb, desc, seq); //create object plain
    type = &fasta; //assign pointer type to fasta
    type -> printFormat(); //print format

    Genbank genbank(id, acc, gi, gb, desc,seq, vec); //create object genbank
    type = &genbank; //assign pointer type to genbank
    type -> printFormat(); //print format

    vec.clear(); //clear vector vec
}
void b8() //display sequence details in Plain + FASTA + EMBL
{
    rich::input(); //call rich input function
    Format *type; //create object pointer type
    Plain plain(seq); //create object plain
    type = &plain; //assign pointer type to plain
    type -> printFormat(); //print format

    Fasta fasta(id, gi, gb, desc, seq); //create object plain
    type = &fasta; //assign pointer type to fasta
    type -> printFormat(); //print format

    Embl embl(id, acc, gi, gb, desc,seq, vec);//create object embl
    type = &embl; //assign pointer type to embl
    type -> printFormat(); //print format

    vec.clear(); //clear vector vec

}
void b9() //display sequence details in Plain + FASTA + Genbank + EMBL
{
    rich::input(); //call rich input function
    Format *type; //create object pointer type
    Plain plain(seq); //create object plain
    type = &plain; //assign pointer type to plain
    type -> printFormat(); //print format

    Fasta fasta(id, gi, gb, desc, seq); //create object plain
    type = &fasta; //assign pointer type to fasta
    type -> printFormat(); //print format

    Genbank genbank(id, acc, gi, gb, desc,seq, vec); //create object genbank
    type = &genbank; //assign pointer type to genbank
    type -> printFormat(); //print format

    Embl embl(id, acc, gi, gb, desc,seq, vec);//create object embl
    type = &embl; //assign point type to embl
    type -> printFormat(); //print format

    vec.clear(); //clear vector vec
}


