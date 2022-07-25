///////////////////// INSTÄLLNINGAR
int valve1 = 3;             // pin nummer
int valve2 = 5;             // pin nummer
int rotortilt = 4;          // pin nummer
int start = 100;            // PWM startström
int slut = 255;             // PWM slutström
int deadbandlow = 400;      // dödbandets lägre gräns
int deadbandhigh = 600;     // dödbandets övre gräns
int safetymin = 50;         // error min rulle
int safetymax = 1000;       // error max rulle


void setup() {
///////////////////// IN OCH UTGÅNGAR
pinMode (A0, INPUT);
pinMode (A1, INPUT);
pinMode (valve1, OUTPUT);
pinMode (valve2, OUTPUT);
pinMode (rotortilt, OUTPUT);
Serial.begin (9600);
}

void loop() {
//////////////////// LOOPEN
  int rightrullevalue = analogRead (A0);    // läsa höger rulle
  int leftrullevalue = analogRead (A1);     // läsa vänster rulle
  int PWM1;
  
if((rightrullevalue >= deadbandhigh)&& (rightrullevalue <= safetymax)){
   PWM1 = map (rightrullevalue,deadbandhigh,safetymax, start, slut);
        analogWrite (valve1, PWM1);
        analogWrite (valve2, LOW);
        analogWrite(rotortilt, LOW);}

        
else if((rightrullevalue <= deadbandlow)&& (rightrullevalue >= safetymin)){ 
   PWM1 = map (rightrullevalue, safetymin, deadbandlow, slut, start);
        analogWrite (valve2, PWM1);
        analogWrite (valve1, LOW);
        analogWrite(rotortilt, LOW);}

        
else if((leftrullevalue >= deadbandhigh)&& (leftrullevalue <= safetymax)){ 
   PWM1 = map (leftrullevalue,deadbandhigh, safetymax, start, slut);
        analogWrite (valve1, PWM1);
        analogWrite (valve2, LOW);
        analogWrite(rotortilt, HIGH);}

        
else if((leftrullevalue <= deadbandlow)&& (leftrullevalue >= safetymin) ){ 
    PWM1= map (leftrullevalue, safetymin, deadbandlow, slut, start);
        analogWrite (valve2, PWM1);
        analogWrite (valve1, LOW);
        analogWrite(rotortilt, HIGH);}


else {( analogWrite(rotortilt, LOW));
        analogWrite(valve1, LOW);
        analogWrite(valve2, LOW);
        PWM1 = 0;}


    ////////// DIAGNOSTIK 
Serial.print("rightrullevalue=");
Serial.print(rightrullevalue);
Serial.print("  leftrullevalue=");
Serial.print(leftrullevalue);
Serial.print("  pwm=");
Serial.println(PWM1);

}
