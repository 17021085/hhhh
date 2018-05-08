#include<iostream>
#include "console.h"
#include<ctime>
#define Dot_ran 254
#define max 100
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define Tuong_Tren 1
#define Tuong_Duoi 25
#define Tuong_Trai 3
#define Tuong_Phai 40


using namespace std;
struct ToaDo
{
	int x;
	int y;
};

ToaDo ran[max];
int SoDot = 4;//so dot ban dau 
void KhoiTao();
void HienthiRan(ToaDo DotCuoi);
ToaDo Dichuyen(int huong);
void Batsukien(int &huong);
ToaDo Hienthimoi(int somoi);
bool kiemtraanmoi(ToaDo moi);
void Themdot();
bool Gameover();
void VeTuong();
void bangdiem();
void Xulythua();
void intro();
int main()
{
	intro();
	Sleep(2000);
	system("cls");
	KhoiTao();
	int x = 0, y = 0;
	int huong = RIGHT;
	int diem = 0;
	int Sleeping = 150;
	int somoi=0;
	srand(time(0));
	VeTuong();
	bangdiem();
	ToaDo moi = Hienthimoi(somoi);
	
	
	//Vong Lap Game
	while (1) {

		ToaDo DotCuoi = Dichuyen(huong);
		Batsukien(huong);
		HienthiRan(DotCuoi);

		if (kiemtraanmoi(moi) == true) {
			Themdot();
			somoi++;
			if (somoi % 4 == 0) Sleeping -= 10;
			diem = diem += 8;
			gotoXY(Tuong_Phai + 8, Tuong_Tren + 3);
			setTextColor(DARK_GREEN_COLOR);
			cout << diem;
			setTextColor(WHITE_COLOR);
			moi = Hienthimoi(somoi);
			
		}
		if(Gameover()== true) 
			break;
		Sleep(Sleeping);
	} 

	Xulythua();
	system("pause");
	return 0;
}

