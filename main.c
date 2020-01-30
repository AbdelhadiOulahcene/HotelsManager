#include <stdio.h>
#include <stdlib.h>
#include "Biblio_LLC.h"
#include <string.h>
#include "conio21/conio.c"

void cadre(int opt){
	int i,x=3,y=12;
    for(i = 1;i<=120;i++) {
        gotoxy(i,1);
        delay(opt);
    	printf("%c\n", 205);
	}
    gotoxy(40,3);
	write("ESI - Ecole Nationale Superieure d'informatique \n" , 20) ;
	for(i = 1;i<=120;i++) {
        gotoxy(i,5);
        delay(opt);
    	printf("%c\n", 205);
	}
    for(i = 1;i<=10;i++) {
    	gotoxy(35,i+5);
    	delay(opt);
    	if (i == 35) printf("%c\n", 202);
    	else printf("%c\n", 186);
	}
	 for(i = 1;i<=10;i++) {
    	gotoxy(85,i+5);
    	delay(opt);
    	if (i == 35) printf("%c\n", 202);
    	else printf("%c\n", 186);
	}
	for(i = 1;i<=58;i++) {
        gotoxy(i+30,15);
        delay(opt);
    	printf("%c\n", 205);
	}
gotoxy(40,7);
textcolor(RED);
write("TP 1 : GESTION DES RESERVATIONS D'HOTELS \n " , 20);
gotoxy(40,9);
write("REALISE PAR :  ZELLAT - OULAHCENE  \n ", 20);
gotoxy(40,11);
write("GROUPE : C-10  \n ", 20);
gotoxy(40,13);
write("ENCADRE PAR  :  ENS KACET.S \n ", 20);
gotoxy(40,15);

}
void write(char *chaine,int dela){
    int i;
for (i=0;i<=strlen(chaine);i++){ cprintf("%c",chaine[i]); delay(dela);}
}
typedef char* chaine ;
int menu1 ()
{
chaine t [] = {  "1- CHARGER LES RESERVATIONS DEPUIS UN FICHIER TEXTE  ",
                     "2- SAUVGARDER LES RESERVATIONS DANS UN FICHIER TEXTE  ",
                     "3- AFFICHAGE DU STATUT DES RESERVATIONS ",
                     "4- INSERER UNE NOUVELLE RESERVATION  ",
                     "5- MODIFIER UNE RESERVATION ",
                     "6- SUPPRIMER UNE RESERVATION   ",
                     "7- RECHERCHER UNE CHAMBRE LIBRE ",
                     "8- RECHERCHER LA RESERVATION EFFECTUES PAR UNE PERSONNE ",
                     "9- RAJOUTER UN HOTEL ",
                     "10- SUPPRIMER UN HOTEL ",
                     "11- LIBERER TOUTES LES CHAMBRES OCCUPEES AYANT UNE DATE FIN EGALE A LA DATE DU JOUR ",
                     "12- TRIER LES LISTES D'HOTELS PAR ORDRE ALPHABETIQUE ",
                     "13- EXIT ",
                  };
    int  n = 13 ;
    int i , j , k , quite = 1, quite2 , y = 10 , x= 20 ;
    char c1,c2 ,c3 , c4 ;

    textcolor(BLACK);
    k = 0 ;
    for( i = 0 ; i< n ; i++)
        {

            if (i==0){ textbackground(BLACK); textcolor(WHITE);}
            else {textbackground(WHITE); textcolor(BLACK);}
            gotoxy(x,y+i);
            printf("%s\n",t[i]);



        }
    i=0;
    while( quite)
        {
            c1 = _getch();
            if( c1 == 13 ) quite =0 ;

            else if( c1 == -32 )
                {
                    c2 = _getch();
                    if (c2 == 72 )
                        {
                            if(i > 0)
                                {

                                    gotoxy(x,i-1+y);
                                    textbackground(BLACK);
                                    textcolor(WHITE);
                                    printf("%s\n",t[i-1]);
                                    textbackground(WHITE);
                                    textcolor(BLACK);
                                    gotoxy(x,i+y);
                                    printf("%s\n",t[i]);
                                    i--;
                                }
                            else
                                {
                                    gotoxy(x,y+n-1);
                                    textbackground(BLACK);
                                    textcolor(WHITE);
                                    printf("%s\n",t[n-1]);
                                    gotoxy(x,y);
                                    textbackground(WHITE);
                                    textcolor(BLACK);
                                    printf("%s\n",t[0]);
                                    i=n-1;
                                }
                        }
                else if (c2 == 80)
                    {
                        if( i < n-1)
                            {
                                gotoxy(x,y+i+1);
                               textbackground(BLACK);
                                textcolor(WHITE);
                                printf("%s\n",t[i+1]);
                                textbackground(WHITE);
                                textcolor(BLACK);
                                gotoxy(x,y+i);
                                printf("%s\n",t[i]);
                                i++;
                            }
                    else
                        {
                            gotoxy(x,y);
                             textbackground(BLACK);
                                    textcolor(WHITE);
                            printf("%s\n",t[0]);
                            gotoxy(x,y+i);
                            textbackground(WHITE);
                                    textcolor(BLACK);
                            printf("%s\n",t[i]);
                            i=0 ;
                        }
                    }
                }
            }
    clrscr();
    return i+1;
}
void chargement(int t){
        //chargement
        int i , d=40;
            for (i=0 ; i<=50 ; i++)
            {
                if ( i<44)
                    {
                        textcolor(BLACK);
                        gotoxy(d+i-10,2);
                        printf("%c",219);
                        delay(t);
                    }
                    else
                         if ( i>55)
                    {
                        textcolor(BLACK);
                        gotoxy(d+i-25,2);
                        printf("%c",219);
                        delay(t);
                    }
                textcolor(WHITE);
                textbackground(BLACK);
                gotoxy(44,2);
                printf("Chargement ... %d %c\r",2*i,37);
                textbackground(BLACK);
                textcolor(BLACK);
textbackground(WHITE);
                delay(t / 2);
            }
}
void sauvgardement(int t){
        //chargement
        int i , d=40;
            for (i=0 ; i<=50 ; i++)
            {
                if ( i<44)
                    {
                        textcolor(BLACK);
                        gotoxy(d+i-10,2);
                        printf("%c",219);
                        delay(t);
                    }
                    else
                         if ( i>55)
                    {
                        textcolor(BLACK);
                        gotoxy(d+i-25,2);
                        printf("%c",219);
                        delay(t);
                    }
                textcolor(WHITE);
                textbackground(BLACK);
                gotoxy(44,2);
                printf("Sauvgarde en cours .. %d %c\r",2*i,37);
                textbackground(BLACK);
                textcolor(BLACK);
textbackground(WHITE);
                delay(t / 2);
            }
}
int main()
{
int choix , k = 0 , charg = 0 ;
AlphaStruct  *tete;
tete=malloc(sizeof(AlphaStruct));
tete = NULL ;
textcolor(GREEN);
textbackground(WHITE);
SetConsoleTitle("TP_ZELLAT_OULAHCENE");
system("mode con cols=120 lines=1000");
cadre(7);
gotoxy(50,17) ;
Sleep(500) ;
printf("\n");
printf("                            $$$$$$\\                        $$\\     $$\\                                 \n" );
printf("                           $$  __$$\\                       $$ |    \\__|                                 \n" );
printf("                           $$ /  \\__| $$$$$$\\   $$$$$$$\\ $$$$$$\\   $$\\  $$$$$$\\  $$$$$$$\\               \n" );
printf("                           $$ |$$$$\\ $$  __$$\\ $$  _____|\\_$$  _|  $$ |$$  __$$\\ $$  __$$\\              \n" );
printf("                           $$ |\\_$$ |$$$$$$$$ |\\$$$$$$\\    $$ |    $$ |$$ /  $$ |$$ |  $$ |             \n" );
printf("                           $$ |  $$ |$$   ____| \\____$$\\   $$ |$$\\ $$ |$$ |  $$ |$$ |  $$ |             \n" );
printf("                           \\$$$$$$  |\\$$$$$$$\\ $$$$$$$  |  \\$$$$  |$$ |\\$$$$$$  |$$ |  $$ |             \n" );
printf("                            \\______/  \\_______|\\_______/    \\____/ \\__| \\______/ \\__|  \\__|             \n" );

printf("\n");
printf("\n");
printf("\n");

printf("               $$$$$$$\\                            $$\\   $$\\            $$\\               $$\\   \n");
printf("               $$  __$$\\                           $$ |  $$ |           $$ |              $$ | \n");
printf("               $$ |  $$ | $$$$$$\\   $$$$$$$\\       $$ |  $$ | $$$$$$\\ $$$$$$\\    $$$$$$\\  $$ | $$$$$$$\\  \n");
printf("               $$ |  $$ |$$  __$$\\ $$  _____|      $$$$$$$$ |$$  __$$\\_ $$  _|  $$  __$$\\ $$ |$$  _____|   \n");
printf("               $$ |  $$ |$$$$$$$$ |\\$$$$$$\\        $$  __$$ |$$ /  $$ | $$ |    $$$$$$$$ |$$ |\\$$$$$$\\  \n");
printf("               $$ |  $$ |$$   ____| \\____$$\\       $$ |  $$ |$$ |  $$ | $$ |$$\\ $$   ____|$$ | \\____$$\\  \n");
printf("               $$$$$$$  |\\$$$$$$$\\ $$$$$$$  |      $$ |  $$ |\\$$$$$$  | \\$$$$  |\\$$$$$$$\\ $$ |$$$$$$$  |  \n");
printf("               \\_______/  \\_______|\\_______/       \\__|  \\__| \\______/   \\____/  \\_______|\\__|\\_______/ \n");

gotoxy(45,40);


system("pause") ;
while ( k== 0){
system("cls");

int x=menu1();

    if (x == 1){
        system("cls");
        Chargement(&tete);
        chargement(15);
        printf("\n \n");
        printf("LES FICHIERS SONT CHARGES AVEC SUCCES \n \n") ;
} else {
if (x == 2){
        system("cls");
        Sauvgarder(tete) ;
         sauvgardement(15);
           printf("\n \n");
          printf("LES FICHIERS SONT SAUVGARDES AVEC SUCCES \n") ;
} else {
if (x == 3){
    system("cls");
        affich_statut(tete) ;
        printf("\n \n");
} else {
if (x == 4){
    system("cls");
        inserer_res(&tete) ;
        printf("\n \n");
} else {
if (x == 5){
    system("cls");
        modifier_res(&tete) ;
        printf("\n \n");

} else {
if (x == 6){
    system("cls");
        supprimer_res(&tete) ;
        printf("\n \n");
} else {
if (x == 7){
    system("cls");
        Chm_Rech(tete) ;
        printf("\n \n");
} else {
if (x == 8){
    system("cls");
       Nom_Rech(tete) ;
       printf("\n \n");
} else {
if (x == 9){
    system("cls");
    if ( tete == NULL){ printf(" CHARGEZ LES FICHIERS D'ABORD SVP  \n ") ; } else {
        Ajouter(tete) ;
        printf("\n \n");
}} else {
if (x == 10){
    system("cls");
        SupHotel(tete) ;
        printf("\n \n");
} else {
if (x == 11){
    Liberer_date(&tete) ;
   if(tete!=NULL) {printf(" LES RESERVATIONS QUI TERMINENT AUJOURD'HUI SONT LIBERES !! \n ");}
    printf("\n \n");
} else {
if (x == 12){
    tete = TRILAST(tete)    ;
   if(tete!=NULL){printf(" LES HOTELS SONT BIEN TRIES ! \n ");}
    printf("\n \n");
} else {
if (x == 13){
     k = 1 ;
} else {
printf("ENTREZ UN CHOIX ENTRE 1 ET 13 \n") ;
}
}
}
}
}
}
}
}
}
}
}
}
}
system("pause") ;
}
return 0 ;
}

