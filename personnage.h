#include <iostream>
#include <vector>
#include "objets.h"
#include <string>
using  namespace std;

class Personnage {
    public:
    char sol;
    int x,y; //position du personnage sur la map
    int argent, pv, xp, degats, defense;
    Personnage(int pt_vie = 10, int dgt = 1, int def = 0) : pv = pt_vie, degats = dgt, defense = def {}
};

class Heros : public Personnage {
    public:
    string nom;
    int niveau, gold;
    vector<objet> equipement;
    vector<int> inventaire;
    Hero(string name, int lvl = 1) : Personnage(), niveau = lvl {
        equipement[0] = Arme ("Branche d'arbre", 1, 2);
        equipement[1] = Armure ("Tutu rose", 1, 2);
        this->degats = (niveau-1)*2;
        this->pv = (niveau-1)*5 + 10;
        this->def = niveau ;
    }    
    void monter_de_niveau() {
        niveau++;
        this->degats = (niveau-1)*2;
        this->pv = (niveau-1)*5 + 10;
        this->def = niveau*1.5 ;
    }
    void attaque(Ennemi cible) {
        cible.pv = cible.pv - (this->degats + equipement[0].attaque)
    }
};

class Ennemi : public Personnage {
    public:
    int xp_loot;
    int gold_loot;
    string msg_attaque, msg_mort;
    Ennemi(int pt_vie = "5", int dgt = "3", string message_attaque = "", string message_mort = "", int val_x = "0", int val_y = "0", int experience_donne = 1, int gold_loot = 2): 
    x = val_x, y = val_y, pv = pt_vie, degats = dgt, msg_attaque = message_attaque, msg_mort = message_mort {}
    void attaque_hero(Heros ) {
        
    }
}