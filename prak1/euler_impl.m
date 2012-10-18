function [x, y] = euler_impl(begin, h, xend, func)
    yn=begin;
    xn=0;
    
    vec_x_tmp=[xn];
    vec_y_tmp=[yn];

    for xn1 = xn:h:xend
        options = optimset('Display', 'off');
        yn1Approx = fsolve(@(n)n-yn-h*func(xn1,n), xn1, options);
        yn1 = yn + h * func(xn1, yn1Approx);
        
        vec_y_tmp=[vec_y_tmp,yn1];
        vec_x_tmp=[vec_x_tmp,xn1];
        
        xn=xn1;
        yn=yn1;
    end
    y = vec_y_tmp;
    x = vec_x_tmp;
end

