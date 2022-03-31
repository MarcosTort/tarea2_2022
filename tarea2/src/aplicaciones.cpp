/* 5286580 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/aplicaciones.h"
#include "../include/cadena.h"
#include "../include/iterador.h"

TCadena insertarAlFinal(nat natural, double real, TCadena cad)
{

  cad = insertarAlInicio(natural, real, cad);
  cad = cadenaSiguiente(cad);
  return cad;
}

TCadena removerPrimero(TCadena cad)
{

  cad = removerDeCadena(natInfo(primeroEnCadena(cad)), cad);
  return cad;
}

TCadena copiaCadena(TCadena cad)
{
  TCadena copia = crearCadena();
  TCadena partida = cad;
  TInfo info = primeroEnCadena(partida);
  copia = insertarAlFinal(natInfo(info), realInfo(info), copia);
  cad = cadenaSiguiente(cad);

  while (cad != partida)
  {
    TInfo info = primeroEnCadena(partida);
    copia = insertarAlFinal(natInfo(info), realInfo(info), copia);
    cad = cadenaSiguiente(cad);
  }
  return copia;
}

TIterador reversoDeIterador(TIterador iter)
{
  TIterador reverso = crearIterador();

  reiniciarIterador(iter);
  reiniciarIterador(reverso);

  while (estaDefinidaActual(iter))
  {
    nat entrante = actualEnIterador(iter);
    agregarAIterador(entrante, reverso);
  }
  reiniciarIterador(iter);
  reiniciarIterador(reverso);

  return reverso;
}
