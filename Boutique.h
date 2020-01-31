#ifndef BOUTIQUE

#include <iostream>
#include <cstdlib>
#include <vector>
#include "objets.h"
#include "personnage.h"
using namespace std;

class Boutique{
    public:
    int bargent;
    vector<objet> stock;
    void vente(int i ){
        if (personnage.argent >= stock[i].prix and personnage.inventaire_plein==false){
            personnage.argent -= stock[i].prix;
            stock.erase(stock.begin()+i)
            personnage.ajoute(stock[i])
            cout<<"It's dangerous to go alone, take this"<<endl;

        } 
        else{
            if (personnage.argent < stock[i].prix){
                cout<<"Je ne fais pas de commerce avec les pauvres"<<endl;
            }
            if (personnage.inventaire_plein){
                cout<<"Ton inventaire est déjà plein, reviens me voir quand tu l'auras vidé"<<endl
            }
        }

    }

};

#endif