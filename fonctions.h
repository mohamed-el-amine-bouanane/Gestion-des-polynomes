
#ifndef _FONCTIONS_H_
#define _FONCTIONS_H_
#include "conio.c"
#include "graphique.h"

typedef struct Mailllon *Maillon; //structure d'un maillon repr�sentant un monome
struct Mailllon
{
    float coef;
    int puis;
    Maillon nxt;
    Maillon prc;
};

typedef struct ensemble *Ensemble; //structure d'un maillon qui repr�sente la t�te d'un polynome le tout dans une liste qui est notre ensemble de pol
struct ensemble
{
    Maillon pol;
    Ensemble nxt;
    Ensemble prc;
};

int length(Ensemble Tete) //donne la longueur d'une liste
{
    Ensemble q; int lgr=0;
     while (Tete != NULL)
        {
            lgr++;
            Tete=(*Tete).nxt;
        }
    return(lgr);
}

void Create_head(Maillon *Tete) //cr�er la t�te d'une liste
{
    Maillon p;
    p=malloc(sizeof(struct Mailllon));
    (*p).nxt=NULL;
    (*p).prc=NULL;
    *Tete=p;
}

void Add_maillon(Maillon *p) //si la queue actuelle de la liste est p alors Add_maillon(&p) permet de cr�er un maillon et le relier � p et ce nouveau maillon devient p - la nouvelle queue
{
    Maillon d;
    d=malloc(sizeof( struct Mailllon));
    (*(*p)).nxt=d;
    (*d).prc=*p;
    (*d).nxt=NULL;
    *p=d;
}

void Insert_maillon2(Maillon *Tete, Maillon p, Maillon q, int Sens) //ins�rer un maillon q dans une liste dont la t�te est Tete au niveau du maillon � l'adresse p : avant si sens==0 ou apr�s si sens==1
{
    Maillon m1; Maillon m2;
    m1=(*p).prc;
    m2=(*p).nxt;
    if (Sens==0)
    {
        if (m1==NULL)
        {
            (*q).nxt=p;
            (*p).prc=q;
            (*q).prc=NULL;
            *Tete=q;
        }
        else
        {
            (*m1).nxt=q;
            (*q).prc=m1;
            (*q).nxt=p;
            (*p).prc=q;
        }

    }
    else
        if (Sens==1)
        {
            if (m2==NULL)
            {
                (*p).nxt=q;
                (*q).prc=p;
                (*q).nxt=NULL;
            }
            else
            {
                (*p).nxt=q;
                (*q).prc=p;
                (*q).nxt=m2;
                (*m2).prc=q;
            }
        }
}

void Delete_maillon(Maillon *Tete, Maillon p) //Supprimer le maillon dont l'adresse p de la liste dont la t�te Tete
{
    if (p==*Tete)
    {
        *Tete=(*p).nxt;
        if ((*Tete) != NULL) (*(*Tete)).prc=NULL;
        free(p);
    }
    else
    {
        if ((*p).nxt==NULL)
        {
            (*(*p).prc).nxt=NULL;
            free(p);
        }
        else
        {
            (*(*p).prc).nxt=(*p).nxt;
            (*(*p).nxt).prc=(*p).prc;
            free(p);
        }
    }
}

