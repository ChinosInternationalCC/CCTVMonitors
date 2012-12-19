#include <TVout.h>
#include <fontALL.h>
#include "bmp.h"

#define SCREEN_LINES 6
#define SCREEN_COLUMNS 128

TVout TV;
//Must be supported by TV module
#define GAME_WIDTH 128
#define GAME_HEIGHT 96

#define PLAYER_WIDTH  7
#define PLAYER_HEIGHT 10

#define STICKS_WIDTH  6
#define STICKS_HEIGHT 7

#define MAX_SCORE 255

struct point2d
  {
  //data
  unsigned char x;
  unsigned char y;

  //drawing
  void point( unsigned char x0, unsigned char y0, char color )
    {TV.set_pixel( x + x0, y + y0, color );}
  void circle( unsigned char x0, unsigned char y0, unsigned char radius, char color, char fill_color )
    {TV.draw_circle( x + x0, y + y0, radius, color, fill_color ); }
  void line( unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, char color )
    {TV.draw_line( x + x0, y + y0, x + x1, y + y1, color ); }
  };

point2d player;
signed char dx;
signed char dy;
void draw_player( void )
{
player.line( 1, 0, 5, 0, 2);//forehead
player.line( 0, 1, 0, 3, 2);//left cheek
player.line( 6, 1, 6, 3, 2);//right cheek
player.point( 2, 2, 2 );//left eye
player.point( 4, 2, 2 );//right eye
player.line( 1, 4, 5, 4, 2);//chin

player.point( 3, 5, 2 );//neck

player.line( 0, 6, 6, 6, 2 );//arms
player.point( 0, 7, 2 ); //left hand
player.point( 3, 7, 2 ); //torso
player.point( 6, 7, 2 ); //right hand

player.point( 2, 8, 2 ); //left knee
player.point( 4, 8, 2 ); //right knee

player.line( 0, 9, 1, 9, 2 );//left foot
player.line( 5, 9, 6, 9, 2 );//right foot
}
void move_player( void )
{
  //Don't have a controller yet...
  if( player.x + dx < 0 || player.x + dx > GAME_WIDTH  - PLAYER_WIDTH  )dx *= -1;
  if( player.y + dy < 0 || player.y + dy > GAME_HEIGHT - PLAYER_HEIGHT )dy *= -1;
  player.x += dx;
  player.y += dy;
}
int d=100; // for delay purposes
int x1,x2,y1,y2,r=0; 
char c='X';
char str[]="lorem ipsum";
void setup()
{
  TV.begin(_PAL,125,115); // for PAL system
  TV.clear_screen();
  randomSeed(analogRead(0)); // seed the random number generator\
  //Serial.begin(9600);
}

void pixels()
{
  TV.clear_screen();
  for (int a=0; a<200; a++)
  {
    x1=random(128);
    y1=random(96);
    TV.set_pixel(x1,y1,2);
    delay(d);
  }
  delay(100);
  TV.clear_screen();
}

void vu_meter(int volume)
{
  for (int i=0;i<10;i++){
  //TV.clear_screen();
  for (int a=0; a<80; a=a+2)
  {
    TV.draw_line(0,a,80,a,1);
    delay(10);
  }
  for (int a=80; a>0; a=a-2)
  {
    TV.draw_line(0,a,80,a,0);
    delay(10);
  }}
  //delay(1000);
  TV.clear_screen();
}  

void circles()
{
  TV.clear_screen();
  for (int i=0; i<30; i++)
  {
    TV.draw_circle(64,48,i,1,0);
    delay(200);
    TV.draw_circle(64,48,i,1,1);
    delay(200);
    TV.draw_circle(64,48,i,0,0);
    delay(200);
  }
  delay(1000);
  TV.clear_screen();
}  

void font(){
  TV.select_font(font4x6);
  int i=0;
  for (int a=0; a<SCREEN_LINES; a++)
  {
    for (int b=0; b<SCREEN_COLUMNS; b++)
    { i=b;
      TV.print_char(b,a,str[i]);
      i++;
      if (i>=sizeof(str))
        i=0;
      delay(500);
      TV.clear_screen();
    }
  }
  delay(1000);
  //TV.clear_screen();  

  TV.select_font(font6x8);

  for (int a=0; a<SCREEN_LINES; a++)
  {
    for (int b=0; b<SCREEN_COLUMNS; b++)
    { i=a;
      TV.print_char(b,a*6,str[i]);
      i++;
      if (i>=sizeof(str))
        i=0;
      delay(300);
      //TV.clear_screen();
    }
  }
  delay(1000);
  //TV.clear_screen();  
   TV.select_font(font8x8);

  for (int a=0; a<SCREEN_LINES; a++)
  {
    for (int b=0; b<SCREEN_COLUMNS; b++)
    { i=a;
      TV.print_char(b,a*6,str[i]);
      i++;
      if (i>=sizeof(str))
        i=0;
      delay(d);
      //TV.clear_screen();
    }
  }
  delay(1000);
  TV.clear_screen();  
  
  TV.select_font(font4x6);

  for (int b=0; b<SCREEN_COLUMNS; b++)
  {
    for (int a=0; a<SCREEN_LINES; a++)

    { i=a;
      TV.print_char(b,a*6,str[i]);
      i++;
      if (i>=sizeof(str))
        i=0;
      delay(d);
      //TV.clear_screen();
    }
  }
  delay(1000);
  //TV.clear_screen();  

  TV.select_font(font6x8);

  for (int b=0; b<SCREEN_COLUMNS; b++)
  {
    for (int a=0; a<SCREEN_LINES; a++)

    { i=a;
      TV.print_char(b,a*6,str[i]);
      i++;
      if (i>=sizeof(str))
        i=0;
      delay(d);
      //TV.clear_screen();
    }
  }
  delay(1000);
  //TV.clear_screen();  
   TV.select_font(font8x8);

  for (int b=0; b<SCREEN_COLUMNS; b++)
  {
    for (int a=0; a<SCREEN_LINES; a++)

    { i=a;
      TV.print_char(b,a*6,str[i]);
      i++;
      if (i>=sizeof(str))
        i=0;
      delay(d);
      //TV.clear_screen();
    }
  }
  delay(1000);
  TV.clear_screen();
}


