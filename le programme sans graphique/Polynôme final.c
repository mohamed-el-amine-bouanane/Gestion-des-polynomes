#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Mailllon *Maillon;
struct Mailllon
{
    float coef;
    int puis;
    Maillon nxt;
    Maillon prc;
};

typedef struct ensemble *Ensemble;
struct ensemble
{
    Maillon pol;
    Ensemble nxt;
    Ensemble prc;
};

int length(Ensemble Tete)
{
    Ensemble q; int lgr=0;
     while (Tete != NULL)
        {
            lgr++;
            Tete=(*Tete).nxt;
        }
    return(lgr);
}

Create_head(Maillon *Tete)
{
    Maillon p;
    p=malloc(sizeof(struct Mailllon));
    (*p).nxt=NULL;
    (*p).prc=NULL;
    *Tete=p;
}

Add_maillon(Maillon *p)
{
    Maillon d;
    d=malloc(sizeof( struct Mailllon));
    (*(*p)).nxt=d;
    (*d).prc=*p;
    (*d).nxt=NULL;
    *p=d;
}

Insert_maillon2(Maillon *Tete, Maillon p, Maillon q, int Sens)
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

void Delete_maillon(Maillon *Tete, Maillon p)
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

Create_polynome(Maillon *Tete)
{
    Maillon p=NULL; int nb,i,j=1;
    printf("Entrez le nombre de termes de votre polynome : ");
    scanf("%d",&nb);
    Create_head(&(*Tete));
    p=*Tete;
    printf("coef[%d] = ",j);
    scanf("%f",&(*p).coef);
    printf("puis[%d] = ",j);
    scanf("%d",&(*p).puis);
    j++;
    for (i=1;i<nb;i++)
    {
        Add_maillon(&p);
        printf("coef[%d] = ",j);
        scanf("%f",&(*p).coef);
        printf("puis[%d] = ",j);
        scanf("%d",&(*p).puis);
        j++;
    }
}

int Degre_pol(Maillon Tete)
{
    Maillon p=Tete; int Deg;
    while (p != NULL)
    {
        if ((*p).nxt == NULL) Deg=(*p).puis;
        p=(*p).nxt;
    }
    return(Deg);
}

Last(Maillon Tete, Maillon *g)
{
    Maillon p=Tete;
    while (p != NULL)
    {
        if ((*p).nxt == NULL) *g=p;
        p=(*p).nxt;
    }
}

float Calcul_X(Maillon Tete, float x)
{
    Maillon p=Tete; float Sum=0;
    while (p != NULL)
    {
        Sum+=((*p).coef)*pow(x,(*p).puis);
        p=(*p).nxt;
    }
    return(Sum);
}

Derive_polynome(Maillon Tete)
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

Somme_de_polynomes(Maillon Tete1, Maillon Tete2, Maillon *Tete3)
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