void Create_polynome(Maillon *Tete,int x,int y,int l) //Cr�er un polyn�me reposant basiquement sur le principe de cr�ation d'une LLC classique
{
    Maillon p=NULL; int nb,i,j=1;
    gotoxy(x,y);
    if (l==FR)
                {

    printf("Entrez le nombre de termes de votre polynome : ");cadrintr(x,y+2);
    scanf("%d",&nb);

    Create_head(&(*Tete));
    p=*Tete;gotoxy(x,y+5);
    printf("coef[%d] = ",j);
    scanf("%f",&(*p).coef);gotoxy(x,y+6);
    printf("puis[%d] = ",j);
    scanf("%d",&(*p).puis);
    j++;y=wherey();
    for (i=1;i<nb;i++)
    {

        Add_maillon(&p);gotoxy(x,y+1);y++;
        printf("coef[%d] = ",j);
        scanf("%f",&(*p).coef);gotoxy(x,y+1);
        printf("puis[%d] = ",j);if ((!(j<5))&&i<5) {x=wherex()+4;y=wherey()-16;}
        scanf("%d",&(*p).puis);
        j++;y+=2;
    }}
    else
    {
        printf("Enter the number of terms of your polynomial : ");cadrintr(x,y+2);
    scanf("%d",&nb);

    Create_head(&(*Tete));
    p=*Tete;gotoxy(x,y+5);
    printf("coef[%d] = ",j);
    scanf("%f",&(*p).coef);gotoxy(x,y+6);
    printf("pow[%d] = ",j);
    scanf("%d",&(*p).puis);
    j++;y=wherey();
    for (i=1;i<nb;i++)
    {

        Add_maillon(&p);gotoxy(x,y+1);y++;
        printf("coef[%d] = ",j);
        scanf("%f",&(*p).coef);gotoxy(x,y+1);
        printf("pow[%d] = ",j);if ((!(j<5))&&i<5) {x=wherex()+4;y=wherey()-16;}
        scanf("%d",&(*p).puis);
        j++;y+=2;
    }
    }
}

int Degre_pol(Maillon Tete) //Donne le degr� de notre polynome de tete Tete en d'autre terme la puissance de notre dernier mon�me de la LLC
{
    Maillon p=Tete; int Deg;
    while (p != NULL)
    {
        if ((*p).nxt == NULL) Deg=(*p).puis;
        p=(*p).nxt;
    }
    return(Deg);
}

void Last(Maillon Tete, Maillon *g) //Donne l'adresse g du dernier mon�me du polynome dont la t�te est Tete
{
    Maillon p=Tete;
    while (p != NULL)
    {
        if ((*p).nxt == NULL) *g=p;
        p=(*p).nxt;
    }
}

int Calcul_X(Maillon Tete, float x) //Evalue la valeur retourn� par un polynome dont la t�te est Tete pour un X donn�
{
    Maillon p=Tete; float Sum=0;
    while (p != NULL)
    {
        Sum+=((*p).coef)*pow(x,(*p).puis);
        p=(*p).nxt;
    }
    return(Sum);
}

void Derive_polynome(Maillon Tete) //Derive un polynome, la d�rivation se fait simplement donc on n'a pas besoin de donner des explications
{
    Maillon p=Tete;
    while (p != NULL)
    {
        if ((*p).puis == (-1))
        {
            Delete_maillon(&Tete,p);
            p=NULL;
        }
        else
        {
             (*p).coef=((*p).coef)*((*p).puis);
            (*p).puis--;
            if ((*p).puis<0) (*p).puis=0;
            p=(*p).nxt;
        }
    }
}

void Somme_de_polynomes(Maillon Tete1, Maillon Tete2, Maillon *Tete3) //Pour r�aliser l'addition d'un polyn�me Tete1 avec un polyn�me Tete2 et la somme est retourn� dans le polyn�me Tete3, on a utilis� un algorithme d'interclassement de LLC tri�es classique
{
    Maillon a=NULL; Maillon b=NULL; Maillon c;
    Create_head(&(*Tete3));
    c=*Tete3;
    a=Tete1;
    b=Tete2;
    while ((a != NULL) && (b != NULL))
    {
       if ((*a).puis<(*b).puis)
       {
           (*c).coef=(*a).coef;
           (*c).puis=(*a).puis;
           a=(*a).nxt;
           Add_maillon(&c);
       }
       else
       {
           if ((*b).puis<(*a).puis)
           {
               (*c).coef=(*b).coef;
               (*c).puis=(*b).puis;
               b=(*b).nxt;
               Add_maillon(&c);
           }
           else
           {
               (*c).coef=((*b).coef+(*a).coef);
               (*c).puis=(*b).puis;
               b=(*b).nxt;
               a=(*a).nxt;
               Add_maillon(&c);
           }
       }
    }
    if ((a != NULL) || (b != NULL))
    {
        while (b != NULL)
        {
            (*c).coef=(*b).coef;
            (*c).puis=(*b).puis;
            b=(*b).nxt;
            Add_maillon(&c);
        }
        while (a != NULL)
        {
            (*c).coef=(*a).coef;
            (*c).puis=(*a).puis;
            a=(*a).nxt;
            Add_maillon(&c);
        }
    }
    (*(*c).prc).nxt=NULL;
    c=(*c).prc;
    while (((*c).coef == 0) && (c != *Tete3))
    {
        c=(*c).prc;
        (*c).nxt=NULL;
    }
}

