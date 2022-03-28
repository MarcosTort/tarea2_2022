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
  _rep_cadena *sig;
  _rep_cadena *inicio, *final;
};

TCadena crearCadena()
{
  TCadena res = new _rep_cadena;
  res->inicio = res->final = NULL;
  return res;
}

void liberarCadena(TCadena cad)
{

  if (cad != NULL)
  {
    while (cad->sig != NULL)
    {
      TCadena prox_a_borrar = cad->inicio;
      cad->inicio = cad->inicio->sig;
      liberarInfo(prox_a_borrar->dato);
      delete (prox_a_borrar);
    }
  }
}

TInfo primeroEnCadena(TCadena cad)
{
  return cad->inicio->dato;
};

TCadena cadenaSiguiente(TCadena cad)
{
  if(cad == NULL || cad->inicio == cad->final){
    return cad;
  }
  else{
    TCadena resultado = cad->sig;
  }
};

nat cantidadEnCadena(TCadena cad)
{
  nat count = 0;
  if (cad == NULL)
  {
    return count;
  }
  else
  {
    count = 1;
    while (cad->sig != cad->inicio)
    {
      count++;
      cad = cad->sig;
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
    while ((cad != NULL) && (natInfo(cad->dato) != natural))
    {
      if (cad->sig != cad->inicio)
      {
        cad = cad->sig;
      }
      else
      {
        break;
      }
    }
    if (natInfo(cad->dato) == natural)
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
  TCadena q = new _rep_cadena;
  TInfo dato = crearInfo(natural, real);
  q->dato = dato;
  q->sig = cad;
  if (cad == NULL)
  {
    cad->final = q;
  }
  cad = q;
  cad->inicio = q;
  return cad;
}

TInfo infoCadena(nat natural, TCadena cad)
{
  ////////printf("info cadena");
  while (natInfo(cad->dato) != natural)
  {
    cad = cad->sig;
  }

  return cad->dato;
}
/*
  Remueve el primer elemento de 'cad' cuyo componente natural es 'natural'.
  Se libera la memoria asignada al mismo.
  Devuelve 'cad'.
  Precondición: estaEnCadena(natural, cad).
 */
TCadena removerDeCadena(nat natural, TCadena cad)

{
  // si tiene solo un elemento, borro info y cad
  if (cad->sig == cad->inicio)
  {
    liberarInfo(cad->dato);
    delete cad;
    return NULL;
  }
  else
  // si tiene mas de un elemento, busco
  {
    TCadena cadd = cad;

    // pregunto si el buscado está en el inicio
    if (natInfo(cadd->dato) == natural)
    {
      TCadena newStart = cadd->sig;
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
        // guardo posicion actual por si la siguiente encuentra
        aux = cadd;
        cadd = cadd->sig;
      }

      // q apunta a cad
      TCadena q = cadd;

      // asigno aux al primero de cad si el elemento a remover es el ultimo
      if (q->sig == cadd->final)
      {
        aux->sig = cadd->inicio;
      }

      // asigno aux al siguiente elemento
      else
      {
        aux->sig = q->sig;
      }
      liberarInfo(q->dato);
      delete q;
      return cad;
    }
  }
}

void imprimirCadena(TCadena cad)
{
  char *dat = infoATexto(cad->dato);
  printf("%s", dat);
  delete[] dat;
  cad = cad->sig;
  while (cad != cad->inicio)
  {
    char *dat = infoATexto(cad->dato);
    printf("%s", dat);
    delete[] dat;
    cad = cad->sig;
  }
  printf("\n");
}
