 
                   ____ ____  _____ _           _               
                  / ___| __ )|  ___| | __ _ ___| |__   ___ _ __ 
                 | |  _|  _ \| |_  | |/ _` / __| '_ \ / _ \ '__|
                 | |_| | |_) |  _| | | (_| \__ \ | | |  __/ |   
                  \____|____/|_|   |_|\__,_|___/_| |_|\___|_|   
 

                                INTRODUCCI�N
                                ------------

GBFlasher es el software para el programador USB GBCartFlasher, creado por kraku
y chroost, y continuado y mejorado por David Pello (zako).
Este software permite leer la memoria rom y leer, escribir y borrar la ram de un
cartucho de gameboy original, y leer, escribir y borrar la flash y ram de un
cartucho flasheable de gameboy (modificado o fabricado).

La aplicaci�n est� formada por dos partes, un ejecutable de linea de comandos,
(gbcf), escrito en C++ usando la librer�a est�ndard, y un interfaz gr�fico 
escrito en Java.


                                    USO
                                    ---

La aplicaci�n de l�nea de comandos es totalmente funcional, y puede usarse sin
el interfaz. Puedes consultar la sintaxis de la aplicaci�n, invoc�ndola con el
par�metro --help.

./gbcf --help
GB Flasher CLI v0.23
David Pello, Ladecadence.net

USO:
gbcf <acci�n> [opciones] [fichero]

ACCIONES:
--status:	Muestra informaci�n sobre el cartucho
--read-rom:	Leer la memoria ROM del cartucho (Juego)
--write-rom:	Escribir la memoria ROM del cartucho
--erase-rom:	Borrar la memoria ROM del cartucho
--read-ram:	Leer la memoria RAM del cartucho (Partidas)
--write-ram:	Escribe la memoria RAM del cartucho
--erase-ram:	Borra la memoria RAM del cartucho

OPCIONES
--rom <num>:    Tama�o del ROM
                0=32Kb, 1=64Kb, 2=128Kb, 3=256Kb, 4=512Kb, 5=1Mb
                6=2Mb, 7=4Mb, 8=8Mb
--ram <num>:    Tama�o RAM:
                0=2KB, 1=8KB, 2=32KB, 3=128KB
                
                
As� por ejemplo, para ver si el cartucho est� introducido correctamente y 
consultar su contenido, ejecutaremos:

./gbcf --status

Para escribir un archivo .gb en la memoria flash:

./gbcf --write-rom /directorio/de/la/rom.gb

Para leer la ram(partidas guardadas), que sabemos que ocupa 32K y guardarla en
el archivo /home/usuario/partidas.sav:

./gbcf --read-ram --ram 2 /home/usuario/partidas.sav


El interfaz gr�fico en Java, envuelve la aplicaci�n de l�nea de comandos, 
haci�ndolo m�s amigable, a trav�s de una barra de herramientas y un sistema de
men�s.
Adem�s de las opciones m�s comunes, agrega la funcionalidad de borrar 
autom�ticamente la memoria flash antes de escribirla, y la de consultar el 
tama�o de la memoria (flash o ram) antes de leerla, seleccionando 
autom�ticamente el tama�o adecuado. Estas dos funcionalidades se pueden 
desactivar en el men� opciones.

                                  INSTALACION
                                  -----------

En Windows, debemos instalar el Java runtime environment (JRE) de SUN , 
versiones 1.5 o 1.6 (java.com). Luego descomprimimos el paquete en una carpeta
a nuestro gusto, y conectamos el flasher.
Windows detectar� hardware nuevo, deberemos seleccionar la opci�n de definir una
ubicaci�n del controlador, seleccionando la subcarpeta "driver" dentro de la 
carpeta donde hayamos descomprimido nuestro flasher (puede pedirla dos veces). 
Si todo va bien, windows detectar� e instalar� el driver del chip USB-Serie.
Una vez instalado, podriamos ejecutar la interfaz Java con el archivo BAT 
incluido en el paquete, o ejecutar la aplicaci�n de l�nea de comandos, desde el
int�rprete de �rdenes de windows.

En Linux y en MacOSX, los binarios est�n compilados est�ticamente, asi que no 
requieren instalar librer�as adicionales, solamente la JRE de Java 1.5 o 1.6 
(que en MacOSX ya est� instalada por defecto), y o bien usar la aplicaci�n de
l�nea de comandos desde un terminal, o bien lanzar el .jar haciendo doble click
sobre el en OSX, o ejecutando el script gbflasher.sh en Linux.





David Pello, Dic. 2008.
Este software queda licenciado bajo la GPL:
http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt




