#ifndef MONSTRES
#include <iostream>
#include <cstdlib>
#include <vector>
#include "personnage.h"

class Aline : public Ennemi {
    Aline(int x,int y): Ennemi(20,5,"Je veux ton loyer, donne moi ton loyer","Vous l'achevez avec un four",x,y,5,5){};
};
class Cafard : public Ennemi {
    Cafard(int x,int y): Ennemi(5,2, "*Bruit menaçant de cafard*", "*Bruit d'agonie de cafard*",x,y,2,2){};
};
class Picheur : public Ennemi {
    Picheur(int x,int y):Ennemi(10,4,"Tu viens à Minas Telien ce soir?","Y'a une externe ce soir?",x,y,3,3){};
};
class Bencheur : public Ennemi {
    Bencheur(int x,int y):Ennemi(15,5,"Je vais t'exploser comme le bar des Camin","Bon ben go BDL",x,y,4,4){};
};
class P16  : public Ennemi{
    P16(int x,int y):Ennemi(20,6,"Je vais te montrer la colère des Anciens", "De toute façon c'était mieux avant",x,y,5,5){};
};
class Camin: public Ennemi{
    Camin(int x,int y):Ennemi(15,7,"Soumets-toi devant la moustache du chef","Putain de Cyprien",x,y,4,4){};
};
class JPG: public Ennemi{
    JPG(int x, int y): Ennemi(30,1,"...","...",x,y,1,1){};
};
class PAM: public Ennemi{
    PAM(int x, int y): Ennemi(20,7,"C'est moi qui l'aurai cette chambre!","",x,y,5,5){}
};

#endif
