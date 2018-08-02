# TheNinjaGame
End work for basics of programming language course from my first school year. (2013)

Santeri Hetekivi Harjoitustyö 1 / 1  
13I220B Ohjelmointikielet, perusteet 5.11.  
1202466 OJ 5G00BM  

## The Ninja Game

The Ninja Game on hyvin yksinkertainen komentorivillä toimiva roguelike-peli.

Pelissä tarkoitus on liikuttaa (liiku1 ja liiku2) numeroa määritetyssä kentässä (kartta), joka
sisältää satunnaisesti luotuja objekteja (kenttä).

Halusin luoda peliin suoran näppäimenpainalluksen havaitsemisen, vaikkei aihetta oltu
käyty läpi tunnilla opin sen käytön hyvin nopealla google haulla. Tämä mahdollisti myös
peliohjeiden tulostamisen ruudulle (help) pelkällä näppäimistön H painikkeen painamisella.

Numeron joutuessa satunnaisen objektin kanssa samaan ruutuun osuminen käynnistää
pöytäroolipelimainen virtuaalisella nopanheitoilla ratkaistavan taistelun (taistelu), jonka lopputulos
määrää pelaajan kohtalon roguelike tyyliin. Näin määritetään myös äkkikuolema tai pelaajan tason
nouseminen, joka vaikuttaa seuraavan nopanheiton tuloksiin.

Pelaajan saavuttaessa yhden kerroksen loppu. Ohjelma määrittää seuraavaan kerrokseen
suuremman todennäköisyyden satunnaisobjektien luontiin kentälle. Näin peli vaikenee kerros
kerrokselta, varsinkin jos pelaaja ei ole nostattanut tasoaan.

Pelaajan saavuttaessa tason 11 hän on periaatteessaa kuolematon, koska vastustajan
nopanheitto arvotaan 11 kantaisella satunnaismuttujalla. Pelaaja on tässävaiheessa saanut jo omaan
muuttujansa loppuun +11, jolloin hän saa jokakerta suuremman arvon. Tämä on tehty tarkoituksella
motivoidakseni pelaajaa taistelemaan heti alussa, jotta pääsee viimeiset kerrokset läpi ilman
roguelikelle tyypillistä hermostuttavaa viimehetken kuolemaa.

Pelaajan päästessä ohjelman loppuun, samalla täyttäen kaikki silmukoiden ehdot (main),
ohjelma kysyy pelaajan lempinimeä ja tulostaa pelaajan lempinimen ja tason erilliseen ohjelman
luomaan .txt tiedostoon(victory). Näin pidetään kirjalla eri pelaajien saavuttamista tasoista.
Peli toteutuksessa käytettiin C++ koodia, jota opin kurssin OJ 5G00BM35 aikana.
Koodi on jaoteltu 5 cpp tiedostoon ja 1 header tiedostoon (ohjelma luo ehdot saavuttaessaan myös
txt tiedoston).

```
Koodi tiedostojen sisältämät ohjelmat
main.cpp int main()
kartta.cpp int kartta(int key1,int key2,int floor)
liiku.cpp int liiku1 (char ch, int floor, int key1)
int liiku2 (char ch, int floor, int key2)
toiminnot.cpp int taistelu(int pelaaja)
void clear()
void victory (int pelaaja)
int help()
```
*Pelin toimivuus on kokeiltu seitsemässä eri Windows 7 - (starter versiosta aina ultimateen) ja
yhdessä Windows Xp pohjaisella tietokoneella. Linux ja Mac yhteensopivuus ei ole tiedossa.


