function [x, y] = euler2_expl(begin, h, xend)
    yn=begin;
    xn=0;

    vec_x_tmp=[xn];
    vec_y_tmp=[yn];

    for xn1 = xn:h:xend
        %yn+1 = yn + h * f(xn,yn)
        %xn+1 = xn + h
        
        yn1=yn+h*(10-500*yn+5000*xn);
        
        vec_y_tmp=[vec_y_tmp,yn1];
        vec_x_tmp=[vec_x_tmp,xn1];
  
        xn=xn1;
        yn=yn1;
    end
    y = vec_y_tmp;
    x = vec_x_tmp;
end