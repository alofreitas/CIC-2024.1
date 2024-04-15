public class lampdimmer {
    private int vidautil;
    private boolean estado;
    private int lum;

    public lampdimmer(int vidautil, int lum){
        this.vidautil = vidautil;
        this.lum = lum;
        this.estado = false;
    }

    public boolean ligar(int lum){
        if(estadoLamp()){
            return false;
        } else{
            if (queimada()){
                return false;
            } else{
                this.lum = lum;
                estado = true;
                vidautil--;
                return true;
            }
        }
    }

    public boolean desligar(){
        if(!estadoLamp()){
            return false;
        } else{
            if (queimada()){
                return false;
            } else{
                estado = false;
                this.lum = 0;
                return true;
            }
        }
    }

    public boolean estadoLamp() {
        return estado;
    }

    public boolean queimada(){
        if (vidautil != 0){
            return false;
        } else{
            estado = false;
            return true;
        }
    }

    public int qntVidaUtil() {
        return vidautil;
    }
}