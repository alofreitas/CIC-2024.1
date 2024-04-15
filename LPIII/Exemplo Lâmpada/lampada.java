public class lampada {
    private int vidautil;
    private boolean estado;

    public lampada(int vidautil){
        this.vidautil = vidautil;
        this.estado = false;
    }

    public boolean ligar(){
        if(estadoLamp()){
            return false;
        } else{
            if (queimada()){
                return false;
            } else{
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