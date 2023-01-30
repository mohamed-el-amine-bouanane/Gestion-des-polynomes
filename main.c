/**
TP1 D'ALSDD ...BINOME BOUANANE ET LAISSAOUI
GESTION DES POLYNOMES
CE TP EST GEREE D UNE FACON QUE L'UTILISATEUR PEUX CHOISIR ENTRE LA LANGUE FRANCAISE ET L'ANGLAIS
IL SUFFIT JUSTE D'APPUYER SUR LA TOUCHE CTRL+L
ON A 2 BIBLIOTHEQUES
   =1 POUR LES FONCTIONS QUI GERENT LES DEFFERANTE OPERATION SUR LES POLYNOME ET ELLE EST BIEN COMMENTER
   =2 POUR L INTERFACE GRAPHIQUE QUI AFFICHE LES ENTETE BACKGROUND LES CADRE ETC ....
LE PROGRAMME PRINCIPPALE CONTIENT LE MENU QUI EST EN 2 PARTIES
   = 1 POUR LA LANGUE FRANCAISE {if l==FR}
   = 2 POUR L'ANGLAIS {else}
IL Y A UN GUIDE D UTILISATION APRES L ACCEUILE - APPUYER SUR H-
POUR BIEN COMPRENDRE LES FONCTIONS NOUS CONSIELLONS DE VOIRE LA VIDEO ATTACHEE
NOUS AVONS COMMENTE TOUTES LES FONCTIONS SANS REPETEE LE COMMENTAIRE ALORS SOYEZ ATTENTIF AUX COMMENTAIRES
*/

///____________________________________________________INCLUDES____________________________________________

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include "fonctions.h"
#include "graphique.h"
#include <SDL.h>

