## Backtracking (BT)
**Objetivo**
Construir progresivamente una contraseña y utilizar una condición de factibilidad para determinar si una rama del árbol de búsqueda puede continuar siendo explorada.
## Pseudocódigo

```text
ALGORITMO Backtracking

ENTRADA:
    hashObjetivo
    alfabeto
    longitudMinima
    longitudMaxima

SALIDA:
    contraseñaEncontrada
    nodosGenerados
    nodosVisitados
    nodosPodados
    tiempoEjecucion

INICIO

    nodosGenerados ← 0
    nodosVisitados ← 0
    nodosPodados ← 0
    contraseñaEncontrada ← NO ENCONTRADA

    PARA longitud ← longitudMinima HASTA longitudMaxima HACER

        BACKTRACKING("", longitud)

        SI contraseñaEncontrada ≠ NO ENCONTRADA ENTONCES
            RETORNAR contraseñaEncontrada
        FIN SI

    FIN PARA

    RETORNAR contraseñaEncontrada

FIN


PROCEDIMIENTO BACKTRACKING(candidato, longitudObjetivo)

    nodosGenerados ← nodosGenerados + 1

    SI NO ES_FACTIBLE(candidato, longitudObjetivo) ENTONCES
        nodosPodados ← nodosPodados + 1
        RETORNAR
    FIN SI

    nodosVisitados ← nodosVisitados + 1

    SI longitud(candidato) = longitudObjetivo ENTONCES

        hashCandidato ← SHA256(candidato)

        SI hashCandidato = hashObjetivo ENTONCES
            contraseñaEncontrada ← candidato
        FIN SI

        RETORNAR
    FIN SI

    PARA CADA caracter EN alfabeto HACER

        nuevoCandidato ← candidato + caracter

        BACKTRACKING(nuevoCandidato, longitudObjetivo)

        SI contraseñaEncontrada ≠ NO ENCONTRADA ENTONCES
            RETORNAR
        FIN SI

    FIN PARA

FIN PROCEDIMIENTO
```