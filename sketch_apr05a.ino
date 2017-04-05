/**/    /**/    /**/    /**/    /**/    /**/
/*                                        */
/*      SERIAL INFO                       */
/*      777 - Left Leg                    */
/*      888 - Right Legs                  */
/*      999 - Front Legs                  */
/*      After this,                       */
/*      First Value - Rotation Angle      */
/*      Second Value - Speed              */
/*      000 - Stop command                */
/*                                        */
/**/    /**/    /**/    /**/    /**/    /**/


#include <Servo.h>        //стандартная либа
Servo servo1;             //создаем объект серво1, левые лапы
Servo servo2;             //создаем объект серво2, правые лапы
Servo servo3;             //создаем объект серво3, передние лапы

int angle1 = 90;          //переменная описывающая положение первой сервы
int interval1 = 20;       //интервал времени, через который будет поворот 
unsigned long lastTime1;  //время последнего движения серво1, в мс от начала работы
int angle2 = 60;          //переменная описывающая положение второй сервы
int interval2 = 20;       //интервал времени, через который будет поворот 
unsigned long lastTime2;  //время последнего движения серво2, в мс от начала работы
int angle3 = 90;          //переменная описывающая положение третей сервы
int interval3 = 20;       //интервал времени, через который будет поворот 
unsigned long lastTime3;  //время последнего движения серво3, в мс от начала работы
bool s1 = true;
bool s2 = true;
bool s3 = false;
bool stoppy = false;
int valA1 = 10;
int valA2 = 10 ;
int valA3 = 10;
int prov,prov2;
void setup() {
  Serial.begin(9600);
  servo1.attach(2);    //пин 2 управляет первой сервой
  servo2.attach(3);    //пин 3 управляет второй сервой
  servo3.attach(4);    //пин 4 управляет второй сервой
  lastTime1=millis();  //отчсет времени для движений серво1 пошёл
  lastTime2=millis();  //отчсет времени для движений серво2 пошёл
  lastTime3=millis();  //отчсет времени для движений серво3 пошёл
  delay(5000);
}

void loop() {
  if (stoppy != 0)
  forward();
  else 
  stops();
  /*
    if  (angle1 <= 90+valA1 && s1==true)        //до 180
  {
                            //сколько прошло времени с последнего действия?
                            //если больше интервала, то что там дальше? вперёд!
    if ((millis()-lastTime1)>= interval1)
    {
    angle1+=2;               //угол++
    servo1.write(angle1);   //серва встань в позицию
    lastTime1= millis();    //счетчик времени обновись
    }
  }
  else
  {
    s1 = false;
    if ((millis()-lastTime1)>= interval1)
    {
    angle1-=2;               //угол++
    servo1.write(angle1);   //серва встань в позицию
    lastTime1=millis();    //счетчик времени обновись
    }
    if  (angle1 < 90-valA1)        //до 180
    {
       s1 = true;
    }
  } 
  
  if  (angle2 < 65+valA2 && s2==true)        //до 180
  {
                            //сколько прошло времени с последнего действия?
                            //если больше интервала, то что там дальше? вперёд!
    if ((millis()-lastTime2)>= interval2)
    {
    angle2+=2;               //угол++
    servo2.write(angle2);   //серва встань в позицию
    lastTime2=millis();    //счетчик времени обновись
    }
  }
  else
  {
    s2 = false;
    if ((millis()-lastTime2)>= interval2)
    {
    angle2-=2;               //угол--
    servo2.write(angle2);   //серва встань в позицию
    lastTime2=millis();    //счетчик времени обновись
    }
    if  (angle2 < 65-valA2)        //до 180
    {
       s2 = true;
    }
  }
  
  if  (angle3 < 90+valA3  && s3==true)        //до 180
  {
                            //сколько прошло времени с последнего действия?
                            //если больше интервала, то что там дальше? вперёд!
    if ((millis()-lastTime3)>= interval3)
    {
    angle3+=2;               //угол++
    servo3.write(angle3);   //серва встань в позицию
    lastTime3= millis();    //счетчик времени обновись
    }
  }
  else
  {
    s3 = false;
    if ((millis()-lastTime3)>= interval3)
    {
    angle3-=2;               //угол-
    servo3.write(angle3);   //серва встань в позицию
    lastTime3=millis();    //счетчик времени обновись
    }
    if  (angle3 < 90-valA3)        //до 180
    {
       s3 = true;
    }
  }
  */
}

void serialEvent(){
  if (stoppy != 0)
  prov=Serial.parseInt();
  else prov=0;
  if (prov2!=0)
  {
  if (prov2==777){valA1=prov;}
  if (prov2==888){valA2=prov;}
  if (prov2==999){valA3=prov;}
  if (prov2==000){stoppy=0;}
  prov2=0;
  }
  if (prov2 == 0){prov2=prov;}

}


void forward() {
  if  (angle1 <= 90+valA1 && s1==true)        //до 180
  {
                             //сколько прошло времени с последнего действия?
                            //если больше интервала, то что там дальше? вперёд!
    if ((millis()-lastTime1)>= interval1)
    {
    angle1+=2;                //угол++
    servo1.write(angle1);    //серва встань в позицию
    lastTime1= millis();    //счетчик времени обновись
    }
  }
  else
  {
    s1 = false;
    if ((millis()-lastTime1)>= interval1)
    {
    angle1-=2;               //угол++
    servo1.write(angle1);   //серва встань в позицию
    lastTime1=millis();    //счетчик времени обновись
    }
    if  (angle1 < 90-valA1)        //до 180
    {
       s1 = true;
    }
  } 
  
  if  (angle2 < 65+valA2 && s2==true)        //до 180
  {
                             //сколько прошло времени с последнего действия?
                            //если больше интервала, то что там дальше? вперёд!
    if ((millis()-lastTime2)>= interval2)
    {
    angle2+=2;               //угол++
    servo2.write(angle2);   //серва встань в позицию
    lastTime2=millis();    //счетчик времени обновись
    }
  }
  else
  {
    s2 = false;
    if ((millis()-lastTime2)>= interval2)
    {
    angle2-=2;               //угол--
    servo2.write(angle2);   //серва встань в позицию
    lastTime2=millis();    //счетчик времени обновись
    }
    if  (angle2 < 65-valA2)        //до 180
    {
       s2 = true;
    }
  }
  
  if  (angle3 < 90+valA3  && s3==true)        //до 180
  {
                             //сколько прошло времени с последнего действия?
                            //если больше интервала, то что там дальше? вперёд!
    if ((millis()-lastTime3)>= interval3)
    {
    angle3+=2;                //угол++
    servo3.write(angle3);    //серва встань в позицию
    lastTime3= millis();    //счетчик времени обновись
    }
  }
  else
  {
    s3 = false;
    if ((millis()-lastTime3)>= interval3)
    {
    angle3-=2;               //угол-
    servo3.write(angle3);   //серва встань в позицию
    lastTime3=millis();    //счетчик времени обновись
    }
    if  (angle3 < 90-valA3)        //до 180
    {
       s3 = true;
    }
  }
}

void backward() {

}

void left() {

}

void right() {

}

void stops() {
  angle1 = 90;
  angle2 = 65;
  angle3 = 90;
}
