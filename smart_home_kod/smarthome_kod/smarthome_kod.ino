#include <Servo.h>
#include <DallasTemperature.h>
#include <OneWire.h>
int tx=1;
int rx=0;
char inSerial[30];
char buf[100];
Servo ogrzewanie;
Servo brama;
OneWire oneWire(A5); //Podłączenie do A5
DallasTemperature sensors(&oneWire);
void oswietlenie1(){
    digitalWrite(9, HIGH);
}
void oswietlenie2(){
    digitalWrite(9, LOW);
}
void oswietlenie3(){
    digitalWrite(10, HIGH);
}
void oswietlenie4(){
    digitalWrite(10, LOW);
}
void oswietlenie5(){
    digitalWrite(11, HIGH);
}
void oswietlenie6(){
    digitalWrite(11, LOW);
}
void wentylacja1(){
  digitalWrite(12, HIGH);
}
void wentylacja2(){
  digitalWrite(12, LOW);
}
void wentylacja3(){
  digitalWrite(13, HIGH);
}
void wentylacja4(){
  digitalWrite(13, LOW);
}
void ogrzewanie0(){
   ogrzewanie.write(180); 
    delay(1000);  
}
void ogrzewanie1(){
   ogrzewanie.write(135); 
    delay(1000);  
}
void ogrzewanie2(){
   ogrzewanie.write(90); 
    delay(1000);  
}
void ogrzewanie3(){
   ogrzewanie.write(45); 
    delay(1000);  
}
void ogrzewanie4(){
   ogrzewanie.write(0); 
    delay(1000);  
}
void brama1(){
  brama.write(90); 
  delay(500); 
}
void brama2(){
  brama.write(0); 
  delay(500); 
}
void fontanna1(){
  digitalWrite(8, HIGH);
}
void fontanna2(){
  digitalWrite(8, LOW);
}

void setup(){
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  brama.attach(6);
  ogrzewanie.attach(7);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  sensors.begin();
}

void loop(){
    int i=0;
    int m=0;
    int p=0;
    int r=0;
    delay(500);                                         
    if (Serial.available() > 0) {             
       while (Serial.available() > 0) {
         inSerial[i]=Serial.read();
         i++;      
       }
       inSerial[i]='\0';
    
     String komenda=inSerial;
     komenda.toCharArray(buf, 60);
     Check(buf);
     }  
   
  sensors.requestTemperatures(); 
  Serial.println(sensors.getTempCByIndex(0));  
  delay(500);
}
void Check(char inStr[]){   
  int i=0;
  int m=0;
  int a=-1;
  String odebrana=inStr;
  String tablica[19]={"salon on","salon off","kotłownia on","kotłownia off","poddasze on","poddasze off","parter 0","parter 1","poddasze 0","poddasze 1","ogrzewanie 0","ogrzewanie 1","ogrzewanie 2","ogrzewanie 3","ogrzewanie 4","brama on","brama off","fontanna on","fontanna off"};
  for( int j = 0; j < 19; j++ ){
   
   //Serial.println(odebrana);
   /*
   Serial.println("-------");
   Serial.println(tablica[j]);
   Serial.println(sizeof(tablica));
   Serial.println("*****");
   */
   if(odebrana == tablica[j]){
   a=j; 
break;
   }
   }  
   switch(a){
    case 0:
    oswietlenie1();
      for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 1:
    oswietlenie2();
      for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 2:
    oswietlenie3();
     for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 3:
    oswietlenie4();
     for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 4:
    oswietlenie5();
     for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 5:
    oswietlenie6();
     for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 6:
    wentylacja1();
     for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 7:
   wentylacja2();
    for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 8:
   wentylacja3();
    for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 9:
   wentylacja4();
    for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 10:
    ogrzewanie0();
     for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 11:
    ogrzewanie1();
     for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 12:
    ogrzewanie2();
     for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 13:
   ogrzewanie3();
    for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 14:
    ogrzewanie4();
     for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 15:
    brama1();
     for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 16:
    brama2();
     for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 17:
    fontanna1();
     for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case 18:
    fontanna2();
     for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
    case -1:
     for(m=0;m<25;m++){
      inStr[m]=0;
      i=0;
      }
    break;
   }

    for(m=0;m<25;m++){
      inStr[m]=0;
      }
    i=0;

}

  
