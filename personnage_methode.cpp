 #include "personnage.h"
 #include <string>
 
 std::string Heros::attaque_ennemi(Ennemi* cible) {
        int pt_bonus = 0;
        int nb_rand = rand();
        if (nb_rand >= (1-chance_cc)) {
            int pt_bonus = 1;
        }
        Arme* current_weapon = Armes[i_arme];
        cible->pv = cible->pv - (this->degats + current_weapon->attaque + pt_bonus);
        if (cible->pv == 0) {
            return cible->mort_ennemi(*this);
        }
        return "Tiens, prends toi ça !";
    } 