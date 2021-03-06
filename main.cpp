#include<Windows.h>
#include<GL\glut.h>
#include <stdlib.h>
#include<math.h>
#include <iostream>

void init()

{
glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,1920.0,0.0, 1080.0);
}

///For Translation
static float  tx,tmx,twx,tsx  = 0.0;
static float  ty,tmy,twy =  0.0;


  void ALL_MovingForward(void){

/// farmer day speed
    tmx +=0.14;
    if ( tmx >490)
    {
        tmx = -80;
    }
/// farmer night speed
    tmy -=0.12;
    if ( tmy <-100)
    {
        tmy = +50;
    }
///sun , cloud , boat speed
       tx +=0.8;
    if ( tx >1800)
    {
        tx = -1500;
    }
///wave speed
       twx +=0.6;
    if ( twx >1800)
    {
        twx = -1500;
    }
///Swim Speed
       tsx +=0.14;
    if ( tsx >100)
    {
        tsx = -100;
    }
    glutPostRedisplay();
 }


void my_special_key(int key, int x, int y)
{
  switch (key) {

    case GLUT_KEY_RIGHT:
        glutIdleFunc(ALL_MovingForward);
        break;

  }
}



///Sky
void sky()
{
glBegin(GL_QUADS);
glColor3ub(136,199,253);
glVertex2i(0,1080);
glColor3ub(136,199,253);
glVertex2i(1920,1080);
glColor3ub(255,255,255);
glVertex2i(1920,660);
glColor3ub(255,255,255);
glVertex2i(0,660);
glEnd();
}

void night_sky()
{
glBegin(GL_QUADS);
glColor3ub(0 ,0, 25);
glVertex2i(0,1080);
glColor3ub(0 ,0, 25);
glVertex2i(1920,1080);
glColor3ub(51,67,121);
glVertex2i(1920,660);
glColor3ub(51,67,121);
glVertex2i(0,660);
glEnd();
}


///Clouds
void clouds()
{
for (int j=0 ; j<=1350; j+=450)
{


glColor3ub(255,255,255);
glBegin(GL_POLYGON);
for(int i=0; i<360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(540+j+80*cos(theta) , 940+25*sin(theta));

}
glEnd();

glColor3ub(255,255,255);
glBegin(GL_POLYGON);
for(int i=0; i<360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(520+j+30*cos(theta) , 940+35*sin(theta));

}
glEnd();

glColor3ub(255,255,255);
glBegin(GL_POLYGON);
for(int i=0; i<360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(560+j+30*cos(theta) , 940+35*sin(theta));

}
glEnd();

}
}


///Sun
void sun()
{
    glColor3ub(248,229,100);
glBegin(GL_POLYGON);
for(int i=0; i<360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(230+40*cos(theta) , 945+40*sin(theta));

}
glEnd();
}


///MOON
void moon()
{
    glColor3ub(255,255,255);
glBegin(GL_POLYGON);
for(int i=0; i<360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(230+40*cos(theta) , 945+40*sin(theta));

}
glEnd();


///Stars

for(int x=0; x<=1920; x+=160)
    {
    for(int y=0; y<=200; y+=100)
     {
        glColor3ub(255,255,255);
glBegin(GL_POLYGON);
for(int i=0; i<360;i++)
        {
    float theta=i*3.142/180;
    glVertex2f(20+x+2*cos(theta) , 1020-y+2*sin(theta));

        }
glEnd();
     }

    }



    for(int x=0; x<=1920; x+=90)
    {
    for(int y=0; y<=100; y+=100)
     {
        glColor3ub(255,255,255);
glBegin(GL_POLYGON);
for(int i=0; i<360;i++)
        {
    float theta=i*3.142/180;
    glVertex2f(65+x+1.5*cos(theta) , 970-y+1.5*sin(theta));

        }
glEnd();
     }

    }

}


///Hills DAY view

