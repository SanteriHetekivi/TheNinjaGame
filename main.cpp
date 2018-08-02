#include <iostream>
#include "header.h"
#include <conio.h>

int main()
{
    std::cout << "The Ninja Game" << std::endl;                                 //Kerrotaan pelaajalle pelin nimi
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Your dojo is under attack by teleporting enemy ninjas." << std::endl; //Annetaan pelaajalle pelin tarkoitus
    std::cout << "Hurry to 5th Floor before they kill you." << std::endl;
    std::cout << std::endl;
    help();                                                                     //Kerrotaan pelaajalle pelin ohjeet
    std::cout << "Press any key to start" << std::endl;
    getch();
    clear();                                                                    //Puhdistaa ruudun
    std::cout << "Floor 1" << std::endl;                                        //Kerrotaan pelaajalle aloituskerroksen
    kartta(0,4,0);                                                              //Tulostetaan kartan aloitusasema
    std::cout << std::endl;
    int pelaaja = 0;                                                            //Määritetään pelaajan aloitustaso
    int key1=0;                                                                 //Määritetään pelaajan Y kordinaatti
    int key2=4;                                                                 //Määritetään pelaajan X kordinaatti
    for (int floor = 1; floor <=5; ++floor)                                     //Asetetaan peli kestämään 5 kerrosta
    {
        key1 = 0;                                                               //Asetetaan pelaajan Y kordinaatti uuden kentän alussa
        key2 = 4;                                                               //Asetetaan pelaajan Y kordinaatti uuden kentän alussa
        do
        {
            std::cout << std::flush;                                            //Puhdistetaan painallukset
            char ch = getch();                                                  //Otetaan vastaan komento näppäimistöltä
            clear();                                                            //Puhdistaa ruudun
            if (ch == 104 || ch == 72)                                          //Jos painoit H kirjainta tulostetaan ohjeet help aliohjelmasta
                help();
            if (ch == 119 || ch == 87 ||ch == 115 || ch == 83)                  //Jos liikuttiin Y akselilla (W tai S) haetaan uusi arvo siainnillesi liiku1 aliohjelmasta
            {
                key1 = liiku1 (ch,floor,key1);
            }
            if (ch == 65 || ch == 97 ||ch == 100 || ch == 68)                   //Jos liikuttiin X akselilla (D tai A) haetaan uusi arvo siainnillesi liiku2 aliohjelmasta
            {
                key2 = liiku2 (ch,floor,key2);
            }
            if (kartta(key1,key2,floor)==1)                                    //Tarkistetaan osuivatko pelaaja ja ninja samalle ruudulle
            {
                if (taistelu(pelaaja)==1)                                      //Tarkistetaan voittaako vai häviääkö pelaaja ninjalle
                {
                std::cout << "You killed an enemy ninja!!" << std::endl;
                std::cout << "LEVEL UP!!!!!" << std::endl;
                ++pelaaja;                                                  //Korotetaan pelaajan tasoa
                std::cout << "You are now level " << pelaaja << std::endl;
                }
                else
                {
                std::cout << "Enemy ninja killed you!!"<< std::endl;
                std::cout << "YOU ARE DEAD!!"<< std::endl;                  //Kerrotaan pelaajalle häviöstä ja suljetaan peli
                std::cout << "GAME OVER!!"<< std::endl;
                getch();
                return 0;
                }
            }
        }
        while (key1!=4 || key2!=0);                                         //Asetetaan kerroksen läpäisemiseen tarvittavat ehdot
        std::cout << std::endl;
        std::cout << "Floor " << floor << " CLEAR !!!" << std::endl;            //Todetaan pelaajan saavuttaneen kerroksen läpäisemiseen tarvittavat ehdot
    }
    victory(pelaaja);
    getch();
    return 0;                                                                   //Suljetaan peli
}

