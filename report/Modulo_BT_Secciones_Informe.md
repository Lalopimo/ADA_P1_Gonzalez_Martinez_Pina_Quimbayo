# Módulo BT (Backtracking)
---

## 5. Modelamiento (Módulo BT)

El Módulo BT aborda el problema desde el rol de diseñador de una política de contraseñas: dada una política de complejidad (longitud fija, mínimos de tipo de carácter, prohibición de caracteres consecutivos repetidos), el objetivo es generar y contar todas las contraseñas que la cumplen, sin enumerar primero el espacio completo de cadenas y filtrar al final.

**Espacio de búsqueda.** El alfabeto de la instancia está compuesto por 69 símbolos: 26 minúsculas, 26 mayúsculas, 10 dígitos y 5 símbolos especiales (`!`, `@`, `#`, `$`, `%`). Nota: se identificó una inconsistencia en el enunciado, donde se indica un total de "69 símbolos" pero la suma real de los cuatro conjuntos descritos da 67 (26+26+10+5=67); esta ambigüedad fue consultada con el docente, y se documenta explícitamente aquí por transparencia (Sección 17 del enunciado).

**Estado parcial.** Un estado del árbol de búsqueda se representa como el prefijo de la contraseña construido hasta el momento (una cadena de longitud k ≤ n), acompañado de cuatro contadores que registran cuántos caracteres de cada tipo (minúscula, mayúscula, dígito, símbolo) contiene ese prefijo, y del último carácter agregado (implícito en la propia cadena, usado para verificar la restricción de no-repetidos-consecutivos).

**Estado inicial.** La cadena vacía, con los cuatro contadores en cero.

**Estados terminales.** Cadenas de longitud exacta n = 8. Es importante notar que no toda cadena de longitud n es un estado terminal *válido*: solo aquellas que, además de tener la longitud correcta, satisfacen los cuatro mínimos de la política y no contienen caracteres consecutivos repetidos en ningún punto se consideran soluciones.

**Política de la instancia del equipo** (derivada de la semilla 3043, calculada a partir de la concatenación alfabética de los apellidos de los integrantes): minLower = 3, minUpper = 2, minDigit = 2, minSymbol = 1, n = 8. La suma de estos mínimos (8) es exactamente igual a n, lo que implica holgura cero: cualquier posición "desperdiciada" en un tipo de carácter que ya superó su mínimo automáticamente vuelve infactible la rama, sin necesidad de una regla de poda adicional distinta a la fórmula general de factibilidad.

---

## 6. Diseño algorítmico (Módulo BT)

El algoritmo construye cada contraseña de forma incremental, carácter por carácter, evaluando en cada paso si el prefijo parcial todavía puede extenderse hasta una solución válida. Esta evaluación temprana (poda) es lo que distingue a Backtracking de una enumeración exhaustiva pura.

**Función de factibilidad.** Se diseñaron dos condiciones, evaluadas en cada nodo antes de continuar la exploración:

1. **No repetidos consecutivos:** si el candidato tiene longitud ≥ 2 y el último carácter agregado coincide con el penúltimo, la rama es infactible.
2. **Factibilidad de alcanzar los mínimos:** se calcula `faltante_total` como la suma de lo que aún falta por cumplir en cada uno de los cuatro tipos de carácter (`max(0, mínimo − usado)` para cada tipo). Si las posiciones libres restantes (`n − longitud_actual`) son menores que `faltante_total`, ninguna extensión del prefijo puede satisfacer la política, y la rama se poda.

Se verificó formalmente (y se confirmó empíricamente mediante la implementación) que esta combinación de condiciones garantiza que ninguna cadena de longitud n con algún mínimo incumplido pueda llegar al caso base: en ese punto, las posiciones libres son cero, y cualquier faltante positivo ya habría provocado la poda en un nivel anterior del árbol.

**Dos versiones del algoritmo.** Se implementaron dos versiones independientes para permitir la comparación exigida en la Sección 8.2:

- **Con poda:** aplica la función de factibilidad en cada nodo del árbol, antes de generar sus descendientes.
- **Sin poda:** genera el árbol completo hasta las hojas (cadenas de longitud n), sin ningún filtro intermedio, y verifica la política completa (mínimos y no-repetidos-consecutivos) una única vez, al llegar a cada hoja. Esta versión es conceptualmente equivalente a fuerza bruta aplicada sobre el espacio de cadenas de longitud fija, seguida de un filtro final — permite cuantificar cuánto trabajo evita realmente la poda.

Ambas versiones deben producir exactamente el mismo número de soluciones para una misma instancia; esta coincidencia se usa como criterio de verificación de correctitud (ver Sección 10).

---

## 7. Pseudocódigo (Módulo BT)

