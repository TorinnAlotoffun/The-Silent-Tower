#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <stdlib.h> //Zdroj -> https://learn.microsoft.com/cs-cz/cpp/cpp/program-termination?view=msvc-170 Vyuziti -> Ukonceni Programu
using namespace std;
int Podminka = 0;
int anone = 0;
int PocetEnemy = 0;
int pomocnapromena = 0;
int AktHP;
int KonSouboje = 0;
string Zbran;
string NazevNepritelJedna;
string NazevNepritelDva;
string NazevNepritelTri;
string jmeno = "hrdina";
int StatyNepritel[3][9]; //0 = HP, 1 = Dmg, 2 = Obrana, 3 = XP, 4 = Prachy, 5 = Oznacen, 6 = omracen, 7 = omamen, 8 = DoT
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
string inventar[5] = {"Lektvar léčení", "-", "-", "-", "-"};
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
int target;
int josef;
int Schovan = 0;
int SchopnostLvl;
int SchopnostiClass;
int schopnosti[6][3] = {
    {1,2,3}, //Valecnik - Zurivi utok, Omracujici utok, Bojovy krik
    {4,5,6}, //Kouzelnik - Magicka strela, Ohniva koule, Draci dech
    {7,8,9}, //Hranicar - Trnovy slahoun, dvojta strela, Lovcovo znameni
    {10,11,12}, //Bard - Zlomyslny vysmech, Omameni, Tanec boje
    {13,14,15}, //Zlodej - Schovani se, Utok ze zalohy, Mistr Jedu
    {16,17,18} //Goblin - Monstrum, Hbyte ruce, Zurivost malych
};
void LektvarLeceni(){
AktHP = AktHP + 3;
if(AktHP > MaxHP){AktHP = MaxHP;}
}
void LektvarMany(){
AktMana = AktMana + 3;
if(AktMana > MaxMana){AktMana = MaxMana;}
}
void LektvarEnergie(){
AktEnergie = AktEnergie + 3;
if(AktEnergie > MaxEnergie){AktEnergie = MaxEnergie;}
}
void Goblin(int &HPGoblin, int &DMGGoblin, int &OBRGoblin, string &NazevGoblin, int &OdmXP, int &OdmPrachy){
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
void KrysiKral(int &HPKrysiKral, int &DMGKrysiKral, int &OBRKrysiKral, string &NazevKrysiKral, int &OdmXP, int &OdmPrachy){
HPKrysiKral = 10;
DMGKrysiKral = 4;
OBRKrysiKral = 6;
NazevKrysiKral = "Krysí král";
OdmXP = 10;
OdmPrachy = 20;
}
void GoblinSef(int &HPGoblinSef, int &DMGGoblinSef, int &OBRGoblinSef, string &NazevGoblinSef, int &OdmXP, int &OdmPrachy){
HPGoblinSef = 20;
DMGGoblinSef = 5;
OBRGoblinSef = 5;
NazevGoblinSef = "Šéf Goblinů";
OdmXP = 15;
OdmPrachy = 25;
}
void Nekromancer(int &HPNekromancer, int &DMGNekromancer, int &OBRNekromancer, string &NazevNekromancer, int &OdmXP, int &OdmPrachy){
HPNekromancer = 30;
DMGNekromancer = 9;
OBRNekromancer = 7;
NazevNekromancer = "Nekromancer";
OdmXP = 20;
OdmPrachy = 30;
}
void Silentchant(int &HPSilentchant, int &DMGSilentchant, int &OBRSilentchant, string &NazevSilentchant, int &OdmXP, int &OdmPrachy){
HPSilentchant = 30;
DMGSilentchant = 9;
OBRSilentchant = 7;
NazevSilentchant = "Silentchant";
OdmXP = 20;
OdmPrachy = 30;
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
    konec = 0;
do{
    for (int i;i <= 5;i++){
        cout << inventar[i] << " ";
    }
    cout << "\n Co chcete dělat?\n 1 - Zahodit předmět \n 2 - Použít předmět \n 3 - Ukončit\n";
    cin >> uprinv;
    switch (uprinv) {
case 1:
    do{
    cout << " Na jakém místě se nachází předmět, který chcete zahodit? (1 - 5)\n";
    cin >> x;
    }while(x < 1 || x > 5);
    x--;
    cout << "Jste si jisti že chcete " << inventar[x] << " zahodit? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
case 1:
    if(inventar[x] == "-"){
    cout << " Na tomto místě nic nemáte.\n";
    }else{
    inventar[x] = "-";
    konec = 1;
    pomocnapromena = 0;
    }
    break;
case 2:
    break;
default:
    cout << " Neplatný výběr\n";
    break;
    }
    break;
case 2:
    do{
    cout << " Na jakém místě se nachází předmět, který chcete použít? (1 - 5)\n";
    cin >> x;
    }while(x < 1 || x > 5);
    x--;
    cout << "Jste si jisti že chcete " << inventar[x] << " použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
case 1:
    if(inventar[x] == "Lektvar léčení"){
    inventar[x] = "-";
    cout << " Vypijete lektvar léčení.\n";
    LektvarLeceni();
    cout << " Vaše životy: " << AktHP << "/" << MaxHP <<endl;
    konec = 1;
    pomocnapromena = 0;
    }else if(inventar[x] == "Lektvar many"){
    inventar[x] = "-";
    cout << " Vypijete lektvar many.\n";
    LektvarMany();
    cout << " Vaše Mana: " << AktMana << "/" << MaxMana <<endl;
    konec = 1;
    pomocnapromena = 0;
    }else if(inventar[x] == "Energiťák"){
    inventar[x] = "-";
    cout << " Vypijete Energiťák.\n";
    LektvarEnergie();
    cout << " Vaše Energie: " << AktEnergie << "/" << MaxEnergie <<endl;
    konec = 1;
    pomocnapromena = 0;
    }else{
    cout << " Na vybraném místě nic nemáš.\n";
    }
    break;
case 2:
    break;
default:
    cout << " Neplatný výběr\n";
    break;
    }
case 3:
    konec = 1;
    break;
default:
    cout << "Neplatný výběr \n";
}
}while (konec == 0);
}
void FullHeal(){AktHP = MaxHP;}
void FullEnergie(){AktEnergie = MaxEnergie;}
void FullMana(){AktMana = MaxMana;}
void LvlUp(){
int LvlVyber;
xp = 0;
lvl++;
MaxHP++;
MaxEnergie++;
MaxMana++;
FullEnergie();
FullHeal();
FullMana();
if (lvl == 5){
    cout << "\n Odemčena nová schopnost: ";
    switch (schopnosti[SchopnostiClass][1]){
case 2:
    cout << "Omračující útok - omráčí nepřítele.\n";
    break;
case 5:
    cout << "Ohnivá koule - Ublíží všem nepřátelům za Inteligence + 3.\n";
    break;
case 8:
    cout << "Dvojitá střela - provede dva útoky hned po sobě.\n";
    break;
case 11:
    cout << "Omámení - Omámí nepřítele. Omámený nepřítel na vás nebude útočit, pokud vy nebudete útočit na něj.\n";
case 14:
    cout << "Útok ze zálohy - pokud jste schovaní + 5 k útoku.\n";
case 17:
    cout << "Hbyté ruce - Ze zabytých nepřátel získáte více zlaťáků.\n";
    }
}else if(lvl == 10){
    cout << "\n Odemčena nová schopnost: ";
    switch (schopnosti[SchopnostiClass][2]){
case 3:
    cout << "Bojový pokřik - Ublíží všem nepřátelům za Síla + 5.\n";
    break;
case 6:
    cout << "Dračí dech - Ublíží všem nepřátelům za Inteligence + 3, bez ohledu na obranu nepřítele.\n";
    break;
case 9:
    cout << "Lovcovo znamení - Označí jednoho nepřítele, ubíráte mu více životů.\n";
    break;
case 12:
    cout << "Tanec boje - Poškození = Obratnost + charisma.\n";
case 15:
    cout << "Mistr Jedu - pokud jste schovaní, můžete otrávit nepřítele (2 Poškození za kolo).\n";
case 18:
    cout << "Zuřivost malých - Permanentně poškození + 5.\n";
}
}
if (lvl % 5 == 0){
cout << " Jakou vlastnost chcete vylepšit?\n 1 - Síla\n 2 - Obratnost\n 3 - Odolnost\n 4 - Inteligence\n 5 - Charisma\n";
cin >> LvlVyber;
switch (LvlVyber){
case 1:
    Str++;
    break;
case 2:
    Dex++;
    break;
case 3:
    Con++;
    break;
case 4:
    Int++;
    break;
case 5:
    Cha++;
    break;
}
}
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
        cout << "Nemáš dost enregie\n";
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
        cout << "Nemáš dost enregie\n";
    }else{
AktEnergie = AktEnergie - 5;
cout << " Používáš omračující útok\n";
DmgOmracUtk = DmgOmracUtk + 2;
Attack(ObranaCile, DmgOmracUtk, HPCile);
    StatyNepritel[target][6] = 1;
    pomocnapromena = 0;
    }
}
void BojovyPokrik(int Energ,int Str, int ObranaCile, int &DmgZurRev){
    if (Energ <= 9){
        cout << "Nemáš dost energie\n";
    }else{
AktEnergie = AktEnergie - 10;
cout << " Používáš Bojový Pokřik\n";
DmgZurRev = Str + 5 - ObranaCile;
    pomocnapromena = 0;
    }
}
void MagickaStrela(int Mag, int Int, int &ObranaCile, int &HPCile){
    int DmgMagStrel;
    if (Mag <= 0){
        cout << "Nemáš dost many\n";
    }else{
AktMana--;
cout << "Používáš Magickou střelu\n";
DmgMagStrel = Int + 1;
Attack(ObranaCile, DmgMagStrel, HPCile);
    pomocnapromena = 0;
    }
}
void OhnivaKoule(int Mag, int Int, int &Damage, int PocetNepratel){
    int DmgOK = 0;
    if (Mag <= 4){
        cout << "Nemáš dost many\n";
    }else{
AktMana = AktMana - 5;
cout << "Používáš Ohnivou kouli\n";
DmgOK = Int + 3;
Damage = DmgOK / PocetNepratel;
    pomocnapromena = 0;
}
}
void DraciDech(int Mag, int Int, int &Damage){
    int DmgOK = 0;
    if (Mag <= 9){
        cout << "Nemáš dost many\n";
    }else{
AktMana = AktMana - 10;
cout << "Používáš Dračí Dech\n";
DmgOK = Int + 3;
    pomocnapromena = 0;
}
}
void TrnovySlahoun(int Mag){
    if (Mag <= 0){
        cout << "Nemáš dost many\n";
    }else{
    if (PocetEnemy == 1){target = 0;}else if(PocetEnemy == 2) {
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << " " << StatyNepritel[0][0] << "\n 2 - " << NazevNepritelDva << " " << StatyNepritel[1][0] <<endl;
    }else{
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << " " << StatyNepritel[0][0] << "\n 2 - " << NazevNepritelDva << " " << StatyNepritel[1][0] << "\n 3 - " << NazevNepritelTri << " " << StatyNepritel[2][0] <<endl;
    cin >> target;
    target--;}
AktMana = AktMana - 1;
cout << "Používáš Trnový šlahoun\n";
StatyNepritel[target][8] = 1;
    pomocnapromena = 0;
}
}
void DvojitaStrela(){
    if (PocetEnemy == 1){target = 0;}else if(PocetEnemy == 2) {
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << " " << StatyNepritel[0][0] << "\n 2 - " << NazevNepritelDva << " " << StatyNepritel[1][0] <<endl;
    }else{
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << " " << StatyNepritel[0][0] << "\n 2 - " << NazevNepritelDva << " " << StatyNepritel[1][0] << "\n 3 - " << NazevNepritelTri << " " << StatyNepritel[2][0] <<endl;
    cin >> target;
    target--;}
    if (AktEnergie <= 4){cout << "Nemas dost energie\n";}else{
    if (StatyNepritel[target][5] == 1) {Dmg = Dmg + 4;}
    Attack(StatyNepritel[target][2],Dmg,StatyNepritel[target][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[target][0] << " zivotu\n";
    if (PocetEnemy == 1){target = 0;}else if(PocetEnemy == 2) {
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << " " << StatyNepritel[0][0] << "\n 2 - " << NazevNepritelDva << " " << StatyNepritel[1][0] <<endl;
    }else{
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << " " << StatyNepritel[0][0] << "\n 2 - " << NazevNepritelDva << " " << StatyNepritel[1][0] << "\n 3 - " << NazevNepritelTri << " " << StatyNepritel[2][0] <<endl;
    cin >> target;
    target--;}
    if (StatyNepritel[target][5] == 1) {Dmg = Dmg + 4;}
    Attack(StatyNepritel[target][2],Dmg,StatyNepritel[target][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[target][0] << " zivotu\n";
    pomocnapromena = 0;}
}
void LovcovoZnameni(){
    if (PocetEnemy == 1){target = 0;}else if(PocetEnemy == 2){
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva <<endl;
    cin >> target;
    target--;}else{
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva << "\n 3 - " << NazevNepritelTri << endl;
    cin >> target;
    target--;
    }
    if (AktMana >= 9){
        cout << "Nemas dost many.\n";
    }else{
    AktMana = AktMana - 10;
    StatyNepritel[target][5] = 1;
    pomocnapromena = 0;
    }
}
void ZlomyslnyVysmech(int Mag, int Cha, int &ObranaCile, int &HPCile){
    int DmgZloVysm;
    if (Mag <= 0){
        cout << "Nemáš dost many\n";
    }else{
AktMana--;
cout << "Používáš Zlomyslný výsměch\n";
DmgZloVysm = Cha + 1;
Attack(ObranaCile, DmgZloVysm, HPCile);
    pomocnapromena = 0;
    }
}
void Omameni(int Mag, int Cha){
    if (Mag <= 4){
        cout << "Nemáš dost many\n";
    }else{
    if (PocetEnemy == 1){target = 0;}else{
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << " " << StatyNepritel[0][0] << "\n 2 - " << NazevNepritelDva << " " << StatyNepritel[1][0] <<endl;
    cin >> target;
    target--;}
AktMana = AktMana - 5;
cout << "Používáš Omámení\n";
StatyNepritel[target][7] = Cha;
    pomocnapromena = 0;
    }
}
void TanecBoje(int Mag, int Cha){
    if (Mag <= 9){
        cout << "Nemáš dost many\n";
    }else{
AktMana = AktMana - 10;
cout << "Používáš Tanec Boje\n";
Dmg = Cha + Dex;
    pomocnapromena = 0;
    }
}
void SchovaniSe(){
Schovan = 1;
pomocnapromena = 0;
}
void UtokZeZalohy(int DmgSneakUtk, int &ObranaCile, int &HPCile){
if(Schovan == 0){
cout << " Nejsi schovaný\n";
}else{
DmgSneakUtk = DmgSneakUtk + 5;
Attack(ObranaCile,DmgSneakUtk,HPCile);
Schovan = 0;
pomocnapromena = 0;
}
}
void MistrJedu(){
    if (PocetEnemy == 1){target = 0;}else{
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva <<endl;
    cin >> target;
    target--;}
if(Schovan == 0){
cout << " Nejsi schovaný\n";
}else{
StatyNepritel[target][8] = 2;
pomocnapromena = 0;
}
}
void Monstrum(){
srand(time(0));
int NahodneCislo = rand() % 10 + 1;
if(NahodneCislo == 6){
    cout << "Nepřítel vás nechá napokoji\n";
    KonSouboje = 1;
    pomocnapromena = 0;
}
}
void HbyteRuce(int &Odmena){
Odmena = Odmena + 5;
}
void FuryOfTheBall(){
Dmg = Dmg + 5;
}
void Shop(){
int Odejit = 0;
int ShopAkce;
cout << " Výtejte v obchodě.\n";
do{
cout << " Co si chcete koupit?\n 1 - Doplnění životů, energie a many (Zdarma)\n 2 - Vylepšení životů + 1 (5 zlatých)\n 3 - Vylepšení Many + 1(5 zlatých)\n 4 - Vylepšení Energie + 1(5 zlatých)\n 5 - Lektvar skušeností Lvlup (10 zlatých)\n 6 - Lektvary\n 7 - Otevřít inventář\n 8 - Odejít\n";
cin >> ShopAkce;
switch (ShopAkce){
case 1:
    FullHeal();
    FullEnergie();
    FullMana();
    break;
case 2:
    if (Penize < 5){
        cout << " Nemáš dost peněz. \n";
    }else{
    Penize = Penize - 5;
    MaxHP++;
    AktHP++;
    cout << " Vaše životy jsou nyní: " << AktHP << "/" << MaxHP << endl;
    }
    break;
case 3:
    if (Penize < 5){
        cout << " Nemáš dost peněz. \n";
    }else{
    Penize = Penize - 5;
    MaxMana++;
    AktMana++;
    cout << " Vaše mana je nyní: " << AktMana << "/" << MaxMana << endl;
    }
    break;
case 4:
    if (Penize < 5){
        cout << " Nemáš dost peněz. \n";
    }else{
    Penize = Penize - 5;
    MaxEnergie++;
    AktEnergie++;
    cout << " Vaše energie je nyní: " << AktEnergie << "/" << MaxEnergie << endl;
    }
    break;
case 5:
    if (Penize < 10){
        cout << " Nemáš dost peněz. \n";
    }else{
    Penize = Penize - 10;
    LvlUp();
    }
    break;
case 6:
    cout << " Jaký lektvar chcete koupit? (3 zlaté)\n 1 - Lektvar Léčení\n 2 - Lektvar Many\n 3 - Lektvar Energie\n";
    if (Penize < 3){cout << " Nemáš dost peněz\n";}else{
    Penize = Penize - 3;
    cin >> ShopAkce;
    switch (ShopAkce){
    case 1:
        cout << " Na kterou pozici? (0 - 4)\n";
        cin >> x;
        if (x < 0 || x > 4){cout << " Neplatná pozice\n";}
        if (inventar[x] == "-"){inventar[x] = "Lektvar léčení"; Penize = Penize - 3;}else{cout << " Na daném místě již něco máš\n";}
        break;
    case 2:
        cout << " Na kterou pozici? (0 - 4)\n";
        cin >> x;
        if (x < 0 || x > 4){cout << " Neplatná pozice\n";}
        if (inventar[x] == "-"){inventar[x] = "Lektvar many"; Penize = Penize - 3;}else{cout << " Na daném místě již něco máš\n";}
        break;
    case 3:
        cout << " Na kterou pozici? (0 - 4)\n";
        cin >> x;
        if (x < 0 || x > 4){cout << " Neplatná pozice\n";}
        if (inventar[x] == "-"){inventar[x] = "Energiťák"; Penize = Penize - 3;}else{cout << " Na daném místě již něco máš\n";}
        break;
    default:
        cout << " Neplatný výběr\n";
        break;
    }}
    break;
case 7:
    Inventar();
    break;
case 8:
    Odejit = 1;
    break;
}
}while (Odejit == 0);
}
void SoubojFinalBoss(){
int PouzAb = 0;
PocetEnemy = 1;
int z = 0;
Schovan = 0;
StatyNepritel[0][8] = 0;
KonSouboje = 0;
cout << " Před vámi je " << NazevNepritelJedna << "\n";
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
}
do{
pomocnapromena = 1;
if(Schovan == 1){
cout << NazevNepritelJedna << " si vás nevšimne.\n";
}else if(StatyNepritel[0][7] > 0){
StatyNepritel[0][7]--;
cout << NazevNepritelJedna << " na vás nezaútočí.\n";
}else if(StatyNepritel[0][6] == 1){
cout << NazevNepritelJedna << " Je omráčen.\n";
}else if(z == 5){
    if (PouzAb >= 3){
Attack(Dex,z * 10*1.5, AktHP);
    }else{
Attack(Dex,z * 10, AktHP);
z = 0;
cout << " Cítíš vlnu magie kterrá ti ubere " << poskozeni << " životů\n" << " Máš " << AktHP << "/" << MaxHP << " životů.\n";
}
}else{
z++;
}
if (AktHP <= 0){
    cout << ". . .";
    cout << "Zemřel jsi.\n";
    exit(0);
}
do{
cout << " Co chcete dělat?\n 1 - Útok\n 2 - Inventář\n 3 - Speciální schopnosti\n 4 - Počkat\n";
cin >> FightAkce;
switch (FightAkce){
case 1:
    if (StatyNepritel[0][5] == 1) {Dmg = Dmg + 4;}
    Attack(StatyNepritel[0][2],Dmg,StatyNepritel[0][0]);
    cout << "Zásah za " << poskozeni << " životy\n";
    cout << "Váš nepřítel má ještě: " << StatyNepritel[0][0] << " životů\n";
    pomocnapromena = 0;
    Schovan = 0;
    StatyNepritel[0][7] = 0;
    PouzAb++;
    break;
case 2:
    cout << " Inventář\n";
    Inventar();
    pomocnapromena = 0;
    break;
case 3:
    do{
    if (lvl >= 10){
    cout << " Na jaké pozici je schopnost kterou chceš použít? (0,1,2)\n";
    cin >> SchopnostLvl;
    }else if(lvl < 10 && lvl > 5){
    cout << " Na jaké pozici je schopnost kterou chceš použít? (0,1)\n";
    cin >> SchopnostLvl;
    if(SchopnostLvl < 0 || SchopnostLvl > 2){
        cout << "Neplatný výběr\n";
        pomocnapromena = 1;
    }else{
        pomocnapromena = 0;
    }
    }else{
    SchopnostLvl = 0;
    }
    }while(pomocnapromena == 1);
    switch (schopnosti[SchopnostiClass][SchopnostLvl]){
        case 1:
    cout << " Schopnost Zuřiví útok - Provede normální útok, Dmg = Dmg + 2";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    ZuriviUtok(AktEnergie, Dmg, StatyNepritel[0][2],StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    PouzAb++;
    break;
    }
    break;
        case 2:
    cout << " Schopnost Omračující útok - Provede normální útok, Omráčí nepřítele.";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    OmracUtok(AktEnergie, Dmg, StatyNepritel[0][2],StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    PouzAb++;
    break;
    }
    break;
        case 3:
    cout << " Schopnost Bojový Pokřik - Ublíží všem nepřátelům Síla + 5";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    BojovyPokrik(AktEnergie, Str,StatyNepritel[0][2],poskozeni);
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    PouzAb++;
    break;
    }
    break;
        case 4:
    cout << " Schopnost Magická střela - Provede normální útok, Dmg = Inteligence + 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
        MagickaStrela(AktMana, Int, StatyNepritel[0][2],StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    PouzAb++;
    break;
    }
    break;
        case 5:
    cout << " Schopnost Ohnivá koule - Ublíží všem nepřátelům za Inteligence + 3";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    OhnivaKoule(AktMana, Int, poskozeni, PocetEnemy);
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    PouzAb++;
    break;
    }
    break;
        case 6:
    cout << " Schopnost Dračí dech - Ublíží všem nepřátelům za Inteligence + 3, bez ohledu na obranu nepřítele";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    DraciDech(AktMana, Int, poskozeni);
    PouzAb++;
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 7:
    cout << " Schopnost Trnový šlahoun - Trnový šlahoun obmotá nepřítele, DoT 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    TrnovySlahoun(AktMana);
    PouzAb++;
    break;
    }
    break;
        case 8:
    cout << " Schopnost Dvojitá střela - provede dva útoky hned po sobě";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    DvojitaStrela();
    PouzAb++;
    break;
    }
    break;
        case 9:
    cout << " Schopnost Lovcovo znamení - Označí jednoho nepřítele, ubíráte mu více životů";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    LovcovoZnameni();
    PouzAb++;
    break;
    }
    break;
        case 10:
    cout << " Schopnost Zlomyslný výsměch - Provede normální útok, Dmg = Cha + 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    ZlomyslnyVysmech(AktMana, Cha, StatyNepritel[0][2],StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    PouzAb++;
    break;
    }
    break;
        case 11:
    cout << " Schopnost Omámení - Omámí nepřítele. Omámený nepřítel na vás nebude útočit, pokud vy nebudete útočit na něj";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    Omameni(AktMana, Cha);
    PouzAb++;
    break;
    }
    break;
        case 12:
    cout << " Schopnost Tanec boje - Poškození = Obratnost + charisma";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    TanecBoje(AktMana,Cha);
    PouzAb++;
    break;
    }
    break;
        case 13:
    cout << " Schopnost Schování - Schováte se";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    SchovaniSe();
    cout << "jste schovani\n";
    PouzAb++;
    break;
    }
    break;
        case 14:
    cout << " Schopnost Útok ze zálohy - pokud jste schovaní + 5 k útoku";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    UtokZeZalohy(Dmg, StatyNepritel[0][2], StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    PouzAb++;
    break;
    }
    break;
        case 15:
    cout << " Schopnost Mistr Jedu - pokud jste schovaní, můžete otrávit nepřítele (2 Poškození za kolo)";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    MistrJedu();
    PouzAb++;
    break;
    }
    break;
        default:
    cout << " Neplatny vyber\n";
    break;
    }
    break;
