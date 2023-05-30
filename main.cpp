#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<windows.h>

void setconsolecolor(int textColor, int bgColor)
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor +
(bgColor * 16)));
}

main(void)
{
  // Declaração das variaveis

  int game = 1;
  int mapa[16][16] {0};
  int playerspos[2] = {1,1};
  int enemy3spos[2] = {8,1};
  mapa[1][1] = 1;
  mapa[8][1] = 3;
  int movement[2] = {0,0};
  int enemy3mov[2] = {0,0};
  int moment [2];
  int enemy3moment[2];



  //map flavoring
  for(int i = 0; i < 16; i++){
    mapa[15][i] = 2;
    mapa[i][15] = 2;
    mapa[0][i] = 2;
    mapa[i][0] = 2;
  }

  // Ciclo de repetição do jogo
  while(game){




  //enemy perception
  for(int i = 0;i<16;i++){
    for(int j = 0;j<16;j++){
      if(mapa[i][j] == 3){
        for(int i2 = 0;i2<3;i2++){
          for(int j2 = 0;j2<3;j2++){
            if(mapa[i-1+i2][j-1+j2] == 1){
                enemy3mov[0] = 0;
                enemy3mov[1] = 0;
              if(i2 == 0){
                enemy3mov[0] = -1;
              }else if(i2 == 1){
                if(j2 == 0){
                enemy3mov[1] = -1;
              }else if(j2 == 2){
                enemy3mov[1] = 1;
              }
              }else{
              enemy3mov[0] = 1;
              }
            }else{
            if(mapa[i][j - 1] == 2){
              enemy3mov[1] = 1;
              enemy3mov[0] = 0;
            }else if(mapa[i][j + 1] == 2){
              enemy3mov[1] = -1;
              enemy3mov[0] =  0;
            }else if(mapa[i -1][j] == 2){
              enemy3mov[0] = 1;
              enemy3mov[1] = 0;
            }else if(mapa[i + 1][j] == 2){
              enemy3mov[0] = -1;
              enemy3mov[1] = 0;
            }



            }

          }
        }
      }
    }
  }




   //Recepção de inputs
   {


  movement[0] = 0;
  movement[1] = 0;
  switch(getch()){
      case 65:
      case 97:
        //Key a
        movement[0] = 0;
        movement[1] = 1;
        break;
      case 68:
      case 100:
        //Key d
        movement[0] = 0;
        movement[1] = -1;
        break;
      case 83:
      case 115:
        //Key s
        movement[0] = 1;
        movement[1] = 0;
        break;
      case 87:
      case 119:
        //Key w
        movement[0] = -1;
        movement[1] = 0;
        break;
      case 27:
        game = 0;
        break;
  }

   }
setconsolecolor(0,0);
system("cls");

  //moving the player
  moment [0] = playerspos [0] + movement[0];
  moment [1] = playerspos [1] + movement[1];
  if(mapa[moment[0]] [moment[1]] == 0 && moment[0] != -1 && moment[1] != -1 && moment[0] != 16 && moment[1] != 16)
  {
     mapa[moment[0]] [moment[1]]= 1;
     mapa[playerspos[0]] [playerspos[1]] = 0;
     playerspos[0] = moment[0];
     playerspos[1] = moment[1];

  }



  //moving the enemy



  enemy3moment[0] = enemy3spos[0] + enemy3mov[0];
  enemy3moment[1] = enemy3spos[1] + enemy3mov[1];
  mapa[enemy3spos[0]][enemy3spos[1]] = 0;
  mapa[enemy3moment[0]][enemy3moment[1]] = 3;
  enemy3spos[0] = enemy3moment[0];
  enemy3spos[1] = enemy3moment[1];




  game = 0;


  //Map rendering
  for(int i = 0;i <=15;i++)
    {
      setconsolecolor(0,0);
      printf("\n");

      for(int j = 15;j >=0;j--)
      {
        if(mapa[i][j] == 2)
        {
          setconsolecolor(0,8);
          printf("  ");
        }
        else if(mapa[i][j] == 1)
        {
          game = 1;
          setconsolecolor(0,10);
          printf("  ");
        }
        else if(mapa[i][j] == 3)
        {
          setconsolecolor(0,4);
          printf("  ");
        }else{
        if((i+j)%2==0){
        setconsolecolor(0,15);
        }else{
          setconsolecolor(0,7);
        }
        printf("  ");
        }
        }

      }
      if(game == 0){
          setconsolecolor(0,4);
          printf("\nGAME OVER!");
          setconsolecolor(0,0);
    }
  }
}
