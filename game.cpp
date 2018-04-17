#include<iostream>
#include "kmin_console.h"
#include<ctime>
#define Dot_ran 254
#define max 30
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define Tuong_Tren 1
#define Tuong_Duoi 25
#define Tuong_Trai 3
#define Tuong_Phai 65



using namespace std;
struct ToaDo
{
	int x;
	int y;
};

ToaDo ran[max];
int SoDot = 3;//so dot ban dau 
void KhoiTao();
void HienthiRan(ToaDo DotCuoi);
ToaDo Dichuyen(int huong);
void Batsukien(int &huong);
ToaDo Hienthimoi();
bool kiemtraanmoi(ToaDo moi);
bool Gameover();
void VeTuong();
void Xulythua();

int main()
{
	system("cls");
	/*for (int i = 0; i < 256; i++) {
		cout << i <<": " <<(char)i<<endl;
	}*/
	KhoiTao();
	
	int x = 0, y = 0;
	int huong = RIGHT;

	VeTuong();
	ToaDo moi = Hienthimoi();
	//Vong Lap Game
	while (1) {
		//system("cls");

		ToaDo DotCuoi = Dichuyen(huong);
		Batsukien(huong);
		HienthiRan( DotCuoi);
		
		if (kiemtraanmoi(moi) == true) {
			moi = Hienthimoi();
		};
		if(Gameover()== true) 
			break;
		Sleep(300);

	}
	Xulythua();

	system("pause");
	return 0;
}

void KhoiTao() //khoi tao 3 dot ran dau tien
{
	ran[0].x = Tuong_Trai + 3;
	ran[1].x = Tuong_Trai + 2;
	ran[2].x = Tuong_Trai + 1;
	ran[0].y = ran[1].y = ran[2].y = Tuong_Tren +3;
	
} 
void HienthiRan(ToaDo DotCuoi) //in ran ra  man hinh
{
	for (int i = 0; i < SoDot; i++) {
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
	if (key == 'w' || key == 'W' || key == KEY_UP)
	{
		huong = UP;
	}
	else if (key == 's'|| key == 'S' || key == KEY_DOWN)
	{
		huong = DOWN;

	}
	else if (key == 'a' || key == 'A' || key == KEY_LEFT)
	{
		huong = LEFT;
	}
	else if (key == 'd' || key == 'D' || key == KEY_RIGHT)
	{
		huong = RIGHT;
	}
	
}
void VeTuong()
{
	for (int i = Tuong_Trai; i <= Tuong_Phai; i++) {
		gotoXY(i, Tuong_Tren);
		cout << (char)219;
	}
	for (int j = Tuong_Tren; j <= Tuong_Duoi; j++) {
		gotoXY(Tuong_Trai, j); 

		cout << (char)219;
	}
	for (int k = Tuong_Trai; k <= Tuong_Phai; k++) {
		gotoXY(k, Tuong_Duoi);
		cout << (char)219;
	}
	for (int j = Tuong_Tren; j <= Tuong_Duoi; j++) {
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
}
void Xulythua()
{
	if (Gameover() == true)
	{
		Sleep(500);
		system("cls");
		cout << "Game over";
	}
}
ToaDo Hienthimoi()
{
	
	srand(time(NULL));
	int x = Tuong_Trai + 1 + rand() % (Tuong_Phai - Tuong_Trai - 1);
	int y = Tuong_Tren + 1 + rand() % (Tuong_Duoi - Tuong_Tren - 1);
	gotoXY(x, y);
	cout << (char)3;
	return ToaDo{ x,y };
}
bool kiemtraanmoi( ToaDo moi)
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