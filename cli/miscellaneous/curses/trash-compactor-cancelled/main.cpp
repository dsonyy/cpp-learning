#include <curses.h>
#include <stdlib.h>
#include <time.h>

//    int headX = kolumny/2-szer/2+2;
/*

    int kolumny, rzedy;
    getmaxyx(stdscr, rzedy, kolumny);

*/
void menu();


class Player
{
private:

    // pozycja graczy
    int headX;
    int headY;

    // klawiszologia
    char up;
    char down;
    char left;
    char right;

    char first;
    char sec;
    // wypisanie gracza
    void write()
    {
        attron( COLOR_PAIR( 5 ) );
        move(headY,headX);
        first = inch();
        printw("%c",first);
        sec = inch();
        printw("%c",sec);
        attroff( COLOR_PAIR( 5 ));
    }
public:

    // spawn gracza
    Player (int hY = 5, int hX = 27, char U = 'w', char D = 's', char L = 'a', const char R = 'd')
    {
        headX=hX;
        headY=hY;

        up=U;
        down=D;
        left=L;
        right=R;

        write();
    }

    // poruszanie gracza
    void movement()
    {
        // pobieranie ruchu
        char nav = getch();
        //RUCHY GRACZA
        if (nav==right)
        {
            move(headY,headX+2);
            if(inch()!=219)
            {
                move(headY,headX);
                printw("%c",first);
                printw("%c",sec);
                headX=headX+2;
                write();
            }
        }
        else if (nav==left)
        {
            move(headY,headX-2);
            if(inch()!=219)
            {
                move(headY,headX);
                printw("%c",first);
                printw("%c",sec);
                headX=headX-2;
                write();
            }
        }
        else if (nav==up)
        {
            move(headY-1,headX);
            if(inch()!=219)
            {
                move(headY,headX);
                printw("%c",first);
                printw("%c",sec);
                headY=headY-1;
                write();
            }
        }
        else if (nav==down)
        {
            move(headY+1,headX);
            if(inch()!=219)
            {
                move(headY,headX);
                printw("%c",first);
                printw("%c",sec);
                headY=headY+1;
                write();
            }
        }
    }
};

