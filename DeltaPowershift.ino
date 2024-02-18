
const int UP = 2;
const int DOWN = 3;
const int Y4 = 7;
const int Y6 = 8;
const int LED1 = 4;
const int LED2 = 5;
const int LED3 = 6;
int GEAR = 1;
int upshift ;
int oldupshift ;
int downshift ;
int olddownshift ;


void setup() {
  // put your setup code here, to run once:
pinMode(UP, INPUT);
pinMode(DOWN, INPUT);
pinMode(Y4, OUTPUT);
pinMode(Y6, OUTPUT);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
Serial.begin (9600);

}


void loop() {
  // put your main code here, to run repeatedly:
upshift = digitalRead(UP);
downshift = digitalRead(DOWN);
Serial.print("upshift=");
Serial.print(upshift);
Serial.print("  downshift=");
Serial.print(downshift);

if ((upshift==HIGH) && (oldupshift==LOW)){
  GEAR++;
  if (GEAR>3){GEAR=3;}
}
if ((downshift==HIGH) && (olddownshift==LOW)){
  GEAR--;
  if(GEAR<1){GEAR=1;}
}
if(GEAR==1){gear1();}
if(GEAR==2){gear2();}
if(GEAR==3){gear3();}
oldupshift=upshift;
olddownshift=downshift;
delay(100);
}



void gear1(){
digitalWrite(Y4, HIGH);
digitalWrite(Y6, LOW);
digitalWrite(LED1, HIGH);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
Serial.println("  gear=1");

}

void gear2(){
digitalWrite(Y4, HIGH);
digitalWrite(Y6, HIGH);
digitalWrite(LED1, LOW);
digitalWrite(LED2, HIGH);
digitalWrite(LED3, LOW);
Serial.println("  gear=2");
}

void gear3(){
digitalWrite(Y4, LOW);
digitalWrite(Y6, HIGH);
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
digitalWrite(LED3, HIGH);
Serial.println("  gear=3");
}