case 4:
    cout << " Čekáš, doplňuje se ti mana a energie\n";
    if (AktEnergie < MaxEnergie){AktEnergie++;}
    if (AktMana < MaxMana){AktMana++;}
    pomocnapromena = 0;
    break;
}
}while (pomocnapromena == 1);
if (StatyNepritel[0][8] >= 1){StatyNepritel[0][0] = StatyNepritel[0][0] - StatyNepritel[0][8];}
if(StatyNepritel[0][0] <= 0){
cout << "Gratuluji zabyl jsi " << NazevNepritelJedna << endl;
cout << "Ziskal jsi " << StatyNepritel[0][3] << " zkusenosti\n";
xp = xp + StatyNepritel[0][3];
if (lvl > 10 && xp >= 20) {cout << " Level Up\n"; LvlUp();}else if (lvl > 5 && xp >= 10) {cout << " Level Up\n"; LvlUp();}else if (xp >= 5){cout << " Level Up\n"; LvlUp();}
cout << "Našel jsi " << StatyNepritel[0][4] << " Zlatých\n";
Penize = Penize + StatyNepritel[0][4];
KonSouboje = 1;
}
}while (KonSouboje == 0);
}
void SoubojBoss(){
PocetEnemy = 1;
Schovan = 0;
StatyNepritel[0][8] = 0;
KonSouboje = 0;
cout << " Před vámi je " << NazevNepritelJedna << "\n";
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
}
do{
pomocnapromena = 1;
if(Schovan == 1){
cout << NazevNepritelJedna << " si vás nevšimne.\n";
}else if(StatyNepritel[0][7] > 0){
StatyNepritel[0][7]--;
cout << NazevNepritelJedna << " na vás nezaútočí.\n";
}else if(StatyNepritel[0][6] == 1){
cout << NazevNepritelJedna << " Je omráčen.\n";
}else{
cout << NazevNepritelJedna << " na vás zaútočí.\n";
Attack(Dex,StatyNepritel[0][1],AktHP);
cout << "Zásah za " << poskozeni << " životy\n";
cout << "Vaše aktualní životy jsou " << AktHP << "/" << MaxHP <<endl;
if (AktHP <= 0){
    cout << "Zemřel jsi.\n";
    exit(0);
}
}
do{
cout << " Co chcete dělat?\n 1 - Útok\n 2 - Inventář\n 3 - Speciální schopnosti\n 4 - Počkat\n";
cin >> FightAkce;
switch (FightAkce){
case 1:
    if (StatyNepritel[0][5] == 1) {Dmg = Dmg + 4;}
    Attack(StatyNepritel[0][2],Dmg,StatyNepritel[0][0]);
    cout << "Zásah za " << poskozeni << " životy\n";
    cout << "Váš nepřítel má ještě: " << StatyNepritel[0][0] << " životů\n";
    pomocnapromena = 0;
    Schovan = 0;
    StatyNepritel[0][7] = 0;
    break;
case 2:
    cout << " Inventář\n";
    Inventar();
    pomocnapromena = 0;
    break;
case 3:
    do{
    if (lvl >= 10){
    cout << " Na jaké pozici je schopnost kterou chceš použít? (0,1,2)\n";
    cin >> SchopnostLvl;
    }else if(lvl < 10 && lvl > 5){
    cout << " Na jaké pozici je schopnost kterou chceš použít? (0,1)\n";
    cin >> SchopnostLvl;
    if(SchopnostLvl < 0 || SchopnostLvl > 2){
        cout << "Neplatný výběr\n";
        pomocnapromena = 1;
    }else{
        pomocnapromena = 0;
    }
    }else{
    SchopnostLvl = 0;
    }
    }while(pomocnapromena == 1);
    switch (schopnosti[SchopnostiClass][SchopnostLvl]){
        case 1:
    cout << " Schopnost Zuřiví útok - Provede normální útok, Dmg = Dmg + 2";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    ZuriviUtok(AktEnergie, Dmg, StatyNepritel[0][2],StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 2:
    cout << " Schopnost Omračující útok - Provede normální útok, Omráčí nepřítele.";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    OmracUtok(AktEnergie, Dmg, StatyNepritel[0][2],StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 3:
    cout << " Schopnost Bojový Pokřik - Ublíží všem nepřátelům Síla + 5";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    BojovyPokrik(AktEnergie, Str,StatyNepritel[0][2],poskozeni);
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 4:
    cout << " Schopnost Magická střela - Provede normální útok, Dmg = Inteligence + 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
        MagickaStrela(AktMana, Int, StatyNepritel[0][2],StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 5:
    cout << " Schopnost Ohnivá koule - Ublíží všem nepřátelům za Inteligence + 3";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    OhnivaKoule(AktMana, Int, poskozeni, PocetEnemy);
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 6:
    cout << " Schopnost Dračí dech - Ublíží všem nepřátelům za Inteligence + 3, bez ohledu na obranu nepřítele";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    DraciDech(AktMana, Int, poskozeni);
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 7:
    cout << " Schopnost Trnový šlahoun - Trnový šlahoun obmotá nepřítele, DoT 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    TrnovySlahoun(AktMana);
    break;
    }
    break;
        case 8:
    cout << " Schopnost Dvojitá střela - provede dva útoky hned po sobě";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    DvojitaStrela();
    break;
    }
    break;
        case 9:
    cout << " Schopnost Lovcovo znamení - Označí jednoho nepřítele, ubíráte mu více životů";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    LovcovoZnameni();
    break;
    }
    break;
        case 10:
    cout << " Schopnost Zlomyslný výsměch - Provede normální útok, Dmg = Cha + 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    ZlomyslnyVysmech(AktMana, Cha, StatyNepritel[0][2],StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 11:
    cout << " Schopnost Omámení - Omámí nepřítele. Omámený nepřítel na vás nebude útočit, pokud vy nebudete útočit na něj";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    Omameni(AktMana, Cha);
    break;
    }
    break;
        case 12:
    cout << " Schopnost Tanec boje - Poškození = Obratnost + charisma";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    TanecBoje(AktMana,Cha);
    break;
    }
    break;
        case 13:
    cout << " Schopnost Schování - Schováte se";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    SchovaniSe();
    cout << "jste schovani\n";
    break;
    }
    break;
        case 14:
    cout << " Schopnost Útok ze zálohy - pokud jste schovaní + 5 k útoku";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    UtokZeZalohy(Dmg, StatyNepritel[0][2], StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 15:
    cout << " Schopnost Mistr Jedu - pokud jste schovaní, můžete otrávit nepřítele (2 Poškození za kolo)";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    MistrJedu();
    break;
    }
    break;
        default:
    cout << " Neplatny vyber\n";
    break;
    }
    break;
