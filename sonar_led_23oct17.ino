
/*Matériel utilisé : Arduino UNO + HC-SR04 + Led
Principe : l'écho des objets détectés est rendu par l'allumage 
d'une led jaune ou rouge selon la distance 
https://www.carnetdumaker.net/articles/mesurer-une-distance-avec-un-capteur-ultrason-hc-sr04-et-une-carte-arduino-genuino/
*/

const int L1J=4; //broche 4 se nomme L1J pour led jaune
const int L2R=3;//broche 3 se nomme L2R pour led rouge

/* Constantes pour les broches */
const byte TRIGGER_PIN =10; // Broche TRIGGER en D10
const byte ECHO_PIN =11;    // Broche ECHO en D11
 
/* Constantes pour le timeout 
Le timeout correspond au temps nécessaire avant de considérer qu'il n'y a pas d'obstacle, donc pas de mesure possible.
J'ai choisi d'utiliser une timeout de 25 millisecondes (4 mètres aller-retour à 340m/s). */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;



void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
Serial.println("hello  world");
pinMode (L1J, OUTPUT); //4 est une broche de sortie
pinMode (L2R, OUTPUT); //3 est une broche de sortie
 
digitalWrite (L1J, HIGH);
delay(500);
digitalWrite (L2R, HIGH);
delay(500);
digitalWrite (L1J, LOW);
delay(500);
digitalWrite (L2R, LOW);

  /* Initialise les broches met la broche TRIGGER du capteur en sortie et à LOW, 
  et met la broche ECHO du capteur en entrée*/
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);


}


void loop() {
  // put your main code here, to run repeatedly:

/*delay(500);
digitalWrite (L1J, HIGH);
delay(500);
digitalWrite (L2R, HIGH);
delay(500);
digitalWrite (L1J, LOW);
delay(500);
digitalWrite (L2R, LOW);
*/

/* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  float distance_mm = measure / 2.0 * SOUND_SPEED;
   
  /* Affiche les résultats en mm, cm et m */
  Serial.print("Distance: ");
  Serial.print(distance_mm);
  Serial.print("mm (");
  Serial.print(distance_mm / 10.0, 2);
  Serial.print("cm, ");
  Serial.print(distance_mm / 1000.0, 2);
  Serial.println("m)");

   if(distance_mm<500)
   {digitalWrite (L2R, HIGH);} //on allume led rouge si l'objet est à moins de 50cm
   if(distance_mm>500&&distance_mm<1000)
   {digitalWrite (L1J, HIGH);} //on allume led jaune si l'objet est entre 50 et 100cm

  /* Délai d'attente pour éviter d'afficher trop de résultats à la seconde */
  delay(500);
digitalWrite (L1J, LOW);
digitalWrite (L2R, LOW);
}   

