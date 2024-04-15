public class Taxi{
   private int posx,posy;
  // private boolean mapa2 [][];
   private int mapa[][];
   private int percurso;
   private int meuid;
   private static int id = 0;
 
 public Taxi (int posx, int posy, int RuaV, int RuaH){
   this.posx = posx;
   this.posy = posy;
 //  mapa = mapa[RuaV][RuaH];
   this.percurso = 0;
   id++;
   meuid = id;
 
 }
 
 public Taxi (Taxi outroTaxi){
   this(outroTaxi.mapa.length, outroTaxi.mapa[0].length, outroTaxi.posx, outroTaxi.posy);
 }
 // quem é mapa.length? qtd de linhas
 // quem é mapa.length[0]? qtd de colunasq tem na linha
 
 public Taxi (int posx, int posy){
   
 } 
 
 public boolean right(){
   if (posx == 0)
     return false;
   else{
     posx++;
     percurso++;
     return true;
   }
 }
 
 public boolean left(){
   if (posx > mapa[0].length - 1)
     return false;
   else{
     posx--;
     percurso++;
     return true;
   }
   
 }
 
 public boolean up(){
   if (posy == 0)
     return false;
   else{
     posy--;
     percurso++;
     return true;
   }
 }
 
/*public boolean down(){
   if (mapa)
     return false;
   else{
     posy++;
     percurso++;
     return true;
   }
 }
 */
 
 public String fromAtoB(int x1,int y1, int x2, int y2){
   String rota = "";

   if(!cruzamentoOK)
    return rota;
   else{
    int aux = x1 - x2;
    int aux2 = y1 - y2;
        if (aux > 0)
            for (int i = 0; i< aux;i++)
                rota +="left ";
        if (aux < 0)
            for (int i = 0; i< aux;i++)
                rota+= "right ";
        if (aux2 > 0)
            for (int i = 0; i< aux2;i++)
                rota+= "up ";
        if (aux2 < 0)
             for (int i = 0; i< aux;i++)
                 rota+="down ";
        }
    return rota;
    }
 
 public boolean MovetoB (String path){
 String [] caminho = path.split("\\s");
   for (int i = 0; i < caminho.length; i++){
     if (caminho[i] == "left")
      return left();
     else if (caminho[i] == "right")
      return right();
     else if (caminho[i] == "up")
      return up();
     else if (caminho[i] == "down")
      return down();
    
       }
   if (path == " ")
    return false;
   else 
    return true;
    }
 
 public int DisTotal (){
   
 }
 
 }