```text
ALGORITMO Backtracking

ENTRADA:
    alfabeto
    longitudExacta

SALIDA:
    contraseñasGeneradas
    nodosGenerados
    nodosVisitados
    nodosPodados
    tiempoEjecucion


INICIO

   contraseñasGeneradas ← 0
    nodosGenerados ← 0
    nodosVisitados ← 0
    nodosPodados ← 0
    minLower ← 3
    minUpper ← 2
    minDigit ← 2
    minSimbol ← 1

      
    usadoLower ← 0
    usadoUpper ← 0
    usadoDigit ← 0
    usadoSimbol ← 0
    
    inicio ← TIEMPO_ACTUAL()
    
    BACKTRACKING("", longitud)

    fin ← TIEMPO_ACTUAL()

   tiempoEjecucion ← fin - inicio

   IMPRIMIR contraseñasGeneradas
   IMPRIMIR nodosGenerados 
   IMPRIMIR nodosVisitados
   IMPRIMIR nodosPodados
   IMPRIMIR tiempoEjecucion

FIN


PROCEDIMIENTO BACKTRACKING(candidato, longitudObjetivo)
    
     nodosGenerados ← nodosGenerados + 1

    SI ES_FACTIBLE(candidato, longitudObjetivo) ES FALSO ENTONCES
        nodosPodados ← nodosPodados + 1
        RETORNAR
    FIN SI

    nodosVisitados ← nodosVisitados + 1

    SI longitud(candidato) = longitudObjetivo Y
       usadoLower >= minLower Y
       usadoUpper >= minUpper Y
       usadoDigit >= minDigit Y
       usadoSimbol >= minSimbol
    ENTONCES
      
      IMPRIMIR candidato
      contraseñasGeneradas ← contraseñasGeneradas + 1

        RETORNAR

    FIN SI

    PARA CADA caracter EN alfabeto HACER

        candidato ← candidato + caracter
        AGREGAR_CONTADORES(caracter)

        BACKTRACKING(candidato, longitudObjetivo)

          candidato.pop_back()

           QUITAR_CONTADORES(caracter)


    FIN PARA

FIN PROCEDIMIENTO



PROCEDIMIENTO ES_FACTIBLE(candidato, longitudObjetivo)
    
    SI tamaño(candidato) >= 2  ENTONCES 
 
        SI candidato[tamaño(candidato) -2] es igual a candidato[tamaño(candidato) -1] ENTONCES 
 
            RETORNAR falso
    
        FIN SI
    
    FIN SI

    faltante_total ← max(0, minLower - usadoLower)
                   + max(0, minUpper - usadoUpper)
                   + max(0, minDigit - usadoDigit)
                   + max(0, minSimbol - usadoSimbol)

    SI (longitudObjetivo - longitud(candidato)) < faltante_total  ENTONCES 
 
        RETORNAR falso
    
    FIN SI

    RETORNAR verdadero

FIN PROCEDIMIENTO


PROCEDIMIENTO AGREGAR_CONTADORES(caracter)

    SI caracter es (a,b,c, …o z) entonces
        usadoLower ← usadoLower + 1
    DE OTRO MODO SI caracter es (A,B,C, … o Z) entonces
        usadoUpper ← usadoUpper + 1
    DE OTRO MODO SI caracter es (0, 1, 2, … o 9) entonces
        usadoDigit ← usadoDigit + 1
    DE OTRO MODO SI caracter es (*símbolos*) entonces
        usadoSimbol ← usadoSimbol + 1
    FIN SI

FIN PROCEDIMIENTO


PROCEDIMIENTO QUITAR_CONTADORES(caracter)

    SI caracter es (a,b,c, …o z) entonces
        usadoLower ← usadoLower - 1
    DE OTRO MODO SI caracter es (A,B,C, … o Z) entonces
        usadoUpper ← usadoUpper - 1
    DE OTRO MODO SI caracter es (0, 1, 2, … o 9) entonces
        usadoDigit ← usadoDigit - 1
    DE OTRO MODO SI caracter es (*símbolos*) entonces
        usadoSimbol ←usadoSimbol - 1
    FIN SI

FIN PROCEDIMIENTO
```


*Nota de implementación:* el esqueleto de notación (formato ENTRADA/SALIDA/PROCEDIMIENTO) fue sugerido inicialmente como plantilla de referencia por el integrante del equipo Alejandro Martinez; el contenido de la función de factibilidad, el modelo de estado y las condiciones de poda son de autoría individual de quien desarrolló el Módulo BT.

---

## 8. Implementación (decisiones relevantes, Módulo BT)

**Clase con variables miembro en vez de struct con parámetros por referencia.** Se decidió implementar el estado del algoritmo (contadores de tipo de carácter, parámetros de política, métricas de nodos) como variables miembro de dos clases, `BacktrackerConPoda` y `BacktrackerSinPoda`, en vez de un struct pasado por referencia a una función recursiva libre. Esta decisión se tomó por familiaridad previa con el uso de clases en C++ y porque encapsula naturalmente tanto el estado como el comportamiento (los métodos `backtrack`, `esFactible`, `agregarContadores`) en una única unidad.

