
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
            Map.update(win) ; // il va falloir coder le update dans la classe map tel que on reconstruit l'affichage
            refresh() ;
            break ;
          case KEY_RIGHT :
            Map.droite() ;
            Map.update(win) ;
            refresh() ;
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
#include <ncurses.h>

int main {
  initscr() ;
  noecho() ;
  keypad(stdscr, TRUE) ;

}*/