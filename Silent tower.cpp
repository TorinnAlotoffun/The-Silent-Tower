#include <iostream>
#include <windows.h>
using namespace std;
int AktHP;
string jmeno = "hrdina";
int MaxHP;
int Dmg;
int Str;
int Dex;
int Int;
int Cha;
int Con;
int Penize;
string inventar[10] = {"lektvar leceni", "20zlatych"};
int uprinv = 0;
int konec = 0;
int loot;
int x;
void Inventar(){
do{
    cout << " Co chcete delat?\n 1 - Zahodit predmet \n 2 - Pouzit predmet \n 3 - Ukocit\n";
    cin >> uprinv;
    switch (uprinv) {
//case 1:
    //cout << "jaky predmet chces pridat? \n1-lektvar leceni \n2-lektvar sily \n3-jed \n4-tajemny svitek\n5-zlataky";
    //cin >> loot;
    //switch (loot) {
//case 1:
//cout << "ahoj";
    //}
    //cout << "na jake pole chces pridat item?";
    //cin >> x;
    //AddItem(string inventar[x],)
    //break;
case 1:
    cout << "zahodit \n";
    break;
case 2:
    cout << "pouzit\n";
    break;
case 3:
    konec = 1;
    break;
default:
    cout << "Zadej spravne cislo \n";
}
}while (konec = 0);
}


void nastavBarvu(int barva) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, barva);
}

int main(){
int Karel = 0;
int anone = 0;
int placeholder = 0;
int sila;
int vyberclass;
int y = 0;
int pocet;
int HP = 100;
int DMG = 10;
int akce;
do{
cout << "Vytejte ve hre The Silent Tower";
do{
cout << " vyberte si postavu:\n\n 1 - Valecnik\n 2 - Kouzelnik\n 3 - Hranicar\n 4 - Bard\n 5 - Zlodej\n\n";
cin >> vyberclass;
cout << endl;
switch (vyberclass) {
case 1:
    Str = 4;
    Dex = 3;
    Con = 5;
    Int = 2;
    Cha = 1;
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    cout << " Gratuluji, stal jsi se valecnikem.\n\n Valecnici jsou lide pripraveni bojovat s neprately za pomoci hrube sily.\n\n";
    Karel++;
    break;
case 2:
    Str = 2;
    Dex = 4;
    Con = 1;
    Int = 5;
    Cha = 3;
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    cout << " Gratuluji, stal jsi se kouzelnikem.\n\n Kouzelnici jsou krehci, ale neuveritelne nadani, magie jejich krehkost vyvazuje.\n\n";
    Karel++;
    break;
case 3:
    Str = 2;
    Dex = 5;
    Con = 3;
    Int = 4;
    Cha = 1;
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    cout << " Gratuluji, stal jsi se hranicarem.\n\n Hranicari jsou lide ve spojeni s prirodou a jejich primarni zbrani je luk.\n\n";
    Karel++;
    break;
case 4:
    Str = 1;
    Dex = 4;
    Con = 2;
    Int = 3;
    Cha = 5;
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    cout << " Gratuluji, stal jsi se bardem.\n\n Bardi jsou lide, kteri misto boje pestmi bojuji slovi,jsou velmi znamy a oblibeni.\n\n";
    Karel++;
    break;
case 5:
    Str = 2;
    Dex = 5;
    Con = 1;
    Int = 3;
    Cha = 4;
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    cout << " Gratuluji, stal jsi se zlodejem.\n\n Zlodeji nevydrzi moc ran, ale jejich utoky jsou smrtelne.\n\n";
    Karel++;
    break;
default:
    Str = 1;
    Dex = 4;
    Con = 2;
    Int = 1;
    Cha = 1;
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    if (y == 1){
    cout << " Gratuluji, stal jsi se goblinem.\n\n Goblini jsou monstra, ktera neposlouchaji pravidla.\n Vetsinou bivaji prvnim monstrem ktere zacatecnici zabiji.\n\n";
    nastavBarvu(4);
    cout << "Toto povolani vam bylo prideleno podle vasi inteligence \n";
    nastavBarvu(7);
    Karel++;
    }else{
    y++;
    nastavBarvu(4);
    cout << "!POZOR! Pokud si nevyberete z pripravenych povolani, bude volba provedena za vas.\n";
    nastavBarvu(7);
    }
    break;
}
}while (Karel == 0);
    cout << " Vase vlastnosti jsou:\n";
    cout << " sila: " << Str << endl;
    cout << " obratnost: " << Dex << endl;
    cout << " odolnost: " << Con << endl;
    cout << " inteligence: " << Int << endl;
    cout << " charisma: " << Cha << endl;
    cout << " Aktualni zivoty: " << AktHP << "/" << MaxHP << endl;
    cout << "_______________________________________________________________________________________________________________________";
    cout  << endl << endl;
    cout << " Probouzite se v sede kamene mistnosti, uprostred mistnosti je maly ohen, ktery tuto mistnost slabe osvetluje.\n Na druhem konci mistnosti vidite dvere za kterymi neco vydava skrabave zvuky.\n\n";
do{
    cout << " Co chcete delat?\n\n 1 - Jit ke dverim\n 2 - Zustat sedet na zemi\n 3 - Pokusit si vzpomenout jak jste se sem dostali\n";
    cin >> akce;
    placeholder = 0;
switch (akce){
case 1:
    cout << " Jdes smerem ke dverim, chces je otevrit? \n 1 - ano\n 0 - ne\n";
    cin >> anone;
    switch (anone){
        case 1:
            cout << " Za dvermi je schodiste branene krysou. Krysa na vas zautoci\n";
            //souboj
            placeholder ++;
            break;
        case 0:
            cout << " rozhodli jste se ze je vam jedno co se deje za dvermi.\n Vracite se k ohni. co chcete delat dal?\n";
            break;
        default:
            cout << " neplatna volba. zkus znovu\n";
            break;
    }
    break;
case 2:
    cout << " Zustavate sedet na zemi... zem je tvrda a studena, zjevne kamen.";
    break;
case 3:
    cout << " Snazite se premislet nad tim jak jste se sem dostali a proc tu vlastne jste.\n Jak tak premislite zjistite ze nejste schopni vzpomenout si na vase jmeno\n\n Zadejte jak se budete jmenovat: ";
    cin >> jmeno;






}
}while (placeholder == 0);


placeholder = 0;
}while (placeholder == 1);
}