void day_hills()
{

//Hill - 5
glColor3ub(60,117,138);
glBegin(GL_TRIANGLES);
glVertex2i(1530,660);
glVertex2i(1725,752);
glVertex2i(1920,660);
glEnd();

glColor3ub(29,78,92);
glBegin(GL_TRIANGLES);
glVertex2i(1530,660);
glVertex2i(1725,752);
glVertex2i(1590,660);
glEnd();

//Hill-4 ( Largest Hill)
glColor3ub(77,151,175);
glBegin(GL_POLYGON);
glVertex2i(1010,860);
glVertex2i(1170,880);
glVertex2i(1620,660);
glVertex2i(700,660);
glEnd();

glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2i(1010,860);
glVertex2i(1170,880);

glVertex2i(1160,800);
glVertex2i(1090,840);
glVertex2i(1000,790);
glEnd();

glColor3ub(255,255,255);
glBegin(GL_TRIANGLES);
glVertex2i(1170,880);
glVertex2i(1270,832);
glVertex2i(1160,850);
glEnd();

glColor3ub(255,255,255);
glBegin(GL_TRIANGLES);
glVertex2i(1010,860);
glVertex2i(1020,830);
glVertex2i(935,817);
glEnd();

//Hill - 1 ( from left to right )
glColor3ub(60,117,138);
glBegin(GL_TRIANGLES);
glVertex2i(0,660);
glVertex2i(95,712);
glVertex2i(190,660);
glEnd();

glColor3ub(29,78,92);
glBegin(GL_TRIANGLES);
glVertex2i(0,660);
glVertex2i(95,712);
glVertex2i(40,660);
glEnd();

//Hill - 2
glColor3ub(60,117,138);
glBegin(GL_TRIANGLES);
glVertex2i(180,660);
glVertex2i(315,732);
glVertex2i(445,660);
glEnd();

glColor3ub(29,78,92);
glBegin(GL_TRIANGLES);
glVertex2i(180,660);
glVertex2i(315,732);
glVertex2i(225,660);
glEnd();

//Hill - 3
glColor3ub(60,117,138);
glBegin(GL_TRIANGLES);
glVertex2i(410,660);
glVertex2i(595,752);
glVertex2i(750,660);
glEnd();

glColor3ub(29,78,92);
glBegin(GL_TRIANGLES);
glVertex2i(410,660);
glVertex2i(595,752);
glVertex2i(480,660);
glEnd();
}



///Hills Night view

void night_hills()
{

//Hill - 5
glColor3ub(60,117,138);
glBegin(GL_TRIANGLES);
glVertex2i(1530,660);
glVertex2i(1725,752);
glVertex2i(1920,660);
glEnd();

glColor3ub(29,78,92);
glBegin(GL_TRIANGLES);
glVertex2i(1530,660);
glVertex2i(1725,752);
glVertex2i(1590,660);
glEnd();

//Hill-4 ( Largest Hill)
glColor3ub(77,151,175);
glBegin(GL_POLYGON);
glVertex2i(1010,860);
glVertex2i(1170,880);
glVertex2i(1620,660);
glVertex2i(700,660);
glEnd();

glColor3ub(60,117,138);
glBegin(GL_POLYGON);
glVertex2i(1010,860);
glVertex2i(1170,880);

glVertex2i(1160,800);
glVertex2i(1090,840);
glVertex2i(1000,790);
glEnd();

glColor3ub(60,117,138);
glBegin(GL_TRIANGLES);
glVertex2i(1170,880);
glVertex2i(1270,832);
glVertex2i(1160,850);
glEnd();

glColor3ub(60,117,138);
glBegin(GL_TRIANGLES);
glVertex2i(1010,860);
glVertex2i(1020,830);
glVertex2i(935,817);
glEnd();

//Hill - 1 ( from left to right )
glColor3ub(60,117,138);
glBegin(GL_TRIANGLES);
glVertex2i(0,660);
glVertex2i(95,712);
glVertex2i(190,660);
glEnd();

glColor3ub(29,78,92);
glBegin(GL_TRIANGLES);
glVertex2i(0,660);
glVertex2i(95,712);
glVertex2i(40,660);
glEnd();

//Hill - 2
glColor3ub(60,117,138);
glBegin(GL_TRIANGLES);
glVertex2i(180,660);
glVertex2i(315,732);
glVertex2i(445,660);
glEnd();

glColor3ub(29,78,92);
glBegin(GL_TRIANGLES);
glVertex2i(180,660);
glVertex2i(315,732);
glVertex2i(225,660);
glEnd();

//Hill - 3
glColor3ub(60,117,138);
glBegin(GL_TRIANGLES);
glVertex2i(410,660);
glVertex2i(595,752);
glVertex2i(750,660);
glEnd();

glColor3ub(29,78,92);
glBegin(GL_TRIANGLES);
glVertex2i(410,660);
glVertex2i(595,752);
glVertex2i(480,660);
glEnd();
}




///River

void day_river()
{
    glColor3ub(129,212,250);
glBegin(GL_QUADS);
glVertex2i(0,660);
glVertex2i(1920,660);
glVertex2i(1920,0);
glVertex2i(0,0);
glEnd();
}

