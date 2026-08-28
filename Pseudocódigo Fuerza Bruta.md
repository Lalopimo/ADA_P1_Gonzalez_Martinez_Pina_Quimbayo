## 1. Fuerza Bruta (FB)

### Objetivo

Generar sistemáticamente todos los candidatos posibles dentro del espacio
de búsqueda y comparar el SHA-256 de cada candidato con el hash objetivo.

### Pseudocódigo

``` text
ALGORITMO FuerzaBruta

ENTRADA:
    hashObjetivo
    alfabeto
    longitudMinima
    longitudMaxima

SALIDA:
    contraseñaEncontrada
    candidatosEvaluados
    tiempoEjecucion

INICIO

    candidatosEvaluados ← 0
    contraseñaEncontrada ← NO ENCONTRADA

    PARA longitud ← longitudMinima HASTA longitudMaxima HACER

        GENERAR_CANDIDATOS("", longitud)

        SI contraseñaEncontrada ≠ NO ENCONTRADA ENTONCES
            RETORNAR contraseñaEncontrada
        FIN SI

    FIN PARA

    RETORNAR contraseñaEncontrada

FIN


PROCEDIMIENTO GENERAR_CANDIDATOS(candidato, longitudObjetivo)

    SI longitud(candidato) = longitudObjetivo ENTONCES

        candidatosEvaluados ← candidatosEvaluados + 1

        hashCandidato ← SHA256(candidato)

        SI hashCandidato = hashObjetivo ENTONCES
            contraseñaEncontrada ← candidato
        FIN SI

        RETORNAR
    FIN SI

    PARA CADA caracter EN alfabeto HACER

        nuevoCandidato ← candidato + caracter

        GENERAR_CANDIDATOS(nuevoCandidato, longitudObjetivo)

    FIN PARA

FIN PROCEDIMIENTO
```