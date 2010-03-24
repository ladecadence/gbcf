 
                   ____ ____  _____ _           _               
                  / ___| __ )|  ___| | __ _ ___| |__   ___ _ __ 
                 | |  _|  _ \| |_  | |/ _` / __| '_ \ / _ \ '__|
                 | |_| | |_) |  _| | | (_| \__ \ | | |  __/ |   
                  \____|____/|_|   |_|\__,_|___/_| |_|\___|_|   
 

                                INTRODUCCIÓN
                                ------------

GBFlasher es el software para el programador USB GBCartFlasher, creado por kraku
y chroost, y continuado y mejorado por David Pello (zako).
Este software permite leer la memoria rom y leer, escribir y borrar la ram de un
cartucho de gameboy original, y leer, escribir y borrar la flash y ram de un
cartucho flasheable de gameboy (modificado o fabricado).

La aplicación está formada por dos partes, un ejecutable de linea de comandos,
(gbcf), escrito en C++ usando la librería estándard, y un interfaz gráfico 
escrito en Java.


                                    USO
                                    ---

La aplicación de línea de comandos es totalmente funcional, y puede usarse sin
el interfaz. Puedes consultar la sintaxis de la aplicación, invocándola con el
parámetro --help.

./gbcf --help
GB Flasher CLI v0.23
David Pello, Ladecadence.net

USO:
gbcf <acción> [opciones] [fichero]

ACCIONES:
--status:	Muestra información sobre el cartucho
--read-rom:	Leer la memoria ROM del cartucho (Juego)
--write-rom:	Escribir la memoria ROM del cartucho
--erase-rom:	Borrar la memoria ROM del cartucho
--read-ram:	Leer la memoria RAM del cartucho (Partidas)
--write-ram:	Escribe la memoria RAM del cartucho
--erase-ram:	Borra la memoria RAM del cartucho

OPCIONES
--rom <num>:    Tamaño del ROM
                0=32Kb, 1=64Kb, 2=128Kb, 3=256Kb, 4=512Kb, 5=1Mb
                6=2Mb, 7=4Mb, 8=8Mb
--ram <num>:    Tamaño RAM:
                0=2KB, 1=8KB, 2=32KB, 3=128KB
                
                
Así por ejemplo, para ver si el cartucho está introducido correctamente y 
consultar su contenido, ejecutaremos:

./gbcf --status

Para escribir un archivo .gb en la memoria flash:

./gbcf --write-rom /directorio/de/la/rom.gb

Para leer la ram(partidas guardadas), que sabemos que ocupa 32K y guardarla en
el archivo /home/usuario/partidas.sav:

./gbcf --read-ram --ram 2 /home/usuario/partidas.sav


El interfaz gráfico en Java, envuelve la aplicación de línea de comandos, 
haciéndolo más amigable, a través de una barra de herramientas y un sistema de
menús.
Además de las opciones más comunes, agrega la funcionalidad de borrar 
automáticamente la memoria flash antes de escribirla, y la de consultar el 
tamaño de la memoria (flash o ram) antes de leerla, seleccionando 
automáticamente el tamaño adecuado. Estas dos funcionalidades se pueden 
desactivar en el menú opciones.

                                  INSTALACION
                                  -----------

En Windows, debemos instalar el Java runtime environment (JRE) de SUN , 
versiones 1.5 o 1.6 (java.com). Luego descomprimimos el paquete en una carpeta
a nuestro gusto, y conectamos el flasher.
Windows detectará hardware nuevo, deberemos seleccionar la opción de definir una
ubicación del controlador, seleccionando la subcarpeta "driver" dentro de la 
carpeta donde hayamos descomprimido nuestro flasher (puede pedirla dos veces). 
Si todo va bien, windows detectará e instalará el driver del chip USB-Serie.
Una vez instalado, podriamos ejecutar la interfaz Java con el archivo BAT 
incluido en el paquete, o ejecutar la aplicación de línea de comandos, desde el
intérprete de órdenes de windows.

En Linux y en MacOSX, los binarios están compilados estáticamente, asi que no 
requieren instalar librerías adicionales, solamente la JRE de Java 1.5 o 1.6 
(que en MacOSX ya está instalada por defecto), y o bien usar la aplicación de
línea de comandos desde un terminal, o bien lanzar el .jar haciendo doble click
sobre el en OSX, o ejecutando el script gbflasher.sh en Linux.





David Pello, Dic. 2008.
Este software queda licenciado bajo la GPL:
http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt




