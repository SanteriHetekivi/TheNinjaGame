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
    int pelaaja = 0;                                                            //M��ritet��n pelaajan aloitustaso
    int key1=0;                                                                 //M��ritet��n pelaajan Y kordinaatti
    int key2=4;                                                                 //M��ritet��n pelaajan X kordinaatti
    for (int floor = 1; floor <=5; ++floor)                                     //Asetetaan peli kest�m��n 5 kerrosta
    {
        key1 = 0;                                                               //Asetetaan pelaajan Y kordinaatti uuden kent�n alussa
        key2 = 4;                                                               //Asetetaan pelaajan Y kordinaatti uuden kent�n alussa
        do
        {
            std::cout << std::flush;                                            //Puhdistetaan painallukset
            char ch = getch();                                                  //Otetaan vastaan komento n�pp�imist�lt�
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
                if (taistelu(pelaaja)==1)                                      //Tarkistetaan voittaako vai h�vi��k� pelaaja ninjalle
                {
                std::cout << "You killed an enemy ninja!!" << std::endl;
                std::cout << "LEVEL UP!!!!!" << std::endl;
                ++pelaaja;                                                  //Korotetaan pelaajan tasoa
                std::cout << "You are now level " << pelaaja << std::endl;
                }
                else
                {
                std::cout << "Enemy ninja killed you!!"<< std::endl;
                std::cout << "YOU ARE DEAD!!"<< std::endl;                  //Kerrotaan pelaajalle h�vi�st� ja suljetaan peli
                std::cout << "GAME OVER!!"<< std::endl;
                getch();
                return 0;
                }
            }
        }
        while (key1!=4 || key2!=0);                                         //Asetetaan kerroksen l�p�isemiseen tarvittavat ehdot
        std::cout << std::endl;
        std::cout << "Floor " << floor << " CLEAR !!!" << std::endl;            //Todetaan pelaajan saavuttaneen kerroksen l�p�isemiseen tarvittavat ehdot
    }
    victory(pelaaja);
    getch();
    return 0;                                                                   //Suljetaan peli
}