case 4:
    cout << " Čekáš, doplňuje se ti mana a energie\n";
    if (AktEnergie < MaxEnergie){AktEnergie++;}
    if (AktMana < MaxMana){AktMana++;}
    pomocnapromena = 0;
    break;
}
}while (pomocnapromena == 1);
if (StatyNepritel[0][8] >= 1){StatyNepritel[0][0] = StatyNepritel[0][0] - StatyNepritel[0][8];}
if(StatyNepritel[0][0] <= 0){
cout << "Gratuluji zabyl jsi " << NazevNepritelJedna << endl;
cout << "Ziskal jsi " << StatyNepritel[0][3] << " zkusenosti\n";
xp = xp + StatyNepritel[0][3];
if (lvl > 10 && xp >= 20) {cout << " Level Up\n"; LvlUp();}else if (lvl > 5 && xp >= 10) {cout << " Level Up\n"; LvlUp();}else if (xp >= 5){cout << " Level Up\n"; LvlUp();}
cout << "Našel jsi " << StatyNepritel[0][4] << " Zlatých\n";
Penize = Penize + StatyNepritel[0][4];
KonSouboje = 1;
}
}while (KonSouboje == 0);
}
void SoubojJedna(){
PocetEnemy = 1;
Schovan = 0;
StatyNepritel[0][8] = 0;
KonSouboje = 0;
cout << " Před vámi je " << NazevNepritelJedna << ", " << NazevNepritelDva << " a " << NazevNepritelTri << "\n";
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
cout << " Co chcete dělat?\n 1 - Útok\n 2 - Inventář\n 3 - Speciální schopnosti\n 4 - Počkat\n";
cin >> FightAkce;
switch (FightAkce){
case 1:
    if (StatyNepritel[0][5] == 1) {Dmg = Dmg + 4;}
    Attack(StatyNepritel[0][2],Dmg,StatyNepritel[0][0]);
    cout << "Zásah za " << poskozeni << " životy\n";
    cout << "Váš nepřítel má ještě: " << StatyNepritel[0][0] << " životů\n";
    pomocnapromena = 0;
    Schovan = 0;
    StatyNepritel[0][7] = 0;
    break;
case 2:
    cout << " Inventář\n";
    Inventar();
    pomocnapromena = 0;
    break;
case 3:
    do{
    if (lvl >= 10){
    cout << " Na jaké pozici je schopnost kterou chceš použít? (0,1,2)\n";
    cin >> SchopnostLvl;
    }else if(lvl < 10 && lvl > 5){
    cout << " Na jaké pozici je schopnost kterou chceš použít? (0,1)\n";
    cin >> SchopnostLvl;
    if(SchopnostLvl < 0 || SchopnostLvl > 2){
        cout << "Neplatný výběr\n";
        pomocnapromena = 1;
    }else{
        pomocnapromena = 0;
    }
    }else{
    SchopnostLvl = 0;
    }
    }while(pomocnapromena == 1);
    switch (schopnosti[SchopnostiClass][SchopnostLvl]){
        case 1:
    cout << " Schopnost Zuřiví útok - Provede normální útok, Dmg = Dmg + 2";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    ZuriviUtok(AktEnergie, Dmg, StatyNepritel[0][2],StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 2:
    cout << " Schopnost Omračující útok - Provede normální útok, Omráčí nepřítele.";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    OmracUtok(AktEnergie, Dmg, StatyNepritel[0][2],StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 3:
    cout << " Schopnost Bojový Pokřik - Ublíží všem nepřátelům Síla + 5";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    BojovyPokrik(AktEnergie, Str,StatyNepritel[0][2],poskozeni);
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 4:
    cout << " Schopnost Magická střela - Provede normální útok, Dmg = Inteligence + 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
        MagickaStrela(AktMana, Int, StatyNepritel[0][2],StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 5:
    cout << " Schopnost Ohnivá koule - Ublíží všem nepřátelům za Inteligence + 3";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    OhnivaKoule(AktMana, Int, poskozeni, PocetEnemy);
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 6:
    cout << " Schopnost Dračí dech - Ublíží všem nepřátelům za Inteligence + 3, bez ohledu na obranu nepřítele";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    DraciDech(AktMana, Int, poskozeni);
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 7:
    cout << " Schopnost Trnový šlahoun - Trnový šlahoun obmotá nepřítele, DoT 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    TrnovySlahoun(AktMana);
    break;
    }
    break;
        case 8:
    cout << " Schopnost Dvojitá střela - provede dva útoky hned po sobě";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    DvojitaStrela();
    break;
    }
    break;
        case 9:
    cout << " Schopnost Lovcovo znamení - Označí jednoho nepřítele, ubíráte mu více životů";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    LovcovoZnameni();
    break;
    }
    break;
        case 10:
    cout << " Schopnost Zlomyslný výsměch - Provede normální útok, Dmg = Cha + 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    ZlomyslnyVysmech(AktMana, Cha, StatyNepritel[0][2],StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 11:
    cout << " Schopnost Omámení - Omámí nepřítele. Omámený nepřítel na vás nebude útočit, pokud vy nebudete útočit na něj";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    Omameni(AktMana, Cha);
    break;
    }
    break;
        case 12:
    cout << " Schopnost Tanec boje - Poškození = Obratnost + charisma";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    TanecBoje(AktMana,Cha);
    break;
    }
    break;
        case 13:
    cout << " Schopnost Schování - Schováte se";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    SchovaniSe();
    cout << "jste schovani\n";
    break;
    }
    break;
        case 14:
    cout << " Schopnost Útok ze zálohy - pokud jste schovaní + 5 k útoku";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    UtokZeZalohy(Dmg, StatyNepritel[0][2], StatyNepritel[0][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    break;
    }
    break;
        case 15:
    cout << " Schopnost Mistr Jedu - pokud jste schovaní, můžete otrávit nepřítele (2 Poškození za kolo)";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    MistrJedu();
    break;
    }
    break;
        default:
    cout << " Neplatny vyber\n";
    break;
    }
    break;