void night_river()
{
    glColor3ub(6,113,162);
glBegin(GL_QUADS);
glVertex2i(0,660);
glVertex2i(1920,660);
glVertex2i(1920,0);
glVertex2i(0,0);
glEnd();
}


/// Waves in River

void waves_river()
{
    for (int i=0 ; i<= 1920*20 ; i+=135){
for ( int j=0 ; j<= 600; j+=100)
{
    glColor3ub(193 , 234,253);
glLineWidth(4);
glBegin(GL_LINES);
glVertex2i(-1920+i,590-j);
glVertex2i(-1855+i,590-j);  //Lines

glVertex2i(-1835+i,540-j);
glVertex2i(-1770+i,540-j);


glEnd();

}
}
}


/// Swimming Men in River

void swimmer()

{
    for(int k=0 ; k<=90   ; k+=90)
{

for ( int m=0 ; m<=80   ;m+= 80)
{


glColor3ub(251,167,156);
glBegin(GL_QUADS);
glVertex2i(790+k,335+m);
glVertex2i(810+k,320+m); //body
glVertex2i(800+k,300+m);
glVertex2i(780+k,300+m);
glEnd();

glColor3ub(0,0,0);
glBegin(GL_POLYGON);
for(int i=0; i<=360/2;i++)
{
    float theta=i*3.142/180;
    glVertex2f(807+k+8*cos(theta) , 338+m+8*sin(theta));  //hair

}
glEnd();
glColor3ub(251,167,156);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(805+k+8*cos(theta) , 333+m+8*sin(theta));  //head

}
glEnd();

glColor3ub(251,167,156);
glLineWidth(5);
glBegin(GL_LINES);
glVertex2i(790+k,332+m);
glVertex2i(785+k,345+m);   // Hand
glVertex2i(790+k,358+m);
glVertex2i(785+k,345+m);
glVertex2i(808+k,318+m);
glVertex2i(820+k,310+m);

glEnd();
    }

  }
}



///Left Side Field

void field()
{

//left side
glColor3ub(76,175,81);
glBegin(GL_POLYGON);
glVertex2i(0,660);
glVertex2i(610,660);
glVertex2i(670,610);
glVertex2i(625,580);
glVertex2i(0,580);
glEnd();

glColor3ub(67,160,71);
glBegin(GL_POLYGON);
glVertex2i(0,580);
glVertex2i(625,580);
glVertex2i(680,540);
glVertex2i(655,500);
glVertex2i(0,500);
glEnd();

glColor3ub(56,142,61);
glBegin(GL_POLYGON);
glVertex2i(0,500);
glVertex2i(655,500);
glVertex2i(690,465);
glVertex2i(665,440);
glVertex2i(0,440);
glEnd();

glColor3ub(0,128,0);
glBegin(GL_POLYGON);
glVertex2i(0,440);
glVertex2i(665,440);
glVertex2i(680,390);
glVertex2i(605,340);
glVertex2i(0,340);
glEnd();


glColor3ub(0,108,0);
glBegin(GL_POLYGON);
glVertex2i(0,340);
glVertex2i(605,340);
glVertex2i(620,305);
glVertex2i(585,270);
glVertex2i(0,270);
glEnd();


///Right side Field

glColor3ub(76,175,81);
glBegin(GL_POLYGON);
glVertex2i(670+400,610);
glVertex2i(610+400,660);
glVertex2i(1920,660);
glVertex2i(1920,580);
glVertex2i(625+400,580);

glEnd();

glColor3ub(67,160,71);
glBegin(GL_POLYGON);
glVertex2i(680+400,540);
glVertex2i(625+400,580);
glVertex2i(1920,580);
glVertex2i(1920,500);
glVertex2i(655+400,500);

glEnd();

glColor3ub(56,142,61);
glBegin(GL_POLYGON);
glVertex2i(690+400,465);
glVertex2i(655+400,500);
glVertex2i(1920,500);
glVertex2i(1920,440);
glVertex2i(665+400,440);

glEnd();

glColor3ub(0,128,0);
glBegin(GL_POLYGON);
glVertex2i(680+400,390);
glVertex2i(665+400,440);
glVertex2i(1920,440);
glVertex2i(1920,340);
glVertex2i(605+400,340);

glEnd();


glColor3ub(0,108,0);
glBegin(GL_POLYGON);
glVertex2i(620+400,305);
glVertex2i(605+400,340);
glVertex2i(1920,340);
glVertex2i(1920,270);
glVertex2i(585+400,270);

glEnd();


///Nodir Par

glColor3ub(0 , 0,0);
glLineWidth(5);
glBegin(GL_LINES);
glVertex2i(0,270);
glVertex2i(585,270);  //Lines
glVertex2i(620,305);
glVertex2i(585,270);
glVertex2i(680,390);
glVertex2i(605,340);
glVertex2i(680,540);
glVertex2i(655,500);
glVertex2i(670,610);
glVertex2i(625,580);
glVertex2i(690,465);
glVertex2i(665,440);


glVertex2i(620+400,305);
glVertex2i(605+400,340);
glVertex2i(680+400,390);
glVertex2i(665+400,440);
glVertex2i(670+400,610);
glVertex2i(610+400,660);
glVertex2i(680+400,540);
glVertex2i(625+400,580);
glVertex2i(690+400,465);
glVertex2i(655+400,500);
glVertex2i(1920,270);
glVertex2i(585+400,270);
glEnd();
}


