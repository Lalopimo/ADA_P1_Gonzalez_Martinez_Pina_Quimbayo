

# Módulo de Fuerza Bruta (FB)

### Problema

Dado un hash SHA-256 objetivo, encontrar la contraseña que lo genera mediante
la generación sistemática de todos los candidatos posibles dentro de un
espacio de búsqueda definido por un alfabeto y una longitud determinada.

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
- Una indicación de que no se encontró la contraseña cuando se agota el
  espacio de búsqueda.
- El número de candidatos evaluados.
- El tiempo total de ejecución.

### Restricciones

- Deben generarse sistemáticamente los candidatos pertenecientes al espacio
  de búsqueda.
- Cada candidato debe evaluarse mediante SHA-256.
- Cada candidato debe compararse con el hash objetivo.
- No se deben generar candidatos fuera del alfabeto establecido.
- No se deben generar contraseñas con longitudes fuera de las establecidas.
- Cada candidato debe generarse exactamente una vez.
- El algoritmo debe permitir registrar las métricas necesarias para comparar
  experimentalmente su comportamiento.