Affichage_polynome(Maillon Tete)
{
    Maillon d=Tete;
    printf("P(X) = ");
    if (((*Tete).nxt == NULL) && ((*Tete).coef == 0)) printf("0");
    while (d != NULL)
    {
       if ((*d).coef != 0)
       {
            if ((*d).puis == (-1))
                printf("C    , ou C est une constante dans R.");
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
    printf("\n");
}

produit_de_polynomes(Maillon Tete1, Maillon Tete2, Maillon *Tete3)
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

Create_Set(Ensemble *Tete)
{
    Ensemble p;
    p=malloc(sizeof(struct ensemble));
    (*p).nxt=NULL;
    (*p).prc=NULL;
    *Tete=p;
}

Add_pol(Ensemble *p, Maillon q)
{
    Ensemble d;
    d=malloc(sizeof( struct ensemble));
    (*(*p)).nxt=d;
    (*d).prc=*p;
    (*d).nxt=NULL;
    (*d).pol=q;
    *p=d;
}

Afficher_Ensemble(Ensemble Tete)
{
    Ensemble p=Tete; int i=1;
    printf("-----------------------------------\n");
    printf("La liste des polynomes :\n\n");
    while (p != NULL)
    {
        printf("Polynome %d : ",i);
        Affichage_polynome((*p).pol);
        printf("\n");
        p=(*p).nxt;
        i++;
    }
    printf("-----------------------------------\n");
}

void Delete_maillon_par_pos(Maillon *Tete, int j)
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

void Delete_pol_par_pos(Ensemble *Tete, int j)
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

Optimize(Maillon *Tete)
{
    Maillon p=*Tete;
    while (p != *Tete)
    {
        if ((*p).coef == 0) Delete_maillon(&(*Tete),p);
    }
}

Integrate(Maillon Tete)
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

Copy_pol(Maillon Tete1, Maillon *Tete2)
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

Soustraction_de_polynomes(Maillon Tete1, Maillon Tete2, Maillon *Tete3)
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

Produit(Maillon Tete, Maillon p, Maillon *q)
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

Division_Euclideenne(Maillon Tete1, Maillon Tete2, Maillon *Quotient, Maillon *Reste)
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

Generate_pol(Maillon *Tete)
{
    printf("-----------------------------------\n");
    printf("Entrez le polynome generateur :\n");
    Create_polynome(&(*Tete));
    printf("-----------------------------------\n");
}

BinToPol(long long Data, Maillon *Tete)
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

long power(long long a,long long b)
{
    long long Result=1,i=0;
    while (i != b)
    {
        Result=Result*a;
        i++;
    }
    return(Result);
}

PolToBin(Maillon Tete, long long *Data)
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

CRC(long long Data1, Maillon Tete, long long *Data2, long long *CodeCRC)
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

Error_detection(int Data,Maillon Tete, int *Check) //Check=1 => error / Check=0 => no error
{
    Maillon Tete2=NULL; Maillon Quotient1=NULL; Maillon Reste1=NULL; int Rep;
    BinToPol(Data,&Tete2);
    Division_Euclideenne(Tete2,Tete,&Quotient1,&Reste1);
    Optimize(&Reste1);
    if ((*Reste1).coef==0) Rep=0;
    else Rep=1;
    *Check=Rep;
}

Maillon Locate_pol(Ensemble Tete, int k)
{
    Ensemble q=Tete; int a=1;
    while (a != k)
    {
        q=(*q).nxt;
        a++;
    }
    return((*q).pol);
}


main()
{
    Ensemble TeteG=NULL; Ensemble a=NULL; Maillon Tete1=NULL; Maillon Tete2=NULL; long long Happiness,info1,info2,CodeCRC; int Repetition=0,i,Choix; int N,M;
    Create_Set(&TeteG);

    while (Repetition == 0)
    {
        i=0;
        printf("Choisissez le numero correspondant a l'operation que vous voulez executer, n'oublier pas qu'il faut creer un polynome avant de l'utiliser dans quelconque operation :\n");
        printf("***********************************************************************\n");
        printf("1:  Creer un polynome et l'inserer dans l'ensemble de spolynomes\n");
        printf("2:  Afficher l'ensemble des polynomes\n");
        printf("3:  Suprrimer un polynome de l'ensemble des polynomes\n");
        printf("4:  Additionner 2 polynomes\n");
        printf("5:  Soustraire 2 polynomes\n");
        printf("6:  Multiplier 2 polynomes\n");
        printf("7:  Realiser la division euclideenne de deux polynomes\n");
        printf("8:  Deriver un polynome\n");
        printf("9:  Integrer un polynome\n");
        printf("10: Tracer la courbe d'un polynome\n");
        printf("11: Proteger des informations binaires en utilisant le code CRC\n");
        printf("12: Verifier la veracite d'une information ayant le code CRC\n");
        printf("13: evaluation d'un polynome\n");
        printf("14: copy d un polynome\n");
        printf("15: Quitter\n");
        //La fonction copier_polynome est utilisee dans la derivee et l'integrale
        printf("***********************************************************************\n");
        printf("Choisissez un des numeros d'en dessus s'il vous-plait : ");
        scanf("%d",&Choix);
        switch (Choix)
        {
        case 1:
            system("CLS");
            printf("***********************************************************************\n");
            printf("Combien de polynomes voulez-vous creer : ");
            scanf("%d",&N);
            if (N>0)
            {
              for (i=0;i<N;i++)
                {
                    if(a == NULL)
                    {
                       Create_polynome(&Tete1);
                       if (TeteG == NULL) Create_Set(&TeteG);
                       (*TeteG).pol=Tete1;
                       a=TeteG;
                    }
                    else
                    {
                        Create_polynome(&Tete1);
                        Add_pol(&a,Tete1);
                    }

                }
            }
            else printf("Erreur...\n");
            printf("***********************************************************************\n");
            printf("\n");
            break;
        case 2:
            system("CLS");
            printf("***********************************************************************\n");
            if (a == NULL) printf("Aucun polynome a afficher, votre ensemble est vide !\n");
            else
            {
                Afficher_Ensemble(TeteG);
            }
            printf("***********************************************************************\n");
            printf("\n");
            break;
        case 3:
            system("CLS");
            printf("***********************************************************************\n");
            if (a == NULL) printf("Aucun polynome a supprimer, votre ensemble est vide !\n");
            else
            {
                printf("Combien de polynome voulez-vous supprimer : ");
                scanf("%d",&N);
                if (N>length(TeteG)) printf("Le nombre de polynomes que vous voulez supprimer depasse le cardinal de votre ensemble de polynomes.\n");
                else
                {
                    if (N>0)
                    {
                        for (i=0;i<N;i++)
                        {
                            Afficher_Ensemble(TeteG);
                            printf("Donner le numero du polynome que vous voulez supprimer : ");
                            scanf("%d",&M);
                            Delete_pol_par_pos(&TeteG,M);
                            system("CLS");
                        }
                        a=TeteG;
                        if (TeteG != NULL)
                        {
                             while ((*a).nxt != NULL)
                            {
                                a=(*a).nxt;
                            }
                        }
                    }
                    else printf("Erreur...\n");
                }
            }
            printf("***********************************************************************\n");
            printf("\n");
            break;
        case 4:
            system("CLS");
            printf("***********************************************************************\n");
            if (a==NULL) printf("Votre ensemble est vide !\n");
            else
            {
                Afficher_Ensemble(TeteG);
                printf("Donnez le numero du premier polynome a aditionner : ");
                scanf("%d",&N);
                printf("Donnez le numero du deuxieme polynome a aditionner : ");
                scanf("%d",&M);
                Somme_de_polynomes(Locate_pol(TeteG,N),Locate_pol(TeteG,M),&Tete1);
                Affichage_polynome(Tete1);
                printf("Voulez-vous enregistrer ce polynome, tapez 1 pour oui ou 0 pour non :");
                scanf("%d",&N);
                if (N==1) Add_pol(&a,Tete1);
                else
                {
                    if (N==0) free(Tete1);
                    else printf("Erreur...\n");
                }
            }
            printf("***********************************************************************\n");
            printf("\n");
            break;
        case 5:
            system("CLS");
            printf("***********************************************************************\n");
            if (a==NULL) printf("Votre ensemble est vide !\n");
            else
            {
                Afficher_Ensemble(TeteG);
                printf("Donnez le numero du premier polynome : ");
                scanf("%d",&N);
                printf("Donnez le numero du deuxieme polynome a soustraire : ");
                scanf("%d",&M);
                Soustraction_de_polynomes(Locate_pol(TeteG,N),Locate_pol(TeteG,M),&Tete1);
                Affichage_polynome(Tete1);
                printf("Voulez-vous enregistrer ce polynome, tapez 1 pour oui ou 0 pour non :");
                scanf("%d",&N);
                if (N==1) Add_pol(&a,Tete1);
                else
                {
                    if (N==0) free(Tete1);
                    else printf("Erreur...\n");
                }
            }
            printf("***********************************************************************\n");
            printf("\n");
            break;
        case 6:
            system("CLS");
            printf("***********************************************************************\n");
            if (a==NULL) printf("Votre ensemble est vide !\n");
            else
            {
                Afficher_Ensemble(TeteG);
                printf("Donnez le numero du premier polynome a multiplier : ");
                scanf("%d",&N);
                printf("Donnez le numero du deuxieme polynome a multiplier : ");
                scanf("%d",&M);
                produit_de_polynomes(Locate_pol(TeteG,N),Locate_pol(TeteG,M),&Tete1);
                Affichage_polynome(Tete1);
                printf("Voulez-vous enregistrer ce polynome, tapez 1 pour oui ou 0 pour non :");
                scanf("%d",&N);
                if (N==1) Add_pol(&a,Tete1);
                else
                {
                    if (N==0) free(Tete1);
                    else printf("Erreur...\n");
                }
            }
            printf("***********************************************************************\n");
            printf("\n");
            break;
        case 7:
            system("CLS");
            printf("***********************************************************************\n");
            if (a==NULL) printf("Votre ensemble est vide !\n");
            else
            {
                Afficher_Ensemble(TeteG);
                printf("Donnez le numero du premier polynome qui est le dividende : ");
                scanf("%d",&N);
                printf("Donnez le numero du deuxieme polynome qui est le diviseur : ");
                scanf("%d",&M);
                Division_Euclideenne(Locate_pol(TeteG,N),Locate_pol(TeteG,M),&Tete1,&Tete2);
                printf(">> Quotient :\n");
                Affichage_polynome(Tete1);
                printf(">> Reste :\n");
                Affichage_polynome(Tete2);
                printf("Voulez-vous enregistrer les polynomes; tapez 0 pour non, 1 pour le quotient seulement, 2 pour le reste seulement ou 3 pour les deux :");
                scanf("%d",&N);
                if (N==0) free(Tete1);
                else
                {
                    switch (N)
                    {
                    case 1:
                        Add_pol(&a,Tete1);
                        break;
                    case 2:
                        Add_pol(&a,Tete2);
                        break;
                    case 3:
                        Add_pol(&a,Tete1);
                        Add_pol(&a,Tete2);
                        break;
                    default:
                        printf("Erreur...\n");
                        break;
                    }
                }
            }
            printf("***********************************************************************\n");
            printf("\n");
            break;

        case 8:
            system("CLS");
            printf("***********************************************************************\n");
            if (a==NULL) printf("Votre ensemble est vide !\n");
            else
            {
                Afficher_Ensemble(TeteG);
                printf("Donnez le numero du polynome a deriver : ");
                scanf("%d",&N);
                Copy_pol(Locate_pol(TeteG,N),&Tete1);
                Derive_polynome(Tete1);
                Affichage_polynome(Tete1);
                printf("Voulez-vous enregistrer ce polynome, tapez 1 pour oui et 0 pour non :");
                scanf("%d",&N);
                if (N==1) Add_pol(&a,Tete1);
                else
                {
                    if (N==0) free(Tete1);
                    else printf("Erreur...\n");
                }
            }
            printf("***********************************************************************\n");
            printf("\n");
            break;
        case 9:
            system("CLS");
            printf("***********************************************************************\n");
            if (a==NULL) printf("Votre ensemble est vide !\n");
            else
            {
                Afficher_Ensemble(TeteG);
                printf("Donnez le numero du polynome a integrer : ");
                scanf("%d",&N);
                Copy_pol(Locate_pol(TeteG,N),&Tete1);
                Integrate(Tete1);
                Affichage_polynome(Tete1);
                printf("Voulez-vous enregistrer ce polynome, tapez 1 pour oui et 0 pour non :");
                scanf("%d",&N);
                if (N==1) Add_pol(&a,Tete1);
                else
                {
                    if (N==0) free(Tete1);
                    else printf("Erreur...\n");
                }
            }
            printf("***********************************************************************\n");
            printf("\n");
            break;
        case 10:
            system("CLS");
            printf("***********************************************************************\n");
            if (a==NULL) printf("Votre ensemble est vide !\n");
            else
            {
                Afficher_Ensemble(TeteG);
                printf("Donnez le numero du polynome dont vous voulez tracez la courbe : ");
                scanf("%d",&N);
                printf("La courbe du polynome : ");
                Affichage_polynome(Locate_pol(TeteG,N));
                printf("\n");
                //Courbe(Locate_pol(TeteG,N))
            }
            printf("***********************************************************************\n");
            printf("\n");
            break;
        case 11:
            system("CLS");
            printf("***********************************************************************\n");
            printf("Vous voulez creer le polynome generateur ou utiliser un polynome deja existant; tapez 1 pour creer ou 2 pour choisir un polynome existant : ");
            scanf("%d",&N);
            if (N==2)
            {
                if (a==NULL) printf("Votre ensemble est vide !\n");
                else
                {
                    Afficher_Ensemble(TeteG);
                    printf("Choisissez le numero du polynome que vous souhaitez considerer comme generateur : ");
                    scanf("%d",&M);
                    Tete1=Locate_pol(TeteG,M);
                    printf("Entrer l'information : ");
                    scanf("%lld",&info1);
                    CRC(info1,Tete1,&info2,&CodeCRC);
                    printf("\nInformation codee : %lld             i.e.  %lld %lld",info2,info1,CodeCRC);
                }
            }
            else
            {
                if (N==1)
                {
                    Generate_pol(&Tete1);
                    printf("Entrer l'information : ");
                    scanf("%lld",&info1);
                    CRC(info1,Tete1,&info2,&CodeCRC);
                    printf("\nInformation codee : %lld             i.e.  %lld %lld",info2,info1,CodeCRC);
                }
                else printf("Erreur...\n");
            }
            printf("***********************************************************************\n");
            printf("\n");
            break;
        case 12:
            system("CLS");
            printf("***********************************************************************\n");
            printf("Vous voulez creer le polynome generateur ou utiliser un polynome deja existant; tapez 1 pour creer ou 2 pour choisir un polynome existant : ");
            scanf("%d",&N);
            if (N==2)
            {
                if (a==NULL) printf("Votre ensemble est vide !\n");
                else
                {
                    Afficher_Ensemble(TeteG);
                    printf("Choisissez le numero du polynome que vous souhaitez considerer comme generateur : ");
                    scanf("%d",&M);
                    Tete1=Locate_pol(TeteG,M);
                    printf("Entrer l'information : ");
                    scanf("%lld",&info1);
                    Error_detection(info1,Tete1,&Happiness);
                    if (Happiness==0) printf("L'information est intacte !\n");
                    else printf("Linformation a subi des modification lors de sa transmission !\n");
                }
            }
            else
            {
                if (N==1)
                {
                    Generate_pol(&Tete1);
                    printf("Entrer l'information : ");
                    scanf("%lld",&info1);
                    Error_detection(info1,Tete1,&Happiness);
                    if (Happiness==0) printf("L'information est intacte !\n");
                    else printf("Linformation a subi des modification lors de sa transmission !\n");
                }
                else printf("Erreur...\n");
            }
            printf("***********************************************************************\n");
            printf("\n");
            break;
        case 13:
            system("CLS");
            printf("***********************************************************************\n");
            Afficher_Ensemble(TeteG);
                printf("Donnez le numero du polynome a evaluer : ");
                scanf("%d",&N);int NN=0;float calc=0.0;
                printf("\ncombien de valeur vous voulez calculer? : ");scanf("%d",&NN);
                if (!(NN>0)) printf("erreur...!");
                else
                {
                    for (i=0;i<NN;i++)
                    {
                        printf("\ndonner la valeur pour calculer");
                         scanf("%f",&calc);
                        printf("x= %4.2f  et y= %4.2f",calc,Calcul_X(Locate_pol(TeteG,N),calc));
                    }
                }

            printf("***********************************************************************\n");
            printf("\n");
            break;
        case 14:
            system("CLS");
            printf("***********************************************************************\n");
            Afficher_Ensemble(TeteG);
            printf("donner le num de polynome aue vous voulez copy\n");scanf("%d",&N);Copy_pol(Locate_pol(TeteG,N),&Tete1);
            Add_pol(&a,Tete1);
            break;
        case 15:
            system("CLS");
            printf("***********************************************************************\n");
            printf("Merci pour nous avoir fait confiance et de nous laisser effectuer les calculs a votre place,\n");
            printf("Ravi de vous avoir servi, on espere que vous etes satisfaits de la qualite du travail !\n");
            printf("A la prochaine...\n");
            printf("***********************************************************************\n");
            printf("\n");
            Repetition=1;
            break;
        default:
            system("CLS");
            printf("***********************************************************************\n");
            printf("Erreur ! Veuillez saisir un des numeros correspondants la liste s'il vous-plait\n");
            printf("***********************************************************************\n");
            printf("\n");
            break;
        }
    }
}


