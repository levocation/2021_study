#include <stdio.h>
#include <windows.h>

void setcolor(int color, int bgcolor) {
    color &= 0xf;
    bgcolor &= 0xf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);

}

void print1(int num[3][3]){
	system("cls");
	for (int a = 0; a <= 2; a++) {
		for (int b = 0; b <= 2; b++) {
			printf("%2d", num[a][b]);
		}
		printf("\n");
	}
}

void print2(int num[3][3], int aa, int bb){
	system("cls");
	for (int a = 0; a <= 2; a++) {
		for (int b = 0; b <= 2; b++) {
			if ((a == aa && b == bb) || (a == bb && b == aa)) setcolor(10,0); else setcolor(15,0);
			printf("%2d", num[a][b]);
		}
		printf("\n");
	}
}

main() {
	int num[3][3] = {0,};
	int a, b, k = 0, tmp;
	
	// {1,2,7}
	// {4,5,8}
	// {3,6,9}
	
	for (a = 0; a <= 2; a++) {
		for (b = 0; b <= 2; b++) {
			k++;
			num[a][b] = k;
		}
	}
	print1(num);
	
	for (a = 0; a <= 1; a++) {
		for (b = 0; b <= 2; b++) {
			print2(num, a, b);
			system("pause>nul");
			tmp = num[a][b];
			num[a][b] = num[b][a];
			num[b][a] = tmp;
			print1(num);
			system("pause>nul");
		}
	}
	system("cls");
	for (a = 0; a <= 2; a++) {
		for (b = 0; b <= 2; b++) {
			printf("%2d", num[a][b]);
		}
		printf("\n");
	}
}
