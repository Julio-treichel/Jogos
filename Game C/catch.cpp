#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.c>
#include <time.h>
#include <ctype.h>
#include <locale.h>

int co = 35, li = 23, lintir = 10, coltir = 40, pts = 0, record = 0, tempo = 120;
char key, back;

//-----------------Função para jogar novamente----------------------
char playagain(){
  char tecla;     
    textbackground(0);
   do {
      gotoxy(55,24); printf("Jogar novamente? (S/N)");
      tecla=getch();
      tecla=toupper(tecla);
   } while (tecla != 'S' && tecla != 'N'); 
   system("cls");
   return tecla;   
}
//-------------Procedimento de fim de jogo---------------------------
void gameover() {
  textcolor(0);
  textbackground(7);
  gotoxy(30,12); printf(" G A M E   O V E R ");   
  Beep(690,100);
  Sleep(500);   
}
//--------------Procedimento de calculo da pontuação------------------
void pontuacao() {
   pts++;
   if (pts < 0) {
      pts = 0;
   }
   textcolor(15);
   textbackground(0);
   gotoxy(68,1); printf("Pontos: %4d",pts); 
   gotoxy(68,2);
   if (record > 0){
      printf("Record: %4d", record); 
   }
  textbackground(0);     
}
//------------------------------------------------------------------
int out(){
   if ((lintir >= 23 && coltir < co) || (coltir > co + 15 && lintir >= 23)) {
   textcolor(0);
      return 1;
   } else {
      return 0;    
   }
}
//---------------Procedimento para sortear a bolinha----------------
void sorteiaTiro() {
   lintir = 1;
   coltir = rand()%75 + 3; 
}
//------------------------------------------------------------------
void in() {
   gotoxy(coltir,lintir);
   textcolor(10);
   printf("O");
   lintir++;
   if (lintir >= 23) {
      textcolor(0);
   }
   if (lintir < 1 || lintir > 23 || coltir > 78 || coltir < 1) {
      sorteiaTiro();
      textcolor(0);
   }  
}
//------------Procedimento de explosao da bolinha------------------
void explosao(int col, int lin) {
  
  textcolor (15); gotoxy(col, (lin - 1)); printf("  *   "); 
  textcolor (15); gotoxy(col, lin      ); printf("*   * "); Sleep(300);
  
  gotoxy(col, (lin - 1)); printf("     "); 
  gotoxy(col, lin      ); printf("     ");
  tempo = 120;
}
//--------------------Procedimento da barrinha do jogo----------------------
void barrinha(int col, int lin) {
  textcolor(15);
  textbackground(0);
  clrscr();
  gotoxy(col, lin);printf("===============");    
}  
//-----------------Procedimento para início do jogo------------------------
void jogar(){
   int x = 0, tecla = 0, dificuldade = 0, i = 0;

   srand(time(NULL));
   barrinha(1,1);

   system("cls");

   do {
      if (lintir >= 23) {
         textcolor(0);
      }

      dificuldade++;
      Sleep(tempo);
      if (dificuldade == 10) {
         tempo--;
         dificuldade = 0;
      }

      barrinha(co,li);  
      in();
      pontuacao();

      if (out() == 1) {
         explosao(coltir, lintir);
         gameover();
         textcolor(15);
         if (playagain() == 'N')
            tecla = 27;
         else {
            if (pts > record) 
               record = pts;
            pts = 0; 
            if (lintir == li && coltir <= (co + 15)) {
            sorteiaTiro();
            }
         }   
      }   
      if (kbhit()) { 
         tecla = getch();  
         tecla=toupper(tecla);
         switch (tecla){
            case 65: //esquerda tecla: A
            if ((co - 1) >= 4)
               co = co - 4; 
            break;

            case 68: // direita tecla D
               if ((co + 1) <= 63) 
               co = co + 4;   
            break;
         }
      }  
   } while (tecla != 27);
}
//--------------------Procedimento das Instruções--------------------
void instructions(){
   textcolor(10);
   textbackground(0);
   system("cls");
   gotoxy(50, 7);printf("Instruções:");
   gotoxy(38, 9);printf("O objetivo do jogo é capturar o maximo de");
   gotoxy(38, 10);printf("bolinhas possível, movendo a barrinha para");
   gotoxy(38, 11);printf("a esquerda, ou para a direita.");
   gotoxy(50, 13);printf(" A = ESQUERDA");
   gotoxy(50, 14);printf(" D = DIREITA");
   gotoxy(32, 16);printf("Pressione qualquer tecla para retornar ao Menu Principal");
   back = getch();
   textcolor(15);
   textbackground(0);
   system("cls");
}
//---------Procedimento para apresentação dos Créditos---------------
void creditos(){
   textcolor(10);
   textbackground(0);
   system("cls");
   gotoxy(33, 5); printf("Jogo desenvolvido pelo aluno: Julio Treichel");
   gotoxy(25, 6); printf("Primeiro ano de Análise e Desenvolvimento de Sistemas 03/12/2020");
   gotoxy(30, 8); printf("Pressione qualquer tecla para retornar ao Menu Principal");
   back = getch();
   textcolor(15);
   textbackground(0);
   system("cls");
}
//----------Procedimento para apresentação do Score-----------------
void score() {
   textcolor(10);
   textbackground(0);
   system("cls");
   gotoxy(33, 5); printf("A parte de Score do jogo está em desenvolvimento.");
   gotoxy(30, 8); printf("Pressione qualquer tecla para retornar ao Menu Principal");
   back = getch();
   textcolor(15);
   textbackground(0);
   system("cls");
}