void Affichage_polynome(Maillon Tete,int x, int y,int l) //Donne l'affichage d'un polynome de plus petit mon�me jusqu'au plus grand comme une expression math�matique classique
{
    Maillon d=Tete;
    cadrpol(x,y);
    printf("P(X) = ");
    if (((*Tete).nxt == NULL) && ((*Tete).coef == 0)) printf("0");
    while (d != NULL)
    {
       if ((*d).coef != 0)
       {
            if ((*d).puis == (-1))
                if (l==FR)
                {
printf("C    , ou C est une constante dans R.");}
else printf("C    , where C is a constant in R.");
            else
            {
                if ((*d).coef == 1)
                {
                    if ((*d).puis == 1)
                        printf("X");
                    else
                    {
                        if ((*d).puis == 0)
                            printf("(1.00)");
                        else
                            printf("X^(%d)",(*d).puis);
                    }
                }
                else
                {
                    printf("(%2.2f)",(*d).coef);
                    if ((*d).puis == 1)
                        printf("*X");
                    else
                    {
                        if ((*d).puis != 0)
                            printf("*X^(%d)",(*d).puis);
                    }
                }
                if ((*d).nxt != NULL)
                    printf(" + ");
            }
        }
        d=(*d).nxt;
    }
}

void produit_de_polynomes(Maillon Tete1, Maillon Tete2, Maillon *Tete3) //Le produit du p�lynome Tete1 par le polyn�me Tete2 qui est retourn� dans le polyn�me Tete3, se fait en faisant le produit de chacque mon�me du Tete2 par tout le polyn�me Tete1, puis on reparcourt Tete3 pour supprimer les mon�mes dont les puissances sont �gales et retrier les mon�mes de Tete3 suivant un ordre croissant de spuissances
{
    Maillon a=Tete1; Maillon b=Tete2; Maillon c=*Tete3; Maillon tail; int puissance,Existence; Maillon h; Maillon q;
    c=malloc(sizeof(struct Mailllon));
    *Tete3=c;
    while (b != NULL)
    {
        (*c).coef=((*a).coef)*((*b).coef);
        (*c).puis=((*a).puis)+((*b).puis);
        b=(*b).nxt;
        Add_maillon(&c);
    }
    c=(*c).prc;
    (*c).nxt=NULL;
    tail=c;
    b=Tete2;
    a=Tete1;
    a=(*a).nxt;
    while (a != NULL)
    {
        while (b != NULL)
        {
                    puissance=((*a).puis)+((*b).puis);
                    if ((*tail).puis<puissance)
                    {
                        Add_maillon(&tail);
                        (*tail).coef=((*a).coef)*((*b).coef);
                        (*tail).puis=((*a).puis)+((*b).puis);
                    }
                    else
                    {
                        h=*Tete3;
                        Existence=0;
                        while (h != NULL)
                        {

                        if ((*h).puis==puissance)
                            {
                                (*h).coef=((*h).coef)+(((*a).coef)*((*b).coef));
                                Existence=1;
                                h=NULL;
                            }
                        else h=(*h).nxt;
                        }
                        if (Existence==0)
                        {
                            h=*Tete3;
                            while (h != NULL)
                            {
                                if (((*h).puis<puissance) && (puissance<(*(*h).nxt).puis))
                                    {
                                        q=malloc(sizeof(struct Mailllon));
                                        Insert_maillon2(&(*Tete3),h,q,1);
                                        (*q).coef=((*a).coef)*((*b).coef);
                                        (*q).puis=((*a).puis)+((*b).puis);
                                        h=NULL;
                                    }
                               else h=(*h).nxt;
                            }
                        }
                    }
                b=(*b).nxt;
        }
        b=Tete2;
        a=(*a).nxt;
    }
}

