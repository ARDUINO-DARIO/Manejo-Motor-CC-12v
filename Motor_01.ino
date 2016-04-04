int IN3 = 5;    // Input3 conectada al pin 5
int IN4 = 4;    // Input4 conectada al pin 4
int ENB = 3;    // ENB conectada al pin 3 de Arduino
int var;
void setup()
{
   pinMode (ENB, OUTPUT);
   pinMode (IN3, OUTPUT);
   pinMode (IN4, OUTPUT);
   pinMode ( 13, OUTPUT ) ;     // se habilita para encender el led de la placa arduino
 
   Serial.begin(9600) ;               // Inicializa el Puerto serie
}

void loop()
{
  //Preparamos la salida para que el motor gire en un sentido
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
 
  char c = ' ' ;
  String mensaje ="" ;
 
  if (Serial.available())
    {  String s = GetLine();
       int i = s.toInt() ;          //Como esperamos un número, convertimos el texto a numero
       
       if (i == 1)
                       
         {
          digitalWrite (IN3, LOW);
          digitalWrite (IN4, HIGH);
 
           
         Serial.println(String(s) + "Subiendo.");
         digitalWrite( 13 ,  HIGH) ;
         analogWrite(ENB,255);    //si cambiamos el valor entre 0-255 varia la velocidadr
         delay(3000);
         analogWrite(ENB,0);
         Serial.println(String(s) + " Stoop.");
         digitalWrite( 13 ,  LOW) ;
         }
       
       if (i == 2)
         {
          digitalWrite (IN4, LOW);
          digitalWrite (IN3, HIGH);
                     
         Serial.println(String(s) + "Bajando.");
         digitalWrite( 13 ,  HIGH) ;
         analogWrite(ENB,255);
         delay(3000);
         analogWrite(ENB,0);
         Serial.println(String(s) + " Stoop.");
         digitalWrite( 13 ,  LOW) ;
        
         }
     }
}
 
String GetLine()
{  String S = "" ;
  if (Serial.available())
      {
        char c = Serial.read(); ;
        while ( c != '\n')
            {   S = S + c ;
                delay(25) ;
                c = Serial.read();
            }
         return(S) ;
      }
}