void chess()
{ for(int x=0;x<5;x++){
  for (int i=0; i<128; i=i+20)
  for (int j=0; j<96; j=j+20)
  {
  TV.draw_rect(i, j, 20, 20, 1,0);
  TV.invert(); 
  delay(200);
  }
  TV.clear_screen();
  for (int i=0; i<128; i=i+20)
  for (int j=0; j<96; j=j+20)
  {
  TV.draw_rect(i, j, 20, 20, 1,0);
  //TV.invert(); 
  delay(200);}
  TV.clear_screen();
  
  }
}

void row_col()
{
  for (int i=0;i<100;i++){
  //TV.draw_row(i, i, i+10, 1);
  //delay(100);
  TV.draw_column(i*2,20, i+20, 1);
  delay(100);}
  for (int i=20;i<100;i++){
  //TV.draw_row(i, i, i+10, 1);
  //delay(100);
  TV.draw_column(i*2,20, i-20, 1);
  delay(100);}
  for (int i=0;i<100;i++){
  //TV.draw_row(i, i, i+10, 1);
  //delay(100);
  TV.draw_column(i*3,20, i+20, 1);
  delay(100);}
  for (int i=0;i<50;i++){
  //TV.draw_row(i, i, i+10, 1);
  //delay(100);
  TV.draw_column(i*4,20, i+20, 1);
  delay(100);}
  TV.clear_screen();
}
void circle_madness()
{
  for (int j=0;j<20;j++){
  for(int i=0;i<30;i=i+1)
  {
    TV.draw_circle(60, 45, i, 1, 0);
    delay(10);
  }
  for(int i=0;i<30;i=i+1)
  {
    TV.draw_circle(60, 45, i, 2, 0);
    delay(10);
  }
  }
  TV.clear_screen();
  
}

void rect_madness()
{
  for (int j=0;j<20;j++){
  for(int i=0;i<30;i=i+1)
  {
    TV.clear_screen();
    TV.draw_rect(30, 20, i, i, 2, i%2==0);
    
    delay(20);
  }
  }
  TV.clear_screen();
  
}
void display_bmp() {
unsigned char w,l,wb;
  int index;
  /*w = pgm_read_byte(bmp1);
  l = pgm_read_byte(bmp1+1);
  if (w&7)
    wb = w/8 + 1;
  else
    wb = w/8;
  index = wb*(l-1) + 2;
  for ( unsigned char i = 1; i < l; i++ ) {
    TV.bitmap((TV.hres() - w)/2,0,bmp1,index,w,i);
    index-= wb;
    TV.delay(50);
  }
  for (unsigned char i = 0; i < (TV.vres() - l)/2; i++) {
    TV.bitmap((TV.hres() - w)/2,i,bmp1);
    TV.delay(50);
  }
  delay(3000);*/
          TV.bitmap(60,40,spiral);
  delay(10000);
  TV.clear_screen();
        TV.bitmap(60,40,open);
  delay(10000);
  TV.clear_screen();
      TV.bitmap(60,40,disparador);
  delay(10000);
  TV.clear_screen();
    TV.bitmap(60,40,copyright);
  delay(10000);
  TV.clear_screen();
  TV.bitmap(60,40,arduino);
  delay(10000);
  TV.clear_screen();
  TV.bitmap(60,40,tisores);
  delay(10000);
  TV.clear_screen();
  TV.bitmap(60,40,bombeta);
  delay(10000);
  TV.clear_screen();
  TV.bitmap(60,40,tit);
  delay(10000);
  TV.clear_screen();
  TV.bitmap(60,40,umbrella);
  delay(10000);
  TV.clear_screen();
  TV.bitmap(60,40,music);
  delay(10000);
  TV.clear_screen();
  TV.bitmap(60,40,invader);
  delay(10000);
  TV.clear_screen();
  TV.bitmap(0,0,forbiden);
  delay(10000);
  TV.clear_screen();
  TV.bitmap(60,40,bomb);
  TV.delay(10000);
  TV.clear_screen();
}
void loop()
{
   
  //  int in = (int)Serial.read(); 
  display_bmp();
  rect_madness();
  circle_madness();
 row_col();
chess();
 for (int i=0; i<90; i++)
  {
    if ((i%2)==0)
      TV.fill(0);
    else
      TV.fill(1);
    delay(200);
  }
  TV.clear_screen();
 //font();
  pixels();
  vu_meter(80);
  circles();
  chess();
  for (int i=0; i<90; i++)
  {
  move_player();
  draw_player();
    delay(200);
  }

   //Serial.write(in);
}