void Create_Set(Ensemble *Tete) //Cr�er la Tete de l'ensemble des polyn�mes
{
    Ensemble p;
    p=malloc(sizeof(struct ensemble));
    (*p).nxt=NULL;
    (*p).prc=NULL;
    *Tete=p;
}

void Add_pol(Ensemble *p, Maillon q) //Ajouter un polyn�me � l'ensemble des polyn�mes � partir de sa queue
{
    Ensemble d;
    d=malloc(sizeof( struct ensemble));
    (*(*p)).nxt=d;
    (*d).prc=*p;
    (*d).nxt=NULL;
    (*d).pol=q;
    *p=d;
}

void Afficher_Ensemble(Ensemble Tete,int x,int y,int l) //Affiche tous les polyn�mes d'un ensemble de polyn�mes Tete tout en les num�rotant
{
    Ensemble p=Tete; int i=1;
    if (l==FR)
    {
        gotoxy(x,y); printf("La liste des polynomes :");
    gotoxy(x,y+1); printf("------------------------");
    }
    else
    {
        gotoxy(x,y); printf("The list of polynomials :");
    gotoxy(x,y+1); printf("------------------------");
    }

    while (p != NULL)
    {
        gotoxy(10,y+3);
        if (l==FR) printf("Polynome %d : ",i);
        else printf("Polynomial %d : ",i);
        Affichage_polynome((*p).pol,12,y+4,l);y=wherey();
        p=(*p).nxt;
        i++;
    }
}

void Delete_maillon_par_pos(Maillon *Tete, int j) //Supprimer un maillon d'une LLC en donnant son indice
{
    Maillon p=*Tete; int i=1;
    while (i != j)
    {
        p=(*p).nxt;
        i++;
    }
    if (p==*Tete)
    {
        *Tete=(*p).nxt;
        if ((*Tete) != NULL) (*(*Tete)).prc=NULL;
        free(p);
    }
    else
    {
        if ((*p).nxt==NULL)
        {
            (*(*p).prc).nxt=NULL;
            free(p);
        }
        else
        {
            (*(*p).prc).nxt=(*p).nxt;
            (*(*p).nxt).prc=(*p).prc;
            free(p);
        }
    }
}

void Delete_pol_par_pos(Ensemble *Tete, int j) //Supprimer un polyn�me de l'ensemble des polyn�mes selon son indice dans cet ensemble
{
    Ensemble p=*Tete; int i=1;
    while (i != j)
    {
        p=(*p).nxt;
        i++;
    }
    if (p==*Tete)
    {
        *Tete=(*p).nxt;
        if ((*Tete) != NULL) (*(*Tete)).prc=NULL;
        free(p);
    }
    else
    {
        if ((*p).nxt==NULL)
        {
            (*(*p).prc).nxt=NULL;
            free(p);
        }
        else
        {
            (*(*p).prc).nxt=(*p).nxt;
            (*(*p).nxt).prc=(*p).prc;
            free(p);
        }
    }
}

void Optimize(Maillon *Tete) //Supprime les maillons dont les coefficients sont nulles
{
    Maillon p=*Tete;
    while (p != *Tete)
    {
        if ((*p).coef == 0) Delete_maillon(&(*Tete),p);
    }
}

