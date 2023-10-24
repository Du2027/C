#define GPIO1 0;
#define GPIO2 1;
#define GPIO3 2;


int colorset(int r,int g,int b){
  digitalWrite(0, r);
  digitalWrite(1, g);
  digitalWrite(2, b);
}
int main(){
  if(wiringPiSetup()==-1){
    printf("Wiring Pi Setup failed\n");
    }

  int i;
  for(i=0;i<4;i++){
    pinMode(i, OUTPUT);
    printf("OUTPUT : %d\n",i);
  }
  
  while(1){
    for(i=0;i<256;i++){
      colorset(i,0,0);
    }delay(1000);
    for(i=0;i<256;i++){
      colorset(0,i,0);
    }delay(1000);
    for(i=0;i<256;i++){
      colorset(0,0,i);
    }delay(1000);
    for(i=0;i<256;i++){
      colorset(i,i,0);
    }delay(1000);
    for(i=0;i<256;i++){
      colorset(0,i,i);
    }delay(1000);
    for(i=0;i<256;i++){
      colorset(i,i,i);
    }delay(1000);
  }
    return 1;
  }
}
