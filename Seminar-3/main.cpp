#include <cstring>
#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

/*
* Caine -> clasa
*
* nume (char*)
* varsta (int)
* greutate (float)
*
* Constructor fara parametri
* Constructor cu parametri
* Constructor de copiere
* Destructor
* Operatorul de asignare (operatorul =)
*/

char* copiazaString(const char* const& sursa)
{
    if (sursa == nullptr)
    {
        return nullptr;
    }

    char* destinatie = new char[strlen(sursa) + 1];
    strcpy(destinatie, sursa);

    return destinatie;
}

class Caine
{
    int varsta;
    char* nume;
    float greutate;

public:

    Caine() // constructor fara parametri (construieste obiectul)
    {
        varsta = 0;
        nume = nullptr;
        greutate = 0.0f;
    }

    Caine(const int& varsta, const char* nume, const float& greutate) // constructorul cu toti parametrii
    {
        this->varsta = varsta;
        this->greutate = greutate;
        this->nume = copiazaString(nume);
    }

    Caine(const Caine& caine) // constructorul de copiere (face deep copy)
    {
        varsta = caine.varsta;
        greutate = caine.greutate;
        nume = copiazaString(caine.nume);
    }

    ~Caine() // destructor (distruge obiectul)
    {
        if (nume != nullptr)
        {
            delete[] nume;
            nume = nullptr;
        }
    }

    int getVarsta() const // int getVarsta(const Caine* const this)
    {
        /*this->varsta = 5; // (*this).varsta = 5;*/
        return this->varsta;
    }

    char* getNume() const
    {
        return nume;
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

    void setNume(const char* nume)
    {
        if (nume == nullptr)
        {
            return;
        }

        this->nume = copiazaString(nume);
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
    // Caine caine; // am chemat constructorul fara parametri
    // Caine caine = Caine(); // am chemat constructorul fara parametri

    Caine caine(6, "Samson", 10); // am chemat constructorul cu toti parametri
    //Caine caine = Caine(6, "Samson", 10); // am chemat constructorul cu toti parametri

    Caine copie(caine); // am chemat constructorul de copiere
    //Caine copie = Caine(caine); // am chemat constructorul de copiere

    cout << "Numele cainelui este: " << caine.getNume() << '\n';
    cout << "Varsta cainelui este: " << caine.getVarsta() << " ani\n";
    cout << "Greutatea cainelui este: " << caine.getGreutate() << " kilograme\n";

    caine.setVarsta(5);
    caine.setGreutate(20);
    caine.setNume("Grivei");

    cout << "Numele cainelui este: " << caine.getNume() << '\n';
    cout << "Varsta cainelui este: " << caine.getVarsta() << " ani\n";
    cout << "Greutatea cainelui este: " << caine.getGreutate() << " kilograme\n";

    //caine.~Caine(); // NU SE FACE ASA CEVA -> NICIODATA (destructorul va fi chemat automat doar la delete/delete[] sau la incheierea unei functii)

    Caine* ptr = new Caine();
    delete ptr; // delete va chema automat destructorul

    return 0;
}