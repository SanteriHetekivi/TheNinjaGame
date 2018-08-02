#include <iostream>

int liiku1 (char ch, int floor, int key1)
{                                                                //M‰‰ritet‰‰n pelaajan X kordinaatti
    if (ch == 119 || ch == 87)                                     //Jos painoit w tai W kirjainta liikutetaan pelaajaa Y akselilla 1 ylˆs
    {
        ++key1;
    }
    else if (ch == 115 || ch == 83)                                    //Jos painoit s tai S kirjainta liikutetaan pelaajaa Y akselilla 1 alas
    {
        --key1;
    }
    if (key1>4)                                                        //Estet‰‰n pelaajaa kulkemasta asetettujen rajojen ulkopuolelle
    {
        key1 = 4;
    }
    if (key1<0)                                                        //Estet‰‰n pelaajaa kulkemasta asetettujen rajojen ulkopuolelle
    {
        key1 = 0;
    }
    std::cout << "Floor " << floor << std::endl;                       //Kerrotaan pelaajalle nykyinen kerros
    return key1;
}

int liiku2 (char ch, int floor, int key2)
{                                                                //M‰‰ritet‰‰n pelaajan X kordinaatti
    if (ch == 65 || ch == 97)                                     //Jos painoit a tai A kirjainta liikutetaan pelaajaa X akselilla 1 vasemmalle
    {
        --key2;
    }
    else if (ch == 100 || ch == 68)                                    //Jos painoit d tai D kirjainta liikutetaan pelaajaa X akselilla 1 oikealle
    {
        ++key2;
    }
    if (key2>4)                                                        //Estet‰‰n pelaajaa kulkemasta asetettujen rajojen ulkopuolelle
    {
        key2 = 4;
    }
    if (key2<0)                                                        //Estet‰‰n pelaajaa kulkemasta asetettujen rajojen ulkopuolelle
    {
        key2 = 0;
    }
    std::cout << "Floor " << floor << std::endl;                       //Kerrotaan pelaajalle nykyinen kerros
    return key2;
}