///____________________________________________________PROGRAMME PRINCIPALE__________________________________
int main( int argc, char* args[] )///LES PARAMATRES NECCESSAIRE POUR LA BIBLIOTHEQUE SDL ... DANS LA BIBIOGRAPHIE IL EXISTE UNE SOURCE QUI EXPLIQUE POURQUOI CES PARAMETRES
{
    ///----------------------------------declaration des variables ---------------------------------------------///
    int choix,quit=false;
    int l=FR;///POUR LA LANGUR PAR DEFAULT C EST LE FRANCAIS
    char tab[30][600];/// POUR LA LISTE DES CHOIX
    int decalmenu_x=15,decalmenu_y=9;///DECALAGE DU MENU
    int y=0;///CHOIX DE MENU
    ///-------------------- POUR LA STUCTURE NECESSAIRE POUR TRETER LES FONCTIONS
    Ensemble TeteG=NULL;
    Ensemble a=NULL;
    Maillon Tete1=NULL;
    Maillon Tete2=NULL;
    ///------------------POUR CRC
    long long Happiness,info1,info2,CodeCRC;
    int Repetition=0,i,Choix;
    int N,M;
    ///-----------------------------------initialisation de la console -----------------------------------------///
    system("mode 122, 42");
    SetConsoleTitle("TP_BOUANANE_LAISSAOUI");
    ///-----------------------------------programme principale -------------------------------------------------///
    Esi();///ESI LOGO /VOIRE BIB GRAPHIQUE
    TP();///LOGO TP // VOIRE BIB GRAPHIQUE
    loading();/// UN SIMPLE LAODING ...
    Sleep(500);///SLEEP FONCTIONS POUR PRENDRE UN TEMPS D'ARRET
accu:///ETIQUETTE POUR LE FAMEUX GOTO  // COMME LE MIASME ///
    accueil(&l);///NOTRE ACCEUILE
    Create_Set(&TeteG);///INITIALISATION DE L ENSEMBLE DES POLYNOMES
    /**
    MTN L INITIALISATION DES CHOIX DU MENU
    ==== C EST UN TABLEUX 2D CHAQUE LIGNE POUR UN CHOIX JUSQU'A 15 ..LES AUTRES SONT LES MEMES MAIS EN ANGLAIS
    */
    strcpy(tab[0],"1:  Creer un polynome et l'inserer dans l'ensemble des polynomes");
    strcpy(tab[1],"2:  Afficher l'ensemble des polynomes");
    strcpy(tab[2],"3:  Suprrimer un polynome de l'ensemble des polynomes");
    strcpy(tab[3],"4:  Copier un polynome de l'ensemble des polynomes");
    strcpy(tab[4],"5:  Additionner 2 polynomes");
    strcpy(tab[5],"6:  Soustraire 2 polynomes");
    strcpy(tab[6],"7:  Multiplier 2 polynomes");
    strcpy(tab[7],"8:  Realiser la division euclideenne de deux polynomes");
    strcpy(tab[8],"9:  Deriver un polynome");
    strcpy(tab[9],"10:  Integrer un polynome");
    strcpy(tab[10],"11:  Evaluer un polynome");
    strcpy(tab[11],"12: Tracer la courbe d'un polynome");
    strcpy(tab[12],"13: Proteger des informations binaires en utilisant le code CRC");
    strcpy(tab[13],"14: Verifier la veracite d'une information ayant le code CRC");
    strcpy(tab[14],"15: Quitter");
    strcpy(tab[15],"1: Create a polynomial and insert it into the set of polynomials");
    strcpy(tab[16],"2: Display all the polynomes");
    strcpy(tab[17],"3: Remove a polynomial from the set of polynomials");
    strcpy(tab[18],"4: Copy a polynomial from the set of polynomials");
    strcpy(tab[19],"5: Add 2 polynomials");
    strcpy(tab[20],"6: Subtract 2 polynomials");
    strcpy(tab[21],"7: Multiply 2 polynomials");
    strcpy(tab[22],"8: Realize the Euclidean division of two polynomials");
    strcpy(tab[23],"9: Derive a polynomial");
    strcpy(tab[24],"10: Integrate a polynomial");
    strcpy(tab[25],"11: Evaluate a polynomial");
    strcpy(tab[26],"12: Draw the curve of a polynomial");
    strcpy(tab[27],"13: Protect binary information using the CRC code");
    strcpy(tab[28],"14: Check the veracity of information with the CRC code");
    strcpy(tab[29],"15: Exite");
///==================================================MTN L AFFICHAGE DU MENU=================================

    moncadre();
    tmenu();
    cadre1();
    backlang(l);
    ///CES DERNIERS SONT NOTRE ENVIRENEMENT DE TRAVAIL CADRE BACKGROUND ET ENTETE

    {
        moncadre();
        tmenu();
        cadre1();
        backlang(l);
        parler("MENU");/// UN ECHO DU MOT MENU
        i = 0;///POUR L AFFICHAGE DU TABLEAU DE CHOIX
        y = 0;
        if (l==FR)///SI LA LANGUE EST LE FRANCAIS
        {
            for(i=0; i<=14; i++)
            {

                if(i==y)///POUR FAIRE UNE ALLIGNEMENT DE NOTRE CHOIX
                {

                    textbackground(6) ;
                    textcolor(15) ;
                    gotoxy(decalmenu_x+3,i+1+decalmenu_y);
                    write(tab[i],0);
                    parler(tab[i]);
                    printf("\n\n\n\n");
                    textbackground(DARKGRAY) ;

                }
                else/// LES AUTRES CHOIX
                {

                    gotoxy(decalmenu_x,2*i+1+decalmenu_y);
                    write(tab[i],0);
                    parler(tab[i]);
                    printf("\n\n\n\n");

                }
            }
        }
        else///POUR L ANGLAIS
        {
            for(i=15; i<=29; i++)
            {

                if(i==(y+15))
                {

                    textbackground(6) ;
                    textcolor(15) ;
                    gotoxy(decalmenu_x+3,i-15+1+decalmenu_y);
                    write(tab[i],0);
                    parler(tab[i]);
                    //Sleep(50);
                    printf("\n\n\n\n");
                    textbackground(DARKGRAY) ;

                }
                else
                {

                    gotoxy(decalmenu_x,2*(i-15)+1+decalmenu_y);
                    write(tab[i],0);
                    parler(tab[i]);
                    //Sleep(50);
                    printf("\n\n\n\n");

                }
            }
        }

        gotoxy(decalmenu_x+3,y+1+decalmenu_y);
    }

label:/// ETIQUE POUR LE RETOUR AU MENU PRINCIPALE ... LES MEME PROCEDURE QUI CE REPETE
    moncadre();
    tmenu();
    cadre1();
    backlang(l);
    i = 0;
    y = 0;
    if (l==FR)
    {
        for(i=0; i<=14; i++)
        {

            if(i==y)
            {

                textbackground(6) ;
                textcolor(15) ;
                gotoxy(decalmenu_x+3,i+1+decalmenu_y);
                write(tab[i],0);
                printf("\n\n\n\n");
                textbackground(DARKGRAY) ;

            }
            else
            {

                gotoxy(decalmenu_x,2*i+1+decalmenu_y);
                write(tab[i],0);//parler(tab[i]);
                //Sleep(50);
                printf("\n\n\n\n");

            }
        }
    }
    else
    {
        for(i=15; i<=29; i++)
        {

            if(i==(y+15))
            {

                textbackground(6) ;
                textcolor(15) ;
                gotoxy(decalmenu_x+3,i-15+1+decalmenu_y);
                write(tab[i],0);
                //Sleep(50);
                printf("\n\n\n\n");
                textbackground(DARKGRAY) ;

            }
            else
            {

                gotoxy(decalmenu_x,2*(i-15)+1+decalmenu_y);
                write(tab[i],0);//parler(tab[i+15]);
                //Sleep(50);
                printf("\n\n\n\n");

            }
        }
    }

    gotoxy(decalmenu_x+3,y+1+decalmenu_y);

    char c;///NOTRE CHOIX APARTIRE DU CLAVIER
    int bol;
    while(!quit)
    {

        c=_getch();
        switch(c)
        {

        case ESC:///RETOURE AU ACCEUILE ET LE GUIDE
            goto accu;
            break;
        case CTRL_L:///CHANGEMENT DE LA LANGUE
            l=(l+1)%2;
            goto label;
            break;///
        case 80:/// MOVE VERS LE BAS

            if (l==FR)///CHOIX DE LANGUE
            {
                if (y==14)
                    y=0;
                else
                    y++;
                clrmenu(1+decalmenu_y,29+decalmenu_y);
                cadre1corrr();///VOIRE LA BIB GRAPHIQUE
                correc();
                gotoxy(1,y+1+decalmenu_y);
                for(i=0; i<=14; i++)
                {
                    if(i==y)
                    {
                        textbackground(6) ;
                        textcolor(15) ;
                        gotoxy(decalmenu_x+3,2*i+1+decalmenu_y);
                        cprintf("%s\n",tab[i]);
                        textbackground(DARKGRAY) ;
                    }
                    else
                    {
                        gotoxy(decalmenu_x,2*i+1+decalmenu_y);
                        cprintf("%s\n",tab[i]);
                    }
                }
            }
            else///ANGLAIS
            {
                if (y==14)
                    y=0;
                else
                    y++;
                clrmenu(1+decalmenu_y,29+decalmenu_y);
                cadre1corrr();
                correc();
                //moncadre();tmenu();cadre1();backk(l);
                gotoxy(1,y+1+decalmenu_y);
                for(i=15; i<=29; i++)
                {
                    if(i==(y+15))
                    {
                        textbackground(6) ;
                        textcolor(15) ;
                        gotoxy(decalmenu_x+3,2*(i-15)+1+decalmenu_y);
                        cprintf("%s\n",tab[i]);
                        textbackground(DARKGRAY) ;
                    }
                    else
                    {
                        gotoxy(decalmenu_x,2*(i-15)+1+decalmenu_y);
                        cprintf("%s\n",tab[i]);
                    }
                }
            }
            gotoxy(decalmenu_x+3,2*y+1+decalmenu_y);

            break;
        case 72:///MOVE VRS LE HAUT
            if (l==FR)
            {
                if (y==0)
                    y=14;
                else
                    y--;
                clrmenu(1+decalmenu_y,30+decalmenu_y);
                cadre1corrr();
                correc();//moncadre();tmenu();cadre1();backk(l);
                gotoxy(1,y+1+decalmenu_y);
                for(i=0; i<=14; i++)
                {
                    if(i==y)
                    {
                        textbackground(3) ;
                        textcolor(15) ;
                        gotoxy(decalmenu_x+3,2*i+1+decalmenu_y);
                        cprintf("%s\n",tab[i]);
                        textbackground(DARKGRAY) ;
                    }
                    else
                    {
                        gotoxy(decalmenu_x,2*i+1+decalmenu_y);
                        cprintf("%s\n",tab[i]);
                    }
                }
            }
            else
            {
                if (y==0)
                    y=14;
                else
                    y--;
                clrmenu(1+decalmenu_y,30+decalmenu_y);
                cadre1corrr();
                correc();//moncadre();tmenu();cadre1();backk(l);
                gotoxy(1,y+1+decalmenu_y);
                for(i=15; i<=29; i++)
                {
                    if(i==(15+y))
                    {
                        textbackground(3) ;
                        textcolor(15) ;
                        gotoxy(decalmenu_x+3,2*(i-15)+1+decalmenu_y);
                        cprintf("%s\n",tab[i]);
                        textbackground(DARKGRAY) ;
                    }
                    else
                    {
                        gotoxy(decalmenu_x,2*(i-15)+1+decalmenu_y);
                        cprintf("%s\n",tab[i]);
                    }
                }
            }
            gotoxy(decalmenu_x+3,2*y+1+decalmenu_y);
            break;

        case 13:///APPUYER SUR ENTRER ET CHOISIR L OPERATION
            /**
            DANS TOUS CE QUI VIENNENT EN AFFICHE NOTRE ENVIRENEMENT EST DES MESSAGE POUR INTRODUIRE LES DONNES
            LA VIDEO EXPLIQUE BIEN CES FONCTIONNEMENT
            */
            switch(y)
            {
            case 0:
                if (l==FR)
                {
c0:
                    moncadre();
                    tCreer_un_polynome(l);
                    cadre1();
                    backk(l);
                    gotoxy(10,12) ;
                    printf("Combien de polynomes voulez-vous creer : ");
                    cadrintr(10,14);
                    scanf("%d",&N);
                    int positionx=10,positiony=17;
                    if (N>0)
                    {
                        for (i=0; i<N; i++)
                        {
                            if(a == NULL)
                            {
                                Create_polynome(&Tete1,positionx,positiony,l);
                                if (TeteG == NULL)
                                    Create_Set(&TeteG);
                                (*TeteG).pol=Tete1;
                                a=TeteG;
                            }
                            else
                            {
                                if (i%2==0)/// CA C EST POUR REGLER L AFFICHAGE SEULEMENT L UN APRES L AUTRE
                                {
                                    moncadre();
                                    tCreer_un_polynome(l);
                                    cadre1();
                                    backk(l);
                                    positionx=-40;
                                    positiony=12;
                                }
                                Create_polynome(&Tete1,positionx+50,positiony,l);
                                positionx=10;
                                positiony=12;
                                Add_pol(&a,Tete1);
                            }
                        }
                        moncadre();
                        tCreer_un_polynome(l);
                        cadre1();
                        backk(l);
                        gotoxy(40,25);
                        printf("C EST FINI.... RETOURS VERS LE MENU APRES 1 SECONDE ");
                        Sleep(1000);
                    }
                    else/// CAS D UN NOMBRE <0
                    {
                        gotoxy(10,17);
                        printf("Erreur...");
                        gotoxy(10,18);
                        printf("*********");
                        system("pause");
                        goto c0;
                    }
                }
                else///COMME D'HABITUDE LANGLAIS
                {
c0e:
                    moncadre();
                    tCreer_un_polynome(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    gotoxy(10,12) ;
                    printf("How many polynomials do you want to create : ");
                    cadrintr(10,14);
                    scanf("%d",&N);
                    int positionx=10,positiony=17;
                    if (N>0)
                    {
                        for (i=0; i<N; i++)
                        {
                            if(a == NULL)
                            {
                                Create_polynome(&Tete1,positionx,positiony,l);
                                if (TeteG == NULL)
                                    Create_Set(&TeteG);
                                (*TeteG).pol=Tete1;
                                a=TeteG;
                            }
                            else
                            {
                                if (i%2==0)
                                {
                                    moncadre();
                                    tCreer_un_polynome(l);
                                    cadre1();
                                    backk(l);
                                    positionx=-40;
                                    positiony=12;
                                }
                                Create_polynome(&Tete1,positionx+50,positiony,l);
                                positionx=10;
                                positiony=12;
                                Add_pol(&a,Tete1);
                            }
                        }
                        moncadre();
                        tCreer_un_polynome(l);
                        cadre1();
                        backk(l);
                        gotoxy(40,25);
                        printf("textwkhlas^^");
                        Sleep(1000);
                    }
                    else
                    {
                        gotoxy(10,17);
                        printf("Error...");
                        gotoxy(10,18);
                        printf("*********");
                        system("pause");
                        goto c0e;
                    }

                }
                goto label;
            case 1:
                if (l==FR)
                {
                    moncadre();
                    taffich(l);
                    cadre1();
                    backk(l);
                    if (a == NULL)
                    {
                        gotoxy(35,25);
                        printf("Aucun polynome a afficher, votre ensemble est vide !\n");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,37);
                        system("pause");
                    }
                }
                else
                {
                    moncadre();
                    taffich(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a == NULL)
                    {
                        gotoxy(35,25);
                        printf("No polynomial to display, your set is empty !\n");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,37);
                        system("pause");
                    }
                }
                goto label;
            case 2:
                if (l==FR)
                {
c2:
                    moncadre();
                    tsupp(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a == NULL)
                    {
                        gotoxy(35,25);
                        printf("Aucun polynome a supprimer, votre ensemble est vide !");
                        Sleep(1000);
                    }
                    else
                    {
                        gotoxy(10,14);
                        printf("Combien de polynome voulez-vous supprimer : ");
                        gotoxy(10,15);
                        printf("-------------------------------------------");
                        gotoxy(wherex(),14);
                        scanf("%d",&N);
                        if (N>length(TeteG))
                        {
                            moncadre();
                            tsupp(l);
                            cadre1();
                            backk(l);
                            cadrpol(10,20) ;
                            printf("Le nombre de polynomes que vous voulez supprimer depasse le cardinal de votre ensemble de polynomes.\n");
                            Sleep(1000);
                            goto c2;
                        }
                        else
                        {
                            if (N>0)
                            {
                                for (i=0; i<N; i++)
                                {
                                    moncadre();
                                    tsupp(l);
                                    cadre1();
                                    backk(l);
                                    Afficher_Ensemble(TeteG,25,13,l);
                                    gotoxy(25,35);
                                    printf("Donner le numero du polynome que vous voulez supprimer : ");
                                    gotoxy(25,36);
                                    printf("--------------------------------------------------------");
                                    gotoxy(wherex(),35);
                                    scanf("%d",&M);
                                    Delete_pol_par_pos(&TeteG,M);
                                    moncadre();
                                    tsupp(l);
                                    cadre1();
                                    backk(l);
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
                            else
                            {
                                gotoxy(10,17);
                                printf("Erreur...");
                                gotoxy(10,18);
                                printf("*********");
                                system("pause");
                                goto label;
                            }
                        }
                    }
                }
                else
                {
c2e:
                    moncadre();
                    tsupp(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a == NULL)
                    {
                        gotoxy(35,25);
                        printf("No polynomial to display, your set is empty !");
                        Sleep(1000);
                    }
                    else
                    {
                        gotoxy(10,14);
                        printf("How many polynomials do you want to remove : ");
                        gotoxy(10,15);
                        printf("-------------------------------------------");
                        gotoxy(wherex(),14);
                        scanf("%d",&N);
                        if (N>length(TeteG))
                        {
                            cadrpol(10,20) ;
                            printf("The number of polynomials you want to remove exceeds the cardinality of your set of polynomials.\n");
                            Sleep(1000);
                            goto c2e;
                        }
                        else
                        {
                            if (N>0)
                            {
                                for (i=0; i<N; i++)
                                {
                                    moncadre();
                                    tsupp(l);
                                    cadre1();
                                    backk(l);
                                    Afficher_Ensemble(TeteG,25,13,l);
                                    gotoxy(25,35);
                                    printf("Give the number of the polynomial you want to delete : ");
                                    gotoxy(25,36);
                                    printf("--------------------------------------------------------");
                                    gotoxy(wherex(),35);
                                    scanf("%d",&M);
                                    Delete_pol_par_pos(&TeteG,M);
                                    moncadre();
                                    tsupp(l);
                                    cadre1();
                                    backk(l);
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
                            else
                            {
                                gotoxy(10,17);
                                printf("Error...");
                                gotoxy(10,18);
                                printf("*********");
                                system("pause");
                                goto label;
                            }
                        }
                    }
                }
                goto label;
            case 3:
                if (l==FR)
                {
                    moncadre();
                    tcop(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("votre ensemble est vide !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,36);
                        printf("Donnez le numero du  polynome a copier : ");
                        scanf("%d",&N);
                        Copy_pol(Locate_pol(TeteG,N),&Tete1);
                        Add_pol(&a,Tete1);
                    }
                }
                else
                {
                    moncadre();
                    tcop(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("your set is empty !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,36);
                        printf("Give the polynomial number to copy : ");
                        scanf("%d",&N);
                        Copy_pol(Locate_pol(TeteG,N),&Tete1);
                        Add_pol(&a,Tete1);
                    }
                }
                goto label;
            case 4:
                if (l==FR)
                {
c4:
                    moncadre();
                    tAdd();
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("votre ensemble est vide !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Donnez le numero du premier polynome a aditionner : ");
                        scanf("%d",&N);
                        gotoxy(25,36);
                        printf("Donnez le numero du deuxieme polynome a aditionner : ");
                        scanf("%d",&M);
                        Somme_de_polynomes(Locate_pol(TeteG,N),Locate_pol(TeteG,M),&Tete1);
c41:
                        moncadre();
                        tAdd();
                        cadre1();
                        backk(l);
                        Affichage_polynome(Tete1,10,14,l);
                        cadrpol(10,18);
                        printf("Voulez-vous enregistrer ce polynome, tapez 1 pour oui ou 0 pour non :");
                        scanf("%d",&N);
                        if (N==1)
                            Add_pol(&a,Tete1);
                        else
                        {
                            if (N==0)
                                free(Tete1);
                            else
                            {
                                gotoxy(20,21);    //------------------
                                printf("Erreur...\n");
                                gotoxy(20,19);
                                system("pause");
                                goto c41;
                            }
                        }
                    }
                }
                else
                {
c4e:
                    moncadre();
                    tAdd();
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("your set is empty !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Give the number of the first polynomial to add : ");
                        scanf("%d",&N);
                        gotoxy(25,36);
                        printf("Give the number of the second polynomial to add : ");
                        scanf("%d",&M);
                        Somme_de_polynomes(Locate_pol(TeteG,N),Locate_pol(TeteG,M),&Tete1);
c41e:
                        moncadre();
                        tAdd();
                        cadre1();
                        backk(l);
                        Affichage_polynome(Tete1,10,14,l);
                        cadrpol(10,18);
                        printf("Do you want to save this polynomial, type 1 for yes or 0 for no :");
                        scanf("%d",&N);
                        if (N==1)
                            Add_pol(&a,Tete1);
                        else
                        {
                            if (N==0)
                                free(Tete1);
                            else
                            {
                                gotoxy(20,21);    //------------------
                                printf("Error...\n");
                                gotoxy(20,19);
                                system("pause");
                                goto c41e;
                            }
                        }
                    }
                }
                goto label;
            case 5:
                if (l==FR)
                {
c5:
                    moncadre();
                    tsous();
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("votre ensemble est vide !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Donnez le numero du premier polynome : ");
                        scanf("%d",&N);
                        gotoxy(25,36);
                        printf("Donnez le numero du deuxieme polynome a soustraire : ");
                        scanf("%d",&M);
                        Soustraction_de_polynomes(Locate_pol(TeteG,N),Locate_pol(TeteG,M),&Tete1);
c51:
                        moncadre();
                        tsous();
                        cadre1();
                        backk(l);
                        Affichage_polynome(Tete1,10,14,l);
                        cadrpol(10,18);
                        printf("Voulez-vous enregistrer ce polynome, tapez 1 pour oui ou 0 pour non :");
                        scanf("%d",&N);
                        if (N==1)
                            Add_pol(&a,Tete1);
                        else
                        {
                            if (N==0)
                                free(Tete1);
                            else
                            {
                                gotoxy(20,21);    //------------------
                                printf("Erreur...\n");
                                gotoxy(20,19);
                                system("pause");
                                goto c51;
                            }
                        }
                    }
                }
                else
                {
c5e:
                    moncadre();
                    tsous();
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("your set is empty !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Give the number of the first polynomial : ");
                        scanf("%d",&N);
                        gotoxy(25,36);
                        printf("Give the number of the second polynomial to be subtracted : ");
                        scanf("%d",&M);
                        Soustraction_de_polynomes(Locate_pol(TeteG,N),Locate_pol(TeteG,M),&Tete1);
c51e:
                        moncadre();
                        tsous();
                        cadre1();
                        backk(l);
                        Affichage_polynome(Tete1,10,14,l);
                        cadrpol(10,18);
                        printf("Do you want to save this polynomial, type 1 for yes or 0 for no :");
                        scanf("%d",&N);
                        if (N==1)
                            Add_pol(&a,Tete1);
                        else
                        {
                            if (N==0)
                                free(Tete1);
                            else
                            {
                                gotoxy(20,21);    //------------------
                                printf("Error...\n");
                                gotoxy(20,19);
                                system("pause");
                                goto c51e;
                            }
                        }
                    }
                }
                goto label;
            case 6:
                if (l==FR)
                {
c6:
                    moncadre();
                    tmult();
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("votre ensemble est vide !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Donnez le numero du premier polynome a multiplier : ");
                        scanf("%d",&N);
                        gotoxy(25,36);
                        printf("Donnez le numero du deuxieme polynome a multiplier : ");
                        scanf("%d",&M);
                        produit_de_polynomes(Locate_pol(TeteG,N),Locate_pol(TeteG,M),&Tete1);
c61://------------------------------------------------------------------------------------------------
                        moncadre();
                        tmult();
                        cadre1();
                        backk(l);
                        Affichage_polynome(Tete1,10,14,l);
                        cadrpol(10,18);
                        printf("Voulez-vous enregistrer ce polynome, tapez 1 pour oui ou 0 pour non :");
                        scanf("%d",&N);
                        if (N==1)
                            Add_pol(&a,Tete1);
                        else
                        {
                            if (N==0)
                                free(Tete1);
                            else
                            {
                                gotoxy(20,21);    //------------------
                                printf("Erreur...\n");
                                gotoxy(20,19);
                                system("pause");
                                goto c61;
                            }
                        }
                    }
                }
                else
                {
c6e:
                    moncadre();
                    tmult();
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("your set is empty !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Give the number of the first polynomial to multiply : ");
                        scanf("%d",&N);
                        gotoxy(25,36);
                        printf("Give the number of the second polynomial to multiply : ");
                        scanf("%d",&M);
                        produit_de_polynomes(Locate_pol(TeteG,N),Locate_pol(TeteG,M),&Tete1);
c61e://------------------------------------------------------------------------------------------------
                        moncadre();
                        tmult();
                        cadre1();
                        backk(l);
                        Affichage_polynome(Tete1,10,14,l);
                        cadrpol(10,18);
                        printf("Do you want to save this polynomial, type 1 for yes or 0 for no :");
                        scanf("%d",&N);
                        if (N==1)
                            Add_pol(&a,Tete1);
                        else
                        {
                            if (N==0)
                                free(Tete1);
                            else
                            {
                                gotoxy(20,21);    //------------------
                                printf("Error...\n");
                                gotoxy(20,19);
                                system("pause");
                                goto c61e;
                            }
                        }
                    }
                }
                goto label;
            case 7:
                if (l==FR)
                {
c7:
                    moncadre();
                    tdiv();
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("votre ensemble est vide !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Donnez le numero du premier polynome qui est le dividende : ");
                        scanf("%d",&N);
                        gotoxy(25,36);
                        printf("Donnez le numero du deuxieme polynome qui est le diviseur : ");
                        scanf("%d",&M);
                        Division_Euclideenne(Locate_pol(TeteG,N),Locate_pol(TeteG,M),&Tete1,&Tete2);
                        clrscr();
c71://-------------------------------------------------------------------------------------------------------------------------------
                        moncadre();
                        tdiv();
                        cadre1();
                        backk(l);
                        gotoxy(3,15);
                        printf(">> Quotient :");
                        Affichage_polynome(Tete1,18,14,l);
                        gotoxy(3,18);
                        printf(">> Reste :\n");
                        Affichage_polynome(Tete2,18,17,l);
                        gotoxy(10,25);
                        printf("Voulez-vous enregistrer les polynomes:?");
                        gotoxy(15,27);
                        printf("tapez 0 pour non, 1 pour le quotient seulement, 2 pour le reste seulement ou 3 pour les deux :");

                        scanf("%d",&N);
                        if (N==0)
                            free(Tete1);
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
                            {
                                gotoxy(20,18);    //---------------------------------------------------------
                                printf("Erreur...\n");
                                gotoxy(20,19);
                                system("pause");
                                goto c71;
                            }
                            break;
                            }
                        }
                    }
                }
                else
                {
c7e:
                    moncadre();
                    tdiv();
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("your set is empty !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Give the number of the first polynomial which is the dividend : ");
                        scanf("%d",&N);
                        gotoxy(25,36);
                        printf("Give the number of the second polynomial which is the divisor : ");
                        scanf("%d",&M);
                        Division_Euclideenne(Locate_pol(TeteG,N),Locate_pol(TeteG,M),&Tete1,&Tete2);
c71e://-------------------------------------------------------------------------------------------------------------------------------
                        moncadre();
                        tdiv();
                        cadre1();
                        backk(l);
                        gotoxy(3,15);
                        printf(">> Quotient :");
                        Affichage_polynome(Tete1,18,14,l);
                        gotoxy(3,18);
                        printf(">> Rest :\n");
                        Affichage_polynome(Tete2,18,17,l);
                        gotoxy(10,25);
                        printf("Do you want to save the polynomials:?");
                        gotoxy(15,27);
                        printf("type 0 for no, 1 for the quotient only, 2 for the rest only or 3 for both :");

                        scanf("%d",&N);
                        if (N==0)
                            free(Tete1);
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
                            {
                                gotoxy(20,18);    //---------------------------------------------------------
                                printf("Erreur...\n");
                                gotoxy(20,19);
                                system("pause");
                                goto c71e;
                            }
                            break;
                            }
                        }
                    }
                }
                goto label;

            case 8:
                if (l==FR)
                {
c8:
                    moncadre();
                    tdir(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("votre ensemble est vide !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Donnez le numero du polynome a deriver : ");
                        scanf("%d",&N);
                        Copy_pol(Locate_pol(TeteG,N),&Tete1);
                        Derive_polynome(Tete1);
c81://__________________________________________________________________________________________________________________________________
                        moncadre();
                        tdir(l);
                        cadre1();
                        backk(l);
                        Affichage_polynome(Tete1,10,16,l);
                        gotoxy(10,25);
                        printf("Voulez-vous enregistrer ce polynome, tapez 1 pour oui et 0 pour non :");
                        scanf("%d",&N);
                        if (N==1)
                            Add_pol(&a,Tete1);
                        else
                        {
                            if (N==0)
                                free(Tete1);
                            else
                            {
                                gotoxy(20,18);    //---------------------------------------------------------
                                printf("Erreur...\n");
                                gotoxy(20,19);
                                system("pause");
                                goto c81;
                            }
                        }
                    }
                }
                else
                {
c8e:
                    moncadre();
                    tdir(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("your set is empty !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Give the polynomial number to be derived : ");
                        scanf("%d",&N);
                        Copy_pol(Locate_pol(TeteG,N),&Tete1);
                        Derive_polynome(Tete1);
c81e://__________________________________________________________________________________________________________________________________
                        moncadre();
                        tdir(l);
                        cadre1();
                        backk(l);
                        Affichage_polynome(Tete1,10,16,l);
                        gotoxy(10,25);
                        printf("Do you want to save this polynomial, type 1 for yes and 0 for no :");
                        scanf("%d",&N);
                        if (N==1)
                            Add_pol(&a,Tete1);
                        else
                        {
                            if (N==0)
                                free(Tete1);
                            else
                            {
                                gotoxy(20,18);    //---------------------------------------------------------
                                printf("Error...\n");
                                gotoxy(20,19);
                                system("pause");
                                goto c81e;
                            }
                        }
                    }
                }
                goto label;
            case 9:
                if (l==FR)
                {
c9:
                    moncadre();
                    tint();
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("votre ensemble est vide !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Donnez le numero du polynome a integrer : ");
                        scanf("%d",&N);
                        Copy_pol(Locate_pol(TeteG,N),&Tete1);
                        Integrate(Tete1);
c91://__________________________________________________________________________________________________________________________________
                        moncadre();
                        tdir(l);
                        cadre1();
                        backk(l);
                        Affichage_polynome(Tete1,10,16,l);
                        gotoxy(10,25);
                        printf("Voulez-vous enregistrer ce polynome, tapez 1 pour oui et 0 pour non :");
                        scanf("%d",&N);
                        if (N==1)
                            Add_pol(&a,Tete1);
                        else
                        {
                            if (N==0)
                                free(Tete1);
                            else
                            {
                                gotoxy(20,18);    //------------------------------------------------
                                printf("Erreur...\n");
                                gotoxy(20,19);
                                system("pause");
                                goto c91;
                            }
                        }
                    }
                }
                else
                {
c9e:
                    moncadre();
                    tint();
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("your set is empty !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Give the polynomial number to integrate : ");
                        scanf("%d",&N);
                        Copy_pol(Locate_pol(TeteG,N),&Tete1);
                        Integrate(Tete1);
c91e://__________________________________________________________________________________________________________________________________
                        moncadre();
                        tdir(l);
                        cadre1();
                        backk(l);
                        Affichage_polynome(Tete1,10,16,l);
                        gotoxy(10,25);
                        printf("Do you want to save this polynomial, type 1 for yes and 0 for no :");
                        scanf("%d",&N);
                        if (N==1)
                            Add_pol(&a,Tete1);
                        else
                        {
                            if (N==0)
                                free(Tete1);
                            else
                            {
                                gotoxy(20,18);    //------------------------------------------------
                                printf("Error...\n");
                                gotoxy(20,19);
                                system("pause");
                                goto c91e;
                            }
                        }
                    }
                }
                goto label;
            case 10:
                if (l==FR)
                {
c10:
                    moncadre();
                    tcalc(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("votre ensemble est vide !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Donnez le numero du  polynome a evaluer : ");
                        scanf("%d",&N);
                        gotoxy(25,36);
                        float calc=0.0;
                        int M;
                        printf("combien de valeur vous voulez calculer? : ");
                        scanf("%d",&M);
                        if (!(M>0))
                        {
                            moncadre();
                            tcop(l);
                            tcalc(l);
                            backk(l);
                            gotoxy(35,25);
                            printf("erreur...!");
                            system("pause");
                            goto c10;
                        }
                        else
                        {
                            moncadre();
                            tcalc(l);
                            cadre1();
                            backk(l);
                            for (i=0; i<M; i++)
                            {
                                gotoxy(10,14+7*i);
                                printf("donner la valeur pour calculer");
                                cadrintr(42,wherey()-1);
                                scanf("%f",&calc);
                                cadrpol(10,wherey()+2);
                                printf("x= %4.2f  et y= %4.2f",calc,Calcul_X(Locate_pol(TeteG,N),calc));
                            }
                            Sleep(2000);
                        }
                    }
                }
                else
                {
c10e:
                    moncadre();
                    tcalc(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("your set is empty !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Give the polynomial number to evaluate : ");
                        scanf("%d",&N);
                        gotoxy(25,36);
                        float calc=0.0;
                        int M;
                        printf("how much value you want to calculate? : ");
                        scanf("%d",&M);
                        if (!(M>0))
                        {
                            moncadre();
                            tcop(l);
                            tcalc(l);
                            backk(l);
                            gotoxy(35,25);
                            printf("error...!");
                            system("pause");
                            goto c10e;
                        }
                        else
                        {
                            moncadre();
                            tcalc(l);
                            cadre1();
                            backk(l);
                            for (i=0; i<M; i++)
                            {
                                gotoxy(10,14+7*i);
                                printf("give the value to calculate");
                                cadrintr(42,wherey()-1);
                                scanf("%f",&calc);
                                cadrpol(10,wherey()+2);
                                printf("x= %4.2f  et y= %4.2f",calc,Calcul_X(Locate_pol(TeteG,N),calc));
                            }
                            Sleep(2000);
                        }
                    }
                }
                goto label;
            case 11:///AFFICHAGE DU COURB DANS UNE AUTRE FENETRE ///---------ELLE SERA FERME APRES 15 SECONDS
                if (l==FR)
                {
c11:
                    moncadre();
                    tcourb(l);
                    cadre1();
                    backk(l);
                    ////parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("votre ensemble est vide !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Donnez le numero du polynome dont vous voulez tracez la courbe : ");
                        scanf("%d",&N);
                        printf("\n");
                        int i,y;
                        float x=-7.8947368421;///L INTERVALE POUR TRACER LA COURBE -8 CM TO 8 CM
                        //Courbe(Locate_pol(TeteG,N))
                        ///-----------------------------------------------PARTIE SDL-----------------------------------------------------------------
                        SDL_Window *fenetre = NULL;
                        SDL_Renderer *renderer = NULL;
                        SDL_Init(SDL_INIT_VIDEO);
                        fenetre = SDL_CreateWindow("COURBE DE POLYNOME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,600,0);
                        renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_SOFTWARE);
                        SDL_SetRenderDrawColor(renderer,255,255,255, SDL_ALPHA_OPAQUE);
                        SDL_RenderDrawLine(renderer, 300, 0, 300, 600);
                        SDL_RenderDrawLine(renderer, 0, 300, 600, 300);
                        SDL_SetRenderDrawColor(renderer,0,255,0, SDL_ALPHA_OPAQUE);
                        for (i=-300; i<300; i++)
                        {

                            SDL_RenderDrawPoint(renderer,300+i, 300-38*(Calcul_X(Locate_pol(TeteG,N),x)));///A CHAQUE FOIX EN ALLUME UN PIXELE
                            x+=0.0263157895;///INCRMENTATION DU VARIABLE

                        }
                        SDL_RenderPresent(renderer);
                        SDL_Delay(15000);///QUITE QPRES 15 SEC VOUS POUVEZ LE CHANGER COMME VOUS VOULEZ
                        SDL_DestroyRenderer(renderer);
                        SDL_DestroyWindow(fenetre);
                        SDL_Quit();
                        ///---------------------------------------------------------------------------------------------------------------
                    }
                }
                else///LE MEME TRAVAIL EN ANGLAIS
                {
c11e:
                    moncadre();
                    tcourb(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    if (a==NULL)
                    {
                        gotoxy(35,25);
                        printf("your set is empty !");
                        Sleep(1000);
                    }
                    else
                    {
                        Afficher_Ensemble(TeteG,25,13,l);
                        gotoxy(25,35);
                        printf("Give the number of the polynomial whose curve you want to draw : ");
                        scanf("%d",&N);
                        gotoxy(25,36);
                        printf("The polynomial curve : ");
                        Affichage_polynome(Locate_pol(TeteG,N),25,16,l);
                        printf("\n");
                        float x=-7.8947368421;
                        ///----------------------------------------------------------------------------------------------------------------
                        SDL_Window *fenetre = NULL;
                        SDL_Renderer *renderer = NULL;
                        SDL_Init(SDL_INIT_VIDEO);
                        fenetre = SDL_CreateWindow("COURBE DE POLYNOME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,600,0);
                        renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_SOFTWARE);
                        SDL_SetRenderDrawColor(renderer,255,255,255, SDL_ALPHA_OPAQUE);
                        SDL_RenderDrawLine(renderer, 300, 0, 300, 600);
                        SDL_RenderDrawLine(renderer, 0, 300, 600, 300);
                        SDL_SetRenderDrawColor(renderer,0,255,0, SDL_ALPHA_OPAQUE);
                        for (i=-300; i<300; i++)
                        {

                            SDL_RenderDrawPoint(renderer,300+i, 300-(38*(Calcul_X(Locate_pol(TeteG,N),x))));
                            x+=0.0263157895;

                        }
                        SDL_RenderPresent(renderer);
                        SDL_Delay(10000);
                        SDL_DestroyRenderer(renderer);
                        SDL_DestroyWindow(fenetre);
                        SDL_Quit();
                        ///---------------------------------------------------------------------------------------------------------------

                    }
                }
                goto label;
            case 12:
                if (l==FR)
                {
c12:
                    moncadre();
                    tcrc(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    gotoxy(10,13);
                    printf("Vous voulez creer le polynome generateur ou utiliser un polynome deja existant:");
                    gotoxy(15,15);
                    printf("tapez 1 pour creer ou 2 pour choisir un polynome existant :");
                    scanf("%d",&N);
                    if (N==2)
                    {
                        if (a==NULL)
                        {
                            gotoxy(30,14);
                            printf("Votre ensemble est vide !");
                            Sleep(1000);
                        }
                        else
                        {
                            moncadre();
                            tcrc(l);
                            cadre1();
                            backk(l);
                            Afficher_Ensemble(TeteG,25,15,l);
                            gotoxy(10,36);
                            printf("Choisissez le numero du polynome que vous souhaitez considerer comme generateur : ");
                            scanf("%d",&M);
                            Tete1=Locate_pol(TeteG,M);
                            moncadre();
                            tcrc(l);
                            cadre1();
                            backk(l);
                            gotoxy(10,15);
                            printf("Entrer l'information : ");
                            cadrintr(35,14);
                            scanf("%lld",&info1);
                            CRC(info1,Tete1,&info2,&CodeCRC);
                            cadrpol(10,18);
                            printf("Information codee : %lld             i.e.  %lld %lld",info2,info1,CodeCRC);
                            gotoxy(10,35);
                            system("pause");
                        }
                    }
                    else
                    {
                        if (N==1)
                        {
                            moncadre();
                            tcrc(l);
                            cadre1();
                            backk(l);
                            Generate_pol(&Tete1,10,12,l);
                            moncadre();
                            tcrc(l);
                            cadre1();
                            backk(l);
                            gotoxy(10,14);
                            printf("Entrer l'information : ");
                            cadrintr(35,13);
                            scanf("%lld",&info1);
                            CRC(info1,Tete1,&info2,&CodeCRC);
                            cadrpol(10,18);
                            printf("Information codee : %lld             i.e.  %lld %lld",info2,info1,CodeCRC);
                            gotoxy(10,35);
                            system("pause");
                        }
                        else
                        {
                            gotoxy(20,18);    //-----------------------------------------------
                            printf("Erreur...\n");
                            gotoxy(20,19);
                            system("pause");
                            goto c12;
                        }
                    }
                }
                else
                {
c12e:
                    moncadre();
                    tcrc(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    gotoxy(10,13);
                    printf("You want to create the generator polynomial or use an already existing polynomial:");
                    gotoxy(15,15);
                    printf("type 1 to create or 2 to choose an existing polynomial :");
                    scanf("%d",&N);
                    if (N==2)
                    {
                        if (a==NULL)
                        {
                            gotoxy(30,14);
                            printf("your set is empty !");
                            Sleep(1000);
                        }
                        else
                        {
                            moncadre();
                            tcrc(l);
                            cadre1();
                            backk(l);
                            Afficher_Ensemble(TeteG,25,15,l);
                            gotoxy(10,36);
                            printf("Choose the polynomial number that you want to consider as a generator : ");
                            scanf("%d",&M);
                            Tete1=Locate_pol(TeteG,M);
                            moncadre();
                            tcrc(l);
                            cadre1();
                            backk(l);
                            gotoxy(10,15);
                            printf("Enter the information : ");
                            cadrintr(35,14);
                            scanf("%lld",&info1);
                            CRC(info1,Tete1,&info2,&CodeCRC);
                            cadrpol(10,18);
                            printf("coded Information  : %lld             i.e.  %lld %lld",info2,info1,CodeCRC);
                            gotoxy(10,35);
                            system("pause");
                        }
                    }
                    else
                    {
                        if (N==1)
                        {
                            moncadre();
                            tcrc(l);
                            cadre1();
                            backk(l);
                            Generate_pol(&Tete1,10,12,l);
                            moncadre();
                            tcrc(l);
                            cadre1();
                            backk(l);
                            gotoxy(10,14);
                            printf("Enter the information : ");
                            cadrintr(35,13);
                            scanf("%lld",&info1);
                            CRC(info1,Tete1,&info2,&CodeCRC);
                            cadrpol(10,18);
                            printf("coded Information  : %lld             i.e.  %lld %lld",info2,info1,CodeCRC);
                            gotoxy(10,35);
                            system("pause");
                        }
                        else
                        {
                            gotoxy(20,18);    //-----------------------------------------------
                            printf("Error...\n");
                            gotoxy(20,19);
                            system("pause");
                            goto c12e;
                        }
                    }
                }
                goto label;
            case 13:
                if (l==FR)
                {
c13:
                    moncadre();
                    tcrc2(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    gotoxy(10,15);
                    printf("Vous voulez creer le polynome generateur ou utiliser un polynome deja existant:");
                    gotoxy(15,17);
                    printf("tapez 1 pour creer ou 2 pour choisir un polynome existant : ");
                    scanf("%d",&N);
                    if (N==2)
                    {
                        if (a==NULL)
                        {
                            gotoxy(20,19);
                            printf("Votre ensemble est vide !");
                            Sleep(1000);
                        }
                        else
                        {
                            moncadre();
                            tcrc2(l);
                            cadre1();
                            backk(l);
                            Afficher_Ensemble(TeteG,25,15,l);
                            gotoxy(10,36);
                            printf("Choisissez le numero du polynome que vous souhaitez considerer comme generateur : ");
                            scanf("%d",&M);
                            Tete1=Locate_pol(TeteG,M);
                            moncadre();
                            tcrc2(l);
                            cadre1();
                            backk(l);
                            gotoxy(10,15);
                            printf("Entrer l'information : ");
                            cadrintr(35,14);
                            scanf("%lld",&info1);
                            Error_detection(info1,Tete1,&Happiness);
                            if (Happiness==0)
                            {
                                gotoxy(20,18);
                                printf("L'information est intacte !");
                                gotoxy(20,19);
                                system("pause");
                            }
                            else
                            {
                                gotoxy(20,18);
                                printf("Linformation a subi des modification lors de sa transmission !");
                                gotoxy(20,19);
                                system("pause");
                            }
                        }
                    }
                    else
                    {
                        if (N==1)
                        {
                            moncadre();
                            tcrc2(l);
                            cadre1();
                            backk(l);
                            Generate_pol(&Tete1,10,12,l);
                            moncadre();
                            tcrc2(l);
                            cadre1();
                            backk(l);
                            gotoxy(10,14);
                            printf("Entrer l'information : ");
                            cadrintr(35,13);
                            scanf("%lld",&info1);
                            Error_detection(info1,Tete1,&Happiness);
                            if (Happiness==0)
                            {
                                gotoxy(20,18);
                                printf("L'information est intacte !");
                                gotoxy(20,19);
                                system("pause");
                            }
                            else
                            {
                                gotoxy(20,18);
                                printf("Linformation a subi des modification lors de sa transmission !");
                                gotoxy(20,19);
                                system("pause");
                            }
                        }
                        else
                        {
                            gotoxy(20,18);    //-----------------------------------------------
                            printf("Erreur...");
                            gotoxy(20,19);
                            system("pause");
                            goto c13;
                        }
                    }
                }
                else
                {
c13e:
                    moncadre();
                    tcrc2(l);
                    cadre1();
                    backk(l);
                    //parler(tab[y]);
                    gotoxy(10,15);
                    printf("You want to create the generator polynomial or use an already existing polynomial:");
                    gotoxy(15,17);
                    printf("type 1 to create or 2 to choose an existing polynomial : ");
                    scanf("%d",&N);
                    if (N==2)
                    {
                        if (a==NULL)
                        {
                            gotoxy(20,19);
                            printf("your set is empty !");
                            Sleep(1000);
                        }
                        else
                        {
                            moncadre();
                            tcrc2(l);
                            cadre1();
                            backk(l);
                            Afficher_Ensemble(TeteG,25,15,l);
                            gotoxy(10,36);
                            printf("Choose the polynomial number that you want to consider as a generator : ");
                            scanf("%d",&M);
                            Tete1=Locate_pol(TeteG,M);
                            moncadre();
                            tcrc2(l);
                            cadre1();
                            backk(l);
                            gotoxy(10,15);
                            printf("Enter the information : ");
                            cadrintr(35,14);
                            scanf("%lld",&info1);
                            Error_detection(info1,Tete1,&Happiness);
                            if (Happiness==0)
                            {
                                gotoxy(20,18);
                                printf("Information is intact !");
                                gotoxy(20,19);
                                system("pause");
                            }
                            else
                            {
                                gotoxy(20,18);
                                printf("The information has undergone changes during its transmission !");
                                gotoxy(20,19);
                                system("pause");
                            }
                        }
                    }
                    else
                    {
                        if (N==1)
                        {
                            moncadre();
                            tcrc2(l);
                            cadre1();
                            backk(l);
                            Generate_pol(&Tete1,10,12,l);
                            moncadre();
                            tcrc2(l);
                            cadre1();
                            backk(l);
                            gotoxy(10,14);
                            printf("Enter the information : ");
                            cadrintr(35,13);
                            scanf("%lld",&info1);
                            Error_detection(info1,Tete1,&Happiness);
                            if (Happiness==0)
                            {
                                gotoxy(20,18);
                                printf("Information is intact !");
                                gotoxy(20,19);
                                system("pause");
                            }
                            else
                            {
                                gotoxy(20,18);
                                printf("The information has undergone changes during its transmission !");
                                gotoxy(20,19);
                                system("pause");
                            }
                        }
                        else
                        {
                            gotoxy(20,18);    //-----------------------------------------------
                            printf("Error...");
                            gotoxy(20,19);
                            system("pause");
                            goto c13e;
                        }
                    }
                }
                goto label;
            case 14:
                goto fin;
            }
            break;
        }

    }
    goto label;
fin:///===========================ETIQUE POUR LA FIN DU PROGRAMME UNE SALUTAION ET REMERCIMENT==================

    moncadre();
    cadre1();
    backk(l);
    quitter(&l,&quit);
    if (quit!= 1)///SI L UTILISATEUR CHOISI DE RETOUR VERS LE MENU AUTRE FOIS
        goto label;
    contacter();/// INFORMATIONS POUR NOUS CONTACTER
    Sleep(5000);
    the_end();///GRAPHIQUE POUR LA SORTIE
}





