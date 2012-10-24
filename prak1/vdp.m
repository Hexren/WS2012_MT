function [ res ] = vdp( x, y )
% Van-Der-Pol-Gleichung zu Aufgabe 2

res = [y(2); 6 * ( 1 - y(1)^2 ) * y(2) - y(1)]; 

end
