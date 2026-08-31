## Backtracking (BT)
**Objetivo**
Construir progresivamente una contraseña y utilizar una condición de factibilidad para determinar si una rama del árbol de búsqueda puede continuar siendo explorada.
## Pseudocódigo

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
