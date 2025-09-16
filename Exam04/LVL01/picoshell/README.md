## PICOSHELL

#### Archivos mostrados : picoshell.c, main.c

```c
int	picoshell(char **cmds[])
```

- [picoshell.c](./picoshell.c) : Archivo del programa.

- [main.c](./main.c) : Main dado por el propio subject, que te permite compilar.

El ejercicio simula el comportamiento básico de una shell cuando ejecutas comandos con pipes.

ls -l | grep txt | wc -l.

**Funcionalidad principal:**
- Crea procesos hijo para cada comando.
- Establece pipes entre comandos consecutivos.
- Redirige stdin/stdout apropiadamente.
- Espera a que todos los procesos terminen.
- Retorna 1 si algún comando falla, 0 si todos exitosos.

**Conceptos clave:**
- Manejo de **pipes** y **file descriptors**.
- Uso de `fork()`, `execvp()`, `dup2()` y `wait()`.
- Redirección de entrada/salida estándar.
- Sincronización de procesos padre/hijo.
