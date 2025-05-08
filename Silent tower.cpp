#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h> //Zdroj -> https://learn.microsoft.com/cs-cz/cpp/cpp/program-termination?view=msvc-170 Vyuziti -> Ukonceni Programu
using namespace std;
int AktHP;
int KonSouboje = 0;
int Schovany = 0;
int Zmateni = 0;
string NazevNepritelJedna;
string jmeno = "hrdina";
int StatyNepritelJedna[4];
int StatyNepritelDva[4];
int StatyNepritelTri[4];
int MaxHP;
int Dmg;
int poskozeni;
int Str;
int FightAkce;
int Dex;
int Int;
int Cha;
int Con;
int Penize;
string inventar[10] = {"lektvar leceni", "20zlatych"};
int uprinv = 0;
int konec = 0;
int loot;
int lvl = 1;
int xp = 0;
int MaxMana;
int AktMana;
int MaxEnergie;
int AktEnergie;
int x;

void GoblinEnmy(int &HPGoblin, int &DMGGoblin, int &OBRGoblin, string &NazevGoblin, int &OdmXP){
HPGoblin = 10;
DMGGoblin = 3;
OBRGoblin = 4;
NazevGoblin = "Goblin";
OdmXP = 5;
}
void Krysa(int &HPKrysa, int &DMGKrysa, int &OBRKrysa, string &NazevKrysy, int &OdmXP){
HPKrysa = 5;
DMGKrysa = 1;
OBRKrysa = 3;
NazevKrysy = "Krysa";
OdmXP = 1;
}
void Kostlivec(int &HPKostlivec, int &DMGKostlivec, int &OBRKostlivec, string &NazevKostlivec, int &OdmXP){
HPKostlivec = 10;
DMGKostlivec = 5;
OBRKostlivec = 5;
NazevKostlivec = "Kostlivec";
OdmXP = 10;
}
void Hul(){
Dmg = Dex + 2;
}
void Sekera(){
Dmg = Str + 3;
}
void Mec(){
Dmg = Str + 2;
}
void Luk(){
Dmg = Dex + 2;
}
void Dyka(){
Dmg = Dex + 2;
if (Schovany == 1){
    Dmg = Dmg + 2;
}
}
void Kytara(){

Dmg = Dex + 2;
if (Zmateni == 1){
    Dmg = Cha + 2;
}
}
void Klacek() {
Dmg = Str + 1;
}
void Inventar(){
do{
    for (int i;i <= 10;i++){
        cout << inventar[i] << " ";
    }
    cout << " Co chcete delat?\n 1 - Zahodit predmet \n 2 - Pouzit predmet \n 3 - Ukocit\n";
    cin >> uprinv;
    switch (uprinv) {
case 1:
    cout << "zahodit \n";
    break;
case 2:
    cout << "na jakem miste se nachazi predmet, ktery chcete pouzit?\n";
    cin >> x;
    cout << "Jste si jisti ze chcete " << inventar[x] << " pouzit?\n";
    if (x == 3){
        Mec();
    }
    break;
case 3:
    konec = 1;
    break;
default:
    cout << "Neplatny vyber \n";
}
}while (konec = 0);
}
void nastavBarvu(int barva) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, barva);
}
void Attack(int ObranaNepritele, int DmgUtok, int &HpNepritele){
poskozeni = 0;
poskozeni = DmgUtok - ObranaNepritele;
if (poskozeni <= 0) {poskozeni = 1;}
HpNepritele = HpNepritele - poskozeni;
}

