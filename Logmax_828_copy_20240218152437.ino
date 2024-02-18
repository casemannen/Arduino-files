/////////////////////  SETTINGS  /////////////////////////////////////////////////////////
//////////////////////  OUTPUT  //////////////////////////////////////////////////////////
//int knifeOFF   = 2;
int knifeON      = 30;    //201-ON  200-OFF
int rollersON    = 22;    //202
int bodyUP       = 24;    //203
int bodyDOWN     = 26;    //204
int slowFORWARD  = 38;    //206 
int slowREVERSE  = 40;    //207
int fastFORWARD  = 42;    //208
int fastREVERSE  = 48;    //209
int highpressure = 46;    //210
int LED          = 32;    //211 ANVÄNDS EJ UTGÅNG 44 är kass
int treecounter  = 50;    //300
int lowerknifeON = 52;    //301
//int sawOFF = 28;
int sawON        = 28;    //303-ON 302-OFF


////////////////////////  INPUT  /////////////////////////////////////////////////////////
// EARTH = ACTIVE
int treesucceded1       = 2;
int treesucceded2        = 3;
int treesucceded3        = 4;
int treesucceded4        = 5;
int treebutton1         = 23;
int treebutton2         = 25;
int treebutton3         = 27;
int treebutton4         = 29;
int slowFORWARDbutton   = 31;
int slowREVERSEbutton   = 33;
int fastFORWARDbutton   = 35;
int fastREVERSEbutton   = 37;    
int rollersONbutton     = 39;
int bodybutton         = 41;
int lowerknifeONbutton  = 43;
int knifebutton         = 45;         
int sawbutton           = 47;         
int upperbutton         = 49;
int lowerbutton         = 51;
int sawHOME             = 53;

////////////////////////  NAMES  /////////////////////////////////////////////////////////
int treesucceded1status       = 0;
int treesucceded2status       = 0;
int treesucceded3status       = 0;
int treesucceded4status       = 0;
int tree1status         = 0;
int tree2status         = 0;
int tree3status         = 0;
int tree4status         = 0;
int slowFORWARDstatus   = 0;         
int slowREVERSEstatus   = 0;
int fastFORWARDstatus   = 0;
int fastREVERSEstatus   = 0;    
int rollersONstatus     = 0;
int bodystatus          = 0;
int lowerknifeONstatus  = 0;
int knifestatus         = 0;         
int sawstatus           = 0;         
int upperstatus         = 0;
int lowerstatus         = 0;
int sawHOMEstatus             = 0;
int pressure  = 0;

int oldupperstatus = 0;
int oldlowerstatus = 0;
int oldrollersONstatus = 0;
int oldbodystatus = 0;
int oldlowerknifeONstatus = 0;
int oldknifestatus = 0;
int oldsawstatus = 0;

int program = 0;
int statusbody = 0;
int statusrollers = 0;
int statusknife = 0;
int statuslowerknife = 0;
unsigned long time;
unsigned long endlesstimer;
int off = 10000;
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
///////////////////// INPUTS AND OUTPUTS //////////////////////////////////////////////////
pinMode (22, OUTPUT);
pinMode (24, OUTPUT);
pinMode (26, OUTPUT);
pinMode (28, OUTPUT);
pinMode (30, OUTPUT);
pinMode (38, OUTPUT);
pinMode (40, OUTPUT);
pinMode (42, OUTPUT);
pinMode (44, OUTPUT);
pinMode (46, OUTPUT);
pinMode (48, OUTPUT);
pinMode (50, OUTPUT);
pinMode (52, OUTPUT);

pinMode (2, INPUT_PULLUP);
pinMode (3, INPUT_PULLUP);
pinMode (4, INPUT_PULLUP);
pinMode (5, INPUT_PULLUP);
pinMode (23, INPUT_PULLUP);
pinMode (25, INPUT_PULLUP);
pinMode (27, INPUT_PULLUP);
pinMode (29, INPUT_PULLUP);
pinMode (31, INPUT_PULLUP);
pinMode (33, INPUT_PULLUP);
pinMode (35, INPUT_PULLUP);
pinMode (37, INPUT_PULLUP);
pinMode (39, INPUT_PULLUP);
pinMode (41, INPUT_PULLUP);
pinMode (43, INPUT_PULLUP);
pinMode (45, INPUT_PULLUP);
pinMode (47, INPUT_PULLUP);
pinMode (49, INPUT_PULLUP);
pinMode (51, INPUT_PULLUP);
pinMode (53, INPUT_PULLUP);






Serial.begin (9600);
delay(500);

}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
delay(50);
time++;
endlesstimer++;

