## Módulo de Backtracking (BT)

### Problema

Dado un hash SHA-256 objetivo, encontrar la contraseña que lo genera mediante
la construcción incremental de candidatos y la exploración de un árbol de
búsqueda.

A diferencia de Fuerza Bruta, el algoritmo utiliza una condición de
factibilidad para determinar si una rama del árbol puede continuar siendo
explorada. Cuando una rama no puede producir una solución válida, esta se
poda y no se generan los candidatos que dependen de ella.

### Entradas

El módulo recibe:

- **Hash objetivo:** cadena hexadecimal correspondiente al SHA-256 de la
  contraseña que se desea encontrar.
- **Alfabeto:** conjunto de caracteres permitidos para construir las
  contraseñas.
- **Longitud de contraseña:** longitud o rango de longitudes que deben
  explorarse.
- **Configuración del experimento:** parámetros necesarios para registrar
  las métricas de ejecución.

Los alfabetos definidos para el módulo son:

- **A1:** letras minúsculas `a-z`, con 26 caracteres.
- **A2:** letras minúsculas `a-z` y dígitos `0-9`, con 36 caracteres.

Las longitudes establecidas son:

- Para A1: 3, 4, 5 y 6 caracteres.
- Para A2: 3, 4 y 5 caracteres.

### Salidas

El módulo produce:

- La contraseña encontrada, si existe dentro del espacio de búsqueda.
- Una indicación de que no se encontró la contraseña cuando se agota la
  búsqueda.
- El número de nodos generados.
- El número de nodos visitados.
- El número de nodos podados.
- El porcentaje de reducción obtenido mediante la poda.
- El tiempo total de ejecución.

### Restricciones

- La contraseña debe construirse de manera incremental.
- Cada posición debe utilizar únicamente caracteres pertenecientes al
  alfabeto establecido.
- No deben superarse las longitudes establecidas.
- Cada estado parcial debe evaluarse mediante la condición de factibilidad
  definida por el problema.
- Cuando un estado no sea factible, su rama debe podarse y no continuar la
  exploración.
- La poda debe contabilizarse como parte de las métricas del algoritmo.
- El algoritmo debe permitir comparar experimentalmente el comportamiento
  con y sin poda.