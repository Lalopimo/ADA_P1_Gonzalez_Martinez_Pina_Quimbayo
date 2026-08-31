## Módulo de Backtracking (BT)

### Problema

Dada una política de complejidad de contraseñas (longitud fija, mínimos de
tipo de carácter, prohibición de caracteres consecutivos repetidos), generar
y contar todas las contraseñas que cumplen dicha política, sin generar
primero el espacio completo de cadenas posibles y filtrar al final.

A diferencia de Fuerza Bruta, el algoritmo construye cada contraseña de
forma incremental, carácter por carácter, y utiliza una función de
factibilidad para determinar, en cada paso, si el prefijo parcial
construido todavía puede llevar a una solución válida. Cuando un prefijo no
puede satisfacer la política (por ejemplo, porque ya no quedan posiciones
suficientes para cumplir algún mínimo exigido), la rama se abandona de
inmediato ("se poda") sin generar ninguna de sus extensiones.

Este módulo **no busca ningún hash objetivo** ni compara contra una
contraseña conocida de antemano — esa es la tarea del Módulo FB. Aquí el
objetivo es enumerar (o contar) todas las contraseñas que satisfacen la
política de seguridad asignada al equipo.

### Entradas

El módulo recibe:

- **Alfabeto:** conjunto de 69 símbolos (minúsculas, mayúsculas, dígitos, y
  los símbolos `!`, `@`, `#`, `$`, `%`).
- **Longitud fija (n):** longitud exacta que debe tener cada contraseña
  generada (n = 8 para la instancia del equipo, ver Sección 9.2 del
  enunciado).
- **Parámetros de la política:** `minLower`, `minUpper`, `minDigit`,
  `minSymbol` — número mínimo de caracteres de cada tipo que debe contener
  una contraseña válida, derivados de la semilla del equipo.
- **Restricción fija:** prohibición de dos caracteres idénticos
  consecutivos, aplicable a todas las instancias.

Estos cinco valores (n y los cuatro mínimos) se reciben como parámetros de
línea de comandos al ejecutar el programa, lo que permite evaluar distintas
variantes de dificultad (Sección 9.2) sin recompilar.

### Salidas

El módulo produce, para una instancia dada:

- El conjunto de contraseñas que cumplen la política (impresas por
  pantalla).
- El número total de contraseñas válidas encontradas.
- El número de nodos generados.
- El número de nodos visitados (solo aplica a la versión con poda).
- El número de nodos podados (solo aplica a la versión con poda).
- El tiempo total de ejecución (medido con `std::chrono`).

Comparando estas métricas entre la versión con poda y sin poda para la
misma instancia, se puede calcular el porcentaje de reducción del espacio
de búsqueda logrado por la poda (Sección 8.2).

### Restricciones

- La contraseña debe construirse de manera incremental, carácter por
  carácter, a partir de una cadena vacía.
- Cada posición debe utilizar únicamente caracteres pertenecientes al
  alfabeto de 69 símbolos.
- La contraseña completa debe tener exactamente longitud n.
- No puede haber dos caracteres idénticos en posiciones consecutivas, en
  ningún punto de la cadena.
- La contraseña completa debe contener al menos `minLower` minúsculas,
  `minUpper` mayúsculas, `minDigit` dígitos y `minSymbol` símbolos.
- En la versión con poda, cada prefijo parcial debe evaluarse mediante la
  función de factibilidad (`esFactible`) antes de continuar explorando sus
  extensiones; si el prefijo ya no puede satisfacer la política dado el
  número de posiciones restantes, la rama se poda.
- En la versión sin poda, la política completa (mínimos y no-repetidos-
  consecutivos) se verifica una única vez, al llegar a una cadena de
  longitud n, filtrando al final en vez de en cada nivel del árbol.
- El algoritmo debe permitir comparar experimentalmente el comportamiento
  con y sin poda, verificando que el número de soluciones coincida
  exactamente entre ambas versiones (verificación de correctitud, ver
  `tests/verificar_correctitud.cpp`).
