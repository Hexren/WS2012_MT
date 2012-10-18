function [x, y] = euler_expl(begin, h, xend, f)
%euler expl

    yn=begin;
    xn=0;
    
    vec_x_tmp=[xn];
    vec_y_tmp=[yn];

    for xn1 = xn:h:xend
        yn1 = yn + h * f(xn,xn);
        
        vec_y_tmp=[vec_y_tmp,yn1];
        vec_x_tmp=[vec_x_tmp,xn1];
        
        xn=xn1;
        yn=yn1;
    end

    x = vec_x_tmp
    y = vec_y_tmp

end

