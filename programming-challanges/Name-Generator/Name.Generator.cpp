#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace std;

int main(void)
{
    ////////////////////////////////////////////////////// LANGUAGE

    char lang;

    cout << "-------------------------------" << endl;
    cout << "-- Welcome to Name Generator --" << endl;
    do
    {
        cout << "-------------------------------" << endl;
        cout << " 1. Choose the names laguage:"   << endl;
        cout << "    - Polish"                    << endl;

        do
        {
            lang = getch();

            if ((lang == 'p')||(lang == 'P'))
            {
                cout << " You chose: Polish."<< endl << endl;
                break;
            }
            else
                cout << " There is no such a command. Try again."<< endl;

        } while (true);

        ////////////////////////////////////////////////////// GENDER

        char gender;

        cout << " 2. Choose the names gender:"   << endl;
        cout << "    - Masculine"                << endl;
        cout << "    - Feminine"                 << endl;
        cout << "    - Both"                     << endl;

        do
        {
            gender = getch();

            if ((gender == 'm')||(gender == 'M'))
            {
                cout << " You chose: masculine."<< endl << endl;
                gender = 'm';
                break;
            }
            else if ((gender == 'f')||(gender == 'F'))
            {
                cout << " You chose: feminine."<< endl << endl;
                gender = 'f';
                break;
            }
            else if ((gender == 'b')||(gender == 'B'))
            {
                cout << " You chose: both."<< endl << endl;
                gender = 'b';
                break;
            }
            else
                cout << " There is no such a command. Try again." << endl;

        } while (true);

        ////////////////////////////////////////////////////// NUMBER

        unsigned long long int number;

        cout << " 3. Choose the number of random names."         << endl;
        cout << "    (1 - 18 446 744 073 709 551 615 c:)"        << endl;
        cout << " You chose: ";

        do
        {
            cin >> number;

            if (number == 0)
                cout << " This number is too small, try again."<< endl;
            else
                break;


        } while (true);

        ////////////////////////////////////////////////////// START

        do
        {
            system( "cls" );
            cout<<"-------------------------------" <<endl;
            srand(rand());
            if (lang=='p')
            {
                string pol_f[88]  = {"Joanna","Krystyna","Ma�gorzata","Martyna","Marcelina","Agata","Agnieszka","Aleksandra","Alicja","Anastazja","Anna","Apolonia","Angelika","Aurora","Anita" ,"Barbara","Bo�ena","Berta","Chwalis�awa","Diana","Dorota","Danuta","Daniela","Dominika","D�br�wka","Edyta","Ewa","Ewelina","El�bieta","Emma","Emilia","Fatima","Gabriela","Gloria","Gra�ya","Hermenegilda","Honorata","Ida","Ilona","Irena","Iga","Iwona","Joanna","Janina","Jolanta","Kaja","Kamila","Katarzyna","Kinga","Klaudia","Karolina","Kornelia","Laura","Luiza","�ucja","Magdalena","Maria","Michalina","Mariola","Mieczys�awa","Marlena","Maryja","Monika","Natalia","Nikola","Olimpia","Olga","Otylia","Patrycja","Przemys�awa","Renata","Sabina","Sara","Sonia","Stella","Sylwia","Tina","Teresa","Tekla","Urszula","Wanda","Weronika","Wioletta","Wiktoria","�aneta","Zofia","Zuzanna","Zenobia"};
                string pol_m[123] = {"Henryk","Jakub","Oliwier","Abelard","Adam","Andrzej","Aleks","Alwin","Adrian","Aleksander","Alfons","Alfred","Alojzy","Anio�","Arkadiusz","Aron","Artur","August","Bart�omiej","Bartosz","Bernard","Bogus�aw","Boles�aw","Borys","Bronis�aw","Bo�ydar","Cezary","Chrystian","Czes�aw","Damian","Daniel","Denis","Cyprian","Dariusz","Dawid","Dominik","Donald","Dymitr","Edward","Edwin","Eliasz","Eryk","Eugeniusz","Emil","Eugeniusz","Fabian","Feliks","Franciszek","Fryderyk","Gabriel","Gerard","Gilbert","Gracjan","Grzegorz","Hugo","Herman","Ignacy","Iwo","Igor","Jacek","Jaros�aw","Jerzy","J�zef","Janusz","Jerzy","J�zef","Juliusz","Julian","Jurek","Kacper","Kamil","Karol","Konrad","Krystian","Kornel","Leon","Leszek","Lew","Lambert","Lucjan","�ukasz","Maciej","Maksymilian","Marcel","Mateusz","Marcin","Micha�","Marek","Mariusz","Miko�aj","Miros�aw","Mi�osz","Moj�esz","Modest","Norbert","Oskar","Omar","Oleg","Otto","Patryk","Piotr","Przemys�","Przemys�aw","Prokop","Rados�aw","Rafa�","Remigiusz","Rudolf","Ryszard","Salomon","Szymon","Sebastian","Stefan","Tadeusz","Tomasz","Urban","W�odzimierz","Witold","Wac�aw","Zygfryd","Zdzis�aw","Zbigniew","Zenon"};

                if (gender=='m')
                {
                    for (int i=0 ; i<number ; ++i)
                    {
                        cout << "  " << pol_m[ rand() % (sizeof(pol_m) / sizeof(pol_m[0])) ] << endl;
                    }
                }

                if (gender=='f')
                {
                    for (int i=0 ; i<number ; ++i)
                    {
                        cout << "  " << pol_f[ rand() % (sizeof(pol_f) / sizeof(pol_f[0])) ] << endl;
                    }
                }

                if (gender=='b')
                {
                    for (int i=0 ; i<number ; ++i)
                    {
                        int x = rand()%2;
                        if (x==0)
                            cout << "  " << pol_f[ rand() % (sizeof(pol_f) / sizeof(pol_f[0])) ] << endl;
                        else
                            cout << "  " << pol_m[ rand() % (sizeof(pol_m) / sizeof(pol_m[0])) ] << endl;
                    }
                }
            }
            cout <<"-------------------------------" <<endl;



        cout <<" - Try again"    <<endl;
        cout <<" - Back to menu" <<endl;
        cout <<" - Exit"         <<endl;

        waypoint:
            char nav = getch();

            if ((nav=='b')||(nav=='B'))
                break;
            else if ((nav=='e')||(nav=='E'))
                exit(0);
            else if ((!nav=='t')||(!nav=='T'))
            {
                 cout << " There is no such a command. Try again." << endl;
                 goto waypoint;
            }

        } while (true);

    } while (true);
}



