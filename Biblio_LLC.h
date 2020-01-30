

typedef struct ChamStruct
{
    char n_chambre[100] ;
    char type[256] ;
    char statut[100] ;
    char date_debut[100] ;
    char date_fin[100] ;
    char nom[100] ;
    char prix[100] ;
    struct ChamStruct *Next ;
}ChamStruct ;

typedef struct HotStruct
{
    char nom_hotel[100];
    char nom_ville[100];
    struct HotStruct *Next ;
    char capacite[100];
    char n_chm_L[100] ;
    char n_chm_O[100] ;
    ChamStruct *Chambre_Occ ;
    ChamStruct *Chambre_Lib ;
} HotStruct;
typedef struct AlphaStruct
{
    char alph;
    struct AlphaStruct *Next;
    HotStruct *Hotel  ;
}AlphaStruct ;

void print_list_Hot(HotStruct *li);
void print_list_Alph(AlphaStruct *li);
void print_list_Chm(ChamStruct *li);
void Chargement (AlphaStruct **annuaire);
void affich_statut (AlphaStruct *annuaire);
void inserer_res(AlphaStruct **annuaire);
void modifier_res(AlphaStruct **annuaire);
void supprimer_res(AlphaStruct **annuaire);
void PrintAll(AlphaStruct *o);
void Chm_Rech(AlphaStruct *t);
void Nom_Rech(AlphaStruct *t);
void SupHotel(AlphaStruct *tete) ;
void Ajouter (AlphaStruct *j );
void Sauvgarder(AlphaStruct *t);
 void Liberer_date(AlphaStruct **tete);
 void write(char *chaine,int dela);
 void cadre(int opt);
