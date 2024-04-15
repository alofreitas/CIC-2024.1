public class Ponto2D {
    private double x,y;
    private double rho,theta;
    private boolean cart;
    private boolean polar;

public Ponto2D (double rho, double theta, boolean polar){
    if ((rho < 0) || (theta < -180 && theta > 180))
    polar = false;
   
    if(polar == true){
        this.rho = rho;
        this.theta = theta;
        this.x = x_polcart(rho,theta);
        this.y = y_polcart(rho,theta);
    }
    else{
        this.x = rho;
        this.y = theta;
        this.rho = rho_cartpol(x,y);
        this.theta = theta_cartpol(x,y);
    }
    }
public Ponto2D (Ponto2D outroPonto){
    this.x = outroPonto.x;
    this.y = outroPonto.y;
    this.rho = outroPonto.rho;
    this.theta = outroPonto.theta;
}

public double rho_cartpol(double x, double y){
   rho = Math.sqrt(x*x+ y*y);
   return rho;
}

public double theta_cartpol(double x, double y){
   theta = Math.atan(y/x);
   return theta;
}

public double x_polcart(double rho, double theta){
    x = rho * Math.cos(theta);
    return x;
}

public double y_polcart(double rho, double theta){
    y = rho * Math.sin(theta);
    return y;
}

public void change_x(double x1){
    rho = Math.sqrt(x1*x1+ y*y);
    theta = Math.atan(y/x1);
    y = rho * Math.sin(theta);
}

public void change_y (double y1){
    rho = Math.sqrt(x*x+ y1*y1);
    theta = Math.atan(y1/x);
    y = rho * Math.sin(theta);
}

public void change_rho (double rho1){
    x = rho1 * Math.cos(theta);
    y = rho1 * Math.sin(theta);
    theta = Math.atan(y/x);
}

public void change_theta (double theta1){
    x = rho * Math.cos(theta1);
    y = rho * Math.sin(theta1);
    rho = Math.sqrt(x*x+ y*y);
}
}