/* 5286580 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/aplicaciones.h"
#include "../include/cadena.h"
#include "../include/iterador.h"
#include "cadena.cpp"

TCadena insertarAlFinal(nat natural, double real, TCadena cad) {

    cad = insertarAlInicio(natural, real, cad);
    cad = cadenaSiguiente(cad);
    return cad;

}

TCadena removerPrimero(TCadena cad) {

  cad = removerDeCadena(natInfo(primeroEnCadena(cad)), cad);
  return cad;
  }


TCadena copiaCadena(TCadena cad) {
  return NULL;
}

TIterador reversoDeIterador(TIterador iter) {
  return NULL;
}


