#include <iostream>
#include <ctime>
#include <cstdlib>


int kartta(int key1,int key2,int floor)
{
    int rivi1[5];                   //M��ritet��n kartan Y ja X akselit
    int rivi2[5];
    int rivi3[5];
    int rivi4[5];
    int rivi5[5];
    int ran;
    if (floor==0) ran=9999999;          //Asetetaan aloitusasema
    if (floor==1) ran=15;               //Määtetääkartan vaikeustaso pelaajan saattaneen kerroksen mukaan
    if (floor==2) ran=10;
    if (floor==3) ran=7;
    if (floor==4) ran=5;
    if (floor==5) ran=3;
    srand(time(NULL));
    for (int x = 0; x <= 4; x++)
    {
        rivi1[x]=rand() % ran;          //Arvotaan jokaiselle ruudulle oma arvonsa
        rivi2[x]=rand() % ran;
        rivi3[x]=rand() % ran;
        rivi4[x]=rand() % ran;
        rivi5[x]=rand() % ran;
        if (rivi1[x]== 0)               //Jos Y akselilla kohdalla 1 oleva ruutu sai arpatulokseksi 0 asetetaan ninja t�h�n ruutuun vuoron ajaksi
        {
            rivi1[x]=8;
        }
        else                            //Jos Y akselilla kohdalla 1 oleva ruutu ei saanut arpatulokseksi 0 asetetaan ruutu tyhj�ksi vuoron ajaksi
        {
            rivi1[x]=0;
        }
        if (rivi2[x]==0)                //Jos Y akselilla kohdalla 2 oleva ruutu sai arpatulokseksi 0 asetetaan ninja t�h�n ruutuun vuoron ajaksi
        {
            rivi2[x]=8;
        }
        else                            //Jos Y akselilla kohdalla 2 oleva ruutu ei saanut arpatulokseksi 0 asetetaan ruutu tyhj�ksi vuoron ajaksi
        {
            rivi2[x]=0;
        }
        if (rivi3[x]==0)                //Jos Y akselilla kohdalla 3 oleva ruutu sai arpatulokseksi 0 asetetaan ninja t�h�n ruutuun vuoron ajaksi
        {
            rivi3[x]=8;
        }
        else                            //Jos Y akselilla kohdalla 3 oleva ruutu ei saanut arpatulokseksi 0 asetetaan ruutu tyhj�ksi vuoron ajaksi
        {
            rivi3[x]=0;
        }
        if (rivi4[x]==0)                //Jos Y akselilla kohdalla 4 oleva ruutu sai arpatulokseksi 0 asetetaan ninja t�h�n ruutuun vuoron ajaksi
        {
            rivi4[x]=8;
        }
        else                            //Jos Y akselilla kohdalla 4 oleva ruutu ei saanut arpatulokseksi 0 asetetaan ruutu tyhj�ksi vuoron ajaksi
        {
            rivi4[x]=0;
        }
        if (rivi5[x]==0)                //Jos Y akselilla kohdalla 5 oleva ruutu sai arpatulokseksi 0 asetetaan ninja t�h�n ruutuun vuoron ajaksi
        {
            rivi5[x]=8;
        }
        else                            //Jos Y akselilla kohdalla 5 oleva ruutu ei saanut arpatulokseksi 0 asetetaan ruutu tyhj�ksi vuoron ajaksi
        {
            rivi5[x]=0;
        }
    }
    rivi1[0]=7;                         //M��ritet��n kordinaateissa (0,1) oleva ruutu maaliksi
    if (key2>4)key2=4;                  //Varmistetaan viel�, ettei pelaaja kulje X akselin asettamien rajojen
    if (key2<0)key2=0;
    if (key1<1 || key1>4)               //Varmistetaan viel�, ettei pelaaja kulje Y akselin asettamien rajojen yli
    {
        if(rivi5[key2]==8)return 1;     //Tarkistetaan onko ninja teleportannut samaan ruutuun pelaajan kanssa
        rivi5[key2]=1;
    }
    else if (key1 == 1)
    {
        if(rivi4[key2]==8)return 1;     //Tarkistetaan onko ninja teleportannut samaan ruutuun pelaajan kanssa
        rivi4[key2]=1;
    }
    else if (key1 == 2)
    {
        if(rivi3[key2]==8)return 1;     //Tarkistetaan onko ninja teleportannut samaan ruutuun pelaajan kanssa
        rivi3[key2]=1;
    }
    else if (key1 == 3)
    {
        if(rivi2[key2]==8)return 1;     //Tarkistetaan onko ninja teleportannut samaan ruutuun pelaajan kanssa
        rivi2[key2]=1;
    }
    else if (key1 == 4)
    {
        if(rivi1[key2]==8)return 1;     //Tarkistetaan onko ninja teleportannut samaan ruutuun pelaajan kanssa
        rivi1[key2]=1;
    }
    else
    {
        rivi5[key2]=1;                  //Asetetaan pelaaja aloitus asemaan, jos liikeit� ei ole m��ritetty
    }
    rivi1[0]=7;                         //Varmistetaan viel�, ett� maali on oikeassa paikassa
    for (int y=0; y <= 4; y++)          //Tulostetaan Y akselin 1. rivi
    {
        std::cout << rivi1[y];
    }
    std::cout << std::endl;
    for (int y=0; y <= 4; y++)          //Tulostetaan Y akselin 2. rivi
    {
        std::cout << rivi2[y];
    }
    std::cout << std::endl;
    for (int y=0; y <= 4; y++)          //Tulostetaan Y akselin 3. rivi
    {
        std::cout << rivi3[y];
    }
    std::cout << std::endl;
    for (int y=0; y <= 4; y++)          //Tulostetaan Y akselin 4. rivi
    {
        std::cout << rivi4[y];
    }
    std::cout << std::endl;
    for (int y=0; y <= 4; y++)          //Tulostetaan Y akselin 5. rivi
    {
        std::cout << rivi5[y];
    }
    return 0;                           //Suljetaan ohjelma
}
