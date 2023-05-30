#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<windows.h>

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
    if((x == 1 && y == 14) || (x == 1 && y == 1))
      * ipworld = 3;

    if(x == 8 && y == 8)
      * ipworld = 1;

    if(x == 0 || x == worldwide -1 || y == 0 || y == worldhigh -1 || x == 5)
      * ipworld = 2;
    if(x == 5 && y == 8){
      * ipworld = 0;
    }
ipworld++;
  }
}

}
//world rendering function
void worldrendering(int *ipworld, int worldwide, int worldhigh)
{
  setconsolecolor(0,0);


  for(int y=0; y< worldhigh; y++){
    for(int x=0; x<worldwide; x++){

      if(*ipworld == 0){
        if((x + y) %2){setconsolecolor(15,15);
        printf("  ");}else
        {
        setconsolecolor(15,7);
        printf("  ");
        }
      }else if(*ipworld == 1){
        setconsolecolor(0,1);
        printf("11");
      }else if(*ipworld == 2){
        setconsolecolor(0,8);
        printf("[]");
      }else if(*ipworld == 3){
        setconsolecolor(0,4);
        printf("33");
      }else if(*ipworld == 4){
        setconsolecolor(15,6);
        printf("[]");
      }else if(*ipworld == 5){
        setconsolecolor(15,5);
        printf("  ");
      }else{
        setconsolecolor(15,4);
        printf("XX");
      }
      ipworld++;
    }
    setconsolecolor(15,0);
    printf("\n");
  }

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




if(*game == 0){
  setconsolecolor(15,0);
        printf("The player is no more...\nI think you should restart...\n-----------GAME OVER-----------");
}




}
//main function
int main()
{
//variables
int worldwide = 16;
int worldhigh = 16;
int world[worldwide][worldhigh];

int movement[2] = {0};
int action  [2] = {0};

int game = 1;

//world Building

worldflavoring(&world[0][0], worldwide, worldhigh);
worldrendering(&world[0][0], worldwide, worldhigh);

//game loop

while(game){

//event order

  enemyai(&world[0][0], worldwide, worldhigh);

  inputs(&movement[0], &action[0]);

  moveplayer(&world[0][0], worldwide, worldhigh, &movement[0]);

  actionplayer(&world[0][0], worldwide, worldhigh, &action[0]);

  system("cls");

  worldrendering(&world[0][0], worldwide, worldhigh);

  eventcheck(&world[0][0], worldwide, worldhigh, &game);
}
return 0;
}