void KhoiTao() //khoi tao 3 dot ran dau tien
{
	
	ran[0].x = Tuong_Trai + 5;
	ran[1].x = Tuong_Trai + 4;
	ran[2].x = Tuong_Trai + 3;
	ran[0].y = ran[1].y = ran[2].y = Tuong_Tren +3;
	
} 
void HienthiRan(ToaDo DotCuoi) //in ran ra  man hinh
{
	gotoXY(ran[0].x, ran[0].y);
	cout << (char)2;
	for (int i = 1; i < SoDot; i++) {
		gotoXY(ran[i].x, ran[i].y);
		cout << (char)Dot_ran;
	}
	gotoXY(DotCuoi.x, DotCuoi.y);
	cout << " ";
} 
ToaDo Dichuyen(int huong) {
	ToaDo DotCuoi = ran[SoDot - 1];
	for (int i = SoDot - 1; i >= 1; i--) {
		ran[i] = ran[i - 1];
	}
	switch (huong)
	{
	case UP :
		ran[0].y--;
		break;
	case DOWN :
		ran[0].y++;
		break;
	case LEFT :
		ran[0].x--;
		break;
	case RIGHT :
		ran[0].x++;
		break;
	}
	return DotCuoi;
	
}
void Batsukien(int &huong) 
{
	int key = inputKey();
	if ( key == KEY_UP && huong != DOWN)
	{
		huong = UP;
	}
	else if ( key == KEY_DOWN && huong != UP)
	{
		huong = DOWN;

	}
	else if ( key == KEY_LEFT && huong != RIGHT)
	{
		huong = LEFT;
	}
	else if ( key == KEY_RIGHT && huong != LEFT)
	{
		huong = RIGHT;
	}
	
}
void VeTuong()
{
	for (int i = Tuong_Trai; i <= Tuong_Phai; i++) {
		gotoXY(i, Tuong_Tren);
		cout << (char)219;
		gotoXY(i, Tuong_Duoi);
		cout << (char)219;
	}
	for (int j = Tuong_Tren; j <= Tuong_Duoi; j++) {
		gotoXY(Tuong_Trai, j); 
		cout << (char)219;
		gotoXY(Tuong_Phai, j);
		cout << (char)219;
	}
	
}
bool Gameover()
{
	if (ran[0].y == Tuong_Tren)
		return true;
	if (ran[0].y == Tuong_Duoi)
		return true;
	if (ran[0].x == Tuong_Trai)
		return true;
	if (ran[0].x == Tuong_Phai)
		return true;
	for (int i = 1; i <= SoDot - 1; i++) {
		if (ran[0].x == ran[i].x && ran[0].y == ran[i].y) {
			return true;
		}
		}
	
}
void Xulythua()
{
	if (Gameover() == true)
	{
		Sleep(500);
		system("cls");
		

		cout << " `  `. ``.`.`.   .`  ` .`.`  .`        ``          `.`. ` ` ` .`.`.`.``" << endl; Sleep(100);
		cout << " `.  `.     `   .   ` .`.`          .```    `.   `      `.`.`.`` .`.`` .`  .`"<<endl; Sleep(100);
		cout << " `.  `.     `   .   ` .`.`          .```    `.   `      `.`.`.`` .`.`` .`  .`"<<endl; Sleep(100);
		cout << "` ``.`.`` ``-`.`` ` ` ` ``.`    `````.  `.`.   ``-   ``.`.`-`` .`" << endl; Sleep(100);
		cout << "       /h/h/h/h/h/h/h-..h/h/h/h+y+yoso  ssos`.  `. ` `:h/h. -h/h/h/h/h/h/     " << endl; Sleep(100);
		cout << " `.  `.+d/d/d/d/d/d/d:..d/d/d/h+h+hoyo.`syoyoy `  `./h/d/d.`-d/d/d/d/d/d+.`.`" << endl; Sleep(100);
		cout << "  ``.`.+d/d````````````.d/d/``````hoys` sysyoh+y  /h/d/d/d-.-d/d:       .`` ." << endl; Sleep(100);
		cout << "      `+d/d`.:h/h/h/h-..d/d/  .`  hoyo``syoyohoh/y/d/d/d/d. -d/d/h/h/h/.`   " << endl; Sleep(100);
		cout << "       +d/d`.:d/d/d/d:..d/d/h/h/y+hoys..sysy`.oh+d/d`./d/d. -d/d/d/d/d/.`" << endl; Sleep(100);
		cout << "  .  `.+d/d`````::d/d-`.d/d/d/d+hohoys``sysy  `.+d.:  :d/d. -d/d:       .`.`" << endl; Sleep(100);
		cout << "       +d/d/y/y:y/d/d- .d/d/:.:..`hoys``sysy  `.`.`.  :d/d.`-d/d/y/y/y:y/`  " << endl; Sleep(100);
		cout << ". ..   +d/d/d/d/d/d/d- .d/d/` .`  hoyo..syoy   ``. `  :d/d..-d/d/d/d/d/d+  .`" << endl; Sleep(100);
		cout << "``    .:. : `-`-.:. : . - `.`:.:.  ` .`:-- - ....  `. ``.  .:. : ```:.:. : . : . - "<<endl; Sleep(100);
		cout << "`. `  `.  `. ` .`` ` ` .`.`````    ``  `` `  `.   ` `  `.`` ` `   ` `" << endl; Sleep(100);
		cout << "```. ``.`.`.   `   .`  .`.`` `   .`    `````.  ```.  `.`.`. ` .`.`    .`  .```" << endl; Sleep(100);
		cout << "````  `.`.`.```.`. `   ` ` ``    ````  ```.`.`` ` ``. ` ``.`.`.`.`.`.`.`  ````" << endl; Sleep(100);
		cout << "    ``:s:s:s:s:s:s:o..`o:o-.`.```  .`+/++``/o/o:o:o:s:o`.-s:s:s:s:s:s:s:``  " << endl; Sleep(100);
		cout << "  ```.+h/h/d/d/d/d/d:..d/d/.`.`.```.`ssss``oy+h+h/h/d/d..:d/d/d/d/d/h/h+.`  `` " << endl; Sleep(100);
		cout << "  ````+h/d-/./-+:d/d:..d/d/o:``.```+/ssss`.oy+h-/-+-+./`.:d/d:     -d/h+``  ``" << endl; Sleep(100);
		cout << "  ````+d/d`````.-d/d:.`+-d/d/``.```yoys:/``oy+h:+-o-o```.:d/d:+-+-+-d/d+``  ``" << endl; Sleep(100);
		cout << "` ````/h/d``````-d/d-` ``d/h/+-.`+:yoss````oy+h+h/h/d..`.:d/d/d/d/d/d/h/``  ``" << endl; Sleep(100);
		cout << " `   `/h/d.. ``.-d/d-`  `+-h/h+.`yoyo//  ``oy+h-+-o-o```.:d/d:o-+:d/d/o-```` "<< endl; Sleep(100);
		cout << " `````+d/d-+./.+:d/d:.`` ``d/h+/-hoyo.. `  oy+h.:-+-+./``:d/d-.` `o:d//-.````"<<endl; Sleep(100);
		cout << "``  ``+h/d/d/d/d/d/d-` .`.`o:h+h+yo+/````  oy+h+h/d/d/d.`-d/d-` `  `o:h+/- "<< endl; Sleep(100);
		cout << "`  `  :s:o:s:s:o:s:s-.`` `   o:o/o/  ``    /o/s:o:o:o:s..-s:s.` ` ` ` o:s/  `"<< endl; Sleep(100);
		cout << "`.  ``  `. ` ` .`.`  .`.``   `     ```````.`.      `. ``.`.`.`` .`.`` ``  ``" << endl; Sleep(100);
		cout << "``.`.`.   .``   .`.`  .`        ``     ` `  `.`.     ` .`.`.`.`" << endl; Sleep(100);
		cout << "`   `  `.`.`. ` ` .`.`        .`  `           `.`. `  `.     .`.`.`  .`  `"<<endl; Sleep(100);
		cout << "`.  `. ``.`. ``.`. ` `   `   .`  ` ``.`          `.`.       .   ` `   .`  .`"<<endl; Sleep(100);
		
	}
}
ToaDo Hienthimoi(int somoi)
{
	ToaDo temp;
	int x = Tuong_Trai + 5;
	int y = Tuong_Tren + 3;
	for (int v = 0; v <= SoDot - 1; v++) {
		if (x == ran[v].x && y == ran[v].y) {
			 x = Tuong_Trai + 1 + rand() % (Tuong_Phai - Tuong_Trai - 1);
			 y = Tuong_Tren + 1 + rand() % (Tuong_Duoi - Tuong_Tren - 1);
		}
	}
	
		gotoXY(x, y);
		setTextColor(RED_COLOR);
		if (somoi > 0 && somoi % 4 == 0) cout << (char)11;
		else cout << (char)3;
		setTextColor(WHITE_COLOR);
		temp.x = x;
		temp.y = y;
		return temp;
	
}
bool kiemtraanmoi(ToaDo moi)
{
	if (ran[0].x == moi.x && ran[0].y == moi.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Themdot()
{
	//ran[SoDot] = ran[SoDot - 1];
	SoDot++;
}
void bangdiem()
{
	for (int i = Tuong_Phai + 3; i <= Tuong_Phai + 15; i++) {
		gotoXY(i, Tuong_Tren);
		cout << (char)219;
		gotoXY(i, Tuong_Duoi - 15);
		cout << (char)219;
	}
	for (int j = Tuong_Tren; j <= Tuong_Duoi - 15; j++) {
		gotoXY(Tuong_Phai +3, j);
		cout << (char)219;
		gotoXY(Tuong_Phai + 15, j);
		cout << (char)219;
	}
	
	gotoXY(Tuong_Phai + 4, Tuong_Tren + 2);
	setTextColor(RED_COLOR);
	cout << "   Score " ;
	setTextColor(WHITE_COLOR);
}
void intro()
{
	cout << "                                     `.---:/+++/-`                                              " << endl;
	cout << "                                   .+ydmmmmmmmmmmmdo.                                           " << endl;
	cout << "                                 `odmmmmmmmmddddmmmmd.                                          " << endl;
	cout << "                                 smmmmmmmmh::/++ommmmh`                                         " << endl;
	cout << "                                .mmmmmmmmm-   `-/ymmmmy`                                        " << endl;
	cout << "                                -mmmmmmmmmd+-`    .+yhs.                                        " << endl;
	cout << "                                 hmmmmmmmmmmms:o:                                               " << endl;
	cout << "                                 .ymmmmmmmmdssmmy/y/`                                           " << endl;
	cout << "                .:/+/:.`           :ymmmmmddmmdysmmm+/.                                         " << endl;
	cout << "              .ymmmmmmmds:`          ./ydmmmmdmmmmhsymm:                                        " << endl;
	cout << "             -mmmmd+/++oshdo-           `-/sdmmmddmmmmy+:                                       " << endl;
	cout << "             smmmm:  -+yhyo++/-`             :ymmmmdhyhmh                                       " << endl;
	cout << "             ommmmh.    ./ymmdyo-`             ommmmmmmd+                                       " << endl;
	cout << "             .dmmmmmo`     .+dmmmmyo:.        `ymmmddhyy:                                       " << endl;
	cout << "              .hmmmmmms:`     :ymmmmmmmdyssoshmmmmmmmmmo                                        " << endl;
	cout << "                /hmmmmmmmho/-.` :hmmmmmmmmmmmmmmmmmmms-                                         " << endl;
	cout << "                  ./sdmmmmmmmmmdhhmmmmmmmmmmmmmmmmmmyyyyyhhhhddddddmmmmddddddhhyysso++/:-.`     " << endl;
	cout << "                      `:/oshdmmmmmmmmmmmmmmmmmmmmmmmmmdddhhyyyssooo+++///::::-------------:::-` " << endl;
	cout << "                    ````     ``..--:::::::::::---..````                                         " << endl;
	cout << "                .+ydmmmddo  .yhhhs.    `ohhy-    `ohhhhh.       :yhhhy- `+hhhy/  :hhhhhhddo     " << endl;
	cout << "               -dmmms::/oo   :mmmmd+    .mmy      smmmmmh`       hmmmh  `ymmh-   `dmmms::++     " << endl;
	cout << "               ommmmy:.      .mmmmmmy-  .mmo     :mmsmmmms       hmmmh`:dmd/`    `dmmm+         " << endl;
	cout << "               .hmmmmmdho-   .mmsdmmmmo`.mmo    `dmh`ommmm/      hmmmdsmmd-      `dmmmhyy+      " << endl;
	cout << "                `-ohmmmmmmy` .mm:.smmmmh/mmo    smmy/+mmmmm-     hmmmmmmmmh.     `dmmmy+o+      " << endl;
	cout << "                   `./ymmmmo .mm: `/dmmmmmmo   :mmdhhhhmmmmd`    hmmmh/mmmmd:    `dmmm+         " << endl;
	cout << "               /+:.```/mmmm+ .mm/   .smmmmmo  `hmd.````/mmmmy    hmmmh -dmmmmo   `dmmmo.``.::   " << endl;
	cout << "               -dmddddmmmh+` +mmy`    -sdmmo `smms     .dmmmmo` .dmmmd. .ymmmms. :mmmmmddddd.   " << endl;
	cout << "                .-:/++/:.`  `----`      .:/- .----`    .------. .-----.  `.----. .----------    " << endl;

	cout << "                         ___________Made_______by______NguyenTrung_____________                 " << endl;
}