void mapa()
{
    char CH0L0[25][50] ={{'�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�'}};

    char CH1L1[25][50] ={{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ','�','�','�','�','�','�','�','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ','�','�',' ',' ',' ',' ',' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ','�','�',' ',' ',' ',' ',' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ','�','�',' ',' ',' ',' ',' ','�','�','�','�','�','�','�','�','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ','�','�',' ',' ',' ',' ',' ','�','�',' ',' ',' ',' ',' ',' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ','�','�','�','�','�','�','�','�','�','�',' ',' ',' ',' ',' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�',' ',' ',' ',' ',' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�',' ',' ',' ',' ',' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�',' ',' ',' ',' ',' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�',' ',' ',' ',' ',' ','�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};

    for (int i = 0; i<25; i++) //WYPISANIE MAPY
    {
        printw("\n");
        for(int j = 0 ; j<50 ; j++)
        {
            printw("%c",CH1L1[i][j]);
        }
    }

}
void gra()
{
    int kolumny, rzedy;
    getmaxyx(stdscr, rzedy, kolumny);

    const int wys=25, szer=50; //parzysta szerokosc
    unsigned char plansza[wys][szer];

    for (int i = 0; i<wys; i++) //WYPELNIENIE "POWIETRZEM"
    {
        for(int j = 0 ; j<szer ; j++)
        {
            plansza[i][j] = ' ';
        }
    }

    for (int i = 0; i < szer ;i++) //pasek u GORY i na DOLE
    {
        plansza[0][i] = 219;
        plansza[wys-1][i] = 219;
    }

    for (int i = 0; i < wys; i++) //pasek po BOKACH
    {
        plansza[i][0] = 219;
        plansza[i][1] = 219;
        plansza[i][szer-1] = 219;
        plansza[i][szer-2] = 219;
    }

    char CH0L0[25][50] ={{'�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�'},
                         {'�','�','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','�','�'},
                         {'�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�'}};


    for (int i = 0; i<wys; i++) //WYPISANIE MAPY
    {
        mvprintw(i ,kolumny/2-(szer/2),"");
        for(int j = 0 ; j<szer ; j++)
        {
            printw("%c",CH0L0[i][j]);
        }
    }

    Player p0;
    while(true)
    {
        p0.movement();
    }

}

void klawiszologia()
{
    int kolumny, rzedy;
    getmaxyx(stdscr, rzedy, kolumny);

    clear();
    mvprintw(3 ,kolumny/2-25,"��������������������������������������������������");
    mvprintw(4 ,kolumny/2-25,"�                                                �");
    mvprintw(5 ,kolumny/2-25,"�               ==KLAWISZOLOGIA==                �");
    mvprintw(6 ,kolumny/2-25,"�                                                �");
    mvprintw(7 ,kolumny/2-25,"�  PORUSZANIE ROBOTEM:                           �");
    mvprintw(8 ,kolumny/2-25,"�   strza�ki - prawo, lewo, g�ra d��             �");
    mvprintw(9 ,kolumny/2-25,"�                                                �");
    mvprintw(10,kolumny/2-25,"�  EKWIPUNEK - E                                 �");
	mvprintw(11,kolumny/2-25,"�                                                �");
    mvprintw(12,kolumny/2-25,"�  WYB�R PRZEDMIOTU:                             �");
    mvprintw(13,kolumny/2-25,"�   1,2,3,4,5,6,7,8,9                            �");
    mvprintw(14,kolumny/2-25,"�                                                �");
    mvprintw(15,kolumny/2-25,"�  PODNIE� - Q                                   �");
    mvprintw(16,kolumny/2-25,"�  WYRZU� - W                                    �");
    mvprintw(17,kolumny/2-25,"�  U�YJ - U                                      �");
    mvprintw(18,kolumny/2-25,"�  ZNISZCZ - X                                   �");
    mvprintw(19,kolumny/2-25,"�                                                �");
    mvprintw(20,kolumny/2-25,"�  ZMIA�D� - E                                   �");
    mvprintw(21,kolumny/2-25,"�                                                �");
    mvprintw(22,kolumny/2-25,"�  OBRACANIE MAPY - O                            �");
    mvprintw(23,kolumny/2-25,"�  ZMIANA KOLOR�W - K                            �");
    mvprintw(24,kolumny/2-25,"�                                                �");
    mvprintw(25,kolumny/2-25,"�                                                �");
    mvprintw(26,kolumny/2-25,"�                                                �");
    mvprintw(27,kolumny/2-25,"�                                                �");
    mvprintw(28,kolumny/2-25,"�                                                �");
    mvprintw(29,kolumny/2-25,"�                                                �");
    mvprintw(30,kolumny/2-25,"�                                                �");
    mvprintw(31,kolumny/2-25,"�                                                �");
    mvprintw(32,kolumny/2-25,"��������������������������������������������������");
    getch();
    clear();
    menu();
}

void faq()
{
    clear();

  printw("\n   FREQUENTLY ASKED QUESTIONS\n\n");
    attron( COLOR_PAIR( 1 ) );
	printw("   1.PROBLEMY Z KONSOL�\n");
	attroff( COLOR_PAIR( 1 ) );
    printw("     1.1 Dlaczego okno konsoli ma nieodpowiednie wymiary, a gdy myszk� zmieniam\n");
    printw("       jego rozmiar, zawartos� okna znika?\n");

    getch();
    clear();
    menu();
}

void ogrze()
{
    clear();
    printw("��������������������������������������������������\n");
    printw("�                                                �\n");
    printw("�                   ==O GRZE==                   �\n");
    printw("�                                                �\n");
    printw("�                                                �\n");
    printw("��������������������������������������������������\n");
    getch();
    clear();
    menu();
}

void menu()
{
    int kolumny, rzedy;
    getmaxyx(stdscr, rzedy, kolumny);

    /* rysownaie menu */
    attron( COLOR_PAIR( 1 ) );
    mvprintw(3 ,kolumny/2-24,"         �������                  ��");
	mvprintw(4 ,kolumny/2-24,"            � ���� ���� ���� �  � �����");
	mvprintw(5 ,kolumny/2-24,"            � ���� ����  ��� ���� ������");
	mvprintw(6 ,kolumny/2-24,"   ���      � �  � �  � ���  �  �    ����");
	mvprintw(7 ,kolumny/2-24,"  �     ��   � �   ��   ��   ��� �     ��   ��");
	mvprintw(8 ,kolumny/2-24,"  �    �  � � � � �  � ���� �    ���  �  � ����");
	mvprintw(9 ,kolumny/2-24,"  ���� ���� � � � ���� �  � ���� ���� ���� �  �");
	mvprintw(10,kolumny/2-24,"                  �");
	mvprintw(11,kolumny/2-24,"");
    attron( COLOR_PAIR( 2 ) );
    mvprintw(12,kolumny/2-24,"�������������������������������������������������");
    mvprintw(13,kolumny/2-24,"�           WITAJ W TRASH COMPACTOR ;)          �");
    mvprintw(14,kolumny/2-24,"�������������������������������������������������");
    mvprintw(15,kolumny/2-24,"�                       �                       �");
    mvprintw(16,kolumny/2-24,"�  -> Nowa gra          �     Ust. Domy�lne     �");
    mvprintw(17,kolumny/2-24,"�     Klawiszologia     �     Ust. W�asne       �");
    mvprintw(18,kolumny/2-24,"�     FAQ               �                       �");
    mvprintw(19,kolumny/2-24,"�     O grze            �                       �");
    mvprintw(20,kolumny/2-24,"�     Wyj�cie           �                       �");
    mvprintw(21,kolumny/2-24,"�                       �                       �");
    mvprintw(22,kolumny/2-24,"�������������������������������������������������");

    int curY = 16, curX = kolumny/2-21; /* poczatkowa pozycja kursora*/

    bool czypowtorzyc = true; /* odswierzenie menu */
    do
    {
        switch (getch()) /* zmiana pozycji kursora */
        {
        case KEY_DOWN:
            if ((curY < 20) && !((curY == 17)&&(curX ==kolumny/2+3)))
            {
                move(curY,curX);
                printw("  ");
                curY++;
                move(curY,curX);
                printw("->");
            }
            break;

        case KEY_UP:
            if ((curY > 16) && !((curY == 19)&&(curX == kolumny/2+3)))
            {
                move(curY,curX);
                printw("  ");
                curY--;
                move(curY,curX);
                printw("->");
            }
            break;

        case KEY_LEFT:
            if ((curY >=16)&&(curY <= 17)&&(curX==kolumny/2+3))
            {
                move(curY, curX);
                printw("  ");
                curY = 16;
                curX = kolumny/2-21;
                move(curY, curX);
                printw("->");
            }
            else if ((curY >=19)&&(curY <= 20)&&(curX==kolumny/2+3))
            {
                move(curY, curX);
                printw("  ");
                curY = 20;
                curX = kolumny/2-21;
                move(curY, curX);
                printw("->");
            }
            break;
        case KEY_RIGHT: /* wybieranie opcji */
            if ((curY == 16)&&(curX == kolumny/2-21)) /* NOWA GRA */
            {
                move(16,kolumny/2-21);
                printw("  ");
                move(16,kolumny/2+3);
                printw("->");
                curX = kolumny/2+3;
                curY = 16;
            }
            else if ((curY == 16)&&(curX == kolumny/2+3)) /* NOWA GRA -> DOMYSLNE*/
            {
                clear();
                printw("tutaj kiedys bedzie gra");
                czypowtorzyc = false; /* opuszczenie menu*/
            }
            else if ((curY == 17)&&(curX == kolumny/2+3)) /* NOWA GRA -> WLASNE*/
            {
                clear();
                printw("soon");
                czypowtorzyc = false; /* opuszczenie menu*/
            }

            else if ((curY == 17)&&(curX == kolumny/2-21)) /* KLAWISZOLOGIA */
            {
                klawiszologia();
                czypowtorzyc = false;
            }

            else if ((curY == 18)&&(curX == kolumny/2-21)) /* FAQ */
            {
                faq();
                czypowtorzyc = false;
            }

            else if ((curY == 19)&&(curX == kolumny/2-21)) /* O GRZE */
            {
                ogrze();
                czypowtorzyc = false;
            }

            else if ((curY == 20)&&(curX == kolumny/2-21)) /* WYJSCIE */
            {
                move(20,kolumny/2-21);
                printw("  ");
                move(20,kolumny/2+3);
                printw("->");
                curX = kolumny/2+3;
                curY = 20;
            }
            else if ((curY == 20)&&(curX == kolumny/2+3)) /* WYJSCIE -> NIE*/
            {
                move(curY,curX);
                printw("  ");
                move(16,kolumny/2-21); /* pozycja startowa */
                printw("->");
                curY = 16;
                curX = kolumny/2-21;
            }
            else if ((curY == 19)&&(curX == kolumny/2+3)) /* WYJSCIE -> TAK*/
            {
                endwin();
                exit(0);
            }
            break;
        }

        /* wyswietlanie prawych podenu */
        if ((curY == 16) && (curX == kolumny/2-21)) /* podmenu NOWA GRA */
        {
            move(16, kolumny/2+6);
            printw("Ust. Domy�lne  ");
            move(17, kolumny/2+6);
            printw("Ust. W�asne  ");

            move(19, kolumny/2+6);
            printw("               ");
            move(20, kolumny/2+6);
            printw("               ");
        }
        else if ((curY >= 17)&&(curY <=19 ) && (curX == kolumny/2-21)) /* podmenu PUSTE */
        {
            move(16, kolumny/2+6);
            printw("                ");
            move(17, kolumny/2+6);
            printw("                ");

            move(19, kolumny/2+6);
            printw("               ");
            move(20, kolumny/2+6);
            printw("               ");
        }
        else if (curY == 20) /* podmenu WYJSCIE*/
        {
            move(16, kolumny/2+6);
            printw("Naprawd� chcesz");
            move(17, kolumny/2+6);
            printw("wyj�� z gry?   ");

            move(19, kolumny/2+6);
            printw("Tak            ");
            move(20, kolumny/2+6);
            printw("Nie            ");
        }

    } while (czypowtorzyc);
}

int main(void)
{

    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();

    start_color();
    srand( time( NULL ) );
    int color = rand() % 6 + 9;
    init_pair( 1, color, 0 );
    init_pair( 2, 15, 0 );
    init_pair( 5, 4, 12 ); //GRACZ

    gra();
    getch();
    endwin();

}