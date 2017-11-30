/* 
 * Code d'exemple pour un capteur à ultrasons HC-SR04.
 */

/* Constantes pour les broches */
const byte TRIGGER_PIN = 10; // Broche TRIGGER
const byte ECHO_PIN = 11;    // Broche ECHO
 
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;


const int D3 = 3; //broche 3 du micro-contrôleur se nomme maintenant 
const int D4 = 4; // 


/** Fonction setup() */
void setup() {
   
  /* Initialise le port série */
  Serial.begin(9600);
   
  /* Initialise les broches */
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  
}
 
/** Fonction loop() */
void loop() {
  
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  float distance_mm = measure / 2.0 * SOUND_SPEED;
   
  /* Affiche les résultats en mm, cm et m */
  Serial.print(F("Distance: "));
  Serial.print(distance_mm);
  Serial.print(F("mm ("));
  Serial.print(distance_mm / 10.0, 2);
  Serial.print(F("cm, "));
  Serial.print(distance_mm / 1000.0, 2);
  Serial.println(F("m)"));

 if(distance_mm < 1000 && distance_mm>100 )
  {
        Serial.println("d<1000");
        digitalWrite(D3, HIGH);
        delay(1000);
        digitalWrite(D3, LOW);
        delay(1000);
        digitalWrite(D3, HIGH);

    }

    
   if(distance_mm < 100)
{
          Serial.println("d<100");

  digitalWrite(D3, HIGH);
        delay(100);
        digitalWrite(D3, LOW);
        delay(100);
        digitalWrite(D3, HIGH);
  }
  
 else   
 {
        Serial.println("d>1000");
        
        digitalWrite(D3, LOW);
       

    }
  /* Délai d'attente pour éviter d'afficher trop de résultats à la seconde */
  delay(500);
}
