#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int AktHP;
int KonSouboje = 0;
int Schovany = 0;
int Zmateni = 0;
string NazevNepritelJedna;
string jmeno = "hrdina";
int StatyNepritelJedna[3];
int StatyNepritelDva[3];
int StatyNepritelTri[3];
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
int GoblinEnmy(int &HPGoblin, int &DMGGoblin, int &OBRGoblin, string &NazevGoblin){
HPGoblin = 10;
DMGGoblin = 3;
OBRGoblin = 4;
NazevGoblin = "Goblin";
}
int Krysa(int &HPKrysa, int &DMGKrysa, int &OBRKrysa, string &NazevKrysy){
HPKrysa = 5;
DMGKrysa = 1;
OBRKrysa = 3;
NazevKrysy = "Krysa";
}
int Kostlivec(int &HPKostlivec, int &DMGKostlivec, int &OBRKostlivec, string &NazevKostlivec){
HPKostlivec = 10;
DMGKostlivec = 5;
OBRKostlivec = 5;
NazevKostlivec = "Kostlivec";
}
int Sekera(){
Dmg = Str + 3;
}
int Mec(){
Dmg = Str + 2;
}
int Luk(){
Dmg = Dex + 2;
}
int Dyka(){
Dmg = Dex + 2;
if (Schovany == 1){
    Dmg = Dmg + 2;
}
}
int Kytara(){

Dmg = Dex + 2;
if (Zmateni == 1){
    Dmg = Cha + 2;
}
}
int Klacek() {
Dmg = Str + 1;
}
void nastavBarvu(int barva) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, barva);
}

void SoubojJedna(){
KonSouboje = 0;
cout << " Pred vami je " << NazevNepritelJedna << "\n";
do{
cout << " Co chcete delat?\n 1 - Utok\n 2 - Inventar\n 3 - Specialni schopnost"


}while (KonSouboje == 0);
}
int main(){
int Karel = 0;
int anone = 0;
int placeholder = 0;
int sila;
int vyberclass;
int y = 0;
int pocet;
int akce;
do{
cout << "Vytejte ve hre The Silent Tower";
do{
cout << " vyberte si postavu:\n\n 1 - Valecnik\n 2 - Kouzelnik\n 3 - Hranicar\n 4 - Bard\n 5 - Zlodej\n\n";
cin >> vyberclass;
cout << endl;
switch (vyberclass) {
case 1:
    inventar[3] = "Mec";
    Str = 4;
    Dex = 3;
    Con = 5;
    Int = 2;
    Cha = 1;
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    cout << " Gratuluji, stal jsi se valecnikem.\n\n Valecnici jsou lide pripraveni bojovat s neprately za pomoci hrube sily.\n Specialni schopnost: Zurivi utok - Poskozeni + 3\n\n";
    Sleep(2000);
    Karel++;
    break;
case 2:
    inventar[3] = "Hul";
    Str = 2;
    Dex = 4;
    Con = 1;
    Int = 5;
    Cha = 3;
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    cout << " Gratuluji, stal jsi se kouzelnikem.\n\n Kouzelnici jsou krehci, ale neuveritelne nadani, magie jejich krehkost vyvazuje.\n Specialni schopnost: Ohniva koule - ublizi nepriteli za 3 + Inteligence\n\n";
    Sleep(2000);
    Karel++;
    break;
case 3:
    inventar[3] = "Luk";
    Str = 2;
    Dex = 5;
    Con = 3;
    Int = 4;
    Cha = 1;
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    cout << " Gratuluji, stal jsi se hranicarem.\n\n Hranicari jsou lide ve spojeni s prirodou a jejich primarni zbrani je luk.\n Specialni schopnost: Trnovy slahoun - DoT 1\n\n";
    Sleep(2000);
    Karel++;
    break;
case 4:
    inventar[3] = "Kytara";
    Str = 1;
    Dex = 4;
    Con = 2;
    Int = 3;
    Cha = 5;
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    cout << " Gratuluji, stal jsi se bardem.\n\n Bardi jsou lide, kteri misto boje pestmi bojuji slovi,jsou velmi znamy a oblibeni.\n Specialni schopnost: Predstaveni - Zmate nepritele\n\n";
    Sleep(2000);
    Karel++;
    break;
case 5:
    inventar[3] = "Dyka";
    Str = 2;
    Dex = 5;
    Con = 1;
    Int = 3;
    Cha = 4;
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    cout << " Gratuluji, stal jsi se zlodejem.\n\n Zlodeji nevydrzi moc ran, ale jejich utoky jsou smrtelne.\n Specialni schopnost: Schovani se - Schovate se do stinu\n\n";
    Sleep(2000);
    Karel++;
    break;
default:
    inventar[3] = "Klacek";
    Str = 1;
    Dex = 4;
    Con = 2;
    Int = 1;
    Cha = 1;
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    if (y == 1){
    cout << " Gratuluji, stal jsi se goblinem.\n\n Goblini jsou monstra, ktera neposlouchaji pravidla.\n Vetsinou bivaji prvnim monstrem ktere zacatecnici zabiji.\n Specialni schopnost: Monstrum - Sance vyhnout se souboji\n\n";
    Sleep(2000);
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
            Krysa(StatyNepritelJedna[0],StatyNepritelJedna[1],StatyNepritelJedna[2],NazevNepritelJedna);
            for (int i = 0; i <= 2; i++){cout << StatyNepritelJedna[i];}
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
