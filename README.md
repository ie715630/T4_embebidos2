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
0 y se llama incrementar el tiempo en 1 hora. Considerando que al llegar a las 24 horas
se reinicie desde 0, lo mismo con los demás valores.

Estas tres funciones tambien están checando si el valor que tienen actualmente es igual que
el de la alarma que se estableció en el main, de ser así ponen la bandera correspondiente
de cada tipo de tiempo en true, en caso contrario cambian a false.

Para la impresión de la hora lo que se hizo fue crear una función que por medio de getters
obtiene los valores en ese instante de las horas, minutos y segundos y los imprime en la
consola. Esta función es llamada cada que en el handler de 10 ms se llega a la cuenta de 
100 ya mencionada que indica que se llegó al segundo. 

Dentro de esta función de impresión se llama a la función que revisa la alarma, esta
lo que hace es revisar que las 3 banderas de cada tipo de tiempo esten en true, y de
ser así, retornará true. En caso de que sea true su retorno entonces la función de
impresión mandará el ALARM. 
