#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <vector>
#include "objets.h"
#include <string>
#include <cstdlib>
using  namespace std;

class Personnage {
    public:
    char sol;
    int x,y; //position du personnage sur la map
    int argent, pv, xp, degats, defense;
    Personnage(int pt_vie = 10, int dgt = 1, int def = 0) : pv(pt_vie), degats(dgt), defense(def) {}
};

class Heros : public Personnage {
    public:
    string nom;
    int niveau, gold;
    int chance_cc;
    int i = 0;
    vector<Arme*> Armes;
    vector<Armure*> Armures;
    vector<int> inventaire_potion;


    Heros(string name, int lvl = 1) : Personnage(), niveau(lvl) {
        Armes[i] = new Arme ("Branche d'arbre", 1, 2);
        Armures[i] = new Armure ("Tutu rose", 1, 2);
        this->degats = (niveau-1)*2;
        this->pv = (niveau-1)*5 + 10;
        this->defense = niveau ;
    }    


    void monter_de_niveau() {
        niveau++;
        this->degats = (niveau-1)*2;
        this->pv = (niveau-1)*5 + 10;
        this->defense = niveau*1.5 ;
    }
    string attaque_ennemi(Personnage &cible) {
        int pt_bonus = 0;
        int nb_rand = rand();
        if (nb_rand >= (1-chance_cc)) {
            int pt_bonus = 1;
        }
        cible.pv = cible.pv - (this->degats + Armes[i]->attaque + pt_bonus);
        return "Tiens, prends toi ça !";
    }

};

class Ennemi : public Personnage {
    public:
    int xp_loot;
    int gold_loot;
    string msg_attaque, msg_mort;

    Ennemi(char c, int val_x, int val_y) {}

    /* Ennemi(int pt_vie = 5, int dgt = 3, string message_attaque = "", string message_mort = "", int val_x = 0, int val_y = 0, int experience_donne = 1, int gold_loot = 2): 
    Personnage(pt_vie, dgt), , msg_attaque(message_attaque), msg_mort(message_mort) {} */

    string attaque_hero(Heros &cible) {
        if ((this->degats - cible.defense)>=0) {
            cible.pv = cible.pv - (this->degats -cible.defense);
            return "Ouch";
        }
    }
    ~Ennemi () {
        
    }

};

#endif