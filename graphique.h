#ifndef _GRAPHIQUE_H_
#define _GRAPHIQUE_H_
///_______________________________________________________INCLUDE____________________________________________///
#include "fonctions.h"
///_______________________________________________________DEFINITION____________________________________________///
#define FR 0
#define EN 1
///_______________________________________________________STRUCTURES____________________________________________///
enum booleen {false,true};
typedef enum booleen booleen;
typedef char* tabstr ; ///tableau de chaine de caractere
enum ///les code numerique des touches du clavier
{
    ESC =27,
    ARROW_UP =328,
    ARROW_DOWN =336,
    ARROW_LEFT =331,
    ARROW_RIGHT =333,
    F1 =315,
    CTRL_L =12,
    ENTRER =13,
    ALPHA_a =97,
    ALPHA_z =122,
    ALPHA_A =65,
    ALPHA_Z =90,
    KEY_0 =48,
    KEY_9 =57,
    BACK_SPACE=8,
    SPACE_BAR=32

};
///_______________________________________________________LES FONCTIONS____________________________________________///

void parler(char *chaine)///RETURNE L ECHO D UNE CHAINE DE CARACTERES
{
    char temp1[256];
    sprintf(temp1,"echo m=\"%s\" > file.vbs",chaine);
    system(temp1);
    sprintf(temp1,"echo CreateObject(\"SAPI.SpVoice\").Speak m >> file.vbs");
    system(temp1);
    sprintf(temp1,"file.vbs");
    system(temp1);
    remove("file.vbs");
}