////////////////////  READ INPUTS  ///////////////////////////////////////////////////////
upperstatus       = digitalRead(upperbutton);
lowerstatus       = digitalRead(lowerbutton);
tree1status       = digitalRead(treebutton1);
tree2status       = digitalRead(treebutton2);
tree3status       = digitalRead(treebutton3);
tree4status       = digitalRead(treebutton4);
treesucceded1status     = digitalRead(treesucceded1);
treesucceded2status     = digitalRead(treesucceded2);
treesucceded3status     = digitalRead(treesucceded3);
treesucceded4status     = digitalRead(treesucceded4);
rollersONstatus   = digitalRead(rollersONbutton);
bodystatus= digitalRead(bodybutton);
lowerknifeONstatus = digitalRead(lowerknifeONbutton);
knifestatus      = digitalRead(knifebutton);   
sawstatus = digitalRead(sawbutton);
sawHOMEstatus           = digitalRead(sawHOME);
fastREVERSEstatus = digitalRead(fastREVERSEbutton);
fastFORWARDstatus = digitalRead(fastFORWARDbutton);
slowREVERSEstatus = digitalRead(slowREVERSEbutton);
slowFORWARDstatus = digitalRead(slowFORWARDbutton);

Serial.print(program);
Serial.print(upperstatus);
Serial.print(lowerstatus);
Serial.print(tree1status);
Serial.print(tree2status);
Serial.print(tree3status);
Serial.print(tree4status);
Serial.print(treesucceded1status);
Serial.print(treesucceded2status);
Serial.print(treesucceded3status);
Serial.print(";");
Serial.print(treesucceded4status);
Serial.print(slowFORWARDstatus);
Serial.print(lowerknifeONstatus);
Serial.print(slowREVERSEstatus);
Serial.print(fastFORWARDstatus);
Serial.print(sawHOMEstatus);
Serial.print(fastREVERSEstatus);
Serial.print(knifestatus);
Serial.print(bodystatus);
Serial.print(statusbody);

Serial.print(sawstatus);
Serial.print(pressure);
Serial.print(rollersONstatus);
Serial.print(statusknife);
Serial.print(" time=");
Serial.print(time);
Serial.print(" endlesstimer=");
Serial.println(endlesstimer);
//Serial.println("       MADE BY TK TEKNIK TVING_SWEDEN");

if ((time < 50) || (endlesstimer <50)){digitalWrite(highpressure,HIGH);
pressure = 1;}
if ((time > 100) && (endlesstimer > 2000)){digitalWrite(highpressure,LOW);
pressure = 0;}

checkrollers();


////////////////////////////////////////////////////////////////////////////////////////
////////////  UPPER BUTTON JOYSTICK //////////////////////////////////////////////////// KLAR
if ((upperstatus == LOW) && (oldupperstatus == HIGH)) {
  if (program > 3) {  program = 3;}       // Max program på övre knappen
  program--;

 if (program < 1) {  program = 1;}      // Min program på övre knappen

    if (program == 1){
      programraise();
    }
    if (program == 2){
      programopen();
    }
}

/////////////  LOWER BUTTON JOYSTICK //////////////////////////////////////////////////// KLAR
if ((lowerstatus == LOW) && (oldlowerstatus == HIGH)) {
 
  if(program < 2)  { program =2;}          // Min program på nedre knappen
   program++;
  if(program > 5)  { program =5;}          // Max program på nedre knappen
    if (program == 3){
      programknifeON();
     }
    if (program == 4){
      programlowerknifeON();
    }
    if (program == 5){
      programrollersON();
    }
}


///////////////  ROLLERS BUTTON  /////////////////////////////////////////////////////// KLAR
if ((rollersONstatus == LOW) && (oldrollersONstatus == HIGH))  {
  if (statusrollers == 0){ programrollersON(); }
  else if (statusrollers == 1) { programrollersOFF(); }  
}

/////////////////  BODY BUTTON  ///////////////////////////////////////////////////////// KLAR
if ((bodystatus == LOW) && (oldbodystatus == HIGH))  { 

  if (statusbody == 0){ programraise(); }
  else if (statusbody == 1) { programdown(); }
  else if (statusbody == 2) { programdown(); }    
}

///////////////  LOWER KNIFE BUTTON  //////////////////////////////////////////////////// KLAR
if ((lowerknifeONstatus == LOW) && (oldlowerknifeONstatus == HIGH))  { 
 if (statuslowerknife == 0){ programlowerknifeON(); }
  else if (statuslowerknife == 1) { programlowerknifeOFF(); }  
}

///////////////  KNIFE BUTTON  ///////////////////////////////////////////////////////// KLAR
if ((knifestatus == LOW) && (oldknifestatus == HIGH))  { 
  if (statusknife  == 0){
  programknifeON();
  }
  else if (statusknife  == 1){
  programknifeOFF();
  }
}

//////////////  SAW BUTTON  /////////////////////////////////////////////////////////// KLAR
if ((sawstatus == LOW)&& (oldsawstatus == HIGH))  {
  digitalWrite(sawON,HIGH);
  programfloat();
  time = 0;
  endlesstimer = off;
}
if ((sawstatus == HIGH)&& (oldsawstatus == LOW))  {
  digitalWrite(sawON,LOW);
  time = 0;
}

