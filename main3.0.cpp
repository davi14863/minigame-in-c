#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

//background color function
void setconsolecolor(int textColor, int bgColor)
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor +
(bgColor * 16)));
}
//world building function
void worldflavoring(int *ipworld, int worldwide, int worldhigh)
{

for(int y = 0; y < worldhigh; y++){
  for(int x = 0; x < worldwide; x++){
    * ipworld = 0;
    if(x == 7 && y == 7)
      * ipworld = 1;

    if(x == 9 && y == 9)
      * ipworld = 20;
    if(x == 4 && y == 15)
      * ipworld = 20;
    if(x == 25 && y == 27)
      * ipworld = 20;
    if(x == 2 && y == 2)
      * ipworld = 3;
    if(x == 24 && y == 12)
      * ipworld = 30;
    if(x == 14 && y == 8)
      * ipworld = 36;
    if(x == 18 && y == 28)
      * ipworld = 38;
    if(x == 15 && y == 15)
      * ipworld = 40;
    if(x == 18 && y == 15)
      * ipworld = 47;




    if(x == 0 || x == worldwide -1 || y == 0 || y == worldhigh -1 )
      * ipworld = 2;
ipworld++;
  }
}

}
//world rendering function
void worldrendering(int *ipworld, int worldwide, int worldhigh)
{

  int random;
  int worldvar[worldwide][worldhigh] = {0};
  int playerposx = 0;
  int playerposy = 0;
  srand(14863);
  int r;

  //world copy

  for(int y = 0 ; y < worldhigh ; y++){
    for(int x = 0 ; x < worldwide ; x++){
      worldvar[x][y] = *ipworld;
      ipworld++;
    }
  }

  //locating player

  for(int y = 0; y < worldhigh ; y++){
    for(int x = 0 ; x < worldwide ; x++){
      if(worldvar[x][y] == 1){

          playerposx = x;
          playerposy = y;

        if(x < 7) playerposx = 7;
        if(y < 7) playerposy = 7;
        if(x >= worldwide - 7) playerposx = worldwide - 8;
        if(y >= worldhigh - 7) playerposy = worldhigh - 8;

        setconsolecolor(0,0);

printf("\n  ");
  for(int y2 = playerposy - 7 ; y2 <= playerposy + 7 ; y2++){
    for(int x2 = playerposx - 7 ; x2 <= playerposx + 7 ; x2++){

      if(worldvar[x2][y2] == 0){
          if((r = rand()) % 10){
            setconsolecolor(15,10);
        printf("  ");

          }else{
          setconsolecolor(2,10);
        printf(" M");
          }



      }else if(worldvar[x2][y2] == 1){
        setconsolecolor(0,1);
        printf(":D");
      }else if(worldvar[x2][y2] == 2){
        setconsolecolor(0,8);
        printf("[]");
      }else if(worldvar[x2][y2] == 3){
        setconsolecolor(0,4);
        printf(":(");
      }else if(worldvar[x2][y2] == 4){
        setconsolecolor(15,6);
        printf("[]");
      }else if(worldvar[x2][y2] == 5){
        setconsolecolor(15,5);
        printf("55");
      }else if(worldvar[x2][y2] == 21){
        setconsolecolor(0,10);
        printf(" ");
        setconsolecolor(0,6);
        printf("]");
      }else if(worldvar[x2][y2] == 22){
        setconsolecolor(0,6);
        printf("[");
        setconsolecolor(0,10);
        printf(" ");
      }else if(worldvar[x2][y2] == 23){
        setconsolecolor(0,2);
        printf("/V");
      }else if(worldvar[x2][y2] == 24){
        setconsolecolor(0,2);
        printf("V\\");
      }else if(worldvar[x2][y2] == 25){
        setconsolecolor(0,10);
        printf(" ");
        setconsolecolor(0,2);
        printf("/");
      }else if(worldvar[x2][y2] == 26){
        setconsolecolor(0,2);
        printf("\\");
        setconsolecolor(0,10);
        printf(" ");
      }else if(worldvar[x2][y2] == 31){
        setconsolecolor(0,8);
        printf("/_");
      }else if(worldvar[x2][y2] == 32){
        setconsolecolor(0,8);
        printf("_\\");
      }else if(worldvar[x2][y2] == 33){
        setconsolecolor(0,10);
        printf(" _");
      }else if(worldvar[x2][y2] == 34){
        setconsolecolor(0,8);
        printf("/F");
      }else if(worldvar[x2][y2] == 35){
        setconsolecolor(0,8);
        printf("\\");
        setconsolecolor(0,10);
        printf(" ");
      }else if(worldvar[x2][y2] == 37){
        setconsolecolor(0,8);
        printf("/G");
      }else if(worldvar[x2][y2] == 39){
        setconsolecolor(0,8);
        printf("/S");
      }else if(worldvar[x2][y2] == 41){
        setconsolecolor(0,8);
        printf("/");
        setconsolecolor(4,8);
        printf("[");
      }else if(worldvar[x2][y2] == 42){
        setconsolecolor(4,8);
        printf("]");
        setconsolecolor(0,8);
        printf("\\");
      }else if(worldvar[x2][y2] == 43){
        setconsolecolor(0,10);
        printf(" ");
        setconsolecolor(0,8);
        printf("|");
      }else if(worldvar[x2][y2] == 44){
        setconsolecolor(0,8);
        printf("|");
        setconsolecolor(0,10);
        printf(" ");
      }else if(worldvar[x2][y2] == 45){
        setconsolecolor(0,10);
        printf(" ");
        setconsolecolor(4,10);
        printf("S");
      }else if(worldvar[x2][y2] == 46){
        setconsolecolor(4,10);
        printf("S");
        setconsolecolor(0,10);
        printf(" ");
      }else if(worldvar[x2][y2] == 48){
        setconsolecolor(0,6);
        printf("[");
        setconsolecolor(4,6);
        printf("#");
      }else if(worldvar[x2][y2] == 49){
        setconsolecolor(8,6);
        printf("T");
        setconsolecolor(0,6);
        printf("]");
      }else{
        setconsolecolor(15,4);
        printf("XX");
      }
    }
    setconsolecolor(15,0);
    printf("\n  ");
  }

      }
    }
  }
printf("\n");



}
//player input function
void inputs(int *movement, int *action)
{
  *movement = 0;
  *movement++;
  *movement = 0;
  *movement--;
  *action = 0;
  *action++;
  *action = 0;
  *action--;


switch(getch()){

  //inputs for movements
      case 97:
        //Key a
        *movement = -1;
        *movement++;
        *movement = 0;
        *movement--;
        break;

      case 100:
        //Key d
        *movement = 1;
        *movement++;
        *movement = 0;
        *movement--;
        break;

      case 115:
        //Key s
        *movement = 0;
        *movement++;
        *movement = 1;
        *movement--;
        break;

      case 119:
        //Key w
        *movement = 0;
        *movement++;
        *movement = -1;
        *movement--;
        break;

  //inputs for actions
      case 65:
        //Key A
        *action = -1;
        *action++;
        *action = 0;
        *action--;
        break;

      case 68:
        //Key D
        *action = 1;
        *action++;
        *action = 0;
        *action--;
        break;

      case 83:
        //Key S
        *action = 0;
        *action++;
        *action = 1;
        *action--;
        break;

      case 87:
        //Key W
        *action = 0;
        *action++;
        *action = -1;
        *action--;
        break;


  }
}
//player movement function
void moveplayer(int *ipworld, int worldwide, int worldhigh, int *movementx)
{

  int worldvar[worldwide][worldhigh] = {0};
  movementx++;
  int *movementy = movementx;
  movementx--;

  //world copy

  for(int y = 0 ; y < worldhigh ; y++){
    for(int x = 0 ; x < worldwide ; x++){
      worldvar[x][y] = *ipworld;
      ipworld++;
    }
  }
  //world copy movement

  for(int y = 0 ; y < worldhigh ; y++){
    for(int x = 0 ; x < worldwide; x++){
      if(worldvar[x][y] == 1 && worldvar[x + *movementx][y + *movementy] == 0 && x + *movementx != -1 && y + *movementy != -1 && x + *movementx != worldwide && y + *movementy !=worldhigh){
        worldvar[x][y] = 0;
        worldvar[x + *movementx][y + *movementy] = 11;
      }
    }
  }

  //IP unread

  for(int y = 0 ; y < worldhigh ; y++){
    for(int x = 0 ; x < worldwide ; x++){
      ipworld--;
    }
  }
  //IP update based in world copy

  for(int y = 0 ; y < worldhigh; y++){
    for(int x = 0 ; x < worldwide ; x++){
      *ipworld = worldvar[x][y];
      if(worldvar[x][y] == 11){
        *ipworld = 1;
      }

      ipworld++;
    }
  }
}
//player actions function
void actionplayer(int *ipworld, int worldwide, int worldhigh, int *actionx)
{

  int worldvar[worldwide][worldhigh] = {0};
  actionx++;
  int *actiony = actionx;
  actionx--;

  //world copy

  for(int y = 0 ; y < worldhigh ; y++){
    for(int x = 0 ; x < worldwide ; x++){
      worldvar[x][y] = *ipworld;
      ipworld++;
    }
  }
  //world copy movement

  for(int y = 0 ; y < worldhigh ; y++){
    for(int x = 0 ; x < worldwide; x++){
      if(worldvar[x][y] == 1){
        if(worldvar[x + *actionx][y + *actiony] == 0 && x + *actionx != -1 && y + *actiony != -1 && x + *actionx != worldwide && y + *actiony !=worldhigh){
        worldvar[x + *actionx][y + *actiony] = 4;
        }else if(worldvar[x + *actionx][y + *actiony] == 4){
          worldvar[x + *actionx][y + *actiony] = 0;
        }
      }
    }
  }







  //IP unread

  for(int y = 0 ; y < worldhigh ; y++){
    for(int x = 0 ; x < worldwide ; x++){
      ipworld--;
    }
  }
  //IP update based in world copy

  for(int y = 0 ; y < worldhigh; y++){
    for(int x = 0 ; x < worldwide ; x++){
      *ipworld = worldvar[x][y];
      if(worldvar[x][y] == 11){
        *ipworld = 1;
      }

      ipworld++;
    }
  }
}
//enemy movement function
void enemyai(int *ipworld, int worldwide, int worldhigh)
{
  //variables

  int worldvar[worldwide][worldhigh] = {0};
  int movementx = 0;
  int movementy = 0;
  int playerlocationx  = 0;
  int playerlocationy  = 0;
  int distancex = 0;
  int distancey = 0;

  int block = 0;
  int block2 = 0;



  //world copy

  for(int y = 0 ; y < worldhigh ; y++){
    for(int x = 0 ; x <worldwide ; x++){
      worldvar[x][y] = *ipworld;
      ipworld++;
    }
  }

    //IP unread

  for(int y = 0 ; y < worldhigh ; y++){
    for(int x = 0 ; x < worldwide ; x++){
      ipworld--;
    }
  }

  //locating player

  for(int y = 0; y < worldhigh ; y++){
    for(int x = 0 ; x < worldwide ; x++){
      if(worldvar[x][y] == 1){

        playerlocationx = x;
        playerlocationy = y;
      }
    }
  }

  //locating enemy and moving it

  for(int y = 0 ; y < worldhigh ; y++){
    for(int x = 0 ; x < worldwide ; x++){
      if(worldvar[x][y] == 3){

        distancex = x - playerlocationx;
        distancey = y - playerlocationy;

        //modulo da distancia

        if(distancex < 0) distancex = -distancex;
        if(distancey < 0) distancey = -distancey;

        if(distancex > distancey){

          if(x - playerlocationx > 0){
            movementx = -1;
            movementy = 0;
          }else{
            movementx = 1;
            movementy = 0;
          }

          if(worldvar[x + movementx][y + movementy] == 0 || worldvar[x + movementx][y + movementy] == 1 && x + movementx != -1 && x + movementx != worldwide && y + movementy != -1 && y + movementy != worldhigh){
            worldvar[x][y] = 0;
            worldvar[x + movementx][y + movementy] = 13;
          }else{
          block = 1;
          }

        }
        if(distancey >= distancex || block){

          if(y - playerlocationy > 0){
            movementx = 0;
            movementy = -1;
          }else{
            movementx = 0;
            movementy = 1;
          }

          if(worldvar[x + movementx][y + movementy] == 0 || worldvar[x + movementx][y + movementy] == 1 && x + movementx != -1 && x + movementx != worldwide && y + movementy != -1 && y + movementy != worldhigh){
            worldvar[x][y] = 0;
            worldvar[x + movementx][y + movementy] = 13;
          }else{
          block2 = 1;
          }

        }
        if(block2){


          if(x - playerlocationx > 0){
            movementx = -1;
            movementy = 0;
          }else{
            movementx = 1;
            movementy = 0;
          }

          if(worldvar[x + movementx][y + movementy] == 0 || worldvar[x + movementx][y + movementy] == 1 && x + movementx != -1 && x + movementx != worldwide && y + movementy != -1 && y + movementy != worldhigh){
            worldvar[x][y] = 0;
            worldvar[x + movementx][y + movementy] = 13;
          }

        }
        movementx = 0;
        movementy = 0;
        block = 0;
        block2 = 0;

      }
    }
  }


  //IP update based in world copy

  for(int y = 0 ; y < worldhigh ; y++){

    for(int x = 0 ; x < worldwide ; x++){
      *ipworld = worldvar[x][y];
      if(worldvar[x][y] == 13){
        *ipworld = 3;
      }
      ipworld++;
    }
  }
}
//event detector
void eventcheck(int *ipworld, int worldwide, int worldhigh, int *game)
{

  int worldvar[worldwide][worldhigh] = {0};
  int playerlocationx  = 0;
  int playerlocationy  = 0;
  *game = 0;

  //world copy

  for(int y = 0 ; y < worldhigh ; y++){
    for(int x = 0 ; x < worldwide ; x++){
      worldvar[x][y] = *ipworld;
      ipworld++;
    }
  }

  //locating player

  for(int y = 0; y < worldhigh ; y++){
    for(int x = 0 ; x < worldwide ; x++){
      if(worldvar[x][y] == 1){
        playerlocationx = x;
        playerlocationy = y;
        *game = 1;
      }
    }
  }
  if(worldvar[playerlocationx][playerlocationy - 1] == 41 || worldvar[playerlocationx][playerlocationy - 1] == 42){

    printf("Você está na frente de uma fornalha\n");
    printf("+---------------------------------+\n");
    printf("|Oque vc gostarias de fazer?      |\n");
    printf("|1) assar um ferro                |\n");
    printf("|2) assar um ouro                 |\n");
    printf("|3) fazer um carvão               |\n");
    printf("+---------------------------------+\n");
  }else if(worldvar[playerlocationx][playerlocationy - 1] == 48 || worldvar[playerlocationx][playerlocationy - 1] == 49){

    printf("Você está na frente de uma mesa de trabanho\n");
    printf("+---------------------------------+\n");
    printf("|Oque vc gostarias de fazer?      |\n");
    printf("|1) uma caixa                     |\n");
    printf("|2) um fornalha                   |\n");
    printf("|3) uma comida de sementes        |\n");
    printf("+---------------------------------+\n");
  }



if(*game == 0){
  setconsolecolor(15,0);
        printf("The player is no more...\nI think you should restart...\n-----------GAME OVER-----------");
}




}
//multiblock render
void multiblockrender(int *ipworld, int worldwide, int worldhigh)
{
  int worldvar[worldwide][worldhigh] = {0};


  //world copy

  for(int y = 0 ; y < worldhigh ; y++){
    for(int x = 0 ; x <worldwide ; x++){
      worldvar[x][y] = *ipworld;
      ipworld++;
    }
  }

    //IP unread

  for(int y = 0 ; y < worldhigh ; y++){
    for(int x = 0 ; x < worldwide ; x++){
      ipworld--;
    }
  }

  for(int y = 0 ; y < worldhigh ; y++){
    for(int x = 0 ; x <worldwide ; x++){


      if(worldvar[x][y] == 20){
        worldvar[x][y] = 21;
        worldvar[x + 1][y] = 22;
        worldvar[x][y - 1] = 23;
        worldvar[x + 1][y - 1] = 24;
        worldvar[x][y - 2] = 23;
        worldvar[x + 1][y - 2] = 24;
        worldvar[x][y - 3] = 25;
        worldvar[x + 1][y - 3] = 26;
      }else if(worldvar[x][y] == 30){
        worldvar[x][y] = 31;
        worldvar[x + 1][y] = 31;
        worldvar[x + 2][y] = 32;
        worldvar[x][y - 1] = 33;
        worldvar[x + 1][y - 1] = 34;
        worldvar[x + 2][y - 1] = 35;
      }else if(worldvar[x][y] == 36){
        worldvar[x][y] = 31;
        worldvar[x + 1][y] = 31;
        worldvar[x + 2][y] = 32;
        worldvar[x][y - 1] = 33;
        worldvar[x + 1][y - 1] = 37;
        worldvar[x + 2][y - 1] = 35;
      }else if(worldvar[x][y] == 38){
        worldvar[x][y] = 31;
        worldvar[x + 1][y] = 31;
        worldvar[x + 2][y] = 32;
        worldvar[x][y - 1] = 33;
        worldvar[x + 1][y - 1] = 39;
        worldvar[x + 2][y - 1] = 35;
      }else if(worldvar[x][y] == 40){
        worldvar[x][y] = 41;
        worldvar[x + 1][y] = 42;
        worldvar[x][y - 1] = 43;
        worldvar[x +1][y - 1] = 44;
        worldvar[x][y - 2] = 45;
        worldvar[x + 1][y - 2] = 46;
      }else if(worldvar[x][y] == 47){
        worldvar[x][y] = 48;
        worldvar[x + 1][y] = 49;
      }


    }
  }

  //IP update based in world copy

  for(int y = 0 ; y < worldhigh ; y++){

    for(int x = 0 ; x < worldwide ; x++){
      *ipworld = worldvar[x][y];
      if(worldvar[x][y] == 13){
        *ipworld = 3;
      }
      ipworld++;
    }
  }




}
//main function
int main()
{
//variables
int worldwide = 32;
int worldhigh = 32;
int world[worldwide][worldhigh];

int other;

int movement[2] = {0};
int action  [2] = {0};

int game = 1;

//world Building

worldflavoring(&world[0][0], worldwide, worldhigh);
multiblockrender(&world[0][0], worldwide, worldhigh);
worldrendering(&world[0][0], worldwide, worldhigh);

//game loop

while(game){

//event order


if(other){
  enemyai(&world[0][0], worldwide, worldhigh);
  other = 0;
}else{
other = 1;
}
  inputs(&movement[0], &action[0]);
  moveplayer(&world[0][0], worldwide, worldhigh, &movement[0]);
  actionplayer(&world[0][0], worldwide, worldhigh, &action[0]);
  system("cls");
  worldrendering(&world[0][0], worldwide, worldhigh);
  eventcheck(&world[0][0], worldwide, worldhigh, &game);
}
return 0;
}