///House 1

void house_paddy()
{

glColor3ub(255,224,172);
glBegin(GL_QUADS);
glVertex2i(1300-1200,405);
glVertex2i(1500-1200,405);
glVertex2i(1500-1200,335); // Main wall
glVertex2i(1300-1200,335);
glEnd();


glColor3ub(41,12,77);
glBegin(GL_QUADS);
glVertex2i(1330-1200,395);
glVertex2i(1360-1200,395);  //Door
glVertex2i(1360-1200,345);
glVertex2i(1330-1200,345);
glEnd();
glColor3ub(41,24,8);
glBegin(GL_QUADS);
glVertex2i(1410-1200,385);
glVertex2i(1440-1200,385);  // Window -1
glVertex2i(1440-1200,355);
glVertex2i(1410-1200,355);
glEnd();

glColor3ub(41,24,8);
glBegin(GL_QUADS);
glVertex2i(1450-1200,385);
glVertex2i(1480-1200,385);  // Window -2
glVertex2i(1480-1200,355);
glVertex2i(1450-1200,355);
glEnd();

glColor3ub(176,116,18);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2i(1390-1200, 405);
glVertex2i(1390-1200, 335); //Lines

glVertex2i(1425-1200,385);
glVertex2i(1425-1200,355);

glVertex2i(1410-1200,370);
glVertex2i(1440-1200,370);

glVertex2i(1465-1200,385);
glVertex2i(1465-1200,355);

glVertex2i(1450-1200,370);
glVertex2i(1480-1200,370);

glEnd();

glColor3ub(97,97,97);
glBegin(GL_QUADS);
glVertex2i(1345-1200,465);
glVertex2i(1455-1200,465);  // Top Cal
glVertex2i(1500-1200,405);
glVertex2i(1390-1200, 405);
glEnd();




glColor3ub(0 , 0,0);
glLineWidth(10);
glBegin(GL_LINES);
glVertex2i(1345-1200,464);
glVertex2i(1390-1200, 405); //Lines
glVertex2i(1345-1200,466);
glVertex2i(1300-1200,405);
glEnd();


glColor3ub(97,97,97);
glBegin(GL_TRIANGLES);
glVertex2i(1300-1200,405);
glVertex2i(1345-1200,465);   //TRIANGLES
glVertex2i(1390-1200, 405);
glEnd();


/// House Relling

glColor3ub(255, 255,255);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2i(1300-1200,335);
glVertex2i(1300-1200,325);
glVertex2i(1390-1200, 335); //Lines
glVertex2i(1390-1200, 325);

glVertex2i(1300-1200,325);
glVertex2i(1390-1200, 325);

glVertex2i(1300-1200,305);
glVertex2i(1390-1200, 305);
glEnd();



for (int j=0 ; j<=90 ; j+=10)
{
    glColor3ub(255, 255,255);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2i(1300-1200+j,325);
glVertex2i(1300-1200+j,305);



glEnd();
}
}


///Tree beside House

