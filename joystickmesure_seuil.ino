const int L1 = 13; //broche 13 digitale se nomme L1

 
const int valeurA0 = A0;
const int valeurA1= A1 ;
const int valeurA2 = A2;
int lecture1 ;
int lecture2 ;
int lecture3;
int seuilA = 10 ;
 
void setup() {
  pinMode(L1, OUTPUT); //13 est une broche de sortie
  
 
  Serial.begin(9600);// active la liaison série
  Serial.println("Hello world !"); // Nous émettons un message :
}
 
void loop() {
 
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


 delay(1000);



 
}
