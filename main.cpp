#include <ncurses.h>
#include <string>
#include <map.h>
#include <items.h>

int main(){
  initscr();
  noecho() ; // stops writing characters on the screen
  keypad(stdscr, TRUE) ; // permet de lire des caractères type echap, flèches...
  cdbreak() ; // prend les caractères un par un
  int nblignes = 20 ;
  int nbcols = 80 ;
  WINDOW * win = newwin(nblignes, nbcols, 0, 0) ; // crée une nouvelle fenetre

  int ch ;
  char statut = 'n' ; // normal
  string message = "" ;
  while (1) {
    ch = getch() ;
    switch statut {
      case 'n' :
        switch ch {
          case KEY_LEFT :
            Map.gauche() ; // a changer
            Map.rafraichir(win) ; // il va falloir coder le update dans la classe map tel que on reconstruit l'affichage
            break ;
          case KEY_RIGHT :
            Map.droite() ;
            Map.rafraichir() ;
            break ;
        }
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