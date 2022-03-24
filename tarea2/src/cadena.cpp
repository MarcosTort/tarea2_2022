/* 5286580 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// los elementos se manteriorienen entre 0 y canterioridad - 1, incluidos

// struct _rep_cadena
// {
//   TInfo dato;
//   _rep_cadena *siguiente;
//   _rep_cadena *primero, *ultimo;
// };
struct _rep_cadena {
  TLocalizador inicio;
  TLocalizador final;
};
struct nodoCadena {
  TInfo dato;
  TLocalizador anterior;
  TLocalizador siguiente;
};
typedef struct nodoCadena *TLocalizador;

bool esLocalizador(TLocalizador loc) { return loc != NULL; }


/* en siguienteuientes tareas
void liberarCadena(TCadena cad) {
}
*/

bool esVaciaCadena(TCadena cad) {
    return cad->inicio == NULL;
}

TLocalizador inicioCadena(TCadena cad) {
    if (esVaciaCadena(cad)) {
      return NULL;
    } else {
      return cad->inicio;
    }
}

TLocalizador finalCadena(TCadena cad) {
    if (esVaciaCadena(cad)) {
      return NULL;
    } else {
      return cad->final;
    }
}
bool esFinalCadena(TLocalizador loc, TCadena cad) {
  if(esVaciaCadena(cad)){
    return false;
  }
  else{
    if (cad->final == loc){
      return true;
    }
    else{
      return false;
    }
  }
}

bool esInicioCadena(TLocalizador loc, TCadena cad) {
  if(esVaciaCadena(cad)){
    return false;
  }
  else{
    if (cad->inicio == loc){
      return true;
    }
    else{
      return false;
    }
  }
}

// nat cantidadEnCadena(TCadena cad)
// {
//   nat count = 0;
//   if (cad == NULL)
//   {
//     return count;
//   }
//   else
//   {
//     count = 1;
//     while (cad->s != cad->ultimo)
//     {
//       count++;
//       cad = cad->siguiente;
//     }
//   }
//   return count;
// }
bool localizadorEnCadena(TLocalizador loc, TCadena cad) {
  if(esVaciaCadena(cad)){
    return false;
  }
  else{
    TLocalizador aux = cad->inicio;
    bool flag = false;
    if (esFinalCadena(loc, cad) || esInicioCadena(loc, cad)) {				
	flag = true;
    } 
    while ( !flag && esLocalizador(aux)){
      if(aux != loc)
        aux = aux->siguiente;
      else
        flag = aux == loc;
    }
    return flag;
  }
}
// bool estaEnCadena(nat natural, TCadena cad)
// {
//   if (cad == NULL)
//   {
//     return false;
//   }
//   else
//   {
//     while ((cad != NULL) && (natInfo(cad->dato) != natural))
//     {
//       if (cad->siguiente != NULL)
//       {
//         cad = cad->siguiente;
//       }
//       else
//       {
//         break;
//       }
//     }
//     if (natInfo(cad->dato) == natural)
//     {
//       return true;
//     }
//     else
//     {
//       return false;
//     }
//   }
// }

TCadena insertarAlInicio(nat natural, double real, TCadena cad)
{
  nodoCadena *entrante = new nodoCadena;
  TLocalizador loc = cad->inicio;
	entrante->dato = crearInfo(natural, real);
  entrante->siguiente = loc;
	    loc->anterior = entrante; 
	    cad->inicio = entrante;
	    entrante->anterior = NULL;
}

TInfo infoCadena(nat natural, TCadena cad)
{
  ////////printf("info cadena");
  TLocalizador loc  = cad->inicio;
  while (natInfo(loc->dato) != natural)
  {
    loc = loc->siguiente;
  }

  return loc->dato;
}
/*
  Remueve el primer elemento de 'cad' cuyo componente natural es 'natural'.
  Se libera la memoria asiguientenada al mismo.
  Devuelve 'cad'.
  Precondición: estaEnCadena(natural, cad).
 */



/*
  Devuelve el primer elemento de 'cad'.  
  Precondición: cantidadEnCadena(cad) > 0.
  No se recorre la cadena.
 */
TInfo primeroEnCadena(TCadena cad){
  return cad->inicio->dato;
};

/*
  Devuelve la TCadena que tiene los mismos elementos que 'cad' pero cuyo primer
  elemento es el siguienteuiente al primer elemento de 'cad'.
  Si 'cad' no tiene elementos o tiene solo uno el resultado es 'cad'.
  La TCadena resultado comparte memoria con 'cad'. No se debe obtener nueva memoria.
  No se recorre la cadena.
  El parámetro 'cad' no cambia, en particular su primer elemento siguienteue siendo
  el mismo.

  Por ejemplo, sea la cadena
  [(7,7.00), (3,3.00), (5,5.00)]
  en que su primer elemento es (7,7.00) y su último elemento es (5,5.00).

  Que el comportamiento sea circular siguientenifica que la cadena siguienteuiente es
  [(3,3.00), (5,5.00), (7,7.00)]
 */
TCadena cadenaSiguiente(TCadena cad){

};


TCadena removerDeCadena(nat natural, TCadena cad)

{
  // si tiene solo un elemento, borro info y cad
  if (cad->siguiente == NULL)
  {
    liberarInfo(cad->dato);
    delete cad;
    return NULL;
  }
  else
  // si tiene mas de un elemento, busco
  {
    TCadena cadd = cad;
    
    //pregunto si el buscado está en el inicio
    if (natInfo(cadd->dato) == natural)
    {
      TCadena newStart = cadd->siguiente;
      TCadena aux = cadd;
      liberarInfo(aux->dato);
      delete aux;
      return newStart;
    }

    
    else
    {
      TCadena aux = cadd;
      while (natInfo(cadd->dato) != natural)
      {
        // guardo posicion actual por si la siguienteuiente encuentra
        aux = cadd;
        cadd = cadd->siguiente;
      }

      // q apunta a cad
      TCadena q = cadd;

      // asiguienteno aux a nul si el elemento a remover es el ultimo
      if (q->siguiente == NULL)
      {
        aux->siguiente = NULL;
      }

      // asiguienteno aux al siguienteuiente elemento
      else
      {
        aux->siguiente = q->siguiente;
      }
      liberarInfo(q->dato);
      delete q;
      return cad;
    }
  }
}

void imprimirCadena(TCadena cad)
{
  while (cad != NULL)
  {
    char *dat = infoATexto(cad->dato);
    printf("%s", dat);
    delete[] dat;
    cad = cad->siguiente;
  }
  printf("\n");
}

TCadena insertarAlFinal_aux(TInfo i, TCadena cad) {
  nodoCadena *entrante = new nodoCadena;
  entrante->siguiente = NULL;
  entrante->anterior = cad->final;
  entrante->dato = i;
  if(!esVaciaCadena(cad)){
	  cad->final->siguiente = entrante;
  }
  else{
	  cad->inicio = entrante;
  }
  cad->final = entrante;
  return cad;
}