void trees()
{

glColor3ub(139,69,19);
glBegin(GL_QUADS);
glVertex2i(405,470);
glVertex2i( 430,470);
glVertex2i(430,350);
glVertex2i(405, 350);  //Wood Part
glEnd();


glColor3ub(0,128,0);
glBegin(GL_POLYGON);
for(int i=0; i<360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(427+30*cos(theta) , 490+30*sin(theta));   // Circle

}
glEnd();

glColor3ub(0,128,0);
glBegin(GL_POLYGON);
for(int i=0; i<360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(397+30*cos(theta) , 490+30*sin(theta));   // Circle

}
glEnd();

glColor3ub(0,128,0);
glBegin(GL_POLYGON);
for(int i=0; i<360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(412+30*cos(theta) , 510+30*sin(theta));   // Circle

}
glEnd();


glColor3ub(139,69,19);
glBegin(GL_TRIANGLES);
glVertex2i(430,420);
glVertex2i(470,427);   //TRIANGLES
glVertex2i(430,410);
glEnd();


///Hamock (Dolna)

glColor3ub(221 , 210,0);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2i(443, 365);
glVertex2i(443, 420);   //Lines
glVertex2i(467, 365);
glVertex2i(467 ,423);
glEnd();

glColor3ub(0,0,0);
glBegin(GL_QUADS);
glVertex2i(443,365);
glVertex2i( 467,365);
glVertex2i(467,355);
glVertex2i(443, 355);
glEnd();


glColor3ub(139,69,19);
glBegin(GL_TRIANGLES);
glVertex2i(430,420);
glVertex2i(470,427);   //TRIANGLES
glVertex2i(430,410);
glEnd();



///Behind Trees

for ( int j=0 ; j<=470   ; j+=48)
{

glColor3ub(139,69,19);
glBegin(GL_QUADS);
glVertex2i(80+j,625);
glVertex2i( 90+j,625);
glVertex2i(90+j,600);
glVertex2i(80+j, 600);
glEnd();

glColor3ub(0,128,0);
glBegin(GL_TRIANGLES);
glVertex2i(70+j,625);
glVertex2i(85+j,655);   //TRIANGLES
glVertex2i(100+j,625);
glEnd();

glColor3ub(0,128,0);
glBegin(GL_TRIANGLES);
glVertex2i(75+j,645);
glVertex2i(83+j,670);   //TRIANGLES
glVertex2i(95+j,645);
glEnd();

}
}


///Boat

void boat()
{


for ( int b=0 ; b<= 900  ; b+= 900)
{

glColor3ub(251,166,73);
glBegin(GL_POLYGON);
for(int i=180; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(400+b+110*cos(theta) , 180+40*sin(theta));

}
glEnd();



///Man in Boat 1st

glColor3ub(251,167,156);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430+b+10*cos(theta) , 230+10*sin(theta));  //head

}
glEnd();

glColor3ub(0,0,0);
glBegin(GL_POLYGON);
for(int i=0; i<=360/2;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430+b+10*cos(theta) , 235+10*sin(theta));  //hair

}
glEnd();

glColor3ub(42,56,144);
glBegin(GL_QUADS);
glVertex2i(435+b,190);
glVertex2i(470+b,200);
glVertex2i(450+b,180);
glVertex2i(430+b,180);
glEnd();

glColor3ub(42,56,144);
glBegin(GL_QUADS);
glVertex2i(460+b,190);
glVertex2i(470+b,200);  //legs
glVertex2i(470+b,180);
glVertex2i(460+b,180);
glEnd();

glColor3ub(240,64,63);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430+b+10*cos(theta) , 200+20*sin(theta));  // body

}
glEnd();


glColor3ub(47 , 47,47);
glLineWidth(4);
glBegin(GL_LINES);
glVertex2i(460+b,220);
glVertex2i(418+b, 150);   /// Boat Oar

glEnd();

glColor3ub(47 , 47,47);
glBegin(GL_TRIANGLES);
glVertex2i(396+b,127);
glVertex2i(418+b,153);
glVertex2i(432+b,120);
glEnd();

glColor3ub(251,167,156);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(445+b+15*cos(theta) , 210+5*sin(theta));  // hand

}
glEnd();



/// 2nd man in boat

glColor3ub(251,167,156);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430+b-100+10*cos(theta) , 230+10*sin(theta));  //head

}
glEnd();

glColor3ub(0,0,0);
glBegin(GL_POLYGON);
for(int i=0; i<=360/2;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430+b-100+10*cos(theta) , 235+10*sin(theta));  //hair

}
glEnd();

glColor3ub(42,56,144);
glBegin(GL_QUADS);
glVertex2i(435+b-100,190);
glVertex2i(470+b-100,200);
glVertex2i(450+b-100,180);
glVertex2i(430+b-100,180);
glEnd();

glColor3ub(42,56,144);
glBegin(GL_QUADS);
glVertex2i(460+b-100,190);
glVertex2i(470+b-100,200);  //legs
glVertex2i(470+b-100,180);
glVertex2i(460+b-100,180);
glEnd();

glColor3ub(240,64,63);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430+b-100+10*cos(theta) , 200+20*sin(theta));  // body

}
glEnd();