case 4:
    cout << " Čekáš, doplňuje se ti mana a energie\n";
    if (AktEnergie < MaxEnergie){AktEnergie++;}
    if (AktMana < MaxMana){AktMana++;}
    pomocnapromena = 0;
    break;
}
}while (pomocnapromena == 1);
if (StatyNepritel[0][8] >= 1){StatyNepritel[0][0] = StatyNepritel[0][0] - StatyNepritel[0][8];}
if(StatyNepritel[0][0] <= 0){
cout << "Gratuluji zabyl jsi " << NazevNepritelJedna << endl;
cout << "Ziskal jsi " << StatyNepritel[0][3] << " zkusenosti\n";
xp = xp + StatyNepritel[0][3];
if (lvl > 10 && xp >= 20) {cout << " Level Up\n"; LvlUp();}else if (lvl > 5 && xp >= 10) {cout << " Level Up\n"; LvlUp();}else if (xp >= 5){cout << " Level Up\n"; LvlUp();}
srand(time(0));
int NahodOdm = rand() % 2 + 1;
if(NahodOdm == 1){
cout << "Našel jsi " << StatyNepritel[0][4] << " Zlatých\n";
Penize = Penize + StatyNepritel[0][4];}
KonSouboje = 1;
}else{
if(Schovan == 1){
cout << NazevNepritelJedna << " si vás nevšimne.\n";
}else if(StatyNepritel[0][7] > 0){
StatyNepritel[0][7]--;
cout << NazevNepritelJedna << " na vás nezaútočí.\n";
}else if(StatyNepritel[0][6] == 1){
cout << NazevNepritelJedna << " Je omráčen.\n";
}else{
cout << NazevNepritelJedna << " na vás zaútočí.\n";
Attack(Dex,StatyNepritel[0][1],AktHP);
cout << "Zásah za " << poskozeni << " životy\n";
cout << "Vaše aktualní životy jsou " << AktHP << "/" << MaxHP <<endl;
if (AktHP <= 0){
    cout << "Zemřel jsi.\n";
    exit(0);
    KonSouboje = 1;
}
}
}
}while (KonSouboje == 0);
}
}
void SoubojDva(){
PocetEnemy = 2;
Schovan = 0;
StatyNepritel[0][8] = 0;
StatyNepritel[1][8] = 0;
KonSouboje = 0;
cout << " Před vámi je " << NazevNepritelJedna << " a " << NazevNepritelDva << endl;
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
}
if (schopnosti[SchopnostiClass][0] == 16){
Monstrum();}
if (KonSouboje == 1){
}else{
do{
pomocnapromena = 1;
do{
cout << " Co chcete dělat?\n 1 - Útok\n 2 - Inventář\n 3 - Speciální schopnosti\n 4 - Počkat\n";
cin >> FightAkce;
switch (FightAkce){
case 1:
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva <<endl;
    cin >> target;
    target--;
    if (StatyNepritel[target][5] == 1) {Dmg = Dmg + 4;}
    Attack(StatyNepritel[target][2],Dmg,StatyNepritel[target][0]);
    cout << "Zásah za " << poskozeni << " životy\n";
    cout << "Váš nepřítel má ještě: " << StatyNepritel[target][0] << " životů\n";
    pomocnapromena = 0;
    Schovan = 0;
    StatyNepritel[target][7] = 0;
    break;
case 2:
    cout << " Inventář\n";
    Inventar();
    pomocnapromena = 0;
    break;
case 3:
    do{
    if (lvl >= 10){
    cout << " Na jaké pozici je schopnost kterou chceš použít? (0,1,2)\n";
    cin >> SchopnostLvl;
    }else if(lvl < 10 && lvl > 5){
    cout << " Na jaké pozici je schopnost kterou chceš použít? (0,1)\n";
    cin >> SchopnostLvl;
    if(SchopnostLvl < 0 || SchopnostLvl > 2){
        cout << "Neplatný výběr\n";
        pomocnapromena = 1;
    }else{
        pomocnapromena = 0;
    }
    }else{
    SchopnostLvl = 0;
    }
    }while(pomocnapromena == 1);
    switch (schopnosti[SchopnostiClass][SchopnostLvl]){
        case 1:
    cout << " Schopnost Zuřiví útok - Provede normální útok, Dmg = Dmg + 2";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva <<endl;
    cin >> target;
    target--;
    ZuriviUtok(AktEnergie, Dmg, StatyNepritel[target][2],StatyNepritel[target][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[target][0] << " zivotu\n";
    break;
    }
    break;
        case 2:
    cout << " Schopnost Omračující útok - Provede normální útok, Omráčí nepřítele.";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva <<endl;
    cin >> target;
    target--;
    OmracUtok(AktEnergie, Dmg, StatyNepritel[target][2],StatyNepritel[target][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[target][0] << " zivotu\n";
    break;
    }
    break;
        case 3:
    cout << " Schopnost Bojový Pokřik - Ublíží všem nepřátelům Síla + 5";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    BojovyPokrik(AktEnergie, Str,StatyNepritel[0][2],poskozeni);
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    StatyNepritel[1][0] = StatyNepritel[1][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Nepritel 1 ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    cout << "Nepritel 2 ma jeste: " << StatyNepritel[1][0] << " zivotu\n";
    break;
    }
    break;
        case 4:
    cout << " Schopnost Magická střela - Provede normální útok, Dmg = Inteligence + 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva <<endl;
    cin >> target;
    target--;
        MagickaStrela(AktMana, Int, StatyNepritel[target][2],StatyNepritel[target][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[target][0] << " zivotu\n";
    break;
    }
    break;
        case 5:
    cout << " Schopnost Ohnivá koule - Ublíží všem nepřátelům za Inteligence + 3";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    OhnivaKoule(AktMana, Int, poskozeni, PocetEnemy);
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    StatyNepritel[1][0] = StatyNepritel[1][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Nepritel 1 ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    cout << "Nepritel 2 ma jeste: " << StatyNepritel[1][0] << " zivotu\n";
    break;
    }
    break;
        case 6:
    cout << " Schopnost Dračí dech - Ublíží všem nepřátelům za Inteligence + 3, bez ohledu na obranu nepřítele";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    DraciDech(AktMana, Int, poskozeni);
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    StatyNepritel[1][0] = StatyNepritel[1][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Nepritel 1 ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    cout << "Nepritel 2 ma jeste: " << StatyNepritel[1][0] << " zivotu\n";
    break;
    }
    break;
        case 7:
    cout << " Schopnost Trnový šlahoun - Trnový šlahoun obmotá nepřítele, DoT 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    TrnovySlahoun(AktMana);
    break;
    }
    break;
        case 8:
    cout << " Schopnost Dvojitá střela - provede dva útoky hned po sobě";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    DvojitaStrela();
    break;
    }
    break;
        case 9:
    cout << " Schopnost Lovcovo znamení - Označí jednoho nepřítele, ubíráte mu více životů";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    LovcovoZnameni();
    break;
    }
    break;
        case 10:
    cout << " Schopnost Zlomyslný výsměch - Provede normální útok, Dmg = Cha + 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva <<endl;
    cin >> target;
    target--;
    ZlomyslnyVysmech(AktMana, Cha, StatyNepritel[target][2],StatyNepritel[target][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[target][0] << " zivotu\n";
    break;
    }
    break;
        case 11:
    cout << " Schopnost Omámení - Omámí nepřítele. Omámený nepřítel na vás nebude útočit, pokud vy nebudete útočit na něj";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    Omameni(AktMana, Cha);
    break;
    }
    break;
        case 12:
    cout << " Schopnost Tanec boje - Poškození = Obratnost + charisma";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    TanecBoje(AktMana,Cha);
    break;
    }
    break;
        case 13:
    cout << " Schopnost Schování - Schováte se";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    SchovaniSe();
    cout << "jste schovani\n";
    break;
    }
    break;
        case 14:
    cout << " Schopnost Útok ze zálohy - pokud jste schovaní + 5 k útoku";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva <<endl;
    cin >> target;
    target--;
    UtokZeZalohy(Dmg, StatyNepritel[target][2], StatyNepritel[target][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[target][0] << " zivotu\n";
    break;
    }
    break;
        case 15:
    cout << " Schopnost Mistr Jedu - pokud jste schovaní, můžete otrávit nepřítele (2 Poškození za kolo)";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    MistrJedu();
    break;
    }
    break;
        default:
    cout << " Neplatny vyber\n";
    break;
    }
    break;
case 4:
    cout << " Čekáš, doplňuje se ti mana a energie\n";
    if (AktEnergie < MaxEnergie){AktEnergie++;}
    if (AktMana < MaxMana){AktMana++;}
    pomocnapromena = 0;
    break;
}
}while (pomocnapromena == 1);
if (StatyNepritel[0][8] >= 1){StatyNepritel[0][0] = StatyNepritel[0][0] - StatyNepritel[0][8];}
if (StatyNepritel[1][8] >= 1){StatyNepritel[1][0] = StatyNepritel[1][0] - StatyNepritel[1][8];}
if(StatyNepritel[0][0] <= 0){
int y = 0;
if (y == 0){
y = 1;
PocetEnemy--;
cout << "Gratuluji zabyl jsi " << NazevNepritelJedna << endl;
cout << "Ziskal jsi " << StatyNepritel[0][3] << " zkusenosti\n";
xp = xp + StatyNepritel[0][3];
if (lvl > 10 && xp >= 20) {cout << " Level Up\n"; LvlUp();}else if (lvl > 5 && xp >= 10) {cout << " Level Up\n"; LvlUp();}else if (xp >= 5){cout << " Level Up\n"; LvlUp();}
srand(time(0));
int NahodOdm = rand() % 2 + 1;
if(NahodOdm == 1){
cout << "Našel jsi " << StatyNepritel[0][4] << " Zlatých\n";
Penize = Penize + StatyNepritel[0][4];}
}else{}
}else{
if(Schovan == 1){
cout << NazevNepritelJedna << " si vás nevšimne.\n";
}else if(StatyNepritel[0][7] > 0){
StatyNepritel[0][7]--;
cout << NazevNepritelJedna << " na vás nezaútočí.\n";
}else if(StatyNepritel[0][6] == 1){
cout << NazevNepritelJedna << " Je omráčen.\n";
}else{
cout << NazevNepritelJedna << " na vás zaútočí.\n";
Attack(Dex,StatyNepritel[0][1],AktHP);
cout << "Zásah za " << poskozeni << " životy\n";
cout << "Vaše aktualní životy jsou " << AktHP << "/" << MaxHP <<endl;
if (AktHP <= 0){
    cout << "Zemřel jsi.\n";
    exit(0);
    KonSouboje = 1;
}
}
}
if(StatyNepritel[1][0] <= 0){
int y = 0;
if (y == 0){
y = 1;
PocetEnemy--;
cout << "Gratuluji zabyl jsi " << NazevNepritelDva << endl;
cout << "Získal jsi " << StatyNepritel[1][3] << " zkušeností\n";
xp = xp + StatyNepritel[1][3];
if (lvl > 10 && xp >= 20) {cout << " Level Up\n"; LvlUp();}else if (lvl > 5 && xp >= 10) {cout << " Level Up\n"; LvlUp();}else if (xp >= 5){cout << " Level Up\n"; LvlUp();}
srand(time(0));
int NahodOdm = rand() % 2 + 1;
if(NahodOdm == 1){
cout << "Našel jsi " << StatyNepritel[1][4] << " Zlatých\n";
Penize = Penize + StatyNepritel[1][4];}
}else{}
}else{
if(Schovan == 1){
cout << NazevNepritelDva << " si vás nevšimne.\n";
}else if(StatyNepritel[1][7] > 0){
StatyNepritel[1][7]--;
cout << NazevNepritelDva << " na vás nezaútočí.\n";
}else if(StatyNepritel[1][6] == 1){
cout << NazevNepritelDva << " Je omráčen.\n";
}else{
cout << NazevNepritelDva << " na vás zaútočí.\n";
Attack(Dex,StatyNepritel[1][1],AktHP);
cout << "Zásah za " << poskozeni << " životy\n";
cout << "Vaše aktualní životy jsou " << AktHP << "/" << MaxHP <<endl;
if (AktHP <= 0){
    cout << "Zemřel jsi.\n";
    exit(0);
    KonSouboje = 1;
}
}
}
if (PocetEnemy == 0){KonSouboje = 1;}
}while (KonSouboje == 0);
}
}
void SoubojTri(){
PocetEnemy = 3;
Schovan = 0;
StatyNepritel[0][8] = 0;
StatyNepritel[1][8] = 0;
StatyNepritel[2][8] = 0;
KonSouboje = 0;
cout << " Před vámi je " << NazevNepritelJedna << " a " << NazevNepritelDva << endl;
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
}
if (schopnosti[SchopnostiClass][0] == 16){
Monstrum();}
if (KonSouboje == 1){
}else{
do{
pomocnapromena = 1;
do{
cout << " Co chcete dělat?\n 1 - Útok\n 2 - Inventář\n 3 - Speciální schopnosti\n 4 - Počkat\n";
cin >> FightAkce;
switch (FightAkce){
case 1:
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva << "\n 3 - " << NazevNepritelTri <<endl;
    cin >> target;
    target--;
    if (StatyNepritel[target][5] == 1) {Dmg = Dmg + 4;}
    Attack(StatyNepritel[target][2],Dmg,StatyNepritel[target][0]);
    cout << "Zásah za " << poskozeni << " životy\n";
    cout << "Váš nepřítel má ještě: " << StatyNepritel[target][0] << " životů\n";
    pomocnapromena = 0;
    Schovan = 0;
    StatyNepritel[target][7] = 0;
    break;
case 2:
    cout << " Inventář\n";
    Inventar();
    pomocnapromena = 0;
    break;
case 3:
    do{
    if (lvl >= 10){
    cout << " Na jaké pozici je schopnost kterou chceš použít? (0,1,2)\n";
    cin >> SchopnostLvl;
    }else if(lvl < 10 && lvl > 5){
    cout << " Na jaké pozici je schopnost kterou chceš použít? (0,1)\n";
    cin >> SchopnostLvl;
    if(SchopnostLvl < 0 || SchopnostLvl > 2){
        cout << "Neplatný výběr\n";
        pomocnapromena = 1;
    }else{
        pomocnapromena = 0;
    }
    }else{
    SchopnostLvl = 0;
    }
    }while(pomocnapromena == 1);
    switch (schopnosti[SchopnostiClass][SchopnostLvl]){
        case 1:
    cout << " Schopnost Zuřiví útok - Provede normální útok, Dmg = Dmg + 2";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva << "\n 3 - " << NazevNepritelTri <<endl;
    cin >> target;
    target--;
    ZuriviUtok(AktEnergie, Dmg, StatyNepritel[target][2],StatyNepritel[target][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[target][0] << " zivotu\n";
    break;
    }
    break;
        case 2:
    cout << " Schopnost Omračující útok - Provede normální útok, Omráčí nepřítele.";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva << "\n 3 - " << NazevNepritelTri <<endl;
    cin >> target;
    target--;
    OmracUtok(AktEnergie, Dmg, StatyNepritel[target][2],StatyNepritel[target][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[target][0] << " zivotu\n";
    break;
    }
    break;
        case 3:
    cout << " Schopnost Bojový Pokřik - Ublíží všem nepřátelům Síla + 5";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    BojovyPokrik(AktEnergie, Str,StatyNepritel[0][2],poskozeni);
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    StatyNepritel[1][0] = StatyNepritel[1][0] - poskozeni;
    StatyNepritel[2][0] = StatyNepritel[2][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Nepritel 1 ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    cout << "Nepritel 2 ma jeste: " << StatyNepritel[1][0] << " zivotu\n";
    cout << "Nepritel 3 ma jeste: " << StatyNepritel[2][0] << " zivotu\n";
    break;
    }
    break;
        case 4:
    cout << " Schopnost Magická střela - Provede normální útok, Dmg = Inteligence + 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva << "\n 3 - " << NazevNepritelTri <<endl;
    cin >> target;
    target--;
        MagickaStrela(AktMana, Int, StatyNepritel[target][2],StatyNepritel[target][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[target][0] << " zivotu\n";
    break;
    }
    break;
        case 5:
    cout << " Schopnost Ohnivá koule - Ublíží všem nepřátelům za Inteligence + 3";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    OhnivaKoule(AktMana, Int, poskozeni, PocetEnemy);
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    StatyNepritel[1][0] = StatyNepritel[1][0] - poskozeni;
    StatyNepritel[2][0] = StatyNepritel[2][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Nepritel 1 ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    cout << "Nepritel 2 ma jeste: " << StatyNepritel[1][0] << " zivotu\n";
    cout << "Nepritel 3 ma jeste: " << StatyNepritel[2][0] << " zivotu\n";
    break;
    }
    break;
        case 6:
    cout << " Schopnost Dračí dech - Ublíží všem nepřátelům za Inteligence + 3, bez ohledu na obranu nepřítele";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    DraciDech(AktMana, Int, poskozeni);
    StatyNepritel[0][0] = StatyNepritel[0][0] - poskozeni;
    StatyNepritel[1][0] = StatyNepritel[1][0] - poskozeni;
    StatyNepritel[2][0] = StatyNepritel[2][0] - poskozeni;
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Nepritel 1 ma jeste: " << StatyNepritel[0][0] << " zivotu\n";
    cout << "Nepritel 2 ma jeste: " << StatyNepritel[1][0] << " zivotu\n";
    cout << "Nepritel 3 ma jeste: " << StatyNepritel[2][0] << " zivotu\n";
    break;
    }
    break;
        case 7:
    cout << " Schopnost Trnový šlahoun - Trnový šlahoun obmotá nepřítele, DoT 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    TrnovySlahoun(AktMana);
    break;
    }
    break;
        case 8:
    cout << " Schopnost Dvojitá střela - provede dva útoky hned po sobě";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    DvojitaStrela();
    break;
    }
    break;
        case 9:
    cout << " Schopnost Lovcovo znamení - Označí jednoho nepřítele, ubíráte mu více životů";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    LovcovoZnameni();
    break;
    }
    break;
        case 10:
    cout << " Schopnost Zlomyslný výsměch - Provede normální útok, Dmg = Cha + 1";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva << "\n 3 - " << NazevNepritelTri <<endl;
    cin >> target;
    target--;
    ZlomyslnyVysmech(AktMana, Cha, StatyNepritel[target][2],StatyNepritel[target][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[target][0] << " zivotu\n";
    break;
    }
    break;
        case 11:
    cout << " Schopnost Omámení - Omámí nepřítele. Omámený nepřítel na vás nebude útočit, pokud vy nebudete útočit na něj";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    Omameni(AktMana, Cha);
    break;
    }
    break;
        case 12:
    cout << " Schopnost Tanec boje - Poškození = Obratnost + charisma";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    TanecBoje(AktMana,Cha);
    break;
    }
    break;
        case 13:
    cout << " Schopnost Schování - Schováte se";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    SchovaniSe();
    cout << "jste schovani\n";
    break;
    }
    break;
        case 14:
    cout << " Schopnost Útok ze zálohy - pokud jste schovaní + 5 k útoku";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    cout << "Na kterého nepřítele chcete zaútočit?\n 1 - " << NazevNepritelJedna << "\n 2 - " << NazevNepritelDva << "\n 3 - " << NazevNepritelTri <<endl;
    cin >> target;
    target--;
    UtokZeZalohy(Dmg, StatyNepritel[target][2], StatyNepritel[target][0]);
    cout << "Zasah za " << poskozeni << " zivoty\n";
    cout << "Vas nepritel ma jeste: " << StatyNepritel[target][0] << " zivotu\n";
    break;
    }
    break;
        case 15:
    cout << " Schopnost Mistr Jedu - pokud jste schovaní, můžete otrávit nepřítele (2 Poškození za kolo)";
    cout << " Chceš tuto schopnost použít? (1 - Ano, 2 - Ne)\n";
    cin >> anone;
    switch (anone){
    case 1:
    MistrJedu();
    break;
    }
    break;
        default:
    cout << " Neplatny vyber\n";
    break;
    }
    break;
