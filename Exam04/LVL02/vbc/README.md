## VBC.C

#### Archivos mostrados : given.c, vbc.c.

- [given.c](./given.c) : Es el archivo que te dan para "arreglarlo", cambiar o añadir funciones. 
(Este archivo puede variar dependiendo de que campus estés).

- [vbc.c](./vbc.c) : Archivo del ejercicio una vez completado.
(Siempre hay otra manera de hacer las cosas, este archivo no es una solución única)


Este ejercicio consiste en implementar un evaluador de expresiones aritméticas simples en C, construye un árbol de sintaxis abstracta (AST) para analizar la expresión y luego evalúa su resultado, mostrando el valor final por pantalla. Tambien maneja errores de sintaxis y memoria.

#### Es decir, hacer una especie de calculadora de un solo dígito para sumas, multiplicaciones y paréntesis.

Recibe un solo argumento.

	>./a.out '3+3'
	> 6

	./a.out '(2+5)*3'
	> 21

	./a.out '(((((2 + 2)))))'
	> 4