void Integrate(Maillon Tete) //Int�gre un polyn�me de t�te Tete, c'est une int�gration classique qui n'a pas besoin d'explications
{
    Maillon p=Tete;
    while (p != NULL)
    {
        (*p).coef=((*p).coef)/((*p).puis+1);
        (*p).puis++;
        if ((*p).nxt == NULL)
        {
            Add_maillon(&p);
            (*p).coef=1;
            (*p).puis=-1;
        }
        p=(*p).nxt;
    }
}

void Copy_pol(Maillon Tete1, Maillon *Tete2) //Copie tout le contenu de la LLC Tete1 dans une nouvelle LLC Tete2
{
    Maillon p=NULL; Maillon q=Tete1;
    p=malloc(sizeof(struct Mailllon));
    *Tete2=p;
    (*p).nxt=NULL;
    (*p).prc=NULL;
    while (q != NULL)
    {
        (*p).coef=(*q).coef;
        (*p).puis=(*q).puis;
        Add_maillon(&p);
        q=(*q).nxt;
    }
    p=(*p).prc;
    (*p).nxt=NULL;
}

void Soustraction_de_polynomes(Maillon Tete1, Maillon Tete2, Maillon *Tete3) //Il suffit de donner l'oppos� de chaque coefficient du polyn�me Tete2, Faire l'addition puis donner l'oppos� de chaque coefficient du polyn�me 2
{
    Maillon p=Tete2;
    while (p != NULL)
    {
        (*p).coef=((*p).coef)*(-1);
        p=(*p).nxt;
    }
    Somme_de_polynomes(Tete1,Tete2,&(*Tete3));
    p=Tete2;
    while (p != NULL)
    {
        (*p).coef=((*p).coef)*(-1);
        p=(*p).nxt;
    }
}

void Produit(Maillon Tete, Maillon p, Maillon *q) //Donne le produit d'un mon�me p par un polyn�me Tete et retourner le r�sultat dans le polyn�me q
{
    Maillon a=Tete; Maillon b=NULL;
    b=malloc(sizeof(struct Mailllon));
    *q=b;
    while (a != NULL)
    {
        (*b).coef=((*a).coef)*((*p).coef);
        (*b).puis=((*a).puis)+((*p).puis);
        a=(*a).nxt;
        Add_maillon(&b);
    }
    b=(*b).prc;
    (*b).nxt=NULL;
}

void Division_Euclideenne(Maillon Tete1, Maillon Tete2, Maillon *Quotient, Maillon *Reste) //Une division euclideenne polynomiale classique telle qu'on la conna�t math�matiquement, ceci �tait assez facile en utilisant les fonctions introduites pr�cedemment
{
    Maillon p=NULL; Maillon q=NULL; Maillon Replacement1=NULL; Maillon Replacement2=NULL; Maillon a=Tete2; Maillon Queue1; Maillon Queue2;
    p=malloc(sizeof(struct Mailllon));
    *Quotient=p;
    (*p).prc=NULL;
    q=malloc(sizeof(struct Mailllon));
    *Reste=q;
    (*q).prc=NULL;
    if (Degre_pol(Tete1) < Degre_pol(Tete2))
    {
        (*p).coef=0;
        (*p).puis=0;
        (*p).nxt=NULL;
        Copy_pol(Tete1,&(*Reste));
    }
    else
    {
        Copy_pol(Tete1,&Replacement1);
        while (Degre_pol(Replacement1) >= Degre_pol(Tete2))
        {
            Last(Replacement1,&Queue1);
            Last(Tete2,&Queue2);
            (*p).coef=((*Queue1).coef)/((*Queue2).coef);
            (*p).puis=((*Queue1).puis)-((*Queue2).puis);
            Produit(Tete2,p,&Replacement2);
            Soustraction_de_polynomes(Replacement1,Replacement2,&(*Reste));
            Optimize(&(*Reste));
            Copy_pol(*Reste,&Replacement1);
            Add_maillon(&p);
        }
        p=(*p).prc;
        (*p).nxt=NULL;
    }
}