void AffichezGuidefr()///AFFICHAGE DU GUIDE EN FRANCAIS
{
    int z=22;
    int w=5;
    char a=219;
    clrscr();
    textbackground(DARKGRAY);
    system("color 87");
    textcolor(4);
    gotoxy(z,w+1);
    textcolor(5);
    printf("      %c%c%c%c%c%c%c%c%c       %c%c        %c%c      %c%c      %c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+2);
    printf("      %c%c%c%c%c%c%c%c%c       %c%c        %c%c      %c%c      %c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+3);
    printf("      %c%c              %c%c        %c%c      %c%c      %c%c      %c%c     %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+4);
    printf("      %c%c              %c%c        %c%c      %c%c      %c%c      %c%c     %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+5);
    printf("      %c%c              %c%c        %c%c      %c%c      %c%c      %c%c     %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+6);
    printf("      %c%c              %c%c        %c%c      %c%c      %c%c      %c%c     %c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+7);
    printf("      %c%c   %c%c%c%c       %c%c        %c%c      %c%c      %c%c      %c%c     %c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+8);
    printf("      %c%c       %c%c     %c%c        %c%c      %c%c      %c%c      %c%c     %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+9);
    printf("      %c%c       %c%c     %c%c        %c%c      %c%c      %c%c      %c%c     %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+10);
    printf("      %c%c       %c%c     %c%c        %c%c      %c%c      %c%c      %c%c     %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+11);
    printf("      %c%c%c%c%c%c%c%c%c       %c%c%c%c%c%c%c%c%c%c%c%c      %c%c      %c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+12);
    printf("      %c%c%c%c%c%c%c%c%c       %c%c%c%c%c%c%c%c%c%c%c%c      %c%c      %c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+13);
    printf("\n");
    printf("\n");
    textcolor(4);

    puts("                          ____________________________________________________________________");

    puts("                      ");
    puts("                                            GUIDE ET NOTICES DE L'APPLICATION");
    puts("                          ____________________________________________________________________");
    parler("GUIDE ET NOTICES DE L'APPLICATION");
    printf("\n");
    printf("\n");
    textcolor(0);
    printf("                  %c%c%c%c%c%c%c%c%c%c                                                     %c%c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a);
    printf("\n");
    printf("                  %c%c      %c%c                                                     %c%c      %c%c",a,a,a,a,a);
    printf("\n");
    printf("                  %c%c BAS  %c%c   VERS LE BAS                                       %c%c HAUT %c%c  VERS LE HAUT",a,a,a,a,a);
    printf("\n");
    printf("                  %c%c      %c%c                                                     %c%c      %c%c",a,a,a,a,a);
    printf("\n");
    printf("                  %c%c%c%c%c%c%c%c%c%c                                                     %c%c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c                                 %c%c%c%c%c%c%c%c%c%c    ",a,a,a,a,a,a,a,a,a,a,a,a,a);
    printf("\n");
    printf("                  %c%c           %c%c   %c%c        %c%c                                 %c%c      %c%c                 ",a,a,a,a,a);
    printf("\n");
    printf("                  %c%c   CRTL    %c%c + %c%c   L    %c%c  = CHAMGEMENT DE LA LANGUE      %c%c ESC  %c%c   RETOURE   ",a,a,a,a,a);
    printf("\n");
    printf("                  %c%c           %c%c   %c%c        %c%c                                 %c%c      %c%c                  ",a,a,a,a,a);
    printf("\n");
    printf("                  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c                                 %c%c%c%c%c%c%c%c%c%c    ",a,a,a,a,a,a,a,a,a,a,a,a,a);
}

void AffichezGuideen()///AFFICHAGE DU GUIDE EN ANGLAIS
{
    int z=22;
    int w=5;
    char a=219;
    clrscr();
    textbackground(DARKGRAY);
    system("color 87");
    textcolor(4);
    gotoxy(z,w+1);
    textcolor(5);
    printf("      %c%c%c%c%c%c%c%c%c       %c%c        %c%c      %c%c      %c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+2);
    printf("      %c%c%c%c%c%c%c%c%c       %c%c        %c%c      %c%c      %c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+3);
    printf("      %c%c              %c%c        %c%c      %c%c      %c%c      %c%c     %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+4);
    printf("      %c%c              %c%c        %c%c      %c%c      %c%c      %c%c     %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+5);
    printf("      %c%c              %c%c        %c%c      %c%c      %c%c      %c%c     %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+6);
    printf("      %c%c              %c%c        %c%c      %c%c      %c%c      %c%c     %c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+7);
    printf("      %c%c   %c%c%c%c       %c%c        %c%c      %c%c      %c%c      %c%c     %c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+8);
    printf("      %c%c       %c%c     %c%c        %c%c      %c%c      %c%c      %c%c     %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+9);
    printf("      %c%c       %c%c     %c%c        %c%c      %c%c      %c%c      %c%c     %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+10);
    printf("      %c%c       %c%c     %c%c        %c%c      %c%c      %c%c      %c%c     %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+11);
    printf("      %c%c%c%c%c%c%c%c%c       %c%c%c%c%c%c%c%c%c%c%c%c      %c%c      %c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+12);
    printf("      %c%c%c%c%c%c%c%c%c       %c%c%c%c%c%c%c%c%c%c%c%c      %c%c      %c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(z,w+13);
    printf("\n");
    printf("\n");
    textcolor(4);

    puts("                          ____________________________________________________________________");

    puts("                      ");
    puts("                                        GUIDE AND NOTICES FOR THE APPLICATION");
    puts("                          ____________________________________________________________________");
    parler("GUIDE AND NOTICES FOR THE APPLICATION");
    printf("\n");
    printf("\n");
    textcolor(0);
    printf("                  %c%c%c%c%c%c%c%c%c%c                                                     %c%c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a);
    printf("\n");
    printf("                  %c%c      %c%c                                                     %c%c      %c%c",a,a,a,a,a);
    printf("\n");
    printf("                  %c%c  UP  %c%c   MOVW UP                                           %c%c DOWN %c%c  MOVE DOWN",a,a,a,a,a);
    printf("\n");
    printf("                  %c%c      %c%c                                                     %c%c      %c%c",a,a,a,a,a);
    printf("\n");
    printf("                  %c%c%c%c%c%c%c%c%c%c                                                     %c%c%c%c%c%c%c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c                                 %c%c%c%c%c%c%c%c%c%c    ",a,a,a,a,a,a,a,a,a,a,a,a,a);
    printf("\n");
    printf("                  %c%c           %c%c   %c%c        %c%c                                 %c%c      %c%c                 ",a,a,a,a,a);
    printf("\n");
    printf("                  %c%c   CRTL    %c%c + %c%c   L    %c%c  = LANGUAGE CHANGE              %c%c ESC  %c%c   BACK   ",a,a,a,a,a);
    printf("\n");
    printf("                  %c%c           %c%c   %c%c        %c%c                                 %c%c      %c%c                  ",a,a,a,a,a);
    printf("\n");
    printf("                  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c                                 %c%c%c%c%c%c%c%c%c%c    ",a,a,a,a,a,a,a,a,a,a,a,a,a);
}

void cadre1()/// "CADR2" EST UN PROCEDEUR PERMET D'AFFICHER UN CADRE DANS LA CONSOLE
{
    int i;
    gotoxy(6,9) ;
    for (i=0; i<=110; i++)
    {
        textcolor (9);
        printf("%c",176);
    }
    gotoxy(6,40) ;
    for (i=0; i<=110; i++)
    {
        textcolor (9);
        printf("%c",176);
    }

    for (i=9; i<=40; i++)
    {
        gotoxy(6,i) ;
        textcolor (9);
        printf("%c",219) ;
        gotoxy(116,i);
        textcolor (9);
        printf("%c",219) ;
    }
    textcolor (15);

}

void printfslow(char ch[],int temps) ///ecrit une chaine de caractere avec un temp d'arret entre chaque caractere
{
    int i;
    for (i=0 ; i < strlen(ch); i++)
    {
        printf("%c",ch[i]);
        Sleep(temps);
    }
}

void moncadre()///CA C'EST MON CADRE PRINCIPALE "THE BACLGROUND"
{
    clrscr();
    system("color 87");
    int i;
    textbackground(DARKGRAY);
    printf("%c",201);
    for (i=1; i<120; i++)
    {
        textcolor((15+i)%15);
        printf("%c",205);
    }
    printf("%c\n",187);
    for (i=1; i<40; i++)
    {
        textcolor((15+i)%15);
        printf("%c",186);
        gotoxy(wherex()+119,wherey());
        printf("%c\n",186);
    }

    printf("%c",200);
    for (i=1; i<120; i++)
    {
        textcolor((15+i)%15);
        printf("%c",205);
    }
    printf("%c",188);
}

void Esi()///AFFICHAGE ET PRONOCIATION DU MOT ESI
{
    moncadre();
    float c=0.5;
    gotoxy(1,9);
    textcolor(14);
    printfslow("\t     ******************************                  **********      **        **************\n",c);
    Sleep(100);
    printfslow("\t     *******************************             ****************** ***        ***************\n",c);
    Sleep(100);
    printfslow("\t         ****** ********************           *******       ***********           *******\n",c);
    Sleep(100);
    printfslow("\t          *****                 *****         *****              *******            *****\n",c);
    Sleep(100);
    printfslow("\t          *****                   ****        ****                 ******           *****\n",c);
    Sleep(100);
    textcolor(9);
    printfslow("\t         ******                    ***       *****                  *****          ******\n",c);
    Sleep(100);
    printfslow("\t         ******          ***        **       ******                   ***          ******\n",c);
    Sleep(100);
    printfslow("\t         ******          ***                  *******                  **          ******\n",c);
    Sleep(100);
    textcolor(0);
    printfslow("\t         ******         ****                  ***********                          ******\n",c);
    Sleep(100);
    printfslow("\t         ******        *****                    ***************                    ******\n",c);
    Sleep(100);
    printfslow("\t         *******************                      *****************                ******\n",c);
    Sleep(100);
    printfslow("\t         *******************                         ******************            ******\n",c);
    Sleep(100);
    printfslow("\t         ******        *****                               **************          ******\n",c);
    Sleep(100);
    printfslow("\t         ******         ****                                     *********         ******\n",c);
    Sleep(100);
    printfslow("\t         ******          ***                ****                    *******        ******\n",c);
    Sleep(100);
    textcolor(9);
    printfslow("\t         ******          ***         ***    ****                     ******        ******\n",c);
    Sleep(100);
    printfslow("\t         ******                     ****     ****                     *****        ******\n",c);
    Sleep(100);
    printfslow("\t         ******                    ****      ******                   *****        ******\n",c);
    Sleep(100);
    textcolor(14);
    printfslow("\t         *****                  ******       ******                 *****          *****\n",c);
    Sleep(100);
    printfslow("\t         ******                *******        *********            ******          ******\n",c);
    Sleep(100);
    printfslow("\t     ********************************         **** *********************       **************\n",c);
    Sleep(100);
    printfslow("\t     ********************************         ***    ****************          ***************\n\n",c);
    parler("ecole nationale Supecrieure d'informatique");
}

void TP()///AFFICHAGE ET PRONOCIATION DU MOT TP1 DE ALSDD
{
    moncadre();
    gotoxy(3,12);
    textcolor(14);
    printf("\t                     **********************         ************                  ****\n");
    Sleep(100);
    printf("\t                     **********************          ************                *****\n");
    Sleep(100);
    printf("\t                     ******   ****   ******          ****      ***              ******\n");
    Sleep(100);
    textcolor(9);
    printf("\t                     ****     ****     ****          ****       ***            *******\n");
    Sleep(100);
    printf("\t                     **       ****       **          ****       ***           ********\n");
    Sleep(100);
    printf("\t                              ****                   ****      ***           **** ****\n");
    Sleep(100);
    textcolor(0);
    printf("\t                              ****                   ************                 ****\n");
    Sleep(100);
    printf("\t                              ****                   **********                   ****\n");
    Sleep(100);
    printf("\t                              ****                   ****                         ****\n");
    Sleep(100);
    printf("\t                              ****                   ****                         ****\n");
    Sleep(100);
    textcolor(9);
    printf("\t                              ****                   ****                         ****\n");
    Sleep(100);
    printf("\t                              ****                   ****                         ****\n");
    Sleep(100);
    printf("\t                              ****                   ****                         ****\n");
    Sleep(100);
    textcolor(14);
    printf("\t                             ******                 ******                       ******\n");
    Sleep(100);
    printf("\t                           **********             **********                   **********\n");
    parler("Premier TP d'Algorithmique et structures de donnees dynamiques");
}

void loading()///LOADING S'AFFICHE AU MILIEU DE L ECRAN
{
    int l;
    moncadre();
    gotoxy(22,21);
    textcolor(12);
    printf("\t\t LOADING ");
    for(l=0; l<14; l++)
    {
        textcolor(15);
        Sleep(100);
        printf("%c ",254);
    }
    textcolor(12);
    printf("100 %c",37);
    textcolor(15);
}

void backlang(int l)/// affiche un ENTETE de page (les touche retour et changer de langue)
{
    int xi,yi,x=6,y=4;
    xi=wherex();
    yi=wherey();
    gotoxy(1,3);
    textcolor(9);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,217);
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,191);
    gotoxy(x,y+2);
    printf("%c            %c",179,179);
    gotoxy(x,y+1);
    printf("%c            %c",179,179);
    gotoxy(x+(111-14),y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,217);
    gotoxy(x+(111-14),y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,191);
    gotoxy(x+111-14,y+2);
    printf("%c            %c",179,179);
    gotoxy(x+111-14,y+1);
    printf("%c            %c",179,179);
    textcolor(15);
    if(l==FR)
    {
        gotoxy(x+1,y+1);
        printf("   Retour");
        gotoxy(x+1,y+2);
        printf("   (Echap)");
        gotoxy(x+112-14+1,y+1);
        printf("  Langue ");
        gotoxy(x+112-14+1,y+2);
        printf(" (Ctrl+L) ");
    }
    else
    {
        gotoxy(x+1,y+1);
        printf("  Go back");
        gotoxy(x+1,y+2);
        printf("   (ESC)");
        gotoxy(x+112-14+1,y+1);
        printf("  Language ");
        gotoxy(x+112-14+1,y+2);
        printf("  (Ctrl+L)");
    }
    gotoxy(xi,yi);
}

void backk(int l)/// affiche un TETE de page (les touche retour )
{

    /**int xi,yi,x=6,y=4;
    xi=wherex();
    yi=wherey();
    gotoxy(1,3);
    textcolor(9);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,217);
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,191);
    gotoxy(x,y+2);
    printf("%c            %c",179,179);
    gotoxy(x,y+1);
    printf("%c            %c",179,179);
    textcolor(15);
    if(l==FR)
    {
        gotoxy(x+1,y+1);
        printf("   Retour");
        gotoxy(x+1,y+2);
        printf("   (Echap)");
    }
    else
    {
        gotoxy(x+1,y+1);
        printf("  Go back");
        gotoxy(x+1,y+2);
        printf("   (ESC)");
    }
    gotoxy(xi,yi);*/
}

int _getkey(void) ///lit une touche du clavier tout en gerant le buffer
{
    int ch;
    clearkeybuf();
    ch=_getch();
    if (ch==0 || ch==224)
        ch=_getch()+256;

    return ch;
}

void accueil(int *l)/// graphique d'entrer ET MON ACCUEIL
{
    int i,x,y,c;

    moncadre();
    gotoxy(3,2);
    x=wherex();
    y=wherey();
    gotoxy(x,y);
    printf(" ______  _____  __ ");
    gotoxy(x,y+1);
    printf("|  ____|/ ____||__|");
    gotoxy(x,y+2);
    printf("| |__  | (___   __ ");
    gotoxy(x,y+3);
    printf("|  __|  \\___ \\ |  |");
    gotoxy(x,y+4);
    printf("| |____ ____) ||  |");
    gotoxy(x,y+5);
    printf("|______|_____/ |__|");
    textcolor(9);
    gotoxy(x+15,y);
    printf(" __");
    gotoxy(x+15,y+1);
    printf("|__|");
    textcolor(15);
    gotoxy(x+21,y+1);
    printf("%ccole nationale",144);
    gotoxy(x+21,y+3);
    printf("Sup%crieure",130);
    gotoxy(x+21,y+5);
    printf("d'Informatique");
    int j=0,tmpp=0;
    do
    {
        textcolor(j);
        tmpp++;
        Sleep(100);
        gotoxy(25,10);
        printf("Premier TP d'Algorithmique et structures de donnees dynamiques");
        j++;
    }
    while(tmpp<15);
    textcolor(9);
    c=1;
    gotoxy(4,11);
    x=wherex();
    y=wherey();
    gotoxy(x+6,y);
    printfslow("                      _ _           _   _                   _                        _   _              ",c);
    gotoxy(x+6,y+1);
    printfslow("    /\\               | (_)         | | (_)                 | |                      | | (_)             ",c);
    gotoxy(x+6,y+2);
    printfslow("   /  \\   _ __  _ __ | |_  ___ __ _| |_ _  ___  _ __     __| | ___    __ _  ___  ___| |_ _  ___  _ __   ",c);
    gotoxy(x+6,y+3);
    printfslow("  / /\\ \\ | '_ \\| '_ \\| | |/ __/ _` | __| |/ _ \\| '_ \\   / _` |/ _ \\  / _` |/ _ \\/ __| __| |/ _ \\| '_ \\",c);
    gotoxy(x+6,y+4);
    printfslow(" / ____ \\| |_) | |_) | | | (_| (_| | |_| | (_) | | | | | (_| |  __/ | (_| |  __/\\__ \\ |_| | (_) | | | |",c);
    gotoxy(x+6,y+5);
    printfslow("/_/    \\_\\ .__/| .__/|_|_|\\___\\__,_|\\__|_|\\___/|_| |_|  \\__,_|\\___|  \\__, |\\___||___/\\__|_|\\___/|_| |_| ",c);
    gotoxy(x+6,y+6);
    printfslow("         | |   | |                                                    __/ |                     ",c);
    gotoxy(x+6,y+7);
    printfslow("         |_|   |_|                                                   |___/                              ",c);
    textcolor(15);
    textcolor(9);
    gotoxy(9,19);
    x=wherex();
    y=wherey();
    gotoxy(x+16,y);
    printfslow("     _                          _                         ",c);
    gotoxy(x+16,y+1);
    printfslow("    | |                        | |                         ",c);
    gotoxy(x+16,y+2);
    printfslow("  __| | ___  ___    _ __   ___ | |_   _ _ __   ___  _ __ ___   ___  ___           ",c);
    gotoxy(x+16,y+3);
    printfslow(" / _` |/ _ \\/ __|  | '_ \\ / _ \\| | | | | '_ \\ / _ \\| '_ ` _ \\ / _ \\/ __|      ",c);
    gotoxy(x+16,y+4);
    printfslow("| (_| |  __/\\__ \\  | |_) | (_) | | |_| | | | | (_) | | | | | |  __/\\__ \\",c);
    gotoxy(x+16,y+5);
    printfslow(" \\__,_|\\___||___/  | .__/ \\___/|_|\\___ |_| |_|\\___/|_| |_| |_|\\___||___/             ",c);
    gotoxy(x+16,y+6);
    printfslow("                   | |             __/ |  ",c);
    gotoxy(x+16,y+7);
    printfslow("                   |_|            |___/  ",c);
    textcolor(15);

    gotoxy(21,28);
    x=11;
    y=wherey();
    int z=40;
    int w=10;
    char a=219;
    textcolor(0);
    printfslow(" ________________________________________________________________________________",c);
    printf("\n");
    textcolor(15);
    gotoxy(x+10,y+1);

    printf("|%c%c                                                                            %c%c|",a,a,a,a);
    textcolor(0);
    printf("\n");
    textcolor(15);
    gotoxy(x+10,y+2);
    printf("|%c%c   REALISE PAR   --->   BOUANANE MOHAMED EL-AMINE | LAISSAOUI BADREDDINE    %c%c|",a,a,a,a);
    textcolor(0);
    printf("\n");
    gotoxy(x+10,y+3);
    printf("|%c%c____________________________________________________________________________%c%c|",a,a,a,a);
    textcolor(0);
    printf("\n");
    gotoxy(x+10,y+4);
    printf("|%c%C                                                                              %c%C|",a,a,a,a);
    textcolor(15);
    printf("\n");
    gotoxy(x+10,y+5);
    printf("|%c%c                SECTION B    --|-->    1CPI   --|-->    GO6                 %c%c|",a,a,a,a);
    textcolor(15);
    printf("\n");
    gotoxy(x+10,y+6);
    textcolor(15);
    printf("|%c%c____________________________________________________________________________%c%c|",a,a,a,a);
    textcolor(0);
    printf("\n");
    gotoxy(x+10,y+7);
    printf("|%c%c____________________________________________________________________________%c%c|",a,a,a,a);
    textcolor(0);
    printf("\n");
    gotoxy(x+10,y+8);

    printf("|%c%C                                                                              %c%C|",a,a,a,a);
    textcolor(15);
    printf("\n");
    gotoxy(x+10,y+9);

    printf("|%c%c                     ENCADRE PAR MONSIEUR BALLA AMMAR                       %c%c|",a,a,a,a);
    textcolor(15);
    printf("\n");
    textcolor(15);
    gotoxy(x+10,y+10);

    printf("|%c%c____________________________________________________________________________%c%c|",a,a,a,a);
    parler("applicqtion de gestion des polynomes REALISé PAR BOUANANE MOHAMED EL-AMINE et LAISSAOUI BADREDDINE,ENCADRé PAR MONSIEUR BALLA AMMA");
    j=0;//gotoxy(10,y+11);
    do
    {
        textcolor(j);
        tmpp++;
        Sleep(100);
        gotoxy(14,y+11);
        printf("Si vous voulez lire l'aide appuyez sur %cH%c, sinon appuyez sur %cEntrer%c pour lancer le programme.",34,34,34,34);
        j++;
    }
    while(j<15);
    parler("Si vous voulez lire l'aide appuyez sur H, sinon appuyez sur Entrer pour lancer le programme.");
    //printf("Si vous voulez lire l'aide appuyez sur %cH%c, sinon appuyez sur %cEntrer%c pour lancer le programme.",34,34,34,34);
    do
    {
        c=_getkey();
    }
    while ((c!=ENTRER)&&(c!='H')&&(c!='h'));
    if((c=='h')||(c=='H'))
    {
        AffichezGuidefr();
        do
        {
            c=_getkey();
            if (c==CTRL_L)
            {
                *l=(*l+1)%2;
                if (*l==FR)
                {
                    AffichezGuidefr();
                }

                else
                {
                    AffichezGuideen();

                }
            }
        }
        while (c!=ENTRER);
    }
}

void Color(int couleurDuTexte,int couleurDeFond)///POUR GERER LES COULEUR DU TEXT
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void tmenu()///ENTETE POUR LE MENU
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    printf("%c%c%c%c                           Menu                          %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void tCreer_un_polynome(int l)///ENTETE POUR LA CREATION DES POLYNOMES AVEC LE SWITCH DE LA LANGUE
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    if (l==FR)
        printf("%c%c%c%c                    Creer un polynome                    %c%c%c%c\n",219,219,219,219,219,219,219,219);
    else
        printf("%c%c%c%c                  creation of polynomial                 %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void taffich(int l )///ENTETE POUR LA AFFICHAGE DES POLYNOMES AVEC LE SWITCH DE LA LANGUE
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    if(l==FR)
        printf("%c%c%c%c           Affichage de l'ensemble des polynomes         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    else
        printf("%c%c%c%c             displaying the set of polynomials           %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void tsupp(int l)///ENTETE POUR LA SUPPRETION DES POLYNOMES AVEC LE SWITCH DE LA LANGUE
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    if (l==FR)
        printf("%c%c%c%c                 Suprretion d'un polynome                %c%c%c%c\n",219,219,219,219,219,219,219,219);
    else
        printf("%c%c%c%c                 Suprretion of polynomials                %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void tcop(int l)///ENTETE POUR LE COPIER DES POLYNOMES AVEC LE SWITCH DE LA LANGUE
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    if (l==FR)
        printf("%c%c%c%c                   Copier d'un polynome                  %c%c%c%c\n",219,219,219,219,219,219,219,219);
    else
        printf("%c%c%c%c                    Copy of polynomial                   %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void tAdd()///ENTETE POUR L'ADDITION DES POLYNOMES AVEC LE SWITCH DE LA LANGUE
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    printf("%c%c%c%c                         Addition                        %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void tcalc(int l)///ENTETE POUR L'EVALUATION DES POLYNOMES AVEC LE SWITCH DE LA LANGUE
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    if (l==FR)
        printf("%c%c%c%c                  Evaluer un Polynome                    %c%c%c%c\n",219,219,219,219,219,219,219,219);
    else
        printf("%c%c%c%c                 Evaluate a Polynomial                   %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void tsous()///ENTETE POUR LA SOUSTRACTION DES POLYNOMES AVEC LE SWITCH DE LA LANGUE
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    printf("%c%c%c%c                       SOUSTRACTION                      %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void tmult()///ENTETE POUR LA MULTIPLICATION DES POLYNOMES AVEC LE SWITCH DE LA LANGUE
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    printf("%c%c%c%c                      MULTIPLICATION                     %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void tdiv()///ENTETE POUR LA DIVISION DES POLYNOMES AVEC LE SWITCH DE LA LANGUE
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    printf("%c%c%c%c                   division euclideenne                  %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void tdir(int l)///ENTETE POUR LA DERIVER DES POLYNOMES AVEC LE SWITCH DE LA LANGUE
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    if (l==FR)
        printf("%c%c%c%c                   Deriver un polynome                   %c%c%c%c\n",219,219,219,219,219,219,219,219);
    else
        printf("%c%c%c%c                   Derive a polynomial                   %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void tint()///ENTETE POUR L'integration DES POLYNOMES AVEC LE SWITCH DE LA LANGUE
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    printf("%c%c%c%c                        INTEGRATION                      %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void tcourb(int l)///ENTETE POUR LA COURBE DES POLYNOMES AVEC LE SWITCH DE LA LANGUE
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    if (l==FR)
        printf("%c%c%c%c              Tracer la courbe d'un polynome             %c%c%c%c\n",219,219,219,219,219,219,219,219);
    else
        printf("%c%c%c%c               PLOAT THE CURVE OF POLYNOMIAL             %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void tcrc(int l)///ENTETE POUR CRC AVEC LE SWITCH DE LA LANGUE
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    if(l==FR)
        printf("%c%c%c%c              Proteger des informations (CRC)            %c%c%c%c\n",219,219,219,219,219,219,219,219);
    else
        printf("%c%c%c%c             Protection of informations (CRC)            %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void tcrc2(int l)///ENTETE POUR CRC AVEC LE SWITCH DE LA LANGUE
{
    Color(9,15);
    gotoxy(30,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(30,4);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,5);
    if (l==FR)
        printf("%c%c%c%c      Verifier la veracite d'une information (CRC)       %c%c%c%c\n",219,219,219,219,219,219,219,219);
    else
        printf("%c%c%c%c        Check the veracity of information  (CRC)         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,6);
    printf("%c%c%c%c                                                         %c%c%c%c\n",219,219,219,219,219,219,219,219);
    gotoxy(30,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void cadre1corrr()/// "CADR2" EST UN PROCEDEUR PERMET D'AFFICHER UN CADRE DANS LA CONSOLE
{
    int i;
    for (i=10; i<=40; i++)
    {
        gotoxy(6,i) ;
        textcolor (9);
        printf("%c",219) ;
        gotoxy(116,i);
        textcolor (9);
        printf("%c",219) ;
    }
    textcolor (15);

}

void correc()///correction des erreure d'affichage dans le menu
{
    int i;
    gotoxy(1,10);
    for (i=10; i<40; i++)
    {
        gotoxy(1,i);
        textcolor((15+i)%15);
        printf("%c",186);
        gotoxy(wherex()+119,wherey());
        printf("%c",186);
    }
    textcolor(14);
}

void clrmenu(int start,int end)///effacer le menu pour afficher le de nouveau avec des autre couleurs
{
    int i;
    for(i=start; i<=end; i++)
    {
        gotoxy(1,i);
        clreol();
    }
}

void write(char *chaine,int dela)///printfslow d une autre facon
{
    int i;
    for (i=0; i<=strlen(chaine); i++)
    {
        cprintf("%c",chaine[i]);
        Sleep(dela);
    }
}

void deletech(int start,int end)///clear des ligne
{
    int i;
    for(i=start; i<=end; i++)
    {
        gotoxy(11,i);
        clreol();
        Sleep(50);
    }
}

void cadrintr(int x,int y)///affichage d un cadre pour indroduire les donnees a la position (x,y)
{
    gotoxy(x,y);
    int i;
    for (i=x; i<=x+15; i++)
    {
        gotoxy(i,y) ;
        printf("%c",196) ;
        gotoxy(i,y+2) ;
        printf("%c",196) ;
    }
    gotoxy(x-1,y+1) ;
    printf("%c",179) ;
    gotoxy(x+16,y+1) ;
    printf("%c",179) ;
    gotoxy(x-1,y) ;
    printf("%c",218) ;
    gotoxy(x-1,y+2) ;
    printf("%c",192) ;
    gotoxy(x+16,y) ;
    printf("%c",191) ;
    gotoxy(x+16,y+2) ;
    printf("%c",217) ;
    gotoxy(x+2,y+1) ;
}

void cadrpol(int x,int y)///affichage d un cadre pour afficher les polynomes a la position (x,y)
{
    gotoxy(x,y);
    int i;
    for (i=x; i<=x+95; i++)
    {
        gotoxy(i,y) ;
        printf("%c",196) ;
        gotoxy(i,y+2) ;
        printf("%c",196) ;
    }
    gotoxy(x-1,y+1) ;
    printf("%c",179) ;
    gotoxy(x+96,y+1) ;
    printf("%c",179) ;
    gotoxy(x-1,y) ;
    printf("%c",218) ;
    gotoxy(x-1,y+2) ;
    printf("%c",192) ;
    gotoxy(x+96,y) ;
    printf("%c",191) ;
    gotoxy(x+96,y+2) ;
    printf("%c",217) ;
    gotoxy(x+2,y+1) ;
}

void the_end()///graphique pour la fin
{
    moncadre();
    int x=10;
    gotoxy(x,17);
    printf ("             __            ____             U _____ u _   _     _____   U  ___ u _____                         \n ");
    gotoxy(x,18);
    printf ("         U /" "  \\  u     U |  __"")u    ___    \\|  ___""|/| \\ |"" |   |_ ""  _|   \\/"" _ \\/|_ ""  _|  \n");
    gotoxy(x,19);
    printf ("          \\/ __ \\/       \\|  _ \\/   |_"" _|    |  _|""  <|  \\| |>    | |     | | | |  | |          \n");
    gotoxy(x,20);
    printf ("          / ___  \\        | |_) |    | |     | |___ U| |\\  |u   /| |\\.-,_| |_| | /| |\\     \n");
    gotoxy(x,21);
    printf ("         /_/    \\_\\       |____/   U/| |\\u   |_____| |_| \\_|   u |_|U \\_)-\\___/ u |_|U      \n" );
    gotoxy(x,22);
    printf ("         \\\\      >>      _|| \\\\_.-,_|___|_,-.<<   >> ||   \\\\,-._// \\\\_     \\\\   _// \\\\_     \n");
    gotoxy(x,23);
    printf ("        (__)    (__)    (__) (__)\\_)-' '-(_/(__) (__)(_"")   (_/(__) (__)   (__) (__) (__)       \n");
    Sleep(3000);
}

void thank()///graphique pour la fin
{
    moncadre();
    textcolor(14);
    Sleep(100);
    textcolor(13);
    cputsxy(5,10,"                                                                   @@                                                                        \n");
    Sleep(60);
    cputsxy(5,11,"                                                                 @@@@                                                                        \n");
    Sleep(60);
    cputsxy(5,12," @@@@@@@@@@  @@@@@@        @@@@@@      @@@@@@@@@@    @@@@@@@@    @@@@              IIIIIIIIII        IIIIIIII    IIIIII    IIII    IIIIIIIIII\n");
    Sleep(60);
    cputsxy(5,13,"   @@    @@@@      @@    @@@@    @@      @@    @@  @@@@    @@      @@                II      II    IIII    IIII    IIII      II      II    II\n");
    Sleep(60);
    textcolor(15);
    cputsxy(5,14,"   @@      @@      @@    @@      @@@@    @@        @@              @@                II      II    II        II    IIII      II      II      \n");
    Sleep(60);
    cputsxy(5,15,"   @@      @@      @@    @@@@@@@@@@@@    @@        @@              @@                II      IIII  II        II    IIII      II      II      \n");
    Sleep(60);
    textcolor(9);

    cputsxy(5,16,"   @@      @@      @@    @@              @@        @@              @@                II      II    II        II    IIII      II      II      \n");
    Sleep(60);
    cputsxy(5,17,"   @@      @@      @@    @@@@      @@    @@        @@@@    @@      @@                II      II    IIII    IIII    IIII    IIII      II      \n");
    Sleep(60);
    cputsxy(5,18," @@@@@@  @@@@@@  @@@@@@    @@@@@@@@    @@@@@@        @@@@@@      @@@@@I              IIIIIIII        IIIIIIII        IIIIII  IIII  IIIIII    \n");
    Sleep(60);
    cputsxy(5,19,"                                                                                     II                                                      \n");
    Sleep(60);
    cputsxy(5,20,"                                                                                     II                                                      \n");
    Sleep(60);
    cputsxy(5,21,"                                                                                  IIIIII                                                    \n");
    Sleep(60);

    textcolor(13);
    cputsxy(5,24,"                                                                                               @@                      @@                            \n");
    Sleep(60);
    cputsxy(5,25,"                                   II                                                        @@@@                    @@@@        @@                  \n");
    Sleep(60);
    cputsxy(5,26,"                                   II                                                                                            @@                  \n");
    Sleep(60);
    cputsxy(5,27,"IIIIII    IIII      IIIIIIII    IIIIIIIIII  IIIIIIIIII    IIIIII            @@@@@@    @@@@    @@@@        @@@@@@@@    @@@@    @@@@@@@@@@    @@@@@@    \n");
    Sleep(60);
    textcolor(15);
    cputsxy(5,28," II        II    IIII    IIII    IIII        II    II  IIII    II            @@        @@      @@      @@      @@      @@      @@@@      @@@@    @@  \n");
    Sleep(60);
    cputsxy(5,29,"   II    II      II        II    IIII        II        II      IIII            @@    @@        @@      @@@@            @@      @@@@      @@      @@@@\n");
    Sleep(60);
    cputsxy(5,30,"   II    II      II        II    IIII        II        IIIIIIIIIIII            @@    @@        @@        @@@@@@        @@      @@@@      @@@@@@@@@@@@\n");
    Sleep(60);
    textcolor(9);
    cputsxy(5,31,"   IIIIII        II        II    IIII        II        II                      @@@@@@          @@            @@@@      @@      @@@@      @@          \n");
    Sleep(60);
    cputsxy(5,32,"     IIII        IIII    IIII    IIII        II        IIII      II              @@@@          @@      @@      @@      @@      @@@@      @@@@      @@\n");
    Sleep(60);
    cputsxy(5,33,"     II            IIIIIIII        IIIIII  IIIIII        IIIIIIII                @@          @@@@@@    @@@@@@@@      @@@@@@      @@@@@@    @@@@@@@@  \n");
    Sleep(60);
    textcolor(15);
    _getch();
}

int confirmation(char *msgfr,char *msgen,int *l)  ///graphique pour la fin
{
    int x,y,c;
    x=wherex();
    y=wherey();
    textbackground(1);
    textcolor(7);
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    gotoxy(x,y+1);
    printf("%c                                                          %c",186,186);
    gotoxy(x,y+2);
    printf("%c                                                          %c",186,186);
    gotoxy(x,y+3);
    printf("%c                                                          %c",186,186);
    gotoxy(x,y+4);
    printf("%c                                                          %c",186,186);
    gotoxy(x,y+5);
    printf("%c                                                          %c",186,186);
    gotoxy(x,y+6);
    printf("%c                                                          %c",186,186);
    gotoxy(x,y+7);
    printf("%c                                                          %c",186,186);
    gotoxy(x,y+8);
    printf("%c                                                          %c",186,186);
    gotoxy(x,y+9);
    printf("%c                                                          %c",186,186);
    gotoxy(x,y+10);
    printf("%c                                                          %c",186,186);
    gotoxy(x,y+11);
    printf("%c                                                          %c",186,186);
    gotoxy(x,y+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

    textcolor(7);
    gotoxy(x+2,y+11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,217);
    gotoxy(x+2,y+9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,191);
    gotoxy(x+2,y+10);
    printf("%c            %c",179,179);
    gotoxy(x+44,y+11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,217);
    gotoxy(x+44,y+9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,191);
    gotoxy(x+44,y+10);
    printf("%c            %c",179,179);

    gotoxy(x+2,y);
    printf("[Confirmation]");


    textbackground(4);
    textcolor(15);
    gotoxy(x+59,y);
    printf("X");

    textbackground(1);
    textcolor(15);
    do
    {
        if(*l==FR)
        {
            gotoxy(x+2,y+3);
            printf("%-57s",msgfr);
            gotoxy(x+2,y+6);
            printf("         Etes vous s%cr de vouloir continuer ?",150);
            gotoxy(x+3,y+10);
            printf(" Non (ESC)");
            gotoxy(x+45,y+10);
            printf("Oui (Entrer)");


        }
        else
        {
            gotoxy(x+2,y+3);
            printf("%-57s",msgen);
            gotoxy(x+2,y+6);
            printf("           Do you wish to continue ?            ",150);
            gotoxy(x+3,y+10);
            printf("  No (ESC)");
            gotoxy(x+45,y+10);
            printf(" Yes (Enter)");
        }
        gotoxy(110,40);
        c=_getkey();
        if (c==CTRL_L)
            *l=(*l+1)%2;

    }
    while((c!=ESC)&&(c!=ENTRER));
    textcolor(15);
    textbackground(0);

    gotoxy(x,y);
    clreol();
    gotoxy(x,y+1);
    clreol();
    gotoxy(x,y+2);
    clreol();
    gotoxy(x,y+3);
    clreol();
    gotoxy(x,y+4);
    clreol();
    gotoxy(x,y+5);
    clreol();
    gotoxy(x,y+6);
    clreol();
    gotoxy(x,y+7);
    clreol();
    gotoxy(x,y+8);
    clreol();
    gotoxy(x,y+9);
    clreol();
    gotoxy(x,y+10);
    clreol();
    gotoxy(x,y+11);
    clreol();
    gotoxy(x,y+12);
    clreol();
    gotoxy(x,y+1);


    return c;//retourne esc ou entrer

}

void quitter(int *l,int *quit)/// confirmation pour quitter le programme
{
    int c;
    moncadre();
    gotoxy(25,11);
    c=confirmation("Vous vous appretez a quittter le programme !","You are going to leave the program !",l);
    if (c==ENTRER)
    {
        *quit=1;
        moncadre();
        cadre1();
        gotoxy(20,20);
        printf("Merci pour nous avoir fait confiance et de nous laisser effectuer les calculs a votre place,\n");
        gotoxy(20,21);
        printf("Ravi de vous avoir servi, on espere que vous etes satisfaits de la qualite du travail !\n");
        Sleep(2000);
    }
}

void contacter ()///graphique de sortie
{
    moncadre();
    int x=20,y=15;
    cadre1();
    Color(12,8);
    gotoxy(x,y-1);
    printf("                    ********************\n");
    gotoxy(x+20,y);
    printf("*      POUR NOUS   *");
    gotoxy(x+20,y+1);
    printf("*      CONTACTER:  * \n");
    gotoxy(x,y+2);
    printf("                    ********************\n");
    gotoxy(x,y+3);
    Color(10,8);
    printf("\t+------------------------------------------------+\n");
    gotoxy(x,y+4);
    Color(0,8);
    printf(" \t|Mr. BOUANANE MOHAMED EL AMINE                   |\n");
    gotoxy(x,y+5);
    printf(" \t|Mr. LAISSAOUI AKRAM BADREDDINE                  |\n");
    gotoxy(x,y+6);
    Color(10,8);
    printf(" \t+------------------------------------------------+\n");
    Color(0,8);
    gotoxy(x,y+7);
    printf(" \t|Telephone: 0561-78-70-05<>0668-08-87-98         |\n");
    Color(10,8);
    gotoxy(x,y+8);
    printf(" \t+------------------------------------------------+\n");
    Color(0,8);
    gotoxy(x,y+9);
    printf(" \t|Facebook: NEBU RAM                              |\n");
    Color(10,8);
    gotoxy(x,y+10);
    printf(" \t+------------------------------------------------+\n");
    Color(0,8);
    gotoxy(x,y+11);
    printf(" \t|Facebook: MOHAMED BOUANANE                      |\n");
    Color(10,8);
    gotoxy(x,y+12);
    printf(" \t+------------------------------------------------+\n");
    Color(0,8);
    gotoxy(x,y+13);
    printf(" \t|Adresse de l'ecole: OUED SMAR,Alger,Algerie.    |\n");
    Color(10,8);
    gotoxy(x,y+14);
    printf(" \t+------------------------------------------------+\n");
    Color(0,8);
    gotoxy(x,y+15);
    printf(" \t|Site web de l'ecole: www.esi.dz                 |\n");
    Color(10,8);
    gotoxy(x,y+16);
    printf(" \t+------------------------------------------------+\n\n");
}
#endif
