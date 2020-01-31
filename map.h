#ifndef CARTE_H
#define CARTE_H

#include<iostream>
#include<vector>
#include<fstream>
#include<ncurses.h>
#include<map>
#include<string>
#include"personnage.h"
#include"Monstres.h"
#include"objets.h"

using namespace std;

class Carte{
    public:
        int etage;
        vector<vector<char>> terrain;
        vector<Ennemi> ennemis;
        Heros heros;
        int x_max;
        int y_max;
        map<string,char> image;

    vector<vector<char>> lecture (int n){ //prend en argument un niveau et renvoie un tableau avec la map
        vector<vector<char>> vmap{};
        string adress;
        adress = "map/niveau"+to_string(n)+".txt";
        ifstream data{adress};
        
        int x;
        int y;
        data >> x;
        data >> y;

        char c;
        data.get(c);

        for (int i=0;i<y;i++){
            vector<char> ligne;
            for(int j=0;j<x;j++){
                data.get(c);
                ligne.push_back(c);
            }
            data.get(c);
            vmap.push_back(ligne);
        }

        data.close();
        return vmap;
    }
    void rafraichir(WINDOW* win) {
        for (int x = 0 ; x<x_max ; x++ ) {
            for (int y = 0 ; y<y_max ; y++) {
            mvwaddch(win, y, x, terrain[x][y]);
            }
        }
        wrefresh(win) ;
    }
    Map (int n, Hero h): etage{n},hero{h} {
        image["heros"] = 'H';
        image["cafard"] = 'C';
        image["sol_salle"] = '.';
        image["sol_couloir"] = '#';
        image["porte"] = '+';
        image["escalier"] = '=';
        image["arme"] = '!';
        terrain = lecture(n);
        x_max = terrain.size;
        y_max = terrain[0].size;
        for (int x = 0; x < x_max; x++){
            for (int y = 0; y < y_max; y++){
                switch (terrain[x][y]){
                    case image["heros"]:
                        heros = Heros(x,y);
                    case image["cafard"] = 'C':
                        Cafard(x,y);
                }
            }
        }
    }
    string deplacement(int x_rel, int y_rel){
        int x = heros.x;
        int y = heros.y;
        switch (terrain[x + x_rel][y + y_rel]){
            case image["sol_salle"]:
                heros.x += x_rel;
                heros.y += y_rel;
                terrain[x][y] = heros.sol;
                heros.sol = image["sol_salle"];
                terrain[heros.x][heros.y] = image["heros"];
                return "Je suis dans une salle !";
            case image["sol_couloir"]:
                heros.x += x_rel;
                heros.y += y_rel;
                terrain[x][y] = heros.sol;
                heros.sol = image["sol_couloir"];
                terrain[heros.x][heros.y] = image["heros"];
                return "Je suis dans un couloir !";
            case image["porte"]:
                heros.x += x_rel;
                heros.y += y_rel;
                terrain[x][y] = heros.sol;
                heros.sol = image["porte"];
                terrain[heros.x][heros.y] = image["heros"];
                return "Je passe une porte !";
            case image["escalier"]:
                heros.x += x_rel;
                heros.y += y_rel;
                terrain[x][y] = heros.sol;
                heros.sol = image["escalier"];
                terrain[heros.x][heros.y] = image["escalier"];
                return "Je suis sur un escalier !";
            case image["arme"]:
                return "Arme";
        }

    }
    string haut(){
        return deplacement(-1, 0);
    }
    string bas(){
        return deplacement(1, 0);
    }
    string gauche(){
        return deplacement (0,-1);
    }
    string droite(){
        return deplacement (0, 1);
    }
    int escalier(){
        if (terrain[heros.x][heros.y] = image["escalier"]){
            return +1;
        }
        else {
            return 0;
        }
    }
};

#endif