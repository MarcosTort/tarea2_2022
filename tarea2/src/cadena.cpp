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
  return NULL;
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
// TCadena inicioCadena(TCadena cad){
//   return cad->inicio;
// }

// TCadena finalCadena(TCadena cad){
//   return cad->final;
// }
TCadena cadenaSiguiente(TCadena cad)
{
  if(cad == NULL || cad->inicio == cad->final){
    return cad;
  }
  else{
    TCadena fin = cad->final->sig;
    TCadena inicio = cad->inicio->sig;
    TCadena resultado = cad->sig;
    resultado->inicio = inicio;
    resultado->final = fin;
    return resultado;
  }
};

nat cantidadEnCadena(TCadena cad)
{
  cad = cad->inicio;
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
  cad = cad->inicio;
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
  printf("%s", "Inicio");
  TCadena q = crearCadena();
  printf("%s", "121");
  TInfo dato = crearInfo(natural, real);
  printf("%s", "123");
  q->dato = dato;
  printf("%s","125");
  cad = cad->inicio;
  printf("%s", "127");
  q->sig = cad;
  printf("%s","129");
  
  if (cad == NULL)
  {
    printf("%s","entra a if");
    cad->final = q;
    printf("%s","135");
  }
  cad = q;
  printf("%s","138");
  cad->inicio = q;
  printf("%s","140");
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

    // pregunto si el buscado está en el inicio
    if (natInfo(cad->inicio->dato) == natural)
    {
      TCadena newStart = cad->sig;
      cad->inicio = newStart;
      cad->final->sig = newStart;
      TCadena aux = cad;
      liberarInfo(aux->dato);
      delete aux;
      return newStart;
    }

    else
    {
      TCadena aux = cad;
      while (natInfo(cad->dato) != natural)
      {
        // guardo posicion actual por si la siguiente encuentra
        aux = cad;
        cad = cad->sig;
      }

      // q apunta a cad
      TCadena q = cad;

      // asigno aux al primero de cad si el elemento a remover es el ultimo
      if (q == cad->final)
      {
        aux->sig = cad->inicio;
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
  if(cad->inicio != NULL){
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
  }}
  printf("\n");
}