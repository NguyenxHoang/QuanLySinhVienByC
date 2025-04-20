#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void delay(int mili){// ham delay 
	Sleep(mili);
}


void setColor(int color){// ham doi mau chu
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

// sinh vien
struct diemSo{
	float toan, ly, hoa;
};

struct sinhVien{
	char name[50];
	char lop[50];
	char truong[50];
	char mssv[50];
	struct diemSo diem;
};

typedef struct sinhVien SV;

void nhapSV(SV* a){// them thong tin sinh vien
	printf("Nhap ten sinh vien: ");
	fgets(a->name, sizeof(a->name), stdin);
	a->name[strcspn(a->name, "\n")] = '\0';
	printf("Nhap chuyen nganh sinh vien: ");
	fgets(a->lop, sizeof(a->lop), stdin);
	a->lop[strcspn(a->lop, "\n")] = '\0';
	printf("Nhap truong sinh vien: ");
	fgets(a->truong, sizeof(a->truong), stdin);
	a->truong[strcspn(a->truong, "\n")] = '\0';
	printf("Nhap ma so sinh vien: ");
	fgets(a->mssv, sizeof(a->mssv), stdin);
	a->mssv[strcspn(a->mssv, "\n")] = '\0';
}


void xuatSV(SV* a) {
    printf("          *=====---=====*            \n");
    printf("Ten sinh vien: %s\n", a->name);
    printf("Chuyen nganh sinh vien: %s\n", a->lop);
    printf("Truong sinh vien hoc la: %s\n", a->truong);
    printf("Ma so sinh vien: %s\n", a->mssv);
}


void xoaSV(SV* a, int* n, int index){// xoa sinh vien
	for	(int i = index; i < *n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	(*n)--;
}


void nhapDiem(SV* a){
	printf("Nhap diem mon toan: ");
	scanf("%f", &a->diem.toan);
	printf("Nhap diem mon ly: ");
	scanf("%f", &a->diem.ly);
	printf("Nhap diem mon hoa: ");
	scanf("%f", &a->diem.hoa);
	getchar(); 
}

void xuatDiem(SV* a){
	printf("Diem toan: %0.2f - Diem ly: %0.2f - Diem hoa: %0.2f\n", a->diem.toan, a->diem.ly, a->diem.hoa);
}

//


int main(){
	int e = 0;
	char s1[50];// nhap diem
	char s2[50];// sinh vien can xoa
	char s3[50];// sinh vien can tim
	int nhap;
	int lua_chon;
	SV s[50];// mang chua sinh vien
	int n = 0;
	do{
		setColor(3);
		printf("@======================@\n");
		printf("|    Quan Ly Lop Hoc   |\n");
		printf("|   1. Giang Vien      |\n");
		printf("|   2. Sinh Vien       |\n");
		printf("|   3. Thoat           |\n");
		scanf("%d", &nhap);
		fflush(stdin);
		if	(nhap != 1 && nhap != 2) printf("Du lieu khong hop le vui long nhap lai.\n");
		switch(nhap){
			case 1:// giang vien
				do{
					setColor(12);
					printf("--------------\n");
					printf("1. Them Sinh Vien\n");
					printf("2. Xoa Sinh Vien\n");
					printf("3. Tim kiem sinh vien\n");
					printf("4. Nhap diem sinh vien\n");
					printf("5. Thoat              \n");
					scanf("%d", &lua_chon);
					fflush(stdin);
					e = 0; 
					switch(lua_chon){
						case 1:	setColor(7);		// them sinh vien
							nhapSV(&s[n]);
							n++;
						break;
						case 2: setColor(7);// Xoa sinh vien
						printf("Nhap ten sinh vien can xoa: ");
							fgets(s2, sizeof(s2), stdin);
							s2[strcspn(s2, "\n")] = '\0';
							for	(int i = 0 ; i < n; i++)
							{
								if	(stricmp(s[i].name, s2) == 0)
								{
									xoaSV(&s[i], &n, i);
									e = 1;
								}
								i--;	
							}
							if	( e == 0) printf("Khong tim thay sinh vien ten %s\n", s2);
							break;
						case 3: setColor(7);// tim kiem sinh vien
							printf("Nhap ten sinh vien can tim: ");
							fgets(s3, sizeof(s3), stdin);
							s3[strcspn(s3, "\n")] = '\0';
							for	(int i = 0; i < n; i++)
							{
								if	(stricmp(s[i].name, s3) == 0)
								{
									xuatSV(&s[i]);
									e = 1;
								}
							}
							if	( e == 0) printf("Khong tim thay sinh vien ten %s\n", s3);
							break;
						case 4: setColor(7);
							printf("Nhap ten sinh vien can nhap diem: ");
							fgets(s1, sizeof(s1), stdin);
							s1[strcspn(s1, "\n")] = '\0';
							for	(int i = 0; i < n; i++)
							{
								if	(stricmp(s[i].name, s1) == 0)
								{
									nhapDiem(&s[i]);
									e = 1;
								}
							}
								if	( e == 0) printf("Khong tim thay sinh vien ten %s\n", s1);
							break;			
					}
					if	(lua_chon != 1 && lua_chon != 2 && lua_chon != 3 && lua_chon != 4 && lua_chon != 5) 
						printf("Du kien khong hop le. Vui long nhap lai\n");
				} while(lua_chon == 1 || lua_chon == 2 || lua_chon == 3 || lua_chon == 4 || lua_chon != 5);
				// giang vien 
				break;
			
			case 2:// sinh vien
				do{
				setColor(14);
				printf("---------------\n");
				printf("1. Xem diem sinh vien \n");
				printf("2. Xem thong tin sinh vien  \n");
				printf("3. Thoat\n");
				scanf("%d", &lua_chon);
				fflush(stdin);
				e = 0;
				switch(lua_chon){
					case 1: setColor(7);
						printf("Nhap ten sinh vien muon xem: ");
						gets(s1);
						fflush(stdin);
						for	(int i = 0; i < n; i++)
						{
							if	(stricmp(s[i].name, s1) == 0)
							{
								xuatDiem(&s[i]);
								e = 1;
							}
						}
						if	(e == 0) printf("Khong co sinh vien %s\n", s1);
						break;
					case 2: setColor(7);
						printf("Nhap ten sinh vien muon xem: ");
						gets(s2);
						fflush(stdin);
						for	(int i = 0; i < n; i++)
						{
							if	(stricmp(s[i].name, s2) == 0)
								{
									printf("*================================*\n");
									printf("Ho va ten: %s\n", s[i].name);
									printf("Chuyen nganh: %s\n", s[i].lop);
									printf("Sinh vien truong: %s\n", s[i].truong);
									printf("Ma so sinh vien: %s\n", s[i].mssv);
									e = 1;
								}
						}
						if	(e == 0) printf("Du kien khong hop le vui long nhap lai\n");
						break;	
				}// switch cua sinh vien
				
				
				if	(lua_chon != 1 && lua_chon != 2 && lua_chon != 3) printf("Du kien khong hop le vui long nhap lai\n");	
				} while(lua_chon == 1 || lua_chon == 2 || lua_chon != 3);
			break;
		}// switch lon nhat
	} while(nhap == 1 || nhap == 2 || nhap != 3);
	return 0;
	
	
	
	
	
	
	
	
}