**Parametrización por línea de comandos (argv).** La primera versión de ambas clases definía `n` y los mínimos de la política como constantes fijas. Esto obligaba a recompilar el programa para cada instancia distinta, lo cual era inviable para la fase de experimentación (Sección 9.2, cinco variantes de dificultad). Se modificó el diseño para recibir estos cinco valores como parámetros del constructor, alimentados desde `argv` en `main.cpp`, permitiendo evaluar cualquier instancia sin recompilar: `./ada_p1 <n> <minLower> <minUpper> <minDigit> <minSymbol>`.

**Separación de la versión con poda y sin poda en clases independientes.** En vez de una sola clase con un parámetro booleano que activara o desactivara la poda, se implementaron dos clases separadas, en archivos distintos. Esto mantiene limpia la comparación de la Sección 8.2 y evita que un error en una condición booleana contamine ambas mediciones, a cambio de cierta duplicación de código (los métodos `agregarContadores`/`quitarContadores` son idénticos en ambas clases).

**Corrección de desbordamiento de enteros (`int` a `long long`).** Durante la fase de experimentación, se observó un valor negativo en el conteo de nodos generados (-882,992,959) para una instancia de política permisiva (minLower=minUpper=minDigit=minSymbol=1, n=6). La causa fue que las variables de conteo estaban declaradas como `int` (rango máximo ≈2.14×10⁹), y el árbol de búsqueda de esa instancia superó ese límite, produciendo un desbordamiento (overflow) que envolvió el contador a un valor negativo. La corrección consistió en cambiar el tipo de las variables de conteo (`nodosGenerados`, `nodosVisitados`, `nodosPodados`, `contraseñasGeneradas`) a `long long` (rango ≈9.2×10¹⁸), sin modificar la lógica del algoritmo. Este hallazgo se documenta también como evidencia adicional de la magnitud real del espacio de búsqueda en instancias de baja restricción.

**Corrección de un error en el alfabeto.** En una versión temprana, el alfabeto contenía una letra `k` duplicada y omitía la letra `q`, lo cual duplicaba la exploración de una rama e impedía generar contraseñas con `q`. Se corrigió a la secuencia completa y sin duplicados de a-z, A-Z, 0-9 y los cinco símbolos definidos.

---

## 9. Análisis de complejidad (Módulo BT)

**Complejidad temporal — peor caso.** El peor caso de Backtracking para este problema conserva la cota exponencial de Fuerza Bruta: cuando la política no impone ninguna restricción efectiva, la poda por mínimos nunca se activa, y el algoritmo recorre un árbol de tamaño comparable al de la enumeración exhaustiva completa, del orden de `|Σ| · (|Σ|-1)^(n-1)` nodos (el factor `|Σ|-1` en los niveles siguientes al primero se debe a la restricción de no-repetidos-consecutivos, que actúa incluso sin ninguna política de mínimos).

**Complejidad temporal — mejor caso.** Ocurre cuando la política es tan restrictiva que resulta matemáticamente infactible (la suma de mínimos excede n). La poda detecta la infactibilidad en el nodo raíz mismo, y el algoritmo termina en tiempo O(1) respecto al tamaño del alfabeto y la longitud. Se observó empíricamente en la variante (ii) (n=6, política del equipo, suma de mínimos=8): 1 nodo generado, 0 ms, frente a 1,634,650,501 nodos y ≈16.1 minutos de la versión sin poda para la misma instancia.

**Caso promedio.** Depende de qué tan pronto, en promedio, un prefijo deja de poder satisfacer la política — es decir, de la holgura entre la suma de mínimos y n. Instancias con holgura cero tienden hacia el peor caso, porque la poda solo se activa cerca del final de cada rama.

**Complejidad espacial.** Dominada por la profundidad del árbol de recursión, O(n). No se almacena el árbol completo en memoria; cada candidato se construye y se deshace incrementalmente.

**Evidencia empírica del crecimiento exponencial — serie con poda, política fija (minLower=minUpper=minDigit=minSymbol=1):**

| n | Nodos generados (con poda) | Tiempo (ms) | Factor de crecimiento (respecto a n-1) |
|---|---|---|---|
| 4 | 5,327,841 | 107 | — |
| 5 | 634,181,265 | 9,721 | ×119.1 (nodos), ×90.8 (tiempo) |
| 6 | 54,951,581,889 | 951,046 | ×86.6 (nodos), ×97.8 (tiempo) |
| 7 | — (no ejecutado) | Estimado >30 horas | Extrapolado desde n=6 |