case 4:
    cout << " Čekáš, doplňuje se ti mana a energie\n";
    if (AktEnergie < MaxEnergie){AktEnergie++;}
    if (AktMana < MaxMana){AktMana++;}
    pomocnapromena = 0;
    break;
}
}while (pomocnapromena == 1);
if (StatyNepritel[0][8] >= 1){StatyNepritel[0][0] = StatyNepritel[0][0] - StatyNepritel[0][8];}
if (StatyNepritel[1][8] >= 1){StatyNepritel[1][0] = StatyNepritel[1][0] - StatyNepritel[1][8];}
if (StatyNepritel[2][8] >= 1){StatyNepritel[2][0] = StatyNepritel[2][0] - StatyNepritel[2][8];}
if(StatyNepritel[0][0] <= 0){
int y = 0;
if (y == 0){
y = 1;
PocetEnemy--;
cout << "Gratuluji zabyl jsi " << NazevNepritelJedna << endl;
cout << "Ziskal jsi " << StatyNepritel[0][3] << " zkusenosti\n";
xp = xp + StatyNepritel[0][3];
if (lvl > 10 && xp >= 20) {cout << " Level Up\n"; LvlUp();}else if (lvl > 5 && xp >= 10) {cout << " Level Up\n"; LvlUp();}else if (xp >= 5){cout << " Level Up\n"; LvlUp();}
srand(time(0));
int NahodOdm = rand() % 2 + 1;
if(NahodOdm == 1){
cout << "Našel jsi " << StatyNepritel[0][4] << " Zlatých\n";
Penize = Penize + StatyNepritel[0][4];}
}else{}
}else{
if(Schovan == 1){
cout << NazevNepritelJedna << " si vás nevšimne.\n";
}else if(StatyNepritel[0][7] > 0){
StatyNepritel[0][7]--;
cout << NazevNepritelJedna << " na vás nezaútočí.\n";
}else if(StatyNepritel[0][6] == 1){
cout << NazevNepritelJedna << " Je omráčen.\n";
}else{
cout << NazevNepritelJedna << " na vás zaútočí.\n";
Attack(Dex,StatyNepritel[0][1],AktHP);
cout << "Zásah za " << poskozeni << " životy\n";
cout << "Vaše aktualní životy jsou " << AktHP << "/" << MaxHP <<endl;
if (AktHP <= 0){
    cout << "Zemřel jsi.\n";
    exit(0);
    KonSouboje = 1;
}
}
}
if(StatyNepritel[1][0] <= 0){
int y = 0;
if (y == 0){
y = 1;
PocetEnemy--;
cout << "Gratuluji zabyl jsi " << NazevNepritelDva << endl;
cout << "Získal jsi " << StatyNepritel[1][3] << " zkušeností\n";
xp = xp + StatyNepritel[1][3];
if (lvl > 10 && xp >= 20) {cout << " Level Up\n"; LvlUp();}else if (lvl > 5 && xp >= 10) {cout << " Level Up\n"; LvlUp();}else if (xp >= 5){cout << " Level Up\n"; LvlUp();}
srand(time(0));
int NahodOdm = rand() % 2 + 1;
if(NahodOdm == 1){
cout << "Našel jsi " << StatyNepritel[1][4] << " Zlatých\n";
Penize = Penize + StatyNepritel[1][4];}
}else{}
}else{
if(Schovan == 1){
cout << NazevNepritelDva << " si vás nevšimne.\n";
}else if(StatyNepritel[1][7] > 0){
StatyNepritel[1][7]--;
cout << NazevNepritelDva << " na vás nezaútočí.\n";
}else if(StatyNepritel[1][6] == 1){
cout << NazevNepritelDva << " Je omráčen.\n";
}else{
cout << NazevNepritelDva << " na vás zaútočí.\n";
Attack(Dex,StatyNepritel[1][1],AktHP);
cout << "Zásah za " << poskozeni << " životy\n";
cout << "Vaše aktualní životy jsou " << AktHP << "/" << MaxHP <<endl;
if (AktHP <= 0){
    cout << "Zemřel jsi.\n";
    exit(0);
    KonSouboje = 1;
}
}if(StatyNepritel[2][0] <= 0){
int y = 0;
if (y == 0){
y = 1;
PocetEnemy--;
cout << "Gratuluji zabyl jsi " << NazevNepritelDva << endl;
cout << "Získal jsi " << StatyNepritel[2][3] << " zkušeností\n";
xp = xp + StatyNepritel[2][3];
if (lvl > 10 && xp >= 20) {cout << " Level Up\n"; LvlUp();}else if (lvl > 5 && xp >= 10) {cout << " Level Up\n"; LvlUp();}else if (xp >= 5){cout << " Level Up\n"; LvlUp();}
srand(time(0));
int NahodOdm = rand() % 2 + 1;
if(NahodOdm == 1){
cout << "Našel jsi " << StatyNepritel[2][4] << " Zlatých\n";
Penize = Penize + StatyNepritel[2][4];}
}else{}
}else{
if(Schovan == 1){
cout << NazevNepritelDva << " si vás nevšimne.\n";
}else if(StatyNepritel[2][7] > 0){
StatyNepritel[2][7]--;
cout << NazevNepritelDva << " na vás nezaútočí.\n";
}else if(StatyNepritel[2][6] == 1){
cout << NazevNepritelDva << " Je omráčen.\n";
}else{
cout << NazevNepritelDva << " na vás zaútočí.\n";
Attack(Dex,StatyNepritel[2][1],AktHP);
cout << "Zásah za " << poskozeni << " životy\n";
cout << "Vaše aktualní životy jsou " << AktHP << "/" << MaxHP <<endl;
if (AktHP <= 0){
    cout << "Zemřel jsi.\n";
    exit(0);
    KonSouboje = 1;
}
}
}
if (PocetEnemy == 0){KonSouboje = 1;}
}while (KonSouboje == 0);
}while(KonSouboje == 1);
}
}
int main(){
    SetConsoleOutputCP(CP_UTF8);
josef = 1;
int Karel = 0;
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
    Podminka = 1;
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
    cout << "Jste si jisti svím výběrem? 1 - Ano 2 - Ne\n";
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
    cout << "Neplatný výběr";
    break;
    }

}while (Karel == 0);
    cout << "_______________________________________________________________________________________________________________________";
    cout  << endl << endl;
    cout << " Probouzíte se v šedé kamenné místnosti. Uprostřed místnosti hoří malý oheň, který ji slabě osvětluje. Na druhém konci místnosti vidíte dveře, za kterými něco vydává škrábavé zvuky.\n"; //pouzito AI pro opravení chyb v již napsaném textu
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
            Krysa(StatyNepritel[0][0],StatyNepritel[0][1],StatyNepritel[0][2],NazevNepritelJedna,StatyNepritel[0][3],StatyNepritel[0][4]);
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
    cout << " Zůstáváte sedět na zemi... zem je tvrdá a studená, zjevně kámen.\n";
    break;