////////////// RENEW OLD STATUS  /////////////////////////////////////////////////////// KLAR
 oldupperstatus = upperstatus;
 oldlowerstatus = lowerstatus;
 oldrollersONstatus = rollersONstatus;
 oldsawstatus = sawstatus;
 oldknifestatus = knifestatus;
 oldlowerknifeONstatus = lowerknifeONstatus;
 oldbodystatus = bodystatus;
}
///////////////////////////////////////////////////////////////////////// THE END OF LOOP //////////////////////////////////////////////////////////////////////////////////////////
///////////////////// PROGRAMS  //////////////////////////////////////////////////////////
void programfloat(){
  digitalWrite(bodyUP,LOW);
  digitalWrite(bodyDOWN,LOW);
  statusbody = 2;
  time = 0;
  endlesstimer = off;
}
//////////////////////////////////////////////////////////////////////////////////////////
void programdown(){
  digitalWrite(bodyUP,LOW);
  digitalWrite(bodyDOWN,HIGH);
  statusbody = 0;
  time = 0;
  endlesstimer = off;
}
///////////////////////////////////////////////////////////////////////////////////////////
void programraise(){
  digitalWrite(bodyUP,HIGH);
  digitalWrite(bodyDOWN,LOW);
  statusbody = 1;
  time = 0;
  endlesstimer = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
void programopen(){
  programknifeOFF();
  programlowerknifeOFF();
  programrollersOFF();
  time = 0;
  endlesstimer = off;
  }
////////////////////////////////////////////////////////////////////////////////////////////
void programrollersON(){
  digitalWrite(rollersON,HIGH);
  statusrollers = 1;
  time = 0;
  endlesstimer = off;
}
void programrollersOFF(){
  digitalWrite(rollersON,LOW);
  statusrollers = 0;
  time = 0;
  endlesstimer = off;
}
/////////////////////////////////////////////////////////////////////////////////////////////
void programlowerknifeON(){
  digitalWrite(lowerknifeON,HIGH);
  statuslowerknife = 1;
  time = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////
void programlowerknifeOFF(){
  digitalWrite(lowerknifeON,LOW);
  statuslowerknife = 0;
  time = 0;
  endlesstimer = off;
}
/////////////////////////////////////////////////////////////////////////////////////////////
void programknifeON(){
  digitalWrite(knifeON,HIGH);
  statusknife = 1;
  time = 0;
  endlesstimer = 0;
}
void programknifeOFF(){
  digitalWrite(knifeON,LOW);
  statusknife = 0;
  time = 0;
  endlesstimer = off;
}
//////////////////////////////////////////////////////////////////////////////////////////////
void checkrollers(){
if ((tree1status == LOW)&&(treesucceded1status == HIGH)&&(sawHOMEstatus == LOW)){
    digitalWrite(fastFORWARD,HIGH);
    time = 0;
    endlesstimer = off;
}
else if ((tree2status == LOW)&&(treesucceded2status == HIGH)&&(sawHOMEstatus == LOW)){
    digitalWrite(fastFORWARD,HIGH);
    time = 0;
    endlesstimer = off;
}
else if ((tree3status == LOW)&&(treesucceded3status == HIGH)&&(sawHOMEstatus == LOW)){
    digitalWrite(fastFORWARD,HIGH);
    time = 0;
    endlesstimer = off;
}
else if ((tree4status == LOW)&&(treesucceded4status == HIGH)&&(sawHOMEstatus == LOW)){
    digitalWrite(fastFORWARD,HIGH);
    time = 0;
    endlesstimer = off;
}
else if ((fastFORWARDstatus == LOW)&&(sawHOMEstatus == LOW)){
    digitalWrite(fastFORWARD,HIGH);
    time = 0;
    endlesstimer = off;
}
else if ((fastREVERSEstatus == LOW)&&(sawHOMEstatus == LOW)){
    digitalWrite(fastREVERSE,HIGH);
    time = 0;
    endlesstimer = off;
}
else if ((slowFORWARDstatus == LOW)&&(sawHOMEstatus == LOW)){
    digitalWrite(slowFORWARD,HIGH);
    time = 0;
    endlesstimer = off;
}
else if ((slowREVERSEstatus == LOW)&&(sawHOMEstatus == LOW)){
    digitalWrite(slowREVERSE,HIGH);
    time = 0;
    endlesstimer = off;
}
else{ digitalWrite(fastFORWARD,LOW);
      digitalWrite(fastREVERSE,LOW);
      digitalWrite(slowFORWARD,LOW);
      digitalWrite(slowREVERSE,LOW);
      }


}           ///////////////////////////THE END/////////////////////////////////////
