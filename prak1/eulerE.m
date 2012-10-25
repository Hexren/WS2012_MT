function [ X, Y ] = eulerE( func, t, h, init )
%Generisches explizites Euler verfhren
%   Parameter:
%       func: Zeiger auf die DGL
%       t: Endzeitpunkt der Simulation
%       h: Schrittweite
%       init: Anfangswert der Funktion

Y = zeros(t/h,length(init));
X = zeros(t/h,1);

y = init;
index = 1;
	
X(index) = 0;
Y(index,:) = y;

for k=0:h:t
    y = y + h * func(k, y);
    
    X(index) = k;
    Y(index,:) = y;
    index = index + 1;
end
end
