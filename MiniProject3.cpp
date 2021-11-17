
 /*
    Name:       Byron Dowling, Paxton Proctor, Timothy Lockhart
    Course:     4103 Operating Systems
    Date:       11/12/2021

    Assignment: Mini Project #3
*/

#include <iostream>
#include <fstream>
#include <deque>


using namespace std;


struct Entry
{
    unsigned int Hex_Address;
    int command;
    int Page_Num;
};


int main()
{
    int PT_Size = 12;
    unsigned int Hits = 0;
    unsigned int Misses = 0;

    deque<Entry> TLB;
    //deque<Entry>::iterator it;

    ifstream Fin;

    Fin.open("spice.txt");
    //Fin.open("spicy.txt");

    while(!Fin.eof())
    {
        Entry temp;

        Fin >> temp.command;
        Fin >> hex >> temp.Hex_Address;
        temp.Page_Num = (temp.Hex_Address >>12);

        if (TLB.size() < PT_Size)
        {
            if (TLB.empty())
            {
                TLB.push_back(temp);
                Misses++;
            }

            else
            {
                bool found = false;

                for (int i = 0; i < TLB.size(); i++)
                {
                    if (temp.Page_Num == TLB[i].Page_Num)
                    {
                        Hits++;
                        found = true;
                    }
                }

                if (!found)
                {
                    TLB.push_back(temp);
                    Misses++;
                }
            }
        }

        else
        {
            bool found2 = false;

            for (int i = 0; i < TLB.size(); i++)
            {
                if (temp.Page_Num == TLB[i].Page_Num)
                {
                    found2 = true;
                    Hits++;
                }
            }

            if (!found2)
            {
                TLB.pop_front();
                TLB.push_back(temp);
                Misses++;
            }
        }

    }


    cout << "Hits: " << Hits << endl;
    cout << "Misses: " << Misses << endl;

    return 0;
}
