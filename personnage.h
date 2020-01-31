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
        Arme arme("Branche d'arbre", 1, 2);
        Armure armure("Tutu rose", 1, 2);
        Armes.push_back(&arme);
        Armures.push_back(&armure);
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

    Ennemi(char c, int val_x, int val_y) {
    switch ( c ) {
	case 'C' :
		Personnage(5,2);
		x=val_x;
		y=val_y;
		xp_loot = 2;
		gold_loot = 2;
		msg_attaque="Cafard : *Bruit menaçant de cafard*";
		msg_mort="*Bruit d'agonie de cafard*";
		break;
    case 'J' :
		Personnage(30, 1);
		x=val_x;
		y=val_y;
		xp_loot = 1;
		gold_loot = 1;
		msg_attaque="JPG :...";
		msg_mort="...";
		break;
	case 'V' :
		Personnage(20, 7);
		x=val_x;
		y=val_y;
		xp_loot = 5;
		gold_loot = 5;
		msg_attaque="PAM : C’est moi qui l’aurai cette chambre !";
		msg_mort="Apeuré, il rentre chez lui en 2h30";
		break;

	case 'O' :
		Personnage(15, 7);
		x=val_x;
		y=val_y;
		xp_loot = 4;
		gold_loot = 4;
		msg_attaque="Camin : Soumets toi devant la moustache du chef !";
		msg_mort="Putain de Cyprien";
		break;

	case 'A':
		Personnage(20,5);
		x=val_x;
		y=val_y;
		xp_loot =4;
		gold_loot = 5;
		msg_attaque="Aline: Je veux ton loyer, donne moi ton loyer";
		msg_mort="Vous l’achevez avec un four";
		break;

    case 'P' :
		Personnage(10,4);
		x=val_x;
		y=val_y;
		xp_loot = 4;
		gold_loot = 4;
		msg_attaque="Picheur : Tu viens à Minas-Telien ce soir ?";
		msg_mort="Y’a une interne ce soir ?";
		break;

    case 'B' :
		Personnage(15,5);
		x=val_x;
		y=val_y;
		xp_loot = 5;
		gold_loot = 5;
		msg_attaque="Bencheur : Je vais t’exploser comme le bar des Camin";
		msg_mort="Bon ben go BDL";
		break;

    case '6' :
		Personnage(15,7);
		x=val_x;
		y=val_y;
		xp_loot = 4;
		gold_loot = 4;
		msg_attaque="P16 : Je vais te montrer la colère des anciens";
		msg_mort="De toute façon c’était mieux avant";
		break;

        }
    }
    

    string attaque_hero(Heros &cible) {
        if ((this->degats - cible.defense)>=0) {
            cible.pv = cible.pv - (this->degats -cible.defense);
            return "Ouch";
        }
    }
    ~Ennemi () {}

};

#endif






/* Ennemi(int pt_vie = 5, int dgt = 3, string message_attaque = "", string message_mort = "", int val_x = 0, int val_y = 0, int experience_donne = 1, int gold_loot = 2): 
    Personnage(pt_vie, dgt), , msg_attaque(message_attaque), msg_mort(message_mort) {} */