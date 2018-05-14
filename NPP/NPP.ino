 #include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
int rodstatus = 20;
int uranium = 100;
int heat = 17; 
int temp = 17;
int reaction = 0;
int rs = 1;
int rodmaterial = 1;
int cooldown = 1;
  int canoff = 44;
  String k;

void setup() {
  // put your setup code here, to run once:
  pinMode(52,INPUT_PULLUP);
  pinMode(53,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
lcd.begin(20,4);
  lcd.home();
lcd.print("Chernobyl sim)");
lcd.setCursor(0,1);
lcd.print("Version 0.8 SIALPHA");
lcd.setCursor(0,2);
lcd.print("GLORY TO USSR!!!!");
delay(1000);
pinMode(43,OUTPUT);
pinMode(44,OUTPUT);
pinMode(45,OUTPUT);
pinMode(46,OUTPUT);
pinMode(47,OUTPUT);
pinMode(48,OUTPUT);
pinMode(49,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 lcd.home();
 lcd.clear();
  int kn1 = digitalRead(52);
  if(kn1 == 0){
    delay(10);
    kn1 = digitalRead(52);
    if(kn1 == 0){
      if(rodstatus<42){
      rodstatus++;}
     
    }
  }
  kn1 = digitalRead(53);
  if(kn1 == 0){
    delay(10);
    kn1 = digitalRead(53);
    if(kn1 == 0){
      if(rodstatus>0){
      rodstatus = rodstatus-1;}
     
    }
  }
  lcd.print("Temperature:");
  lcd.print(heat);
  lcd.print("\x99""C");
  lcd.setCursor(0,1);
  lcd.print("Rod status:");
  lcd.print(rodstatus);
  lcd.print("'pos.");
  lcd.setCursor(0,2);
  lcd.print("DEB.");
  lcd.print(temp);
  lcd.print("HE,");
   lcd.print(rs);
  lcd.print(" OA, K ");
  lcd.print(k);
  lcd.setCursor(0,3);
  lcd.print(canoff);
  lcd.print(" CO,");
  lcd.print(reaction);
    lcd.print("REAC,CD-");
  lcd.print(cooldown);
  delay(100);
  //math shit,do something with it
    int kn2 = digitalRead(12);
  if(kn2 == 0){
    delay(10);
    kn2 = digitalRead(12);
    if(kn2 == 0){
      if(reaction == 0 && cooldown == 1){
       heat = 28;
      reaction = 1;
      delay(100);
      cooldown = 0;
      lcd.setCursor(0,2);
      lcd.print("REACTOR LAUNCHING");
      digitalWrite(43,HIGH);
      delay(1000);
      lcd.clear();}
     if(reaction == 1 && canoff == 1){
      reaction = 0;
      delay(500);
      cooldown = 1;
      digitalWrite(43,LOW);
     delay(100);
     canoff = 0;}
    }
  }
  if(heat<=0){
    heat = 0;}
if(heat<150 && heat>75){
    rs = 2;}
    else 
    if(heat<900 && heat>150){ 
      rs = 3;}
      else  
      if(heat<1900 && heat>900){
        rs = 4;}
        else 
        if (heat<3000 && heat>1900){ 
          rs = 5;}
          else 
          if(heat<4500 && heat>3000){ 
            rs = 6;}
            else 
            if(heat>4500){ 
              //MELTDOWN WARNING AND EXEC.
              //melt rods
              lcd.clear();
              lcd.setCursor(0,0);
lcd.print("Just because of you");
lcd.setCursor(0,1);
lcd.print("Your NPP has blown. You");
lcd.setCursor(0,2);
lcd.print("With GLEB AND VITEK WERE");
lcd.setCursor(0,3);
lcd.print("FIRED. GLORY TO KGB!");
delay(999999999999999999999);  
              
            }
         
  //reaction datum.
  if(reaction == 1){
    if( canoff != 1){
    delay(100);
    canoff = 1;
    }temp = heat;
heat = temp+(16*rs)-rodstatus*2.4;
if(heat<0){
rs=1;}
int nn = heat;
delay(10);
int ne = heat;
if(nn>ne){
  k="<1";
}
if(nn<ne){
k=">1";}
}
if (rs == 1){
digitalWrite(44,HIGH);
 digitalWrite(46,LOW);
  digitalWrite(45,LOW);
  digitalWrite(47,LOW);
  digitalWrite(48,LOW);
  digitalWrite(49,LOW);}
else if (rs == 2){
  digitalWrite(45,HIGH);
  digitalWrite(44,HIGH);
   digitalWrite(46,LOW);
  digitalWrite(47,LOW);
  digitalWrite(48,LOW);
  digitalWrite(49,LOW);
}
else if(rs == 3){
  digitalWrite(46,HIGH);
  digitalWrite(45,HIGH);
  digitalWrite(44,HIGH);
  digitalWrite(47,LOW);
  digitalWrite(48,LOW);
  digitalWrite(49,LOW);
}
else if(rs == 4){
    digitalWrite(46,HIGH);
  digitalWrite(45,HIGH);
  digitalWrite(44,HIGH);
  digitalWrite(47,HIGH);
  digitalWrite(48,LOW);
  digitalWrite(49,LOW);
}
else if(rs== 5){
      digitalWrite(46,HIGH);
  digitalWrite(45,HIGH);
  digitalWrite(44,HIGH);
  digitalWrite(47,HIGH);
  digitalWrite(48,HIGH);
   digitalWrite(46,LOW);
  digitalWrite(49,LOW);

}
else if(rs==6){
  
 digitalWrite(46,HIGH);
  digitalWrite(45,HIGH);
  digitalWrite(44,HIGH);
  digitalWrite(47,HIGH);
  digitalWrite(48,HIGH);
  digitalWrite(49,HIGH);
}}








  
  /*if(reaction == 1 && canoff == 44){
    lcd.clear();
    lcd.setCursor(0,3);
    lcd.print("Kalibrovka...");
    delay(5000);
          canoff = 1;
  }
     neuttemp = neutrons;
  //temp shit
  if(reaction == 1){
    rs = heat;
    heat = rs;
    heat = heat+(neuttemp/5)-(1,1*rodstatus);
    if(neutrons == 0){
      neutrons = 1;
    }
    
  }
  //Neut thingy,something to improve
  if(reaction == 1){
          if(neutrons == 0){
      neutrons = 1;
    }
    if(neutrons>5000){
      neutrons = 5000;
    }
    if(rs<heat || rs == heat){
    neutrons = neuttemp;
    neutrons = neutrons*2-(rodstatus*50);}
    if(rs>heat){
      neutrons = neutrons*0,75 - (rodstatus*50);
    }
  }
  if(heat < 25 && cooldown == 0){
    heat = 25;
  }
  if(heat<25 && reaction == 0 && cooldown == 1){
    heat = 55;
    delay(100);
    heat = 40;
    delay(100);
    heat = 27;
  }
}*/