glColor3ub(47 , 47,47);
glLineWidth(4);
glBegin(GL_LINES);
glVertex2i(460+b-100,220);
glVertex2i(418+b-100, 150);   // Boat Oar

glEnd();

glColor3ub(47 , 47,47);
glBegin(GL_TRIANGLES);
glVertex2i(396+b-100,127);
glVertex2i(418+b-100,153);
glVertex2i(432+b-100,120);
glEnd();

glColor3ub(251,167,156);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(445+b-100+15*cos(theta) , 210+5*sin(theta));  // hand

}
glEnd();
}
}                                              // loop end



///Paddy

void paddy()
{
    for (int h=0; h<=270; h+=160)
{
glColor3ub(130 , 92,15);
glLineWidth(5);
glBegin(GL_LINES);
glVertex2i(1630+h, 430);
glVertex2i(1630+h, 455);   //Lines

glEnd();

glColor3ub(229,165,29);
glBegin(GL_POLYGON);
for(int i=0; i<=360/2;i++)
{
    float theta=i*3.142/180;
    glVertex2f(1630+h+35*cos(theta) , 325+110*sin(theta));  //paddy

}
glEnd();
 }
}



/// House 2 beside Paddy
void house_beside_paddy()
{


glColor3ub(196,153,26);
glBegin(GL_QUADS);
glVertex2i(1300,405);
glVertex2i(1500,405);
glVertex2i(1500,335); // Main
glVertex2i(1300,335);
glEnd();


glColor3ub(146,0,21);
glBegin(GL_QUADS);
glVertex2i(1330,395);
glVertex2i(1360,395);  //Door
glVertex2i(1360,345);
glVertex2i(1330,345);
glEnd();

glColor3ub(146,0,21);
glBegin(GL_QUADS);
glVertex2i(1410,385);
glVertex2i(1440,385);  // Window -1
glVertex2i(1440,355);
glVertex2i(1410,355);
glEnd();

glColor3ub(146,0,21);
glBegin(GL_QUADS);
glVertex2i(1450,385);
glVertex2i(1480,385);  // Window -2
glVertex2i(1480,355);
glVertex2i(1450,355);
glEnd();

glColor3ub(0 , 0,0);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2i(1390, 405);
glVertex2i(1390, 335); //Lines

glVertex2i(1425,385);
glVertex2i(1425,355);

glVertex2i(1410,370);
glVertex2i(1440,370);

glVertex2i(1465,385);
glVertex2i(1465,355);

glVertex2i(1450,370);
glVertex2i(1480,370);

glEnd();


glColor3ub(255, 255,255);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2i(1300,335);
glVertex2i(1300,325);
glVertex2i(1390, 335); //Lines
glVertex2i(1390, 325);

glVertex2i(1300,325);
glVertex2i(1390, 325);

glVertex2i(1300,305);
glVertex2i(1390, 305);
glEnd();


for (int j=0 ; j<=90 ; j+=10)
{
    glColor3ub(255, 255,255);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2i(1300+j,325);
glVertex2i(1300+j,305);

glEnd();
}


glColor3ub(229,165,29);
glBegin(GL_QUADS);
glVertex2i(1345,465);
glVertex2i(1455,465);  // Top
glVertex2i(1500,405);
glVertex2i(1390, 405);
glEnd();




glColor3ub(0 , 0,0);
glLineWidth(10);
glBegin(GL_LINES);
glVertex2i(1345,464);
glVertex2i(1390, 405); //Lines
glVertex2i(1345,466);
glVertex2i(1300,405);
glEnd();

glColor3ub(170,166,66);
glBegin(GL_TRIANGLES);
glVertex2i(1300,405);
glVertex2i(1345,465);   //TRIANGLES
glVertex2i(1390, 405);
glEnd();
}


///Paddy Field

void paddy_field()
{

for( int i=0 ; i<=500 ; i=i+6)
{
    for ( int j=0 ; j<=80 ; j=j+15)
    {
     glBegin(GL_TRIANGLES);
  glColor3ub(181, 231, 29);
     glVertex2i(1300+i,560-j);
  glColor3ub(183, 215, 55);
     glVertex2i(1304+i,585-j);
  glColor3ub(49, 221, 49);
     glVertex2i(1308+i, 560-j);
     glEnd();
    }

  }
}



/// Man beside house 1

void man_beside_house()
{

glColor3ub(251,167,156);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430+115+10*cos(theta) , 230+115+10*sin(theta));  //head

}
glEnd();

glColor3ub(0,0,0);
glBegin(GL_POLYGON);
for(int i=0; i<=360/2;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430+115+10*cos(theta) , 235+115+10*sin(theta));  //hair

}
glEnd();