//--------------------Procedimento do Menu Principal-----------------
void menu() {
   int op = 1;

   do {
      textcolor(10);
      textbackground(0);

      gotoxy(43, 2); printf("╔═══╗ ╔═══╗ ╔════╗ ╔═══╗ ╔╗ ╔╗");
      gotoxy(43, 3); printf("║╔═╗║ ║╔═╗║ ║╔╗╔╗║ ║╔═╗║ ║║ ║║");
      gotoxy(43, 4); printf("║║ ╚╝ ║║ ║║ ╚╝║║╚╝ ║║ ╚╝ ║╚═╝║");
      gotoxy(43, 5); printf("║║ ╔╗ ║╚═╝║   ║║   ║║ ╔╗ ║╔═╗║");
      gotoxy(43, 6); printf("║╚═╝║ ║╔═╗║   ║║   ║╚═╝║ ║║ ║║");
      gotoxy(43, 7); printf("╚═══╝ ╚╝ ╚╝   ╚╝   ╚═══╝ ╚╝ ╚╝"); 

      textcolor(0);
      textbackground(8);
      
      gotoxy(51, 10); printf(" Jogar       ");
      gotoxy(51, 11); printf(" Instruções  ");
      gotoxy(51, 12); printf(" Score       ");
      gotoxy(51, 13); printf(" Créditos    ");
      gotoxy(51, 14); printf(" Sair        ");

      textcolor(0);
      textbackground(15);
      
      switch (op) {
      case 1:
         gotoxy(51, 10); printf(" Jogar       ");
      break;

      case 2:
         gotoxy(51, 11); printf(" Instruções  ");
      break;

      case 3:
         gotoxy(51, 12); printf(" Score       ");
      break;

      case 4:
         gotoxy(51, 13); printf(" Créditos    ");
      break;

      case 5:
         gotoxy(51, 14); printf(" Sair        ");
      break;
      }

      key = getch();
      key = toupper(key);
      switch (key) {
         case 87: //Movimentação para baixo tecla: W
            if ((op - 1) >= 1) {
               op --;
            } else {
               op = 5;
            }
            break;
         case 83: //Movimentação para cima tecla: S
            if ((op + 1) <= 5) {
               op ++;
            } else {
               op = 1;
            }
            break;
         //---------------Selecionar opção (Enter)
         case 13: 
            switch (op) {
            case 1:
            //------------
            jogar();
               break;
            case 2:
            instructions();
               break;
            case 3:
            //------------Chamada do procedimento Score
            score();
               break;
            case 4:
            creditos();
               break;
            case 5: 
            //---------------------Sair do jogo
               key = 27;
               break;
            default:
               break;
            }
         break;
      }
   } while (key != 27);
}

//-----------------------------------------------------------------------------     
int main() {
   SetConsoleOutputCP(CP_UTF8);
   // setlocale(LC_ALL,"portuguese");

   CONSOLE_CURSOR_INFO cursor = {1, FALSE};
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

   menu();
   
  return 0;
}