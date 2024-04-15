public class Main_Lamp {
    public static void main(String[] args) {
        lampada lamp = new lampada(2);
        lampdimmer dimmer = new lampdimmer(10, 20);

        System.out.println("Está queimada: " + lamp.queimada());
        System.out.println("Está ligada: " + lamp.estadoLamp());
        System.out.println("Vida util: " + lamp.qntVidaUtil());

        for (int c = 0; c < 2; c++){
            if (c % 2 != 0){
                lamp.desligar();
            } else{
                lamp.ligar();
            }
            System.out.println("\nEstá queimada: " + lamp.queimada());
            System.out.println("Está ligada: " + lamp.estadoLamp());
            System.out.println("Vida util: " + lamp.qntVidaUtil());
        }
    }
}