void Generate_pol(Maillon *Tete,int x, int y,int l) //G�n�re le polyn�me g�n�rateur pour donner le code CRC
{
    if (l==FR)
    {
      gotoxy(x,y);
    printf("Entrez le polynome generateur :");gotoxy(x,y+1);
    printf("-------------------------------");
    Create_polynome(&(*Tete),x,y+3,l);
    }
    else
    {
       gotoxy(x,y);
    printf("Enter the generator polynomial :");gotoxy(x,y+1);
    printf("-------------------------------");
    Create_polynome(&(*Tete),x,y+3,l);
    }

}

void BinToPol(long long Data, Maillon *Tete) //Transforme une information en binaire Data en un polyn�me Tete
{
    Maillon p=NULL; int i=0,j=10;
    while (Data != 0)
    {
        if ((Data%10)==1)
        {
            if (p==NULL)
            {
                Create_head(&p);
                *Tete=p;
            }
            else Add_maillon(&p);
            (*p).coef=1;
            (*p).puis=i;
        }
        Data=(Data/j);
        i++;
    }
}

long long power(long long a,long long b) //l'�quivalent de la fonction pow() mais avec des types long long pour pouvoir lire des informations plus grandes
{
    long long Result=1,i=0;
    while (i != b)
    {
        Result=Result*a;
        i++;
    }
    return(Result);
}

void PolToBin(Maillon Tete, long long *Data) //Tranforme un polyn�me Tete en une information binaire Data en se reposant sur la velrudes coefficients modulo 2
{
    long long Sum=0; Maillon p=Tete; long long a,b;
    while (p != NULL)
    {
        a=(*p).coef;
        b=(a%2);
        if ((b==1) || (b==(-1))) Sum=Sum+power(10,(*p).puis);
        p=(*p).nxt;
    }
    *Data=Sum;
}

void CRC(long long Data1, Maillon Tete, long long *Data2, long long *CodeCRC) //Retourne le code CRC CodeCRC d'une information Data1 par le polyn�me g�n�rateur Tete et la concat�ne avec l'information de base dans Data2
{
    Maillon Tete2=NULL; Maillon Tete3=NULL; Maillon p=NULL; Maillon Quotient1=NULL; Maillon Reste1=NULL; long long Information,Code,Puissance;
    BinToPol(Data1,&Tete2);
    Last(Tete,&p);
    Produit(Tete2,p,&Tete3);
    Division_Euclideenne(Tete3,Tete,&Quotient1,&Reste1);
    PolToBin(Reste1,&Code);
    Puissance=power(10,(*p).puis);
    Information=(Data1*Puissance)+Code;
    *Data2=Information;
    *CodeCRC=Code;
}

void Error_detection(int Data,Maillon Tete, int *Check) //Permet la d�tection d'erreur d'une information avec un code CRC calcul� par le polyn�me g�n�rateur Tete de sorte que : Check==1 ===> error / Check==0 ===> no error
{
    Maillon Tete2=NULL; Maillon Quotient1=NULL; Maillon Reste1=NULL; int Rep;
    BinToPol(Data,&Tete2);
    Division_Euclideenne(Tete2,Tete,&Quotient1,&Reste1);
    Optimize(&Reste1);
    if ((*Reste1).coef==0) Rep=0;
    else Rep=1;
    *Check=Rep;
}

Maillon Locate_pol(Ensemble Tete, int k) //Donne l'adresse d'un polyn�me dont l'indice dans l'ensemble des plyn�mes Tete est k
{
    Ensemble q=Tete; int a=1;
    while (a != k)
    {
        q=(*q).nxt;
        a++;
    }
    return((*q).pol);
}


#endif
