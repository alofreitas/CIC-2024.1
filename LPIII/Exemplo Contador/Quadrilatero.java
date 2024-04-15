public class Quadrilatero {
    private double xa, xb, xc, xd, ya, yb, yc, yd;
    private static int quad = 0;
    private int meu_quad;
  
    public Quadrilatero(double xa, double xb, double xc, double xd, double ya, double yb, double yc, double yd) {
      this.xa = xa;
      this.xb = xb;
      this.xc = xc;
      this.xd = xd;
      this.ya = ya;
      this.yb = yb;
      this.yc = yc;
      this.yd = yd;
      quad++;
      meu_quad = quad;
    }

    public Quadrilatero(double xa, double xc, double ya, double yc) {
      this.xa = xa;
      this.ya = ya;
      this.xc = xc;
      this.yc = yc;
      xd = xa;
      yd = yc;
      xb = xc;
      yb = ya;
    }
  
    public double[] GetVertices() {
      double[] vertices = { 0 };
      vertices[0] = xa;
      vertices[1] = ya;
      vertices[2] = xb;
      vertices[3] = yb;
      vertices[4] = xc;
      vertices[5] = yc;
      vertices[6] = xd;
      vertices[7] = yd;
  
      return vertices;
    }
  
    public boolean eRetangulo() {
      if ((xa == xb && xc == xd) && (yb == yc && ya == yd) && (ya - yb == yc - yd && xb - xc == xa - xd)) 
            return true;
          else
            return false;
      }
  
    public boolean eQuadrado() {
      if ((eRetangulo() == true) && (ya - yb == xb - xc)) 
          return true;
      else
        return false;
    }
  
    public static int quantosQuadrilateros() {
      return quad;
    }
  
    public int qualMeuNumero() {
      return meu_quad;
    }
  }