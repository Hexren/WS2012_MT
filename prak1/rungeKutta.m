function [x, y] = rungeKutta(begin, h, xend, func)
    yn=begin;
    xn=0;
    
    vec_x_tmp=[xn];
    vec_y_tmp=[yn];
    xn = xn + h;
    
    for xn1 = xn:h:xend
        yn1 = yn + h/2 * (func(xn,yn) + f(xn1, yn + h * func(xn,yn)) );
        
        vec_y_tmp=[vec_y_tmp,yn1];
        vec_x_tmp=[vec_x_tmp,xn1];
        
        xn=xn1;
        yn=yn1;
    end
    y = vec_y_tmp;
    x = vec_x_tmp;
end

