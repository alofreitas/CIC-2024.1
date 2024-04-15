public class Main {
    public static void main(String[] args) {
        int val = 10;
        Contador Meu_contador = new Contador();
        if (Meu_contador.MenorOuIgualQue(val))
            Meu_contador.incrementa(5);
        else{
            for (int i = 0; i < 5; i++)
            Meu_contador.decrementa();
        }

        System.out.println("Contador: " + Meu_contador.getValor());
        System.out.println("Valor: " + val);
    }
}
