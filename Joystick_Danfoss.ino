/*


Danfoss valve with 5v joystick
Can be used with forest wagon
Delevoped by Tobias Karlsson Tving, SWEDEN





*/
///////////////////// INSTÄLLNINGAR //////////////////////////////////////////////////////
int valveX = 6;             // pin utgång (pwm) ventil 1
int valveY = 3;             // pin utgång (pwm) ventil 2
int powerX = 7;              // pin utgång power ventil 1
int powerY = 8;              // pin utgång power ventil 2
int upperbutton = 5;        // pin utgång 3dje funktion
int lowerbutton = 4;         // pin utgång 4de funktion

int startlow = 123;           // PWM startström -
int slutlow = 80;              // PWM slutström -
int starthigh = 129;           // PWM startström +
int sluthigh = 175;            // PWM slutström + (191 flytläge)
int deadbandlow = 450;      // dödbandets lägre gräns
int deadbandhigh = 560;     // dödbandets övre gräns
int safetymin = 50;         // error min XYZ-axel
int safetymax = 970;       // error max XYZ-axel
int loopfrekvens = 100;       // tid i ms som en loop tar
  int PWMX;
  int PWMY;

void setup() {
///////////////////// IN OCH UTGÅNGAR //////////////////////////////////////////////////////
pinMode (A2, INPUT);             // pin ingång X
pinMode (A1, INPUT);             // pin ingång Y
pinMode (A0, INPUT);             // pin ingång Z
pinMode (valveX, OUTPUT);
pinMode (valveY, OUTPUT);
pinMode (upperbutton, OUTPUT);
pinMode (lowerbutton, OUTPUT);
pinMode (powerX, OUTPUT);
pinMode (powerY, OUTPUT);

Serial.begin (9600);
delay(500);
}

void loop() {
/////////////////////////////////////////////////////////////////////////////////////////////
//////////////////// LOOPEN  ////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
  int Xvalue = analogRead (A2);    // läsa X-axeln
  int Yvalue = analogRead (A1);     // läsa Y-axeln
  int Zvalue = analogRead (A0);     // läsa Z-axeln



  //////////////////////////////////////

  Serial.print("X=");
Serial.print(Xvalue);
Serial.print("\t");
Serial.print("Y=");
Serial.print(Yvalue);
Serial.print("\t");
Serial.print("Z=");
Serial.print(Zvalue);
Serial.print("\t");
Serial.print("  pwmX=");
Serial.print(PWMX);
Serial.print("\t");
Serial.print("  pwmY=");
Serial.print(PWMY);
Serial.print("\t");
///////// Här kollas X-värdet
if((Xvalue >= deadbandhigh)&& (Xvalue <= safetymax)){
   PWMX = map (Xvalue,deadbandhigh,safetymax, startlow, slutlow);
   digitalWrite (powerX, HIGH);
   //Serial.print("valveX-ON");
  // Serial.print("\t");
   Serial.print("X-Right");}            // aktivera ventil
        
else if((Xvalue <= deadbandlow)&& (Xvalue >= safetymin)){
   PWMX = map (Xvalue, deadbandlow, safetymin, starthigh, sluthigh);
   digitalWrite (powerX, HIGH);
   //Serial.print("valveX-ON");
   //Serial.print("\t");
   Serial.print("X-Left");}

else {PWMX = 0;

//Serial.print("valveX-OFF");
//Serial.print("\t");
Serial.print("X-Neutral"); }       // säkerhetsställa 0 flöde
          

Serial.print("\t");

//////// Här kollas Y-värdet
if((Yvalue >= deadbandhigh)&& (Yvalue <= safetymax)){
   PWMY = map (Yvalue,deadbandhigh,safetymax, startlow, slutlow);
   digitalWrite (powerY, HIGH);
   //Serial.print("valveY-ON");
   //Serial.print("\t");
   Serial.print("Y-Down");}

else if((Yvalue <= deadbandlow)&& (Yvalue >= safetymin)){ 
   PWMY = map (Yvalue, deadbandlow, safetymin, starthigh, sluthigh);
   digitalWrite (powerY, HIGH);
   //Serial.print("valveY-ON");
   //Serial.print("\t");
   Serial.print("Y-Up");}

    
else {PWMY = 0;
//Serial.print("valveY-OFF");
//Serial.print("\t");
Serial.print("Y-Neutral");   }            // säkerhetställa 0 flöde
        
Serial.print("\t");
//////// Här kolas Z-värdet
if((Zvalue >= 700)&& (Zvalue <= safetymax)){
        digitalWrite (upperbutton, HIGH);     // utgång för 3dje funktion
        Serial.print("button-down");}


else if((Zvalue <= 300)&& (Zvalue >= safetymin)){
        digitalWrite (lowerbutton, HIGH);     // utgång för 4de funktion
        Serial.print("button-up");}

else {digitalWrite (lowerbutton, LOW);
      digitalWrite (upperbutton, LOW);
Serial.print("button-neutral");}

Serial.print("\t");
Serial.println("delevoped by casemannen");
////////////////////////////////////////////////////////////////////////////////////////////
///////// PWM utgångarna ändras till rätt värde ////////////////////////////////////////////
analogWrite (valveX, PWMX);       // utgång för ventil 1
analogWrite (valveY, PWMY);       // utgång för ventil 2

if(PWMX == 0){
  digitalWrite (powerX, LOW);
  
}

if(PWMY == 0){
 digitalWrite (powerY, LOW);
}

delay(loopfrekvens);
        
///////////////////////////////////////////////////////////////////////////////////////////
////////// DIAGNOSTIK /////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////


/*Serial.print("Settings");
Serial.print(",Loopfrekvens=");
Serial.print(loopfrekvens);
Serial.print(",startlow=");
Serial.print(startlow);
Serial.print(",slutlow=");
Serial.print(slutlow);
Serial.print(",starthigh=");
Serial.print(starthigh);
Serial.print(",sluthigh=");
Serial.print(sluthigh);
Serial.print(",deadbandlow=");
Serial.print(deadbandlow);
Serial.print(",deadbandhigh=");
Serial.print(deadbandhigh);
Serial.print(",safetymin=");
Serial.print(safetymin);
Serial.print(",safetymax=");
Serial.print(safetymax);
Serial.print("\t");
Serial.println("Danfoss valve with 5v joystick delevoped by Tobias Karlsson Tving, SWEDEN");
*/
}
