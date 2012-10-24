function [ X, Y ] = rk2( func, t, h, init )
%Generisches erstes Runge-Kutta-Verfahren 2. Ordnung
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

for k=h:h:t
    f = y + h * func(k, y);
    y = y + (h/2) * (func(k, y) + func(k+h, f));
    
    X(index) = k;
    Y(index,:) = y;
    index = index + 1;
end
end
