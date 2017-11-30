const int L1V=13; //broche 13 se nomme L1V pour led verte
const int L2R=12;//broche 12 se nomme L2R pour led rouge
const int L3B=11; //broche 11 se nomme L3B pour led blanche


const int valeurA0 = A0;  //sortie VRX haut bas du joystick sur A0
const int valeurA1= A1 ; // sortie VRY gauche droite du joystick sur A1
const int valeurA2 = A2; //sortie SW poussoir du joystick sur A2
int lecture1 ;
int lecture2 ;
int lecture3;
int seuilA = 150 ;
int seuilB =800 ;
 
void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
Serial.println("hello  world");
pinMode (L1V, OUTPUT); //13 est une broche de sortie
pinMode (L2R, OUTPUT); //12 est une broche de sortie
pinMode (L3B, OUTPUT); //11 est une broche de sortie

}

void loop() {
  // put your main code here, to run repeatedly:
lecture1 = analogRead(A0);
lecture2 = analogRead(A1);
lecture3 = analogRead(A2);
 
Serial.print("seuilA pour valeur:");
Serial.println(seuilA);
 
Serial.print("A0 a pour valeur:");
Serial.println(analogRead(A0));
 
Serial.print("lecture1 a pour valeur:");
Serial.println(lecture1);
 
Serial.print("A1 a pour valeur:");
Serial.println(analogRead(A1));
 
Serial.print("lecture2 a pour valeur:");
Serial.println(lecture2);

Serial.print("A2 a pour valeur:");
Serial.println(analogRead(A2));
 
Serial.print("lecture3 a pour valeur:");
Serial.println(lecture3);

 if (lecture1< seuilA || lecture1 > seuilB) //pour allumer la led verte quand le joystick est en bas valeur haute, ou en  haut, valeur basse
{
    digitalWrite(L1V, HIGH);
}
else
 {
    digitalWrite(L1V, LOW);
 }
 
if(lecture2 < seuilA || lecture2 > seuilB)//pour allumer la led rouge quand le joystick est à gauche valeur haute, ou à droite, valeur basse

{
   digitalWrite(L2R, HIGH);
}
else
  {
    digitalWrite(L2R, LOW);
  }
  if(lecture3 < seuilA) //pour allumer la led blanche quend on appuie sur le joystick
{
    digitalWrite(L3B, HIGH);
}
else
 {
    digitalWrite(L3B, LOW);
 }
 

}
