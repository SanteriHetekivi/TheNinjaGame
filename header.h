#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
int kartta(int key1,int key2,int level);    //Määritetään aliohjelma kartta
int taistelu(int pelaaja);                  //Määritetään aliohjelma pelaaja
int liiku1 (char ch, int floor, int key1);
int help();
int liiku2 (char ch, int floor, int key2);
void clear();
void victory (int pelaaja);
#endif
