function [ x, y1n, y2n ] = vanDerPolEuler(h, xend )

    y1n=1;
    y2n=2;
    xn=0;
    
    vec_x_tmp=[xn];
    vec_y1n_tmp=[y1n];
    vec_y2n_tmp=[y2n];
    xn = xn + h;    

    for xn1 = xn:h:xend
        y1n1 = y1n + h * vanDerPol_eins(y1n,y2n);
        y2n1 = y2n + h * vanDerPol_zwei(y1n);
        
        vec_y1n_tmp=[vec_y1n_tmp,y1n1];
        vec_y2n_tmp=[vec_y2n_tmp,y2n1];
        vec_x_tmp=[vec_x_tmp,xn1];
        
        y1n=y1n1;
        y2n=y2n1;
    end
    y1n = vec_y1n_tmp;
    y2n = vec_y2n_tmp;
    x = vec_x_tmp;
end



