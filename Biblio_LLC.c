#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblio_LLC.h"
#include <time.h>

void print_list_Alph(AlphaStruct *li)
{
   /*  if(li==NULL)
    {
        printf("rien a afficher , la liste est vide\n");
    } */
    while (li!=NULL)
    {
      printf("%c    " , li->alph );
      li = li->Next;
    }
}
//********************************************************************/
void print_list_Hot(HotStruct *li)
{
  /*   if(li==NULL)
    {
        printf("rien a afficher , la liste est vide\n");
    } */
    while (li!=NULL)
    {
        printf("%s\n" , li->nom_hotel );
        li = li->Next;
    }
}
//***********************************************************************/
void print_list_Chm(ChamStruct *li)
{
     if(li==NULL)
    {
        printf(" Aucune Reservation \n \n");
    }

    while (li!=NULL)
    {
          {
        printf("\t N Chambre : %s | Statut : %s  | Nom : %s | Date-Debut :  %s | Date-Fin :  %s \n" , li->n_chambre, li->statut , li->nom , li->date_debut , li->date_fin ); }
        li = li->Next;

    }

}
//**************************************************************************/
void Chargement (AlphaStruct **annuaire)/**Charger les reservations depuis un fichier texte*/
{
int j,i ;
j=0;
char NomHotel[100] , ville[100]  ,capacite[100] , num_lib[100] , num_occ[100];
char Ch_num[100] ,  statu[100]  , prix[100] , type[100] , date_debut[100] , date_fin[100] ,nom[100];
char tabalpha[26]={0} ;char NomFichier[100] , ligne[100];
AlphaStruct *p = NULL,*q,*L,*z;
HotStruct *p1 ;
ChamStruct *p2 ;
FILE* fichier = NULL;
FILE* fichier2 = NULL;
q=NULL;
fichier = fopen("ListeHotel.txt", "r");

if (fichier != NULL)
    {
    while (!feof(fichier))
        {
        i=0 ;
        fgets(ligne , 50 , fichier) ;
        while( (i<26)&&(tabalpha[i]!= ligne[0]))
            {
                i++;
            }
        if (i==26)
            {
                tabalpha[j]=ligne[0];
                j++;

                p= malloc(sizeof(annuaire));
                p->alph = ligne[0];
                p ->Next = q ;
               q=p;
            }

        }
    }
*annuaire=p;
fichier = NULL;
fichier = fopen("ListeHotel.txt", "r");
z=*annuaire;while(z!=NULL){z->Hotel=NULL,z=z->Next;}
while (!feof(fichier))
    {
        fgets(ligne , 100 , fichier) ;
        sscanf(ligne , "%s | %s | %s | %s | %s " , NomHotel , ville, capacite , num_lib , num_occ);
        L = *annuaire ;
        while ( L->alph != NomHotel[0] )
            {
                L = L->Next;
            }
        p1=malloc(sizeof(HotStruct));
        strcpy((*p1).nom_hotel , NomHotel);
        strcpy((*p1).nom_ville , ville) ;
        strcpy((*p1).capacite , capacite) ;
        strcpy((*p1).n_chm_L , num_lib) ;
        strcpy((*p1).n_chm_O , num_occ) ;
        (*p1).Chambre_Lib=NULL;
        (*p1).Chambre_Occ=NULL;
        strcpy(NomFichier, strcat(NomHotel , ".txt\0") ) ;
        fichier2 = NULL ;
        fichier2 = fopen(NomFichier, "r");
        while (!feof(fichier2))
            {
                fgets(ligne , 100 , fichier2) ;
                sscanf(ligne , " %s | %s | %s | %s | %s | %s | %s" , statu , Ch_num , prix , type , date_debut , date_fin , nom );
                p2=malloc(sizeof(ChamStruct));
                strcpy( (*p2).statut  , statu);
                strcpy( (*p2).n_chambre  , Ch_num );
                strcpy( (*p2).prix  , prix );
                strcpy( (*p2).type  , type );
                strcpy( (*p2).date_debut  , date_fin );
                strcpy( (*p2).date_fin  , date_fin );
                strcpy( (*p2).nom  , nom );
                if ( statu[0] == 'O')
                    {
                        (*p2).Next = (*p1).Chambre_Occ ;
                        (*p1).Chambre_Occ = p2 ;
                    }
                else
                    {
                        (*p2).Next = (*p1).Chambre_Lib ;
                        (*p1).Chambre_Lib = p2 ;
                    }
            }
       (*p1).Next=L->Hotel;
        L->Hotel=p1;
 }
}
//**********************************************************************/
void affich_statut (AlphaStruct *annuaire)/**Afficher les statuts du réservation**/
{
    AlphaStruct *p;
    HotStruct *q;
    ChamStruct *r2;
    if(annuaire==NULL)
    {
        printf("VEUILLEZ CHARGER LA LISTE SVP \n");
    }
    else
    {
        p=annuaire;
        while(p!=NULL)
        {
            q=p->Hotel;
            while(q!=NULL)
            {
                printf("%s\n \n",q->nom_hotel);
                r2=q->Chambre_Occ;
                print_list_Chm(r2);
                q=q->Next;
            }
        p=p->Next ;
        }
    }
}
//************************************************************/
void Chm_Rech(AlphaStruct *t)/**Rechercher une chambre libre selon son type (individuelle ou à deux)**/
{
int k, j , prix , MinPrix , exist = 0 , exist2 = 0 ;
AlphaStruct *o ;
HotStruct *o1 ;
ChamStruct *o2;
char ville[100] , hotel[100] , MinHotel [100] , MinNum[100] , MinType[100] ;
printf(" 1 - RECHERCHER UNE CHAMBRE INDIVIDUELLE \n") ;
printf(" 2 - RECHERCHER UNE CHAMBRE DOUBLE \n") ;
scanf("%d" , &k);
switch(k)
{
    case 1 :
        {
            printf(" 1 - DANS UNE VILLE DONNE \n") ;
            printf(" 2 - DANS UN HOTEL DONNE \n") ;
            printf(" 3 - LE PLUS PETIT PRIX \n ") ;
            scanf("%d" , &j);
            switch(j)
            {
                case 1 :
                    {
                        printf("DONNEZ LE NOM DU LA VILLE  \n ") ;
                        scanf("%s" , ville) ;
                        o = t ;
                        while ( o != NULL)
                            {
                                o1 = o->Hotel ;
                                while ( o1 != NULL)
                                {
                                    if (strcmp( (o1->nom_ville) ,ville ) == 0 )
                                        {
                                        exist = 1 ;
                                        o2 = o1->Chambre_Lib ;
                                        while (o2!=NULL)
                                            {
                                                if ( strcmp(o2->type , "Individuelle") == 0)
                                                    {
                                                        exist2 = 1 ;
                                                        printf("\t N°Chambre : %s   L'Hotel : %s   Prix  :  %s DA \n" , o2->n_chambre, o->Hotel->nom_hotel, o2->prix );
                                                    }
                                                o2= o2->Next;
                                            }
                                        }
                                    o1 = o1->Next ;
                                }
                                o = o->Next ;
                            }
                    if ( exist == 0) { printf(" CETTE VILLE N'EXISTE PAS !! \n "); break;}
                    if ( exist2 == 0) { printf(" IL YA PAS DE TYPE INDIVIDUELLE  DANS CETTE VILLE !! \n");}
                    break ;
                    }
                case 2 :
                    {
                        printf("DONNEZ LE NOM DU L'HOTEL \n") ;
                        scanf("%s" , hotel) ;
                        o = t ;
                        while ( o != NULL)
                            {
                                o1 = o->Hotel ;
                                while ( o1 != NULL)
                                    {
                                        if (strcmp( (o1->nom_hotel) ,hotel ) == 0 )
                                        {
                                            exist = 1 ;
                                            o2 = o1->Chambre_Lib ;
                                            while (o2!=NULL)
                                                {
                                                    if ( strcmp(o2->type , "Individuelle") == 0)
                                                    {
                                                        exist2 = 1 ;
                                                        printf("\t N°Chambre : %s  Le prix est : %s DA \n " , o2->n_chambre , o2->prix);
                                                    }
                                                ( o2 )  =  ( o2->Next );
                                                }
                                        }
                                        o1 = o1->Next ;
                                    }
                                o = o->Next ;
                            }
                        if ( exist == 0) { printf(" CE HOTEL N'EXISTE PAS  !! \n "); break;}
                        if ( exist2 == 0) { printf(" IL YA PAS DE TYPE INDIVIDUELLE DANS CETTE VILLE !! \n");}
                        break ;
                    }
                case 3 :
                    {
                        o = t ;
                        MinPrix = 5000000 ;
                        while ( o != NULL)
                            {
                                o1 = o->Hotel ;
                                while ( o1 != NULL)
                                    {
                                        o2 = o1->Chambre_Lib ;
                                        while (o2!=NULL)
                                            {
                                                if ( strcmp(o2->type , "Individuelle") == 0)
                                                {
                                                    prix = strtol(o2->prix , NULL , 10) ;
                                                    if ( prix < MinPrix)
                                                        {
                                                            MinPrix = prix ;
                                                            strcpy(MinHotel , o->Hotel->nom_hotel) ;
                                                            strcpy(MinNum , o2->n_chambre) ;
                                                            strcpy(MinType , o2->type ) ;
                                                        }
                                                }
                                                o2 = o2->Next;
                                            }
                                        o1 = o1->Next ;
                                    }
                                o = o->Next ;
                            }
                        printf(" N CHambre : %s \t L'Hotel : %s \t Type : %s \t , Prix : %d  DA \n" ,MinNum , MinHotel , MinType, MinPrix);
                        break ;
                    }
            }
        break ;
        };
    case 2  :
        {
            printf(" 1 - DANS UNE VILLE DONNE \n") ;
            printf(" 2 - DANS UN HOTEL DONNE \n") ;
            printf(" 3 - LE PLUS PETIT PRIX \n ") ;
            scanf("%d" , &j);
            switch(j)
                {
                    case 1 :
                        {
                            printf("DONNEZ LE NOM DU LA VILLE  \n ") ;
                            scanf("%s" , ville) ;
                            o = t ;
                            while ( o != NULL)
                                {
                                    o1 = o->Hotel ;
                                    while ( o1 != NULL)
                                        {
                                            if (strcmp( (o1->nom_ville) ,ville ) == 0 )
                                                {
                                                    exist = 1 ;
                                                    o2 = o1->Chambre_Lib ;
                                                    while (o2!=NULL)
                                                        {
                                                            if ( strcmp(o2->type , "Double") == 0)
                                                            {
                                                                exist2 = 1 ;
                                                                printf("\t N°Chambre : %s | L'Hotel : %s  \n" , o2->n_chambre, o->Hotel->nom_hotel);
                                                            }
                                                            ( o2 )  =  ( o2->Next );
                                                        }
                                                }
                                            o1 = o1->Next ;
                                        }
                                    o = o->Next ;
                                }
                            if ( exist == 0) { printf(" CETTE VILLE N'EXISTE PAS"); break;}
                            if ( exist2 == 0) { printf(" IL YA PAS DE TYPE DOUBLE DANS CETTE VILLE !!");}
                            break ;
                        }
                    case 2 :
                        {
                            printf("DONNEZ LE NOM DU L'HOTEL \n ") ;
                            scanf("%s" , hotel) ;
                            o = t ;
                            while ( o != NULL)
                                {
                                    o1 = o->Hotel ;
                                    while ( o1 != NULL)
                                        {
                                            if (strcmp( (o1->nom_hotel) ,hotel ) == 0 )
                                                {
                                                    exist = 1 ;
                                                    o2 = o1->Chambre_Lib ;
                                                    while (o2!=NULL)
                                                        {
                                                            if ( strcmp(o2->type , "Double") == 0)
                                                            {
                                                                exist2 = 1 ;
                                                                printf("\t N°Chambre : %s  Le prix est : %s DA \n " , o2->n_chambre , o2->prix);
                                                            }
                                                            ( o2 )  =  ( o2->Next );
                                                        }
                                                }
                                            o1 = o1->Next ;
                                        }
                                    o = o->Next ;
                                }
                            if ( exist == 0) { printf(" CE HOTEL N'EXISTE PAS!!"); break;}
                            if ( exist2 == 0) { printf(" IL YA PAS DE TYPE INDIVIDUELLE DANS CE HOTEL !!");}
                            break ;
                        }
                    case 3 :
                        {
                            o = t ;
                            MinPrix = 5000000 ;
                            while ( o != NULL)
                                {
                                    o1 = o->Hotel ;
                                    while ( o1 != NULL)
                                        {
                                            o2 = o1->Chambre_Lib ;
                                            while (o2!=NULL)
                                                {
                                                    if ( strcmp(o2->type , "Double") == 0)
                                                        {
                                                            prix = strtol(o2->prix , NULL , 10) ;
                                                            if ( prix < MinPrix)
                                                                {
                                                                    MinPrix = prix ;
                                                                    strcpy(MinHotel , o->Hotel->nom_hotel) ;
                                                                    strcpy(MinNum , o2->n_chambre) ;
                                                                    strcpy(MinType , o2->type ) ;
                                                                }
                                                        }
                                                    o2 = o2->Next;
                                                }
                                            o1 = o1->Next ;
                                        }
                                    o = o->Next ;
                                }
                            printf(" N CHAMBRE  : %s \t L'HOTEL : %s \t TYPE : %s \t , PRIX : %d DA \n" ,MinNum , MinHotel , MinType, MinPrix);
                            break ;
                        }
                }
            break ;
        };
}
}
//**************************************************************************/
void Nom_Rech(AlphaStruct *t)/**Rechercher la Réservation effectuée par une personne « Nom »**/
{
char Nom[100];
int exist = 0  ;
AlphaStruct *o ;
printf("DONNEZ LE NOM DE PERSONNE  \n") ;
scanf("%s" , Nom) ;
o = t ;
while ( o != NULL)
    {
        while ( o->Hotel != NULL)
            {
                 while (o->Hotel->Chambre_Occ!=NULL)
                        {
                            if ( strcmp(o->Hotel->Chambre_Occ->nom  , Nom) == 0)
                                {
                                    exist =  1 ;
                                    printf(" TOUS LES RESERVATIONS EFFECTUES PAR CETTE PERSONNE SONT  : \n") ;
                                    printf("%s \t %s \t %s \t %s \t %s \t \n" , o->Hotel->Chambre_Occ->n_chambre , o->Hotel->Chambre_Occ->statut , o->Hotel->Chambre_Occ->type , o->Hotel->Chambre_Occ->date_debut , o->Hotel->nom_hotel ) ;
                                }
                            o->Hotel->Chambre_Occ = o->Hotel->Chambre_Occ->Next;
                        }
                o->Hotel = o->Hotel->Next ;
            }
        o = o->Next ;
    }
if ( exist == 0 ) { printf(" CE NOM N'EXISTE PAS !! ");}
}
//**************************************************************************/
void PrintAll(AlphaStruct *o)
{
    AlphaStruct *t ;
    HotStruct *q;
    ChamStruct *r1 , *r2;
    t = o ;
    while ( t != NULL)
        {
            printf("La Lettre  : %c \n" , t->alph)  ;
            q=t->Hotel;
            while ( q !=NULL)
                {
                    printf("\t %s \t %s \n" , q->nom_hotel , q->nom_ville) ;
                    r1=q->Chambre_Occ;
                    r2=q->Chambre_Lib;
                    while (r2 != NULL )
                        {
                            printf("\t \t %s \t %s \t %s \t %s \t %s %s \n" ,r2->n_chambre ,r2->nom ,r2->statut , r2->type , r2->prix , "DA") ;
                            r2 =r2->Next ;
                        }
                    while ( r1 != NULL )
                        {
                            printf("\t \t %s \t %s \t %s \t %s \t %s %s \n" , r1->n_chambre , r1->nom , r1->statut , r1->type , r1->prix , "DA") ;
                            r1 = r1->Next ;
                        }
                    q = q->Next ;
                }
            t = t->Next ;
        }
}
//**************************************************************************/
void inserer_res(AlphaStruct **annuaire)/**Insérer une nouvelle Réservation**/
{
    char nomhotel[100],nom[100],num_chm[100],date_debut[100],date_fin[100];
    AlphaStruct *p;
    HotStruct *q;
    char ch[20] ;
    ChamStruct *r1,*r2,*a,*b,*d;
    if (*annuaire==NULL)
    {
        printf("VEUILLEZ CHARGER LA LISTE SVP \n");
    }
    else
    {
        p=*annuaire;
        printf("DONNEZ LE NOM D'HOTEL : (PREMIERE LETTRE EN MAJUSCULE)\n");
        scanf("%s",nomhotel);
        while ((p->Next!=NULL )&&( p->alph != nomhotel[0] ))
            {
                p = p->Next;
            }
        if(p->alph != nomhotel[0])
            {
                printf("HOTEL NON DISPONIBLE \n");
            }
        else
            {
                q=p->Hotel;
                while (strcmp(q->nom_hotel,nomhotel)!=0 && q->Next!=NULL)
                    {
                        q=q->Next;
                    }
                if(strcmp(q->nom_hotel,nomhotel)!=0 && q!=NULL)
                    {
                        printf("HOTEL NON DISPONIBLE \n");
                    }
                else
                    {
                        printf("DONNEZ LE NUMERO DE LA CHAMBRE : \n");
                        scanf("%s",num_chm);
                        r1=q->Chambre_Lib;
                        while(( r1->Next!=NULL) && (strcmp(r1->n_chambre,num_chm)!=0))
                            {
                                r1=r1->Next;
                            }
                        if (strcmp(r1->n_chambre,num_chm)!=0)
                            {
                                r2=q->Chambre_Occ;
                                if (r2==NULL)
                                    {
                                        printf("CETTE CHAMBRE N'EXISTE PAS \n");
                                    }
                                else
                                    {
                                        while(strcmp(r2->n_chambre,num_chm)!=0 && r2->Next!=NULL)
                                            {
                                                r2=r2->Next;
                                            }
                                        if(strcmp(r2->n_chambre,num_chm)!=0)
                                            {
                                            printf("CETTE CHAMBRE N'EXISTE PAS \n");
                                            }
                                        else
                                            {
                                            printf("LA CHAMBRE %s EST OCCUPE  \n",num_chm);
                                            }
                                    }
                            }
                        else
                            {
                                printf("DONNEZ LA DATE DE DEBUT SOUS FORME forme dd/mm/xxxx : \n");
                                scanf("%s",date_debut);
                                printf("DONNEZ LA DATE DE FIN SOUS FORME dd/mm/xxxx : \n");
                                scanf("%s",date_fin);
                                printf("DONNEZ VOTRE NOM SVP : \n");
                                scanf("%s",nom);
                                a=q->Chambre_Lib;
                                int i=0;
                                while(strcmp(a->n_chambre,num_chm)!=0)
                                    {
                                        b=a;
                                        a=a->Next;
                                        i++;
                                    }
                                if (i==0){q->Chambre_Lib=q->Chambre_Lib->Next;}
                                else {b->Next=a->Next;}
                                strcpy(a->n_chambre,num_chm);
                                strcpy(a->date_debut,date_debut);
                                strcpy(a->nom,nom);
                                strcpy(a->date_fin,date_fin);
                                strcpy(a->statut,"Occupe");
                                strcpy(q->n_chm_O , itoa( strtol(q->n_chm_O , NULL , 10 )  + 1 ,ch , 10 ));
                                strcpy(q->n_chm_L , itoa( strtol(q->n_chm_L , NULL , 10 )  - 1 ,ch , 10 ));
                                a->Next=NULL;
                                d=q->Chambre_Occ;
                                if(d==NULL){q->Chambre_Occ=a;}
                                else
                                {
                                   while(d->Next!=NULL)
                                        {
                                            d=d->Next;
                                        }
                                    d->Next=a;
                                }
                                printf("\t RESERVATION AVEC SUCCES \n");
                            }
                    }
            }
    }
}
//************************************************/
void supprimer_res(AlphaStruct **annuaire)/**Supprimer une Réservation**/
{
    char nomhotel[100] , nom[100];
    AlphaStruct *p;
    HotStruct *q;
    char ch[20];
    ChamStruct *a,*b,*d,*e;
        if (*annuaire==NULL)
            {
                printf("VEUILLEZ CHARGER LA LISTE SVP \n");
            }
        else
            {
                p=*annuaire;
                printf("DONNEZ LE NOM D'HOTEL \n ");
                scanf("%s",nomhotel);
                while ( p->alph != nomhotel[0] && p!=NULL )
                    {
                        p = p->Next;
                    }
                if(p->alph != nomhotel[0])
                    {
                        printf("HOTEL NON DISPONIBLE \n");
                    }
                else
                    {
                        q=p->Hotel;
                        while (strcmp(q->nom_hotel,nomhotel)!=0 && q!=NULL)
                            {
                                q=q->Next;
                            }
                        if(strcmp(q->nom_hotel,nomhotel)!=0)
                            {
                                printf("HOTEL NON DISPONIBLE \n");
                            }
                        else
                            {
                                printf("DONNEZ VOTRE NOM : \n");
                                scanf("%s",nom);
                                e=q->Chambre_Occ;
                                if (e==NULL)
                                    {
                                       printf("VOTRE NOM NE FIGURE PAS DANS NOTRE HOTEL ! MERCI !\n");
                                    }
                                else
                                    {
                                        while(strcmp(e->nom,nom)!=0 && e->Next!=NULL)
                                            {
                                                e=e->Next;
                                            }
                                        if(strcmp(e->nom,nom)!=0)
                                            {
                                                printf("VOTRE NOM NE FIGURE PAS DANS NOTRE HOTEL ! MERCI !\n");
                                            }
                                        else
                                            {
                                                a=q->Chambre_Occ;
                                                int i=0;
                                                while(strcmp(a->nom,nom)!=0)
                                                    {
                                                        b=a;
                                                        a=a->Next;
                                                        i++;
                                                    }
                                                if (i==0){q->Chambre_Occ=q->Chambre_Occ->Next;}
                                                else {b->Next=a->Next;}
                                                strcpy(a->date_debut,"NULL");
                                                strcpy(a->nom,"NULL");
                                                strcpy(q->n_chm_L , itoa( strtol(q->n_chm_L , NULL , 10 )  + 1 ,ch , 10 ));
                                                strcpy(q->n_chm_O , itoa( strtol(q->n_chm_O , NULL , 10 )  - 1 ,ch , 10 ));
                                                strcpy(a->date_fin,"NULL");
                                                strcpy(a->statut,"Libre");
                                                a->Next=NULL;
                                                d=q->Chambre_Lib;
                                                printf("LA RESERVATION EST SUPPRIME\n");
                                                while(d->Next!=NULL)
                                                {
                                                    d=d->Next;
                                                }
                                                d->Next=a;
                                            }
                                    }
                            }
                    }
            }
}
//**************************************************************************/
void modifier_res(AlphaStruct **annuaire)/**Modifier une Réservation**/
{
    int k;
    AlphaStruct *p;
    HotStruct *q;
    ChamStruct *a,*e,*z,*r1,*r2,*b,*d,*x,*y,*c,*m;
    char nom_hotel[100],nom[100],nom2[100],date_debut[100],date_fin [100],num_chm[100];

    if (*annuaire==NULL)
    {
        printf("VEUILLEZ CHARGER LA LISTE SVP \n");
    }
    else
    {
    p=*annuaire;
    printf("DONNEZ LE NOM DU L'HOTEL\n");
    scanf("%s",nom_hotel);
    while ( p->alph != nom_hotel[0] && p->Next!=NULL )
        {
            p = p->Next;
        }
    if(p->alph != nom_hotel[0])
        {
            printf("HOTEL NON DISPONIBLE \n");
        }
    else
        {
            q=p->Hotel;
            while (strcmp(q->nom_hotel,nom_hotel)!=0 && q!=NULL)
                {
                    q=q->Next;
                }
            if(strcmp(q->nom_hotel,nom_hotel)!=0)
                {
                    printf("HOTEL NON DISPONIBLE \n");
                }
            else
                {
                    printf("DONNEZ VOTRE NOM  \n");
                    scanf("%s",nom);
                    e=q->Chambre_Occ;
                    if(e==NULL)
                    {
                        printf("VOTRE NOM NE FIGURE PAS DANS NOTRE HOTEL ! MERCI !\n");
                    }
                    else
                    {
                    while(strcmp(e->nom,nom)!=0 && e->Next!=NULL)
                        {
                            e=e->Next;
                        }
                    if(strcmp(e->nom,nom)!=0)
                        {
                            printf("VOTRE NOM NE FIGURE PAS DANS NOTRE HOTEL ! MERCI !\n");
                        }
                    else
                        {
                            m=q->Chambre_Occ;
                            while(strcmp(m->nom,nom)!=0)
                                {
                                      m=m->Next;
                                }
                            printf("\tChambre  %s |%s |%s |%s |%s |%s |%s DA \n" , m->n_chambre, m->type , m->statut , m->nom , m->date_debut , m->date_fin , m->prix );
                            printf("QUE VOULEZ VOUS FAIRE ?\n");
                            printf("\t 1 - CHANGER CHAMBRE\n");
                            printf("\t 2 - CHANGER NOM\n");
                            printf("\t 3 - CHANGER DATE DEBUT \n");
                            printf("\t 4 - CHANGER DATE FIN \n");
                            scanf("%d" , &k);
                            switch(k)
                                {
                                    case 1 :
                                        {
                                            printf("VOICI LES CHAMBRES LIBRES DANS NOTRE HOTEL '%s' :\n",q->nom_hotel);
                                            z=q->Chambre_Lib;
                                            while(z!=NULL)
                                                {
                                                    printf("\t CHAMBRE :%s |%s |%s DA \n" , z->n_chambre, z->type , z->prix );
                                                    z=z->Next;
                                                }
                                            printf("DONNEZ LE NUMERO DE LA CHAMBRE QUE VOUS VOULEZ RESERVER : \n");
                                            scanf("%s",num_chm);
                                            r1=q->Chambre_Lib;
                                            while(strcmp(r1->n_chambre,num_chm)!=0 && r1->Next!=NULL)
                                                {
                                                    r1=r1->Next;
                                                }
                                            if (strcmp(r1->n_chambre,num_chm)!=0)
                                                {
                                                    r2=q->Chambre_Occ;
                                                    while(strcmp(r2->n_chambre,num_chm)!=0 && r2->Next!=NULL)
                                                        {
                                                            r2=r2->Next;
                                                        }
                                                    if(strcmp(r2->n_chambre,num_chm)!=0)
                                                        {
                                                            printf("LA CHAMBRE N'EXISTE PAS \n");
                                                        }
                                                    else
                                                        {
                                                            printf("LA CHAMBRE %s EST OCCUPE \n",num_chm);
                                                        }
                                                }
                                            else
                                                {
                                                    printf("DONNEZ LA DATE DEBIUT : \n");
                                                    scanf("%s",date_debut);
                                                    printf("DONNEZ LA DATE FIN  : \n");
                                                    scanf("%s",date_fin);
                                                    a=q->Chambre_Occ;
                                                    int i=0;
                                                    while(strcmp(a->nom,nom))
                                                        {
                                                            b=a;
                                                            a=a->Next;
                                                            i++;
                                                        }
                                                    if (i==0){q->Chambre_Occ=q->Chambre_Occ->Next;}
                                                    else {b->Next=a->Next;}
                                                    a->Next=NULL;
                                                    strcpy(a->statut,"Libre");
                                                    strcpy(a->nom,"NULL");
                                                    strcpy(a->date_debut,"NULL");
                                                    strcpy(a->date_fin,"NULL");
                                                    c=q->Chambre_Lib;
                                                    while(c->Next!=NULL)
                                                        {
                                                            c=c->Next;
                                                        }
                                                    c->Next=a;
                                                    x=q->Chambre_Lib;
                                                    int j=0;
                                                    while(strcmp(x->n_chambre,num_chm))
                                                        {
                                                            y=x;
                                                            x=x->Next;
                                                            j++;
                                                        }
                                                    if (j==0){q->Chambre_Lib=q->Chambre_Lib->Next;}
                                                    else {y->Next=x->Next;}
                                                    x->Next=NULL;
                                                    strcpy(x->statut,"Occupe");
                                                    strcpy(x->nom,nom);
                                                    strcpy(x->date_debut,date_debut);
                                                    strcpy(x->date_fin,date_fin);
                                                    d=q->Chambre_Occ;
                                                    if(d!=NULL)
                                                        {
                                                            while(d->Next!=NULL)
                                                                {
                                                                    d=d->Next;
                                                                }
                                                            d->Next=x;
                                                        }
                                                    else
                                                        {
                                                            q->Chambre_Occ=x;
                                                        }
                                                }
                                            break;
                                        }
                                    case 2:
                                        {
                                            printf("DONNEZ LE NOUVEAU NOM \n");
                                            scanf("%s",nom2);
                                            strcpy(m->nom,nom2);
                                            break;
                                        }
                                    case 3:
                                        {
                                            printf("VOTRE DATE DEBUT ACTUELLE EST : %s\n",m->date_debut);
                                            printf("DONNEZ LA NOUVELLE DATE DEBUT  \n");
                                            scanf("%s",date_debut);
                                            strcpy(m->date_debut,date_debut);
                                            break;
                                        }
                                    case 4:
                                        {
                                            printf("VOTRE DATE FIN ACTUELLE EST%s \n",m->date_fin);
                                            printf("DONNEZ LA NOUVELLE DATE FIN \n");
                                            scanf("%s",date_fin);
                                            strcpy(m->date_fin,date_fin);
                                            break;
                                        }
                                }
                        }
                }
            }
    }
    }
}
//**************************************************************************/
void SupHotel(AlphaStruct *tete)/**Supprimer un hôtel**/
{
AlphaStruct  *y ;
char  HotelName[100];
printf("DONNEZ LE NOM DU L'HOTEL QUE VOUS VOULEZ SUPPRIMER ?  \n ") ;
scanf("%s" , HotelName);
y=tete; AlphaStruct *p=NULL; int trouv=0;
while (!(trouv)&&(y))
    {
        if (y->alph==HotelName[0])trouv=1;
        else
            {
                p=y;
                y=y->Next;
            }
    }
    if (trouv)
        {
            HotStruct *pt=y->Hotel,*qt=NULL;
            int ext=0;
            while (!(ext)&&(pt))
                {
                    if (strcasecmp(pt->nom_hotel,HotelName)==0) ext=1;
                    else
                        {
                            qt=pt;
                            pt=pt->Next;
                        }
                }
            if (ext)
                {
                    if (qt)
                        {
                            qt->Next=pt->Next;
                        }
                    else
                        {
                            if (pt->Next==NULL)
                                {
                                    if (p) p->Next=y->Next;
                                    else tete=y->Next;
                                    free(y);
                                }
                            else
                                {
                                    y->Hotel=pt->Next;
                                    free(pt);
                                }
                        }
                    free(pt);
                }
            else
                {
                    printf(" L'HOTEL N'EXISTE PAS !  \n");
                }
        }
    else
        {
            printf(" L'HOTEL N'EXISTE PAS !  \n");
        }
}
//******************************************************************************/
void Ajouter (AlphaStruct *j )/**Ajouter un hôtel**/
{
char NewHotel[100] ; AlphaStruct *sav=j,*prec=NULL;
AlphaStruct *a ;
char ch[10] ;
char PrixDouble[20] , PrixIndi[20] ;
int capacite, NumDouble ;
ChamStruct *c , *c1;
HotStruct *o ;
int i , k ;
printf("DONNEZ LE NOM DU L'HOTEL QUE VOUS VOULEZ AJOUTER \n") ;
scanf("%s" , NewHotel);
while ( (sav != NULL) && (NewHotel[0] != sav->alph))
{
    prec=sav;
    sav= sav->Next ;
}
if ( sav == NULL)
{
    a = malloc(sizeof(AlphaStruct)) ;
    a->alph = NewHotel[0];
    a->Next = NULL ;
    prec->Next=a;
    o = malloc(sizeof(HotStruct)) ;
    strcpy(o->nom_hotel , NewHotel) ;
    o->Next = NULL;
    a->Hotel = o ;
    printf(" DONNEZ LA VILLE DE L'HOTEL \n") ;
    scanf("%s" , a->Hotel->nom_ville) ;
    printf(" DONNEZ SA CAPACITE  \n") ;
    scanf("%s" , a->Hotel->capacite) ;
    strcpy(a->Hotel->n_chm_O , "0");
    strcpy(a->Hotel->n_chm_L , (a->Hotel->capacite));
    capacite =  strtol((a->Hotel->capacite) , NULL , 10) ;
    printf("COMBIEN DE CHAMBRE DOUBLE EXISTE ?? \n") ;
    scanf("%d" , &NumDouble) ;
    printf(" DONNEZ LE PRIX DES CHAMBRES DOUBLES \n") ;
    scanf("%s", PrixDouble) ;
    printf(" DONNEZ LE PRIX DES CHAMBRES INDIVIDUELLES \n") ;
    scanf("%s", PrixIndi) ;
    c = malloc(sizeof(ChamStruct)) ;
    o->Chambre_Lib=c;
    strcpy( c->n_chambre , "1"  );
    strcpy( c->type , "Double" )  ;
    strcpy( c->statut , "Libre" )  ;
    strcpy( c->prix , PrixDouble )  ;
    strcpy( c->date_debut , "NULL" )  ;
    strcpy( c->date_fin , "NULL" )  ;
    strcpy( c->nom , "NULL" )  ;
    for ( i = 2 ; i<=NumDouble ; i++)
        {
        c1 = malloc(sizeof(ChamStruct)) ;
        strcpy( c1->n_chambre , itoa(i , ch , 10)  ) ;
        strcpy( c1->type , "Double" )  ;
        strcpy( c1->statut , "Libre" )  ;
        strcpy( c1->prix , PrixDouble )  ;
        strcpy( c1->date_debut , "NULL" )  ;
        strcpy( c1->date_fin , "NULL" )  ;
        strcpy( c1->nom , "NULL" )  ;
        c ->Next = c1 ;
        c = c1 ;
        }
    for ( k = NumDouble+1 ; k <= ( capacite ) ; k++)
        {
        c1 = malloc(sizeof(ChamStruct)) ;
        strcpy( c1->n_chambre , itoa(k , ch , 10)  ) ;
        strcpy( c1->type , "Individuelle" )  ;
        strcpy( c1->statut , "Libre" )  ;
        strcpy( c1->prix , PrixIndi )  ;
        strcpy( c1->date_debut , "NULL" )  ;
        strcpy( c1->date_fin , "NULL" )  ;
        strcpy( c1->nom , "NULL" )  ;
        c ->Next = c1 ;
        c = c1 ;
        }
    c->Next=NULL;
}
else
{
    o = malloc(sizeof(HotStruct)) ;
    strcpy(o->nom_hotel , NewHotel) ;
    o->Next = sav->Hotel ;
    sav->Hotel = o ;
    printf("  DONNEZ LA VILLE DU L'HOTEL\n") ;
    scanf("%s" , sav->Hotel->nom_ville) ;
    printf(" DONNEZ SA CAPACITE \n") ;
    scanf("%s" , sav->Hotel->capacite) ;
    strcpy(sav->Hotel->n_chm_O , "0");
    strcpy(sav->Hotel->n_chm_L , sav->Hotel->capacite);
    capacite =  strtol(sav->Hotel->capacite , NULL , 10) ;
    printf(" DONNEZ LE PRIX DES CHAMBRES DOUBLES  \n") ;
    scanf("%d" , &NumDouble) ;
    c = malloc(sizeof(ChamStruct)) ;
    o->Chambre_Lib=c;
    strcpy( c->n_chambre , "1"  );
    strcpy( c->type , "Double" )  ;
    strcpy( c->statut , "Libre" )  ;
    strcpy( c->prix , PrixDouble )  ;
    strcpy( c->date_debut , "NULL" )  ;
    strcpy( c->date_fin , "NULL" )  ;
    strcpy( c->nom , "NULL" )  ;
    for ( i = 2 ; i<=NumDouble ; i++)
    {
        c1 = malloc(sizeof(ChamStruct)) ;
        strcpy( c1->n_chambre , itoa(i , ch , 10)  ) ;
        strcpy( c1->type , "Double" )  ;
        strcpy( c1->statut , "Libre" )  ;
        strcpy( c1->prix , PrixDouble )  ;
        strcpy( c1->date_debut , "NULL" )  ;
        strcpy( c1->date_fin , "NULL" )  ;
        strcpy( c1->nom , "NULL" )  ;
        c->Next = c1 ;
        c = c1 ;
    }
    for ( k = NumDouble+1 ; k <= ( capacite ) ; k++)
    {
        c1 = malloc(sizeof(ChamStruct)) ;
        strcpy( c1->n_chambre , itoa(k , ch , 10)  ) ;
        strcpy( c1->type , "Individuelle" )  ;
        strcpy( c1->statut , "Libre" )  ;
        strcpy( c1->prix , PrixIndi )  ;
        strcpy( c1->date_debut , "NULL" )  ;
        strcpy( c1->date_fin , "NULL" )  ;
        strcpy( c1->nom , "NULL" )  ;
        c->Next = c1;
        c = c1 ;
    }
    c->Next=NULL;
}
}
//**************************************************************************/
void Sauvgarder(AlphaStruct *tete)/**Sauvegarder les réservations dans un fichier texte**/
{
AlphaStruct *t ;
FILE* fichier1 = NULL ; ChamStruct *chm;
char NomFichier[100] ; HotStruct *hotel;
FILE* fichier2 =NULL ;
char oulah[200] ;
t = tete ;
fichier1 = fopen("ListeHotel.txt" , "w");
while ( t != NULL)
    {
        hotel=t->Hotel;
        while ( hotel != NULL)
            {
                fprintf(fichier1 , hotel->nom_hotel);
                fprintf(fichier1 , " | ");
                fprintf(fichier1 , hotel->nom_ville);
                fprintf(fichier1 , " | ");
                fprintf(fichier1 , hotel->capacite);
                fprintf(fichier1 , " | ");
                fprintf(fichier1 , hotel->n_chm_L);
                fprintf(fichier1 , " | ");
                fprintf(fichier1 , hotel->n_chm_O);
                fprintf(fichier1 , " | ");
                if ( t->Next != NULL || hotel->Next != NULL )
                    {
                        fputs( "\n", fichier1);
                    }
                strcpy ( oulah , hotel->nom_hotel) ;
                strcat ( oulah , ".txt\0") ;
                strcpy (NomFichier,oulah);
                fichier2 = fopen(NomFichier , "w") ;
                chm=hotel->Chambre_Lib;
                while ( chm != NULL)
                    {
                        fprintf(fichier2 , chm->statut);
                        fprintf(fichier2 , " | ");
                        fprintf(fichier2 , chm->n_chambre);
                        fprintf(fichier2 , " | ");
                        fprintf(fichier2 , chm->prix);
                        fprintf(fichier2 , " | ");
                        fprintf(fichier2 , chm->type);
                        fprintf(fichier2 , " | ");
                        fprintf(fichier2 , chm->date_debut);
                        fprintf(fichier2 , " | ");
                        fprintf(fichier2 , chm->date_fin);
                        fprintf(fichier2 , " | ") ;
                        fprintf(fichier2 , chm->nom);
                        fprintf(fichier2 , " | ");

                        chm= chm->Next ;
                        if( ( chm != NULL ) || ( hotel->Chambre_Occ != NULL ))
                            {
                                fputs( "\n", fichier2);
                            }
                    }
                chm=hotel->Chambre_Occ ;
                while ( chm!= NULL)
                    {
                        fprintf(fichier2 , chm->statut);
                        fprintf(fichier2 , " | ");
                        fprintf(fichier2 , chm->n_chambre);
                        fprintf(fichier2 , " | ");
                        fprintf(fichier2 , chm->prix);
                        fprintf(fichier2 , " | ");
                        fprintf(fichier2 , chm->type);
                        fprintf(fichier2 , " | ");
                        fprintf(fichier2 , chm->date_debut);
                        fprintf(fichier2 , " | ");
                        fprintf(fichier2 , chm->date_fin);
                        fprintf(fichier2 , " | ");
                        fprintf(fichier2 , chm->nom);
                        fprintf(fichier2 , " | ");
                        if ( chm->Next != NULL)
                            {
                                fputs( "\n", fichier2);
                            }
                        chm= chm->Next ;
                    }
                hotel = hotel->Next ;
            }
    t = t->Next ;
    }
fclose(fichier1); fclose(fichier2);
}
//**************************************************************************/
void Liberer_date(AlphaStruct **tete)/**Libérer toutes les chambres occupées ayant une date de fin égale à la date du jour**/
{
    AlphaStruct *p;
    HotStruct *h;
    ChamStruct *a,*b,*d,*c;
    char ch[20];
    char date_jour[100],mot[100];strcpy(mot,"11");
    time_t temps;
    strcpy(date_jour, "");
    struct tm date;
    time(&temps);
    date=*localtime(&temps);
    strftime(date_jour,128,"%d/%m/%Y",&date);
    if (*tete==NULL)
        {
            printf("VEUILLEZ CHARGER LA LISTE SVP\n");
        }
    else
        {
            p=*tete;
            while(p!=NULL)
                {
                    h=p->Hotel;
                    while (h!=NULL)
                        {
                            c=h->Chambre_Occ;
                            int i=0;
                            while(c!=NULL )
                                {
                                    if(strcmp(c->date_fin,date_jour)==0)
                                        {
                                            if (i==0){h->Chambre_Occ=h->Chambre_Occ->Next;a=c;c=c->Next;}
                                            else {a=c;c=c->Next;b->Next=a->Next;}
                                            a->Next=NULL;
                                            strcpy(a->date_debut,"NULL");
                                            strcpy(a->nom,"NULL");
                                            strcpy(a->date_fin,"NULL");
                                            strcpy(a->statut,"Libre");
                                            strcpy(h->n_chm_L , itoa( strtol(h->n_chm_L , NULL , 10 )  + 1 ,ch , 10 ));
                                            strcpy(h->n_chm_O , itoa( strtol(h->n_chm_O , NULL , 10 )  - 1 ,ch , 10 ));
                                            d=h->Chambre_Lib;
                                            while(d->Next!=NULL)
                                                {
                                                    d=d->Next;
                                                }
                                            d->Next=a;
                                        }
                                    else
                                        {
                                            b=c;
                                            c=c->Next;
                                            i=1;
                                        }
                                }
                            h=h->Next;
                        }
                    p=p->Next;
                }
        }
}
//**************************************************************************/
HotStruct *trier(HotStruct *s)/**Trier une seule liste des hôtels par ordre alphabétique**/
{
if(s!=NULL)
   {
    HotStruct *p,*q,*d;
    p=s;
    p=p->Next;
    q=p;
    s->Next=NULL;
    int i=0;
    while(q!=NULL)
       {
           i++;
            p=q;
            q=q->Next;
            if( s->Next==NULL)
                {
                    if (strcmp(s->nom_hotel,p->nom_hotel)<0)
                        {
                            s->Next=p;
                            p->Next=NULL;
                        }
                    else
                        {
                            p->Next=s;
                            s=p;
                        }
                }
            else
                {
                            if(strcmp(p->nom_hotel,s->nom_hotel)<0)
                                {
                                    p->Next=s;
                                    s=p;
                                }
                            else
                                {
                                    if (strcmp(p->nom_hotel,s->Next->nom_hotel)<0)
                                        {
                                            p->Next=s->Next;
                                            s->Next=p;
                                        }
                                    else
                                        {
                                            int j=0;
                                            d=s;
                                            while((s->Next!=NULL) && (strcmp(s->nom_hotel,p->nom_hotel)<0 && strcmp(s->Next->nom_hotel,p->nom_hotel)<0))
                                                {
                                                    j++;
                                                    s=s->Next;
                                                }
                                            if(s->Next==NULL)
                                                {
                                                    if (strcmp(s->nom_hotel,p->nom_hotel)<0)
                                                        {
                                                            s->Next=p;
                                                            p->Next=NULL;
                                                        }
                                                    else
                                                        {
                                                            p->Next=s;
                                                            s=p;
                                                        }
                                                }
                                            if(strcmp(s->nom_hotel,p->nom_hotel)<0 && strcmp(p->nom_hotel,s->Next->nom_hotel)<0)
                                                {
                                                    p->Next=s->Next;
                                                    s->Next=p;
                                                }
                                       s=d; }
                                }
                }
       }
    }
    return s;
}
//*****************************************************************/
AlphaStruct *trier2(AlphaStruct *s)/**Trier que Annuaire-Hotel par ordre alphabétique**/
{
if(s!=NULL)
   {
    AlphaStruct *p,*q,*d;
    p=s;
    p=p->Next;
    q=p;
    s->Next=NULL;
    int i=0;
    while(q!=NULL)
       {
           i++;
            p=q;
            q=q->Next;
            if( s->Next==NULL)
                {
                    if (s->alph < p->alph)
                        {
                            s->Next=p;
                            p->Next=NULL;
                        }
                    else
                        {
                            p->Next=s;
                            s=p;
                        }
                }
            else
                {
                            if(p->alph < s->alph)
                                {
                                    p->Next=s;
                                    s=p;
                                }
                            else
                                {
                                    if (p->alph < s->Next->alph)
                                        {
                                            p->Next=s->Next;
                                            s->Next=p;
                                        }
                                    else
                                        {
                                            int j=0;
                                            d=s;
                                            while((s->Next!=NULL) && (s->alph < p->alph) && (s->Next->alph < p->alph))
                                                {
                                                    j++;
                                                    s=s->Next;
                                                }
                                            if(s->Next==NULL)
                                                {
                                                    if (s->alph < p->alph)
                                                        {
                                                            s->Next=p;
                                                            p->Next=NULL;
                                                        }
                                                    else
                                                        {
                                                            p->Next=s;
                                                            s=p;
                                                        }
                                                }
                                            if((s->alph < p->alph) &&  (p->alph < s->Next->alph))
                                                {
                                                    p->Next=s->Next;
                                                    s->Next=p;
                                                }
                                       s=d; }
                                }
                }
       }
    }
    return s;
}
//*****************************************************************/
AlphaStruct *TRILAST (AlphaStruct *t)/**Trier les listes des hôtels par ordre alphabétique **/
{
    AlphaStruct *d;
    t=trier2(t);
    d=t;
    if(d==NULL){printf("VEUILLEZ CHARGER LA LISTE SVP\n");}
    while(d!=NULL)
    {
        d->Hotel=trier(d->Hotel);
        d=d->Next;
    }
    return t;
}





