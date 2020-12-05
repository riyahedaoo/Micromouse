#include <NewPing.h>

#include <l298n_lib.h>

int TRIGGER_PINF=8;
int ECHO_PINF=9;
int TRIGGER_PINL=2;
int ECHO_PINL=7;
int TRIGGER_PINR=12;
int ECHO_PINR=13;
int MAX_DISTANCE=300;
int lWall;
int rWall;
int fWall;
char path[30];
int r;
char *s=path;
int i;

void setup(){
  Serial.begin(9600);
  set_pins(6,5,4,3,10,11);
  repeat();
  findb();
  r=pathlength();
}

void gostraight() {
  dmot('F', 250);
  lmot('F', 250);
}

void turnleft() {
  gostraight();
  delay(300);
  dmot('B', 250);
  lmot('F', 250);
  delay(350);
}

void turnright() {
  gostraight();
  delay(300);
  dmot('F', 250);
  lmot('B', 250);
  delay(350);
}

void uturn() {
  dmot('B', 250);
  lmot('F', 250);
  delay(650);
}

void readsen() {

NewPing sonarLeft(TRIGGER_PINL, ECHO_PINL, MAX_DISTANCE);
NewPing sonarRight(TRIGGER_PINR, ECHO_PINR, MAX_DISTANCE);
NewPing sonarFront(TRIGGER_PINF, ECHO_PINF, MAX_DISTANCE);
  lWall = sonarLeft.ping_cm();
  rWall = sonarRight.ping_cm();
  fWall = sonarFront.ping_cm();
}

void repeat(){
  int a=1;
  while(a=1){
  readsen();
  if(fWall>10 && lWall<10 && rWall<10)
  {
    gostraight();
  }
  if(fWall<10 && lWall>10 && rWall<10)
  {
    *s='L';
    s++;
    turnleft();
    gostraight();
  }
  if(fWall<10 && lWall<10 && rWall>10)
  {
    *s='R';
    s++;
    turnright();
    gostraight();
  }
  if(fWall>10 && lWall>10 && rWall<10)
  {
    *s='L';
    s++;
    turnleft();
    gostraight();
  }
  if(fWall>10 && lWall<10 && rWall>10)
  {
    *s='R';
    s++;
    turnright();
    gostraight();
  }
  if(fWall<10 && lWall>10 && rWall>10)
  {
    *s='L';
    s++;
    turnleft();
    gostraight();
  }
  if(fWall<10 && lWall<10 && rWall<10)
  {
    *s='B';
    s++;
    uturn();
    gostraight();
  }
  if(fWall>10 && lWall>10 && rWall>10)
  {
    *s=' ';
    lmot_stop();
    dmot_stop();
    delay(500);
    uturn();
    a=0;
   }
  
}
}

int pathlength(){
  int w=0;
  while(path[w]!=' '){
    w++;
  }
  return w;
}

void findb(){
  r=pathlength();
  for(i=0;i<=r;i++)
  {
    if(path[i]=='B')
    {
      shortpath();
    }
  }
}

void shortpath(){
  int j;
  if(path[i-1]=='L' && path[i+1]=='R')
  {
    path[i-1]='B';
    for(j=i;path[j]!=' ';j++)
    {
      path[j]=path[j+2];
    }
    path[j]=' ';
  }
  if(path[i-1]=='L' && path[i+1]=='S')
  {
    path[i-1]='R';
    for(j=i;path[j]!=' ';j++)
    {
      path[j]=path[j+2];
    }
    path[j]=' ';
  }
  if(path[i-1]=='L' && path[i+1]=='L')
  {
    path[i-1]='S';
    for(j=i;path[j]!=' ';j++)
    {
      path[j]=path[j+2];
    }
    path[j]=' ';
  }
  if(path[i-1]=='R' && path[i+1]=='R')
  {
    path[i-1]='S';
    for(j=i;path[j]!=' ';j++)
    {
      path[j]=path[j+2];
    }
    path[j]=' ';
  }
  if(path[i-1]=='R' && path[i+1]=='S')
  {
    path[i-1]='L';
    for(j=i;path[j]!=' ';j++)
    {
      path[j]=path[j+2];
    }
    path[j]=' ';
  }
  if(path[i-1]=='R' && path[i+1]=='L')
  {
    path[i-1]='B';
    for(j=i;path[j]!=' ';j++)
    {
      path[j]=path[j+2];
    }
    path[j]=' ';
  }
  if(path[i-1]=='S' && path[i+1]=='R')
  {
    path[i-1]='L';
    for(j=i;path[j]!=' ';j++)
    {
      path[j]=path[j+2];
    }
    path[j]=' ';
  }
  if(path[i-1]=='S' && path[i+1]=='S')
  {
    path[i-1]='B';
    for(j=i;path[j]!=' ';j++)
    {
      path[j]=path[j+2];
    }
    path[j]=' ';
  }
  if(path[i-1]=='S' && path[i+1]=='L')
  {
    path[i-1]='R';
    for(j=i;path[j]!=' ';j++)
    {
      path[j]=path[j+2];
    }
    path[j]=' ';
  }
 findb(); 
}

void loop(){
  char d;
  int k=0;
  readsen();
  while((!fWall<10) && !(rWall<10) && !(lWall<10))
  {
   readsen();
   if((rWall>10 or lWall>10)or(rWall>10 and lWall>10))
   {
     d=path[k];
     if(d=='L')
     {
       turnright();
       gostraight();
     }
     if(d=='R')
     {
       turnleft();
       gostraight();
     }
     if(d=='S')
     {
       gostraight();
     }
     k++;
   }
   else{
     gostraight();
   }
 } 
 delay(3000);

  while(!(fWall>10) && !(rWall>10) && !(lWall>10))
  {
   readsen();
   if((rWall>10 or lWall>10)or(rWall>10 and lWall>10))
   {
     d=path[k];
     if(d=='L')
     {
       turnleft();
       gostraight();
     }
     if(d=='R')
     {
       turnright();
       gostraight();
     }
     if(d=='S')
     {
       gostraight();
     }
     k++;
   }
   else{
     gostraight();
   }
 }
 delay(1500);
 uturn();
}