case 3:
    cout << " Snažíte se přemýšlet nad tím jak jste se sem dostali a proč tu vlastně jste.\n Jak tak přemýšlíte zjistíte že nejste schopni vzpomenout si na vaše jméno\n\n Zadejte jak se budete jmenovat: ";
    cin.ignore(); //Rada od umělé inteligence. Řeší problém s tím, že mi nešlo zapsat nové jméno přes getline.
    getline(cin, jmeno);
    cout << "vase jmeno je " << jmeno <<endl;
    break;
default:
    cout << " Neplatný výběr.";
    break;
}
}while (placeholder == 0);
cout << " Porazili jste krysu, Jediná cesta dál je schodiště.\n";
    cout << " Pokračujete dál po schodech. Jakmile dorazíte nahoru, všimnete si dveří, z pod kterých svítí příjemná žlutá záře. Otevíráte dveře.\n";
    do{
    placeholder = 0;
    cout << " Za dveřmi je středně velká místnost osvětlená loučemi, na protější straně leží sýr... co chcete delat?\n\n 1 - Jít k sýru a prosokumat ho\n 2 - Vrátit se po schodech dolů\n 3 - Zůstat stát\n 4 - Jít ke dveřím na druhé straně místnosti\n";
    cin >> akce;
    switch (akce){
    case 1:
        cout << " Prozkoumáváš sír, zatím co koukáš na sír nevšimneš si krysi, která na tebe zaútočí.";
        Krysa(StatyNepritel[0][0],StatyNepritel[0][1],StatyNepritel[0][2],NazevNepritelJedna,StatyNepritel[0][3],StatyNepritel[0][4]);
        SoubojJedna();
        placeholder = 1;
        break;
    case 2:
        cout << " Vrátíš se po schodech dolů, mrtvola krysi leží dole na schodišti. co chceš dělat? \n 1 - Vrátit se po schodech nahoru \n 2 - Pohřbít krysu \n 3 - Vrátit se k ohni\n";
        cin >> akce;
        switch (akce){
        case 1:
            break;
        case 2:
            cout << " Z kamínků a dalších malích předmětů, co jsi našel ležet po místonsti, jsi zhotovil malou mohylu co chceš dělat dál? ";
            break;
        case 3:
            cout << " Vrátili jste se k ohni, příjemná záře ohně vám doplní energii, manu a životy.\n";
            FullHeal();
            AktEnergie = MaxEnergie;
            AktMana = MaxMana;
            break;
        default:
            cout << " Neplatný výběr.\n";
            break;
}
cout << "Vracíš se po schodech nahoru\n";
break;
    case 3:
        cout << " Stojíte\n";
        break;
    case 4:
        cout << " Jdete ke dveřím na druhé straně místnosti. Dveře jsou zamčené.\n Zaútočí na vás krysa\n";
        Krysa(StatyNepritel[0][0],StatyNepritel[0][1],StatyNepritel[0][2],NazevNepritelJedna,StatyNepritel[0][3],StatyNepritel[0][4]);
        SoubojJedna();
        placeholder = 1;
        break;
}
}while (placeholder == 0);
cout << " Slyšíte cvaknutí v zámku dveří. za dveřmi je schodiště.\n na schodišti jsou dvě krysy\n";
Krysa(StatyNepritel[0][0],StatyNepritel[0][1],StatyNepritel[0][2],NazevNepritelJedna,StatyNepritel[0][3],StatyNepritel[0][4]);
Krysa(StatyNepritel[1][0],StatyNepritel[1][1],StatyNepritel[1][2],NazevNepritelDva,StatyNepritel[1][3],StatyNepritel[1][4]);
SoubojDva();
cout << " Porazili jste krysy. Pokračujete dál cestou po schodech.\n Dorazíte k velkým zdobeným dveřím. Když je otevřete slyšíte ?:''tsss tsss Čichám nějakého člověka''.\n";
cout << " Za dveřmi je Velká kamenná místnost. Na protější straně místnosti jsou poškrábané dveře.\n Na trůnu sedí obrovská krysa se zlatou korunkou na hlavě.\n Krysí Král: ''Co tu děláš?''\n Krysí král na vás zaútočí.";
KrysiKral(StatyNepritel[0][0],StatyNepritel[0][1],StatyNepritel[0][2],NazevNepritelJedna,StatyNepritel[0][3],StatyNepritel[0][4]);
SoubojBoss();
cout << " Porazil jsi Krysího krále. Jeho koruna leží u vašich nohou. \n Pokračujete dál. Za dveřmi vidíte malou chodbu vedoucí nahoru. ?:''psst hej, ty ... Nechceš se podívat na moje zboží?''\n Když se podíváš odkud vede hlas všimneš si malé myšky, která stojí za stánkem zhotoveným z pár dřívek a hadrů.\n";
Shop();
cout << " Myší obchodník: ''Naschledanou " << jmeno << endl;
cout << " Rozloučíš se s malou myškou a pokračuješ chodbou dál.\n Jakmile dorazíš na konec chodby ucítíš čerství vzduch, vcházíš do PŘÍZEMÍ VĚŽE... Gratuluji.\n V místnosti kde se nacházíš jsou zabarikádovná okna a všímáš si hromádek odpadků poházených po zemi.\n Když pokračuješ dál slyšíš lehké chchotání.\n Rychle se otočíš a všimneš si malého goblina, který se ti snaží ukrást peníze.\n";
Goblin(StatyNepritel[0][0],StatyNepritel[0][1],StatyNepritel[0][2],NazevNepritelJedna,StatyNepritel[0][3],StatyNepritel[0][4]);
SoubojJedna();
cout << " Porazil jsi goblina. Pokračuješ dál ve své cestě.\n Cestou chodbami si začínáte všímat více odpadků až vejdete do obrovské místnosti, všímáte si mnoha pokřivených domů, z jejichž oken na vás koukají malé růžové postavy.\n Postava1: ''Hej Nevíš kdo je ttámhleten?'' Postava2: ''Nevypada že by sem patřil...''. Obě postavy běží vaším směrem.\n";
Goblin(StatyNepritel[0][0],StatyNepritel[0][1],StatyNepritel[0][2],NazevNepritelJedna,StatyNepritel[0][3],StatyNepritel[0][4]);
Goblin(StatyNepritel[1][0],StatyNepritel[1][1],StatyNepritel[1][2],NazevNepritelDva,StatyNepritel[1][3],StatyNepritel[1][4]);
SoubojDva();
cout << " Po souboji si vás všimnou další dva goblini. Goblin3: ''HEJ ZABIL KARLA A ADAMA. NANĚJJJJ!!!''\n";
Goblin(StatyNepritel[0][0],StatyNepritel[0][1],StatyNepritel[0][2],NazevNepritelJedna,StatyNepritel[0][3],StatyNepritel[0][4]);
Goblin(StatyNepritel[1][0],StatyNepritel[1][1],StatyNepritel[1][2],NazevNepritelDva,StatyNepritel[1][3],StatyNepritel[1][4]);
SoubojDva();
cout << " Porazili jste další gobliny, po chvíli kdy se snažíte chytit dech obklíčí vás skupina goblinů a odvedou vás do největšího domu.\n Předvedou vás před Goblina oblečeného v saku.\n Šéf Goblinů: ''Ty mi tady vraždíš lidi jo? Připrav se zemřít.\n";
GoblinSef(StatyNepritel[0][0],StatyNepritel[0][1],StatyNepritel[0][2],NazevNepritelJedna,StatyNepritel[0][3],StatyNepritel[0][4]);
SoubojBoss();
cout << " Jakmile padne tělo šéfa goblinů na zem, povede se vám utéct po schodech nahoru do: VYŠŠÍCH PATER... Gratuluji.\n Zadýchaní, zabouchnete dveře. ?: ''Taky tě vyhnali? Mam tu pár věcí co bych ti mohl prodat''.\n Všimnete si goblina opřeného o stěnu, také si všimnete že má přes oko jizvu.\n";
Shop();
cout << " Vyhnaný goblin se s vámi rozloučí, a odemkne drahé dveře, které vám bránily v cestě dál.\n Jakmile projdete dveřmi všímáte si velké místnosti když se podíváte z okna všímáte si že je noc.\n Přede dveřmi vedoucími na schodiště leží kosti. Jakmile se přiblížíte zaútočí na vás dva kostlivci.\n";
Kostlivec(StatyNepritel[0][0],StatyNepritel[0][1],StatyNepritel[0][2],NazevNepritelJedna,StatyNepritel[0][3],StatyNepritel[0][4]);
Kostlivec(StatyNepritel[1][0],StatyNepritel[1][1],StatyNepritel[1][2],NazevNepritelDva,StatyNepritel[1][3],StatyNepritel[1][4]);
SoubojDva();
cout << " Jakmile skončíte s bojem s kostlivci, postupujete dál.\n V další patro je podobné patru předešlému.\n Chcete se podívat z okna?\n 1 - Ano\n 2 - Ne\n";
cin >> anone;
switch (anone){
case 1:
    cout << " Podíváte se z okna. Jste velmi vysoko... ale stále si nepamatujete nic. Otočíte se zpět do místnosti.\n";
    break;
case 2:
    break;
}
cout << " U dveří se zformují dva kostlivci a zaútočí na vás.\n";
Kostlivec(StatyNepritel[0][0],StatyNepritel[0][1],StatyNepritel[0][2],NazevNepritelJedna,StatyNepritel[0][3],StatyNepritel[0][4]);
Kostlivec(StatyNepritel[1][0],StatyNepritel[1][1],StatyNepritel[1][2],NazevNepritelDva,StatyNepritel[1][3],StatyNepritel[1][4]);
SoubojDva();
cout << " Vyjdete do dalšího patra Toto patro je menší než patra předchozí a na protější straně vidíte Postavu s kapucí.\n Nekromancer: ''Znovu ty? vidím že už jsi zabil moje kostlivce... Pojďme to ukončit.''\n Nekromancer vyvolá tři kostlivce kteří na vás zaútočí.";
Kostlivec(StatyNepritel[0][0],StatyNepritel[0][1],StatyNepritel[0][2],NazevNepritelJedna,StatyNepritel[0][3],StatyNepritel[0][4]);
Kostlivec(StatyNepritel[1][0],StatyNepritel[1][1],StatyNepritel[1][2],NazevNepritelDva,StatyNepritel[1][3],StatyNepritel[1][4]);
Kostlivec(StatyNepritel[2][0],StatyNepritel[2][1],StatyNepritel[2][2],NazevNepritelTri,StatyNepritel[2][3],StatyNepritel[2][4]);
SoubojTri();
cout << " Nekromancer: ''Vidím že ses zlepšil, minule jsi s mými kostlivci měl větší problém, ale zvládneš porazit mě?''\n";
Nekromancer(StatyNepritel[0][0],StatyNepritel[0][1],StatyNepritel[0][2],NazevNepritelJedna,StatyNepritel[0][3],StatyNepritel[0][4]);
SoubojBoss();
cout << " Nekromancer: ''Vzdávám se, něco ti prodám jestli chceš, ale jestli ti to pomůže porazit silentchanta, to ti neřeknu.\n";
Shop();
cout << " Rozloučíš se s nekromancerem a ten ti otevře dveře.\n Vydíš dlouhé točité schodiště. Pokračuješ po něm výš a výš, až dorazíš na vrchol. Slyšíš meluzínu a přijde ti jako by jsi tu už byl...\n Otevřete pevné dubové dveře. Vejdete do malé místnosti osvětlenou svícnem uprostřed místnosti.\n U stolu, otočený zády sedí dlouhá postava s čarodějnickým kloboukem.\n Silentchant: '' ... ''\n";
Silentchant(StatyNepritel[0][0],StatyNepritel[0][1],StatyNepritel[0][2],NazevNepritelJedna,StatyNepritel[0][3],StatyNepritel[0][4]);
SoubojFinalBoss();
cout << "Silentchant: ''. ";
Sleep(2000);
cout << ". ";
Sleep(2000);
cout << ".''\n";
Sleep(3000);
cout << " ... Porazil jsi Silentchanta ... Gratuluji. Vyhráli jste. Co chcete dělat\n";
do{
    x = 0;
    cout << " 1 - Přečíst si silentchantovy zápisky\n 2 - Zůstat stát\n 3 - Ukončit hru \n 4 - Hrát znovu\n";
    cin >> pomocnapromena;
    switch (pomocnapromena){
case 1:
    cout << " Zápisky mága silentchanta\n\n Strana 1 Cyklus pátý\n Všimnul jsem si že se tento den opakuje, myslel jsem že je to jen náhoda a tak jsem nic nezapisoval, ale po dnešku...\n Dnes přišel znovu jako válečník, poznal jsem že je to on vypadal úplně stejně jako poprvé.\n Budu zapisovat vše co se bude dít dál.\n\n Strana 2 Cyklus osmý\n Dnes poprvé přišel jako goblin... Zeptal se mě zda nevím kdo je, kdybych nepodepsal tu smlouvu vše bych mu vysvětlil...\n Ale jelikož nemůžu mluvit nic se nedozví... Musím nekromancerovi napsat, aby se mu pokusil vše vysvětlit.\n\n Strana 3 Cyklus 9\n Jakmile se mu to pokusil nekromancer vysvětlit den skončil, vše se resetovalo... proč? jak to funguje?.\n\n Strana 5 Cyklus 15\n Poznatky:\n Jakmile Zemře vše se resetuje.\n Zatím se mu nepodařilo mě porazit...\n Pravděpodobně je měňavec trpící nějakou nemocí... nebo že by byl prokletý... něco zkusím\n\n Strana 20 Cyklus 120\n Už byl blízko... Ale nestihl to kdyby mě zabil o chvilku dřív možná by se něco změnilo.\n";
    break;
case 2:
    cout << " Stojíš v místnosti... Děkuji za to že jste hráli mou hru\n THE END.\n";
    x = 1;
placeholder = 0;
    break;
case 3:
    cout << " Konec Hry, Děkuji za váš čas.\n";
    x = 1;
placeholder = 0;
    break;
case 4:
    placeholder = 1;
    x = 1;
    break;
    }
}while (x == 0);
}while (placeholder == 1);
}
