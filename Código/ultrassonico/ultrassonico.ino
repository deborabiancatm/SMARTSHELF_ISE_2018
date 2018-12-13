//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: FILIPEFLOP
 
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5

#define pino_trigger2 6
#define pino_echo2 7
 
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
Ultrasonic ultrasonic2(pino_trigger2, pino_echo2);
  
void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, cmMsec2;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  long microsec2 = ultrasonic2.timing();
  cmMsec2 = ultrasonic2.convert(microsec2, Ultrasonic::CM);

  
  //Exibe informacoes no serial monitor
  Serial.print("1 - Distancia em cm: ");
  Serial.println(cmMsec);

  Serial.print("2 - Distancia em cm: ");
  Serial.println(cmMsec2);
  Serial.print("\n");
  delay(1000);
}
