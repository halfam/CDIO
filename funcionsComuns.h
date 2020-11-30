int tamany =0;
int resultat = 0;


int media(int valor){
  if(tamany < 10){
    resultat += valor;
    tamany++;
  }else{
    return resultat/10;
  }
}

float valorMedio(float maximo, float minimo){
  return (maximo + minimo) / 2;
}
