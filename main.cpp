#include <ncurses.h>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "objets.h"
#include "personnage.h"
#include "carte.h"
#include "Monstres.h"

using namespace std ;

/*
class Heros {
  public :
  Heros(string nom) {}

};

class Carte{
    public:
        int etage;
        vector<vector<char>> terrain;
        Heros heros;
        int x_max ;
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
    Carte (int n, Heros h): etage{n},heros{h} {
      terrain = lecture(0) ;
      x_max = terrain.size() ;
      y_max = terrain[0].size();
    }
    string deplacement(int x_rel, int y_rel){
      return "ceci est un message" ;
    }
    string haut(){
        return deplacement(-1, 0);
    }
    int escalier(){
        return 1 ;
    }
};
*/



int main(){
  initscr();

  printw("bonjour") ;

  int etage = 0 ;
  Heros heros ("Nom_du_perso") ;
  Carte carte (etage, heros) ;

  noecho() ; // stops writing characters on the screen
  keypad(stdscr, TRUE) ; // permet de lire des caractères type echap, flèches...
  cbreak() ; // prend les caractères un par un
  int nblignes = 24 ; // les quatre dernières sont dévolues aux pv etc
  int nbcols = 80 ;
  WINDOW * win = newwin(nblignes, nbcols, 0, 0) ; // crée une nouvelle fenetre

  char statut = 'n' ; // normal
  std::string message = "" ;
  while (1) {
    int ch = getch() ;
    switch (statut) {
      case 'n' :
        switch (ch) {
          case KEY_UP :
            message = carte.haut() ;
            carte.rafraichir(win) ;
            break ;
          case KEY_DOWN :
            message = carte.bas() ;
            carte.rafraichir(win) ;
            break ;
          case KEY_RIGHT :
            message = carte.droite() ;
            carte.rafraichir(win) ;
            break ;
        }
        mvwprintw(win,20,0,message.c_str()) ;
        break ;
      // autres cas pour le mode
    }
  }
  
  endwin();
  return 0;
}









/*
void rafraichir(WINDOW* win) {
  for (int x = 0 ; x<x_max ; x++ ) {
    for (int y = 0 ; y<y_max ; y++) {
      mvwaddch(win, y, x, terrain[x][y]);
    }
  }
  refresh() ;
}


*/