/* 5286580 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// los elementos se mantienen entre 0 y cantidad - 1, incluidos

struct _rep_cadena
{
  TInfo dato;
  TCadena sig;
  TCadena ant;
};

TCadena crearCadena()
{
  TCadena res = new _rep_cadena;
  return res;
}

void liberarCadena(TCadena cad)
{
  if (cad == NULL)
  {
    return;
  }
  if (cad != NULL)
  {
    bool flag = true;
    TCadena inicio = cad;
    TCadena lugar = cad;
    while (lugar != NULL && flag )
    {
      
      TCadena prox_a_borrar = lugar;
      lugar = lugar->sig;
      flag = lugar != inicio;
      if (prox_a_borrar->dato != NULL)
      {
        liberarInfo(prox_a_borrar->dato);
      }
      delete (prox_a_borrar);
    }
  }
  delete cad;
}

// TInfo inicioCad(TCadena cad)
// {
//   return cad->inicio->dato;
// }
// TInfo finalCad(TCadena cad)
// {
//   return cad->final->dato;
// }

TInfo primeroEnCadena(TCadena cad)
{
  return cad->dato;
};

TCadena cadenaSiguiente(TCadena cad)
{
  if (cad == NULL || cad == cad->sig)
  {
    return cad;
  }
  else
  {
    
    return cad->sig;
  }
};

nat cantidadEnCadena(TCadena cad)
{
  TCadena inicio = cad;
  nat count = 0;
  if (cad != NULL)
  {
    TCadena rec = cad->sig;

    count = 1;

    while (rec != inicio)
    {
      count++;

      rec = rec->sig;
    }
  }

  return count;
}

bool estaEnCadena(nat natural, TCadena cad)
{
  if (cad == NULL)
  {
    return false;
  }
  else
  {
    TCadena inicio = cad;
    TCadena rec = inicio;
    while ((rec != NULL) && (natInfo(rec->dato) != natural))
    {
      if (rec->sig != cad->inicio)
      {
        rec = rec->sig;
      }
      else
      {
        break;
      }
    }
    if (natInfo(rec->dato) == natural)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad)
{
  TCadena in = new nodoCadena;
  TInfo dato = crearInfo(natural, real);
  in->dato = dato;
  if (cad->inicio == NULL)
  {
    in->sig = in;
    cad->final = in;
  }
  else
  {
    in->sig = cad->inicio;
  }
  cad->inicio = in;
  cad->final->sig = in;
  return cad;
}

TInfo infoCadena(nat natural, TCadena cad)
{

  TCadena rec = cad->inicio;
  while (natInfo(rec->dato) != natural)
  {
    rec = rec->sig;
  }

  return rec->dato;
}
/*
  Remueve el primer elemento de 'cad' cuyo componente natural es 'natural'.
  Se libera la memoria asignada al mismo.
  Devuelve 'cad'.
  Precondición: estaEnCadena(natural, cad).
 */
TCadena removerDeCadena(nat natural, TCadena cad)

{
  TCadena rec = cad->inicio;
  // si tiene solo un elemento, borro info y cad
  if (rec->sig == rec)
  {
    liberarInfo(rec->dato);
    delete rec;
    cad->final = cad->inicio = NULL;
    return cad;
  }
  else
  // si tiene mas de un elemento, busco
  {
    // pregunto si el buscado está en el inicio
    if (natInfo(cad->inicio->dato) == natural)
    {
      TCadena aBorrar = cad->inicio;
      TCadena newStart = cad->inicio->sig;
      cad->inicio = newStart;
      cad->final->sig = newStart;
      liberarInfo(aBorrar->dato);
      delete aBorrar;
      return cad;
    }

    else
    {
      TCadena rec = cad->inicio;
      TCadena anteriorABorrar;
      while (natInfo(rec->dato) != natural)
      {
        // guardo posicion actual por si la siguiente encuentra
        anteriorABorrar = rec;
        rec = rec->sig;
      }

      // asigno aux al primero de cad si el elemento a remover es el ultimo
      if (rec == cad->final)
      {
        cad->final = anteriorABorrar;
        anteriorABorrar->sig = cad->inicio;
      }

      // asigno aux al siguiente elemento
      else
      {
        anteriorABorrar->sig = rec->sig;
      }
      liberarInfo(rec->dato);
      delete rec;
      return cad;
    }
  }
}

void imprimirCadena(TCadena cad)
{
  TCadena rec = cad->inicio;
  if (rec != NULL)
  {
    char *dat = infoATexto(rec->dato);
    printf("%s", dat);
    delete[] dat;
    rec = rec->sig;
    while (rec != cad->inicio)
    {
      char *dat = infoATexto(rec->dato);
      printf("%s", dat);
      delete[] dat;
      rec = rec->sig;
    }
  }
  printf("\n");
}