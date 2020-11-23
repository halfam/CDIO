int tamany =0;
int resultat = 0;
int media(int valor){
  if(tamany < 100){
    resultat += valor;
    tamany++;
  }else{
    return resultat/100;
  }
}

float valorMedio(float maximo, float minimo){
  return (maximo + minimo) / 2;
}
