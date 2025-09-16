## FT_POPEN

#### Archivos mostrados : ft_popen.c

```c
int	ft_popen(const char *file, char *const argv[], char type)
```

- [ft_popen.c](./ft_popen.c) : 

Consiste en implementar una función que permite ejecutar un programa externo y comunicarte con él mediante un pipe `"|"`.

Redirige la **entrada** o **salida** estándar según el tipo (**'r'** para leer o **'w'** para escribir), la función crea un proceso hijo, y ejecuta el comando especificado.

Lo importante de este ejercicio es entender y saber manejar la memoria y los **file descriptors (fd)** junto al uso de las funciones `fork()` y `pipe()`.