Los factores de crecimiento medidos (entre 87x y 119x al aumentar n en una unidad) son consistentes con la cota teórica de `|Σ|-1 = 66` por nivel adicional del árbol, considerando además el costo extra de imprimir/contar un número creciente de soluciones válidas en cada instancia.

**Evidencia empírica adicional — la instancia real del equipo (n=8, holgura cero).** Con la política real del equipo (minLower=3, minUpper=2, minDigit=2, minSymbol=1), la instancia no pudo ejecutarse completa en un tiempo razonable. Usando el dato real medido en n=4 (20.5 s, 5,327,841 nodos generados con poda, política de holgura cero equivalente en espíritu) y el factor de crecimiento `66⁴ ≈ 18.97` millones al pasar de n=4 a n=8, se estima un tiempo superior a 12,000 años incluso con poda activa — evidencia directa de que la poda reduce el trabajo relativo pero no cambia el orden de complejidad del peor caso, tal como anticipa la Sección 6.2 del enunciado.

---

## 10. Casos de prueba (Módulo BT)

**Cálculo de la semilla.** Apellidos de los integrantes, ordenados alfabéticamente y concatenados en minúsculas sin espacios ni tildes: `gonzalezmartinezpinaquimbayo`. Se normalizó la letra "ñ" a "n" para el cálculo de la suma de códigos ASCII, dado que el estándar ASCII no incluye caracteres con diacríticos; esta decisión se documenta explícitamente como resolución de una ambigüedad del enunciado (Sección 17). Suma de códigos ASCII resultante y semilla: **3043**.

Parámetros de la política derivados de la semilla (Sección 9.2): minLower = 2 + (3043 mod 3) = 3; minUpper = 1 + (3043 mod 2) = 2; minDigit = 1 + (3043 mod 3) = 2; minSymbol = 1 (fijo); n = 8. Verificación: 3+2+2+1 = 8 = n, cumple la condición ≤ n sin necesidad de ajuste.

**Ausencia de la utilidad oficial de verificación.** El enunciado (Sección 9) indica que se proveería `resources/verificar_semilla.cpp` como utilidad de referencia para que cada equipo confirmara su semilla. Este archivo no fue publicado por el docente al momento de esta entrega; se consultó la situación por el canal oficial del curso, y se implementó una versión propia (`tests/verificar_semilla.cpp`) que reproduce el mismo procedimiento aritmético descrito en la Sección 9.1/9.2, para permitir la reproducibilidad exigida.

**Instancia de referencia común** (Sección 9.2): n=6, minLower=2, minUpper=1, minDigit=1, minSymbol=1, alfabeto completo, sin repetidos consecutivos. Se verificó con la versión con poda: **293,922,208 soluciones**. Esta cifra se validó indirectamente mediante un harness de pruebas (`tests/verificar_correctitud.cpp`) que confirmó la coincidencia exacta entre las versiones con y sin poda en cuatro instancias más pequeñas de distinta naturaleza (mínimo en cero, holgura cero, holgura positiva, y política vacía), estableciendo confianza en la correctitud del algoritmo antes de aplicarlo a instancias de mayor tamaño.

**Instancia real del equipo:** n=8, minLower=3, minUpper=2, minDigit=2, minSymbol=1 — identificada como computacionalmente intratable (ver Sección 9, Análisis de complejidad).

---

## Datos clave del Módulo BT

**Semilla e instancia del equipo:** La semilla calculada para el equipo es 3043, derivada de la concatenación alfabética de los apellidos de los integrantes. Los parámetros de política resultantes son minLower=3, minUpper=2, minDigit=2, minSymbol=1, sobre una longitud fija n=8.

**Instancia de referencia común:** Validada con 293,922,208 soluciones encontradas, para la política minLower=2, minUpper=1, minDigit=1, minSymbol=1, con n=6.

**Efectividad extrema de la poda:** La la variante (ii) de la Sección 9.2 (misma política del equipo aplicada a n=6, donde la suma de mínimos excede la longitud disponible), la versión con poda detecta la infactibilidad total en el nodo raíz, generando un solo nodo en tiempo prácticamente nulo. La versión sin poda, en la misma instancia, debe recorrer 1,634,650,501 nodos para llegar a la misma conclusión. Esto representa una reducción del espacio de búsqueda efectivamente explorado de aproximadamente el 99.9999999%, y es el ejemplo más claro y contundente del efecto de la poda que arrojó la experimentación.

**Muro exponencial:** La instancia real del equipo (n=8, con la política completa) resultó computacionalmente intratable. Con base en mediciones reales en instancias menores (n=4, n=5, n=6) y el patrón de crecimiento observado, se estima que ejecutar esta instancia completa —incluso con poda activa— tomaría más de 12,000 años, lo cual evidencia que la poda reduce el trabajo relativo frente a la fuerza bruta, pero no cambia el orden de complejidad exponencial del peor caso del problema.
