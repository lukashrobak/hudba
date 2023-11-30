// Auta.cpp : Defines the entry point for the application.
//

#include "hudba.h"

#include <stdio.h>
#include <ctype.h>              // tolower
#include <stdlib.h>				// system

#include "hudbaDB.h"

struct t_album* prvni = NULL; // globalni ukazatel na prvni auto

void OnAdd()
{
	char my_name[INTERPRET_SIZE];
	char my_album[ALBUM_SIZE];
	int my_year;

	printf("\nInterpret : ");         // dotazeme se na polozky
	scanf_s("%s", my_name, INTERPRET_SIZE);
	while (getchar() != '\n');
	printf("\nNazov albumu : ");
	scanf_s("%s", my_album, ALBUM_SIZE);
	while (getchar() != '\n');
	printf("\nRok vydania : ");
	scanf_s("%d", &my_year);
	while (getchar() != '\n');
	add(my_name,my_album, my_year, &prvni);         // volame pridavaci funkci
}

void OnDel()
{
	int my_year;

	printf("\nRok vydania : ");
	scanf_s("%d", &my_year);
	while (getchar() != '\n');
	del(my_year, &prvni);         // volame mazaci funkci
}

void ShowAlb()
{
	int lenrok;
	printf("Rok vydania ukazanych albumov: ");
	scanf("%d", &lenrok);
	struct t_album* aktAlbum = prvni; // ukazatel na aktualni auto
	printf("\n\n");
	while (aktAlbum) // prochazeni seznamu
	{
		if (lenrok == aktAlbum->rok) {
			printf("%d: %s - %s\n", aktAlbum->rok, aktAlbum->interpret, aktAlbum->album); // tisk radku
			aktAlbum = aktAlbum->dalsi; // posun na dalsi auto
		}
	}
	getchar();
	getchar();
}


int main()
{
	char  cmd;

	do
	{	
		system("cls");		// smaze obrazovku
		printf("A: Pridat     ");
		printf("D: Smazat     ");
		printf("P: Tisk     ");
		printf("Q: Konec\n\n");

		cmd = tolower(getchar());
		while (getchar() != '\n');

		switch (cmd)
		{
		case 'a':
			OnAdd();					// volame pridani
			break;
		case 'd':
			OnDel();					// volame mazani
			break;
		case 'p':
			ShowAlb();
			break;
		}
	} while (cmd != 'q');     // koncime az pri Q
	return 0;
}


