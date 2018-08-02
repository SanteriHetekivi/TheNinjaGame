#include <iostream>
#include "header.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

int taistelu(int pelaaja)
{
    int p,v;
    srand(time(NULL));
    p = (rand() % 20) + pelaaja;        //Määritetään pelaajan nopanheitto
    v = rand() % 10;                    //Määritetään ninjan nopanheitto
    if (p > v) return 1;                //Jos pelaaja sai korkeamman luvun ilmoitetaan main ohjelmalle hänen voittonsa
    else return 0;                      //Jos pelaaja ei saanut korkeampaa lukua ilmoitetaan main ohjelmalle hänen häviönsä
}

int help()
{
    std::cout << "Help:" << std::endl;                                          //Kerrotaan pelaajalle pelin ohjeet
    std::cout << "Your character (1) moves with keys W,A,S,D." << std::endl;
    std::cout << "Enemy ninjas (8) teleport at random." << std::endl;
    std::cout << "Kill enemy ninjas to get stronger," << std::endl;
    std::cout << "but dont let them kill you." << std::endl;
    std::cout << "Climb the stairs (7) to go to next floor." << std::endl;
    std::cout << "Press H for help." << std::endl;
    std::cout << std::endl;
    return 0;
}

void clear()
{
    std::cout << std::string( 500, '\n' );                                       //Puhdistetaan ruutu tulostamalla tyhjää
}

void victory (int pelaaja)
{
    std::string name;
    std::cout << "VICTORY!!!"<< std::endl;                                      //Kerrotaan pelaajalle, että hän on läpäissyt pelin kaikkien kerroksien ehdot
    std::cout << "You have saved your dojo from enemy ninjas."<< std::endl;
    std::cout << "Your level was: "<< pelaaja << std::endl;                     //Kerrotaan pelaajan taso pelin lopussa
    std::cout << "What is your nick: ";                                         //Kysytään pelaajan lempinimeä
    std::cin >> name;                                                           //Tallennetaan lempinimi
    std::ofstream myfile;
    myfile.open ("highscores.txt", std::ios_base::app);
    myfile << std::setw(30)<< std::left << name << pelaaja << std::endl;        //Kirjoitetaan lempinimi ja taso pelin lopussa tuloslistaan
}
