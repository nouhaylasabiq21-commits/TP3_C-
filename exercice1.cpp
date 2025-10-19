#include <iostream>
#include <string>
using namespace std;

class CompteBancaire {
private:
    string titulaire;
    double solde;

public:
    CompteBancaire() {
        titulaire = "Inconnu";
        solde = 0.0;
        cout << "Constructeur par defaut appele pour le compte de " << titulaire << endl;
    }

    CompteBancaire(const string& nom, double montant) {
        titulaire = nom;
        solde = montant;
        cout << "Constructeur parametre appele pour le compte de " << titulaire << endl;
    }
    CompteBancaire(const CompteBancaire& autre) {
        titulaire = autre.titulaire;
        solde = autre.solde;
        cout << "Constructeur de copie appele pour le compte de " << titulaire << endl;
    }

    void afficher() const {
        cout << "Titulaire : " << titulaire << endl;
        cout << "Solde     : " << solde << " DH" << endl;
    }


    ~CompteBancaire() {
        cout << "Destructeur appele pour le compte de " << titulaire << endl;
    }
};

int main() {
    CompteBancaire compte1;
    CompteBancaire compte2("Alice", 1500.0);
    CompteBancaire compte3 = compte2;

    cout << endl << "Affichage des comptes" << endl;
    compte1.afficher();
    compte2.afficher();
    compte3.afficher();

    cout << endl << "Fin du programme" << endl;
    return 0;
}
