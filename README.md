# T4_embebidos2

En el main solo se configura el systick por interrupciones y se establecen las
estructuras del tiempo y la alarma que se setean con su respectivo seter.

Se configuro el systick para trabajar a 10 mS por lo que para lograr la
frecuencia base del reloj (1 segundo) se tiene un contador local en el handler
del systick que cuenta hasta 100 (100 * 10mS = 1 seg).

Cuando se logra 1 segundo usando el contador se llama una funcion de incremente el 
tiempo en 1 segundo, donde si se logran 60 segundos los segundos se regresan a 0 y se
llama incrementar el tiempo en 1 minuto.

Similar que en el caso anterior al incrementar 1 minuto si esta llega a 60 se iguala a
0 y se llama incrementar el tiempo en 1 hora. 