glColor3ub(251,167,156);
glBegin(GL_QUADS);
glVertex2i(539,335);
glVertex2i(545,335);  //Hands
glVertex2i(529,315);
glVertex2i(523,315);
glEnd();

glColor3ub(251,167,156);
glBegin(GL_QUADS);
glVertex2i(545,335);
glVertex2i(551,335);  //Hands
glVertex2i(567,315);
glVertex2i(561,315);
glEnd();

glColor3ub(255,242,0);
glBegin(GL_POLYGON);
for(int i=0; i<=360/2;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430+115+10*cos(theta) , 200+115+20*sin(theta));  // body

}
glEnd();

glColor3ub(0,174,249);
glBegin(GL_QUADS);
glVertex2i(535,315);
glVertex2i(545,315);  //legs
glVertex2i(542,295);
glVertex2i(535,295);
glEnd();

glColor3ub(0,174,249);
glBegin(GL_QUADS);
glVertex2i(545,315);
glVertex2i(555,315);  //legs
glVertex2i(555,295);
glVertex2i(548,295);
glEnd();


glColor3ub(0,0,0);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(538+4*cos(theta) , 291+3*sin(theta));  // SHOE

}
glEnd();

glColor3ub(0,0,0);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(551+4*cos(theta) , 291+3*sin(theta));  // SHOE

}
glEnd();



/// Man beside Right sided house

for ( int m=0 ; m<= 90 ; m+=90)
{


glColor3ub(251,167,156);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430-m+630+115+10*cos(theta) , 230+115+10*sin(theta));  //head

}
glEnd();

glColor3ub(0,0,0);
glBegin(GL_POLYGON);
for(int i=0; i<=360/2;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430-m+630+115+10*cos(theta) , 235+115+10*sin(theta));  //hair

}
glEnd();



glColor3ub(251,167,156);
glBegin(GL_QUADS);
glVertex2i(539-m+630,335);
glVertex2i(545-m+630,335);  //Hands
glVertex2i(529-m+630,315);
glVertex2i(523-m+630,315);
glEnd();

glColor3ub(251,167,156);
glBegin(GL_QUADS);
glVertex2i(545-m+630,335);
glVertex2i(551-m+630,335);  //Hands
glVertex2i(567-m+630,315);
glVertex2i(561-m+630,315);
glEnd();

glColor3ub(255,242,0);
glBegin(GL_POLYGON);
for(int i=0; i<=360/2;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430-m+630+115+10*cos(theta) , 200+115+20*sin(theta));  // body

}
glEnd();

glColor3ub(0,174,249);
glBegin(GL_QUADS);
glVertex2i(535-m+630,315);
glVertex2i(545-m+630,315);  //legs
glVertex2i(542-m+630,295);
glVertex2i(535-m+630,295);
glEnd();

glColor3ub(0,174,249);
glBegin(GL_QUADS);
glVertex2i(545-m+630,315);
glVertex2i(555-m+630,315);  //legs
glVertex2i(555-m+630,295);
glVertex2i(548-m+630,295);
glEnd();



glColor3ub(0,0,0);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(538-m+630+4*cos(theta) , 291+3*sin(theta));  // SHOE

}
glEnd();

glColor3ub(0,0,0);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(551-m+630+4*cos(theta) , 291+3*sin(theta));  // SHOE

}
glEnd();

}
}


/// Farmer

void farmer()
{


glColor3ub(134,106,84);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430+630+115+10*cos(theta) , 230+185+115+10*sin(theta));  //head

}
glEnd();

glColor3ub(0,0,0);
glBegin(GL_POLYGON);
for(int i=0; i<=360/2;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430+630+115+10*cos(theta) , 235+185+115+10*sin(theta));  //hair

}
glEnd();

glColor3ub(101 , 53,30);
glLineWidth(4);
glBegin(GL_LINES);
glVertex2i(529+630,315+185);
glVertex2i(509+630,355+185);   //Farming Tool
glEnd();


glColor3ub(0,0,0);
glBegin(GL_TRIANGLES);
glVertex2i(500+630,335+185);
glVertex2i(509+630,355+185);  //Farming Tool
glVertex2i(510+630,345+185);
glEnd();

glColor3ub(0,0,0);
glBegin(GL_TRIANGLES);
glVertex2i(532+630,345+185);
glVertex2i(509+630,355+185);  //Farming Tool
glVertex2i(510+630,345+185);
glEnd();

