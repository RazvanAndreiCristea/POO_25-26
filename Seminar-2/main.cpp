#include <iostream>
using namespace std;

/*
* Caine -> clasa
* nume (char*)
* varsta (int)
* greutate (float)
*/

class Caine
{
    int varsta;
    char* nume;
    float greutate;

public:

    int getVarsta() const // int getVarsta(const Caine* const this)
    {
        /*this->varsta = 5; // (*this).varsta = 5;*/
        return this->varsta;
    }

    float getGreutate() const
    {
        return this->greutate;
    }


    void setVarsta(const int& varsta)
    {
        if (varsta < 0)
        {
            return;
        }

        this->varsta = varsta;
    }

    void setGreutate(const float& greutate) // void setGreutate(Caine* const this, const float& greutate)
    {
        if (greutate < 0.0f)
        {
            return;
        }

        this->greutate = greutate;
    }
};

int main()
{
    Caine caine;

    caine.setVarsta(5);
    caine.setGreutate(20);

    cout << "Varsta cainelui este: " << caine.getVarsta() << " ani\n";
    cout << "Greutatea cainelui este: " << caine.getGreutate() << " kilograme\n";

    return 0;
}