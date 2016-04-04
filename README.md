# Manejo-Motor-CC-12v
Manejo de motor de corriente continua de 12v con arduino mega 3

Los detalles en esta página:
http://electronilab.co/tutoriales/tutorial-de-uso-driver-dual-l298n-para-motores-dc-y-paso-a-paso-con-arduino/

# Programa

Controla la dirección del motor, mediante la consola. Si envío 1, el motor gira para la derecha, si envío un 2, el motor gira para la izquierda.
En este caso, la velocidad es constante al 100%.  Se puede variar la velocidad modificando el segundo parámetro del comando “analogWrite(ENB,255);”. Por ser de 8 bits, puede variar entre 0 y 255, siendo 255 la máxima velocidad.