glColor3ub(134,106,84);
glBegin(GL_QUADS);
glVertex2i(539+630,335+185);
glVertex2i(545+630,335+185);  //Hands
glVertex2i(529+630,315+185);
glVertex2i(523+630,315+185);
glEnd();

glColor3ub(134,106,84);
glBegin(GL_QUADS);
glVertex2i(545+630,335+185);
glVertex2i(551+630,335+185);  //Hands
glVertex2i(567+630,315+185);
glVertex2i(561+630,315+185);
glEnd();

glColor3ub(134,106,84);
glBegin(GL_POLYGON);
for(int i=0; i<=360/2;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430+630+115+10*cos(theta) , 200+185+115+20*sin(theta));  // body

}
glEnd();



glColor3ub(134,106,84);
glBegin(GL_QUADS);
glVertex2i(535+630,315+185);
glVertex2i(545+630,315+185);  //legs
glVertex2i(542+630,295+185);
glVertex2i(535+630,295+185);
glEnd();

glColor3ub(134,106,84);
glBegin(GL_QUADS);
glVertex2i(545+630,315+185);
glVertex2i(555+630,315+185);  //legs
glVertex2i(555+630,295+185);
glVertex2i(548+630,295+185);
glEnd();



glColor3ub(134,106,84);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(538+630+4*cos(theta) , 291+190-3+3*sin(theta));  // SHOE

}
glEnd();

glColor3ub(134,106,84);
glBegin(GL_POLYGON);
for(int i=0; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(551+630+4*cos(theta) , 291+190-3+3*sin(theta));  // SHOE

}
glEnd();



glColor3ub(217,222,242);
glBegin(GL_POLYGON);
for(int i=180; i<=360;i++)
{
    float theta=i*3.142/180;
    glVertex2f(430+630+115+10*cos(theta) , 200+185+115+10*sin(theta));

}
glEnd();
}








///DAY VIEW

void day(void)
{
        glClear(GL_COLOR_BUFFER_BIT);
        sky();

        glPushMatrix();
        glTranslatef(tx,ty,0);
        clouds();
        sun();
        glPopMatrix();


    day_hills();
    day_river();

    glPushMatrix();
    glTranslatef(twx,twy,0);
    waves_river();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tsx,0,0);
    swimmer();
    glPopMatrix();


    field();
    house_paddy();
    trees();

    glPushMatrix();
    glTranslatef(tx,ty,0);
    boat();
    glPopMatrix();

    paddy();
    house_beside_paddy();
    paddy_field();
    man_beside_house();

     glPushMatrix();
     glTranslatef(tmx,0,0);
     farmer();
     glPopMatrix();


    glFlush();
     glutSwapBuffers();
}



///NIGHT VIEW

void night(void)
{
glClear(GL_COLOR_BUFFER_BIT);

night_sky();
moon();
night_hills();
night_river();

   glPushMatrix();
    glTranslatef(twx,twy,0);
    waves_river();
    glPopMatrix();

   glPushMatrix();
    glTranslatef(tsx,0,0);
    swimmer();
    glPopMatrix();

field();
house_paddy();
trees();

   glPushMatrix();
    glTranslatef(tx,ty,0);
    boat();
    glPopMatrix();

paddy();
house_beside_paddy();
paddy_field();
man_beside_house();

  glPushMatrix();
     glTranslatef(0,tmy,0);
     farmer();
     glPopMatrix();

    glFlush();
     glutSwapBuffers();
}

void hrithik_keyboard(unsigned char key, int x, int y)
{
  switch (key) {
            case 'p':
               glutIdleFunc(NULL);
               break;

            case 'P':
               glutIdleFunc(NULL);
               break;

            case  'd':
                glutDisplayFunc(day);
                glutKeyboardFunc(hrithik_keyboard);
                glutPostRedisplay();
                    break;
            case 'D':
               glutDisplayFunc(day);
                glutKeyboardFunc( hrithik_keyboard);
                glutPostRedisplay();
                break;

             case 'n':
                glutDisplayFunc(night);
                glutKeyboardFunc(hrithik_keyboard);
                glutPostRedisplay();
                break;
            case  'N':
                glutDisplayFunc(night);
                glutKeyboardFunc( hrithik_keyboard);
                glutPostRedisplay();
                break;

  }
}


int main(int argc, char ** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowPosition(0, 0);
glutInitWindowSize(1920, 1080);
glutCreateWindow("CG Lab Project ||Hrithik & Afroza");
init();
glutDisplayFunc(day);
glutSpecialFunc(my_special_key);
glutKeyboardFunc(hrithik_keyboard);
glutMainLoop();

}
