# sockets-suma
proyecto para la materia protocolos de comunicación

### instrucciones
Utilizando el lenguaje C para Linux, implemente un cliente UDP (SOCK_DGRAM) que envíe cuatro números enteros (N1, N2, N3 y N4) cualesquiera a un servidor (uno a la vez), el servidor realizará la suma del primer y cuarto número recibido, el resultado obtenido se multiplicará por el segundo número y finalmente se le restará el tercer número enviado, si el resultado final es mayor de 500, el servidor mandará un mensaje al cliente indicando que los datos son correctos, en caso contario mandará un mensaje de datos incorrectos y pedirá al cliente que vuelva a mandar cuatro números, esto se repetirá hasta que el resultado obtenido de las operaciones sea mayor de 500.