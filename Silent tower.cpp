#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <stdlib.h> //Zdroj -> https://learn.microsoft.com/cs-cz/cpp/cpp/program-termination?view=msvc-170 Vyuziti -> Ukonceni Programu
using namespace std;
int omracen;
int Omamen;
int DoT;
int PocetEnemy = 0;
int pomocnapromena = 0;
int AktHP;
int KonSouboje = 0;
string Zbran;
string NazevNepritelJedna;
string NazevNepritelDva;
string NazevNepritelTri;
string jmeno = "hrdina";
int StatyNepritelJedna[6]; //0 = HP, 1 = Dmg, 2 = Obrana, 3 = XP, 4 = Prachy, 5 = Oznacen?
int StatyNepritelDva[6];
int StatyNepritelTri[6];
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
string inventar[10] = {"lektvar leceni",};
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
int josef;
int Schovan = 0;
int SchopnostLvl;
int SchopnostiClass;
int schopnosti[6][3] = {
    {1,2,3}, //Valecnik - Zurivi utok, Omracujici utok, Bojovy krik
    {4,5,6}, //Kouzelnik - Magicka strela, Ohniva koule, Draci dech
    {7,8,9}, //Hranicar - Trnovy slahoun, dvojta strela, Lovcovo znameni
    {10,11,12}, //Bard - Zlomyslny vysmech, Omameni, Tanec boje
    {13,14,15}, //Zlodej - Schovani se, Utok ze zalohy, Mistr stinu
    {16,17,18} //Goblin - Monstrum, Hbyte ruce, Zurivost malych
};
void GoblinEnmy(int &HPGoblin, int &DMGGoblin, int &OBRGoblin, string &NazevGoblin, int &OdmXP, int &OdmPrachy){
HPGoblin = 10;
DMGGoblin = 3;
OBRGoblin = 4;
NazevGoblin = "Goblin";
OdmXP = 5;
OdmPrachy = 10;
}
void Krysa(int &HPKrysa, int &DMGKrysa, int &OBRKrysa, string &NazevKrysy, int &OdmXP, int &OdmPrachy){
HPKrysa = 5;
DMGKrysa = 1;
OBRKrysa = 3;
NazevKrysy = "Krysa";
OdmXP = 1;
OdmPrachy = 5;
}
void Kostlivec(int &HPKostlivec, int &DMGKostlivec, int &OBRKostlivec, string &NazevKostlivec, int &OdmXP, int &OdmPrachy){
HPKostlivec = 10;
DMGKostlivec = 5;
OBRKostlivec = 5;
NazevKostlivec = "Kostlivec";
OdmXP = 10;
OdmPrachy = 20;
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
}
void Kytara(){
Dmg = Dex + 2;
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
void ZuriviUtok(int Energ, int DmgZurUtk, int &ObranaCile, int &HPCile){
    if (Energ <= 0){
        cout << "Nemas dost enregie\n";
    }else{
AktEnergie--;
cout << " Používáš zuřiví útok\n";
DmgZurUtk = DmgZurUtk + 2;
Attack(ObranaCile, DmgZurUtk, HPCile);
    pomocnapromena = 0;
    }
}
void OmracUtok(int Energ, int DmgOmracUtk, int &ObranaCile, int &HPCile){
    if (Energ <= 4){
        cout << "Nemas dost enregie\n";
    }else{
AktEnergie = AktEnergie - 5;
cout << " Pouzivas omracujici utok\n";
DmgOmracUtk = DmgOmracUtk + 2;
Attack(ObranaCile, DmgOmracUtk, HPCile);
    omracen = 1;
    pomocnapromena = 0;
    }
}
void ZuriviRev(int Energ,int Str, int ObranaCile, int &DmgZurRev){
    if (Energ <= 9){
        cout << "Nemas dost Energie\n";
    }else{
AktEnergie = AktEnergie - 10;
cout << " Pouzivas zurivi rev\n";
DmgZurRev = Str + 5 - ObranaCile;
    omracen = 1;
    pomocnapromena = 0;
    }
}
void MagickaStrela(int Mag, int Int, int &ObranaCile, int &HPCile){
    int DmgMagStrel;
    if (Mag <= 0){
        cout << "Nemas dost Many\n";
    }else{
AktMana--;
cout << "Pouzivas Magickou strelu\n";
DmgMagStrel = Int + 1;
Attack(ObranaCile, DmgMagStrel, HPCile);
    pomocnapromena = 0;
    }
}
void OhnivaKoule(int Mag, int Int, int &Damage, int PocetNepratel){
    int DmgOK = 0;
    if (Mag <= 4){
        cout << "Nemas dost Many\n";
    }else{
AktMana = AktMana - 5;
cout << "Pouzivas Ohnivou kouli\n";
DmgOK = Int + 3;
Damage = DmgOK / PocetNepratel;
    pomocnapromena = 0;
}
}
void DraciDech(int Mag, int Int, int &Damage){
    int DmgOK = 0;
    if (Mag <= 9){
        cout << "Nemas dost Many\n";
    }else{
AktMana = AktMana - 10;
cout << "Pouzivas Draci Dech\n";
DmgOK = Int + 3;
    pomocnapromena = 0;
}
}
void TrnovySlahoun(int Mag){
    if (Mag <= 0){
        cout << "Nemas dost Many\n";
    }else{
AktMana = AktMana - 1;
cout << "Pouzivas Trnovy slahoun\n";
DoT = 1;
    pomocnapromena = 0;
}
}
void ZlomyslnyVysmech(int Mag, int Cha, int &ObranaCile, int &HPCile){
    int DmgZloVysm;
    if (Mag <= 0){
        cout << "Nemas dost Many\n";
    }else{
AktMana--;
cout << "Pouzivas Zlomyslny vysmech\n";
DmgZloVysm = Cha + 1;
Attack(ObranaCile, DmgZloVysm, HPCile);
    pomocnapromena = 0;
    }
}
void Omameni(int Mag, int Cha){
    if (Mag <= 4){
        cout << "Nemas dost Many\n";
    }else{
AktMana = AktMana - 5;
cout << "Pouzivas Omameni\n";
Omamen = Cha;
    pomocnapromena = 0;
    }
}
void TanecBoje(int Mag, int Cha){
    if (Mag <= 9){
        cout << "Nemas dost Many\n";
    }else{
AktMana = AktMana - 10;
cout << "Pouzivas Tanec Boje\n";
Dmg = Cha + Dex;
    pomocnapromena = 0;
    }
}
void SchovaniSe(){
Schovan = 1;
pomocnapromena = 0;
}
void Monstrum(){
srand(time(0));
int NahodneCislo = rand() % 10 + 1;
if(NahodneCislo == 6){
    cout << "Nepritel vas necha na pokoji\n";
    KonSouboje = 1;
    pomocnapromena = 0;
}
}

void SoubojJedna(){
PocetEnemy = 1;
DoT = 0;
KonSouboje = 0;
cout << " Pred vami je " << NazevNepritelJedna << "\n";
if (Zbran == "Mec"){
    Mec();
}else if (Zbran == "Hul"){
    Hul();
}else if (Zbran == "Sekera"){
    Sekera();
}else if (Zbran == "Luk"){
    Luk();
}else if (Zbran == "Dyka"){
    Dyka();
}else if (Zbran == "Kytara"){
    Kytara();
}else if (Zbran == "Klacek"){
    Klacek();
}if (schopnosti[SchopnostiClass][0] == 16){
Monstrum();}
if (KonSouboje == 1){
}else{
do{
pomocnapromena = 1;
do{
cout << " Co chcete delat?\n 1 - Utok\n 2 - Inventar\n 3 - Specialni schopnosti\n 4 - Pockat\n";
cin >> FightAkce;
switch (FightAkce){
case 1:
    if (StatyNepritelJedna[5] == 1) {Dmg = Dmg + 4;}
    Attack(StatyNepritelJedna[2],Dmg,StatyNepritelJedna[0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritelJedna[0] << " zivotu\n";
    pomocnapromena = 0;
    Schovan = 0;
    Omamen = 0;
    break;
case 2:
    cout << " Inventar\n";
    Inventar();
    pomocnapromena = 0;
    break;
case 3:
    cout << " Na jaké pozici je schopnost kterou chceš použít? (0,1,2)\n";
    cin >> SchopnostLvl;
    switch (schopnosti[SchopnostiClass][SchopnostLvl]){
        case 1:
    ZuriviUtok(AktEnergie, Dmg, StatyNepritelJedna[2],StatyNepritelJedna[0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritelJedna[0] << " zivotu\n";
    break;
        case 2:
    OmracUtok(AktEnergie, Dmg, StatyNepritelJedna[2],StatyNepritelJedna[0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritelJedna[0] << " zivotu\n";
    break;
        case 3:
    ZuriviRev(AktEnergie, Str,StatyNepritelJedna[2],poskozeni);
    StatyNepritelJedna[0] = StatyNepritelJedna[0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritelJedna[0] << " zivotu\n";
    break;
        case 4:
        MagickaStrela(AktMana, Int, StatyNepritelJedna[2],StatyNepritelJedna[0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritelJedna[0] << " zivotu\n";
    break;
        case 5:
    OhnivaKoule(AktMana, Int, poskozeni, PocetEnemy);
    StatyNepritelJedna[0] = StatyNepritelJedna[0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritelJedna[0] << " zivotu\n";
    break;
        case 6:
    DraciDech(AktMana, Int, poskozeni);
    StatyNepritelJedna[0] = StatyNepritelJedna[0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritelJedna[0] << " zivotu\n";
    break;
        case 7:
    TrnovySlahoun(AktMana);
    break;
        case 8:
    if (AktEnergie <= 4){cout << "Nemas dost energie\n";}else{
    if (StatyNepritelJedna[5] == 1) {Dmg = Dmg + 4;}
    Attack(StatyNepritelJedna[2],Dmg,StatyNepritelJedna[0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritelJedna[0] << " zivotu\n";
    if (StatyNepritelJedna[5] == 1) {Dmg = Dmg + 4;}
    Attack(StatyNepritelJedna[2],Dmg,StatyNepritelJedna[0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritelJedna[0] << " zivotu\n";
    pomocnapromena = 0;}
    break;
        case 9:
    if (AktMana >= 9){
        cout << "Nemas dost many.\n";
    }else{
    AktMana = AktMana - 10;
    StatyNepritelJedna[5] = 1;
    pomocnapromena = 0;
    }
    break;
        case 10:
    ZlomyslnyVysmech(AktMana, Cha, StatyNepritelJedna[2],StatyNepritelJedna[0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritelJedna[0] << " zivotu\n";
    break;
        case 11:
    Omameni(AktMana, Cha);
    break;
        case 12:
    break;
        case 13:
    SchovaniSe();
    cout << "jste schovani\n";
    break;
        default:
    cout << " Neplatny vyber\n";
    break;
    }
    break;
case 4:
    cout << " Wait\n";
    if (AktEnergie < MaxEnergie){AktEnergie++;}
    if (AktMana < MaxMana){AktMana++;}
    pomocnapromena = 0;
    break;
}
}while (pomocnapromena == 1);
if (DoT == 1){StatyNepritelJedna[0] = StatyNepritelJedna[0] - 1;}
if(StatyNepritelJedna[0] <= 0){
cout << "Gratuluji zabyl jsi " << NazevNepritelJedna << endl;
cout << "Ziskal jsi " << StatyNepritelJedna[3] << " zkusenosti\n";
xp = xp + StatyNepritelJedna[3];
cout << "Ziskal jsi " << StatyNepritelJedna[4] << " Zlatych\n";
Penize = Penize + StatyNepritelJedna[4];
KonSouboje = 1;
}else{
if(Schovan = 1){
cout << NazevNepritelJedna << " si vas nevsimne.\n";
}else if(Omamen > 0){
Omamen--;
cout << NazevNepritelJedna << " na vas nezautoci.\n";
}else if(omracen == 1){
cout << NazevNepritelJedna << " Je omracen.\n";
}else{
cout << NazevNepritelJedna << " na vas zautoci.\n";
Attack(Dex,StatyNepritelJedna[1],AktHP);
cout << "Zasah za " << poskozeni << " zivotu\n";
cout << "Vase aktualni zivoty jsou " << AktHP << "/" << MaxHP <<endl;
if (AktHP <= 0){
    cout << "Zemrel jsi.\n";
    KonSouboje = 1;
}
}
}
}while (KonSouboje == 0);
}
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
josef = 1;
int Karel = 0;
int anone = 0;
int placeholder = 0;
int sila;
int vyberclass;
int y = 0;
int pocet;
int akce;
do{
cout << " Výtejte ve hře The Silent Tower\n\n";
y = 0;
do{
do{
cout << " Vyberte si postavu:\n\n 1 - Válečník\n 2 - Kouzelník\n 3 - Hraničář\n 4 - Bard\n 5 - Zloděj\n\n";
    josef = 1;
cin >> vyberclass;
cout << endl;
switch (vyberclass) {
case 1:
    Zbran = "Mec";
    Str = 5;
    Dex = 3;
    Con = 5;
    Int = 1;
    Cha = 1;
    cout << " Gratuluji, stal jsi se válečníkem.\n\n Válečníci jsou lidé připravení bojovat s nepřátely za pomoci hrubé síly.\n Speciální schopnost: Zuřiví útok - Poškození + 2\n\n";
    SchopnostiClass = 0;
    josef = 1;
    break;
case 2:
    Zbran = "Hul";
    Str = 1;
    Dex = 3;
    Con = 1;
    Int = 6;
    Cha = 4;
    cout << " Gratuluji, stal jsi se kouzelníkem.\n\n Kouzelníci jsou křehcí, ale neuvěřitelně nadaní, magie jejich křehkost vyvažuje.\n Speciální schopnost: Magická střela - ublíží nepříteli za 1 + Inteligence\n\n";
    SchopnostiClass = 1;
    josef = 1;
    break;
case 3:
    Zbran = "Luk";
    Str = 2;
    Dex = 5;
    Con = 3;
    Int = 4;
    Cha = 1;
    cout << " Gratuluji, stal jsi se hraničářem.\n\n Hraničáři jsou lidé ve spojení s přírodou a jejich primarní zbraní je luk.\n Speciální schopnost: Trnový šlahoun - DoT 1\n\n";
    josef = 1;
    SchopnostiClass = 2;
    break;
case 4:
    Zbran = "Kytara";
    Str = 1;
    Dex = 4;
    Con = 2;
    Int = 3;
    Cha = 5;
    cout << " Gratuluji, stal jsi se bardem.\n\n Bardi jsou lidé, kteří místo boje pěstmi bojují slovy, jsou velmy znamí a oblibení.\n Speciální schopnost: Zlomislný výsměch - Ublíží nepříteli za 1 + cha\n\n";
    josef = 1;
    SchopnostiClass = 3;
    break;
case 5:
    Zbran = "Dyka";
    Str = 2;
    Dex = 5;
    Con = 1;
    Int = 3;
    Cha = 4;
    cout << " Gratuluji, stal jsi se zlodějem.\n\n Zloději nevydrží moc ran, ale jejich útoky jsou smrtelné.\n Speciální schopnost: Schování se - Schováte se do stínu\n\n";
    josef = 1;
    SchopnostiClass = 4;
    break;
default:
    if (y == 1){
    Zbran = "Klacek";
    Str = 1;
    Dex = 4;
    Con = 2;
    Int = 1;
    Cha = 1;
    SchopnostiClass = 5;
    cout << " Gratuluji, stal jsi se goblinem.\n\n Goblini jsou monstra, která neposlouchají pravidla.\n Většinou bývají prvním monstrem, které začátečníci zabijí.\n Speciální schopnost: Monstrum - Šance vyhnout se souboji\n\n";
    nastavBarvu(4);
    cout << "Toto povolání vám bylo přiděleno podle vaší inteligence \n";
    nastavBarvu(7);
    Karel = 1;
    y = 2;
    josef = 1;
    }else{
    y = 1;
    nastavBarvu(4);
    cout << "!POZOR! Pokud si nevyberete z připravených povolání, bude volba provedena za vás.\n";
    nastavBarvu(7);
    josef = 0;
    }
    break;
}
}while (josef == 0);
if (y == 2){
    Penize = 5;
    MaxHP = 3 + Con;
    AktHP = 3 + Con;
    MaxMana = 2 + Int;
    AktMana = 2 + Int;
    MaxEnergie = 2 + Con;
    AktEnergie = 2 + Con;
    cout << " Vaše vlastnosti jsou:\n";
    cout << " síla: " << Str << endl;
    cout << " obratnost: " << Dex << endl;
    cout << " odolnost: " << Con << endl;
    cout << " inteligence: " << Int << endl;
    cout << " charisma: " << Cha << endl;
    cout << " Aktualní životy: " << AktHP << "/" << MaxHP << endl << endl;
    cout << " Aktualní energie: " << MaxEnergie << "/" << AktEnergie << endl << endl;
    cout << " Aktualní mana: " << MaxMana << "/" << AktMana << endl << endl;
    anone = 1;
}else{
    Penize = 10;
    MaxHP = 5 + Con;
    AktHP = 5 + Con;
    MaxMana = 3 + Int;
    AktMana = 3 + Int;
    MaxEnergie = 3 + Con;
    AktEnergie = 3 + Con;
    cout << " Vaše vlastnosti jsou:\n";
    cout << " síla: " << Str << endl;
    cout << " obratnost: " << Dex << endl;
    cout << " odolnost: " << Con << endl;
    cout << " inteligence: " << Int << endl;
    cout << " charisma: " << Cha << endl;
    cout << " Aktualní životy: " << AktHP << "/" << MaxHP << endl << endl;
    cout << " Aktualní energie: " << MaxEnergie << "/" << AktEnergie << endl << endl;
    cout << " Aktualní mana: " << MaxMana << "/" << AktMana << endl << endl;
    cout << "Jste si jisti svim vyberem? 1 - Ano 2 - Ne\n";
    cin >> anone;
}
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

}while (Karel == 0);
    cout << "_______________________________________________________________________________________________________________________";
    cout  << endl << endl;
    cout << " Probouzíte se v šedé kamenné místnosti. Uprostřed místnosti hoří malý oheň, který ji slabě osvětluje. Na druhém konci místnosti vidíte dveře, za kterými něco vydává škrábavé zvuky."; //pouzito AI pro opravení chyb v již napsaném textu
do{
    cout << " Co chcete dělat?\n\n 1 - Jít ke dveřím\n 2 - Zůstat sedět na zemi\n 3 - Pokusit si vzpomenout jak jste se sem dostali\n";
    cin >> akce;
    placeholder = 0;
switch (akce){
case 1:
    cout << " Jdeš směrem ke dveřím, chceš je otevřít? \n 1 - ano\n 2 - ne\n";
    cin >> anone;
    switch (anone){
        case 1:
            cout << " Za dveřmi je schodiště bráněné krysou. Krysa na vás zaútočí\n";
            Krysa(StatyNepritelJedna[0],StatyNepritelJedna[1],StatyNepritelJedna[2],NazevNepritelJedna,StatyNepritelJedna[3],StatyNepritelJedna[4]);
            SoubojJedna();
            placeholder = 1;
            break;
        case 2:
            cout << " Rozhodli jste se že je vám jedno co se děje za dveřmi.\n Vracíte se k ohni. co chcete dělat dál?\n";
            break;
        default:
            cout << " neplatná volba. zkus znovu\n";
            break;
    }
    break;
case 2:
    cout << " Zůstáváte sedět na zemi... zem je tvrdá a studená, zjevně kámen.";
    break;
case 3:
    cout << " Snažíte se přemýšlet nad tím jak jste se sem dostali a proč tu vlastně jste.\n Jak tak přemýšlíte zjistíte že nejste schopni vzpomenout si na vaše jméno\n\n Zadejte jak se budete jmenovat: ";
    cin.ignore(); //Rada od umělé inteligence. Řeší problém s tím, že mi nešlo zapsat nové jméno přes getline.
    getline(cin, jmeno);
    cout << "vase jmeno je " << jmeno;
}
}while (placeholder == 0);
cout << " Porazili jste krysu, Jediná cesta dál je schodiště, chcete jít po schodech nahoru? 1 - Ano 2 - Ne\n";
cin >> anone;
switch (anone) {
case 1:
    cout << " Pokračujete dál po schodech. Jakmile dorazíte po schodech nahoru všimnete si dveří, z pod kterých svítí příjemná žlutá záře.\n\n Chcete je otevřít?\n 1 - Ano\n 2 - Ne\n";
    cin >> anone;
    switch (anone){
    case 1:
        cout << " Za dveřmi je středně velká místnost osvětlená loučemi, na protější straně leží sýr... co chcete delat?\n\n 1 - Jít k sýru a prosokumat ho\n 2 - Vrátit se po schodech dolů\n 3 - Zůstat stát\n 4 - Jít ke dveřím na druhé straně místnosti\n";
        cin >> akce;
        switch (akce){
        case 1:
            cout << " Prozkoumáváš sír, zatím co koukáš na sír nevšimneš si krysi, která na tebe zaútočí.";
            Krysa(StatyNepritelJedna[0],StatyNepritelJedna[1],StatyNepritelJedna[2],NazevNepritelJedna,StatyNepritelJedna[3],StatyNepritelDva[4]);
            SoubojJedna();
            break;
        case 2:
            cout << " Vrátíš se po schodech dolů, mrtvola krysi stále leží dole na schodišti. co chceš dělat? \n 1 - Vrátit se po schodech nahoru \n 2 - Pohřbít krysu \n 3 - Vrátit se k ohni\n";
            cin >> akce;
            switch (akce){
            case 1:
                cout << " Vracíš se zpátky po schodech nahoru\n";
                break;
            case 2:
                cout << " Z kamínků a dalších malích předmětů, co jsi našel ležet po místonsti, jsi zhotovil malou mohylu co chceš dělat dál? ";
            }
        }
    }
    break;
case 2:
cout << " Stojíte v místnosti s poraženou krysou.\n";
break;
}
placeholder = 0;
}while (placeholder == 1);
}
