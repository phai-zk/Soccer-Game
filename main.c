#include <stdio.h>
#include <math.h>
#include <ctype.h>

int find_T(float V ,float S,float deg){
  float Tgoal;
  Tgoal = (2*V*sin(deg))/9.8;
  return Tgoal;
}

int find_H(float V ,float S,float deg){
  float Hgoal;
  float cdeg = 90/57.3;
  Hgoal = ((V*V)*sin(deg)*cos(cdeg-deg))/(2*9.8);
  return Hgoal;
}

int find_x(float V ,float S,float deg){
  float Sx;
  Sx = ((V*V)*sin(2*deg))/9.8;
  return Sx;
}
int main() {
  char out;
  do{
    float V ,S ,Hgoal ,Tgoal ,deg ,Sx;
    printf("*********************************\n");
    printf("---------- SOCCER GAME ----------\n");
    printf("*********************************\n\n");
    printf("--------- Enter variable --------\n");
    printf("Enter velocity (m/s) : ");
    scanf("%f",&V);
    printf("Enter distance (m) : ");
    scanf("%f",&S);
    printf("Enter degree : ");
    scanf("%f",&deg);
    printf("----------- shoot !!! -----------\n");
    deg = deg/57.3;
    Sx = find_x(V,S,deg);
    Tgoal = find_T(V,S,deg);
    Hgoal = find_H(V,S,deg);
    if (Hgoal<0||Sx<S){
      printf("Fail ball :(\n");
    }else if (Hgoal>=2.44){
      printf("Overshoot :(!\n");
    }else if (Tgoal>0.5||Sx == S){
      printf("Save ball (-_-)\n");
    }else if(Sx > S){
      printf("Goal (*-*)!!!\n");
    }
    do{  
      printf("---------------------------------\n");
      printf("your want to try again ? (y/n) : ");
      scanf ("%s",& out);
      out = tolower(out);
    }while(out != 'y'&&out!='n');
    printf("---------------------------------\n\n");
    if (out == 'y'){ 
      printf("*********************************\n");
      printf("----------- NEW ROUND -----------\n");
      printf("*********************************\n\n");
    }
  }while(out != 'n');
  printf("*********************************\n");
  printf("---------- END PROGRAM ----------\n");
  printf("*********************************\n");
}
