public class Contador{
    int cont;

 public Contador(){
    cont = 0;
 }

 public Contador (int valor){
     cont = valor;
 }

 public void incrementa(){
   cont++;
 }

 public void incrementa(int incremento){
     cont+= incremento;
 }

 public void decrementa(){
     cont--;
 }

 public int getValor(){
     return cont;
 }

 public boolean MaiorQue(int val){
     if (cont > val)
       return true;
     else 
       return false;
}

 public boolean MaiorOuIgualQue(int val){
     if ((cont > val) || (cont == val))
       return true;
     else 
       return false;
 }

 public boolean MenorQue(int val){
     if (cont < val)
     return true;
   else 
     return false;
 }

 public boolean MenorOuIgualQue(int val){
     if ((cont < val) || (val == cont))
       return true;
     else 
       return false;
 }

 public boolean Igual(int val){
     if (val == cont)
     return true;
   else 
     return false;
 }
 
 public boolean Diferente(int val){
     if (val != cont)
     return true;
   else 
     return false;
 }
}