void SoubojJedna(){
Inventar();
KonSouboje = 0;
cout << " Pred vami je " << NazevNepritelJedna << "\n";
do{
cout << " Co chcete delat?\n 1 - Utok\n 2 - Inventar\n 3 - Specialni schopnosti\n 4 - Pockat\n";
cin >> FightAkce;
switch (FightAkce){
case 1:
    Attack(StatyNepritelJedna[2],Dmg,StatyNepritelJedna[0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritelJedna[0] << " zivotu\n";
    break;
case 2:
    cout << "Inventar";
    Inventar();
    break;
case 3:
    cout << "Special";
    break;
case 4:
    cout << "Wait";
    break;
}if(StatyNepritelJedna[0] <= 0){
cout << "Gratuluji zabyl jsi " << NazevNepritelJedna << endl;
cout << "Ziskal jsi " << StatyNepritelJedna[3] << " zkusenosti\n";
xp = xp + StatyNepritelJedna[3];
KonSouboje = 1;
}
cout << NazevNepritelJedna << " na vas zautoci.\n";
Attack(Dex,StatyNepritelJedna[1],AktHP);
cout << "Zasah za " << poskozeni << " zivotu\n";
cout << "Vase aktualni zivoty jsou " << AktHP << "/" << MaxHP <<endl;
if (AktHP <= 0){
    cout << "Zemrel jsi.\n";
    KonSouboje = 1;
}
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
cout << " Vytejte ve hre The Silent Tower\n\n";
y = 0;
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
    cout << " Gratuluji, stal jsi se valecnikem.\n\n Valecnici jsou lide pripraveni bojovat s neprately za pomoci hrube sily.\n Specialni schopnost: Zurivi utok - Poskozeni + 3\n\n";
    Sleep(1000);
    break;
case 2:
    inventar[3] = "Hul";
    Str = 2;
    Dex = 4;
    Con = 1;
    Int = 5;
    Cha = 3;
    cout << " Gratuluji, stal jsi se kouzelnikem.\n\n Kouzelnici jsou krehci, ale neuveritelne nadani, magie jejich krehkost vyvazuje.\n Specialni schopnost: Ohniva koule - ublizi nepriteli za 3 + Inteligence\n\n";
    Sleep(1000);
    break;
case 3:
    inventar[3] = "Luk";
    Str = 2;
    Dex = 5;
    Con = 3;
    Int = 4;
    Cha = 1;
    cout << " Gratuluji, stal jsi se hranicarem.\n\n Hranicari jsou lide ve spojeni s prirodou a jejich primarni zbrani je luk.\n Specialni schopnost: Trnovy slahoun - DoT 1\n\n";
    Sleep(1000);
    break;
case 4:
    inventar[3] = "Kytara";
    Str = 1;
    Dex = 4;
    Con = 2;
    Int = 3;
    Cha = 5;
    cout << " Gratuluji, stal jsi se bardem.\n\n Bardi jsou lide, kteri misto boje pestmi bojuji slovi,jsou velmi znamy a oblibeni.\n Specialni schopnost: Predstaveni - Zmate nepritele\n\n";
    Sleep(1000);
    break;
case 5:
    inventar[3] = "Dyka";
    Str = 2;
    Dex = 5;
    Con = 1;
    Int = 3;
    Cha = 4;
    cout << " Gratuluji, stal jsi se zlodejem.\n\n Zlodeji nevydrzi moc ran, ale jejich utoky jsou smrtelne.\n Specialni schopnost: Schovani se - Schovate se do stinu\n\n";
    Sleep(1000);
    break;
default:
    inventar[3] = "Klacek";
    Str = 1;
    Dex = 4;
    Con = 2;
    Int = 1;
    Cha = 1;
    if (y == 1){
    cout << " Gratuluji, stal jsi se goblinem.\n\n Goblini jsou monstra, ktera neposlouchaji pravidla.\n Vetsinou bivaji prvnim monstrem ktere zacatecnici zabiji.\n Specialni schopnost: Monstrum - Sance vyhnout se souboji\n\n";
    Sleep(1000);
    nastavBarvu(4);
    cout << "Toto povolani vam bylo prideleno podle vasi inteligence \n";
    nastavBarvu(7);
    Karel = 1;
    y = 2;
    }else{
    y = 1;
    nastavBarvu(4);
    cout << "!POZOR! Pokud si nevyberete z pripravenych povolani, bude volba provedena za vas.\n";
    nastavBarvu(7);
    }
    break;
}
if (y == 2){
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    MaxMana = 5 + Int;
    AktMana = 5 + Int;
    MaxEnergie = 5 + Dex;
    AktEnergie = 5 + Dex;
    cout << " Vase vlastnosti jsou:\n";
    cout << " sila: " << Str << endl;
    cout << " obratnost: " << Dex << endl;
    cout << " odolnost: " << Con << endl;
    cout << " inteligence: " << Int << endl;
    cout << " charisma: " << Cha << endl;
    cout << " Aktualni zivoty: " << AktHP << "/" << MaxHP << endl << endl;
    cout << " Aktualni energie: " << MaxEnergie << "/" << AktEnergie << endl << endl;
    cout << " Aktualni mana: " << MaxMana << "/" << AktMana << endl << endl;
}else{
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    MaxMana = 5 + Int;
    AktMana = 5 + Int;
    MaxEnergie = 5 + Dex;
    AktEnergie = 5 + Dex;
    cout << " Vase vlastnosti jsou:\n";
    cout << " sila: " << Str << endl;
    cout << " obratnost: " << Dex << endl;
    cout << " odolnost: " << Con << endl;
    cout << " inteligence: " << Int << endl;
    cout << " charisma: " << Cha << endl;
    cout << " Aktualni zivoty: " << AktHP << "/" << MaxHP << endl;
    cout << " Aktualni energie: " << AktEnergie << "/" << MaxEnergie << endl;
    cout << " Aktualni mana: " << AktMana << "/" << MaxMana << endl;
    cout << "Jste si jisti svim vyberem? 1 - Ano 2 - Ne\n";
    cin >> anone;
    switch (anone){
case 1:
    Karel = 1;
    break;
case 2:
    Karel = 0;
    break;
default:
    cout << "Neplatny vyber";
    break;
    }
}
}while (Karel == 0);
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
            Krysa(StatyNepritelJedna[0],StatyNepritelJedna[1],StatyNepritelJedna[2],NazevNepritelJedna,StatyNepritelJedna[3]);
            SoubojJedna();
            placeholder = 1;
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
cout << " Porazili jste krysu, Jedina cesta dal je schodiste, chcete jit po schodech nahoru? 1 - Ano 2 - Ne\n";

placeholder = 0;
}while (placeholder == 1);
}
