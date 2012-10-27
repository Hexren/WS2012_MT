function [ ] = LorenzAttraktor( h, x_end )
%   Lorenz-Attraktor mit Runge-Kutta-Verfahren 2. Ordnung, Aufgabe 3
%   Parameter:
%       h: Schrittweite
%       x_end: Endzeitpunkt der Simulation

% Lorenz-Attraktor mit dem Runge-Kutta-Verfahren berechnen.
[X, RK_Y] = rk2(@dgls, x_end, h, [0.01,0.01,0.0]);

% Funkton x plotten.
figure(1);
plot(X,RK_Y(:,1));
legend('RungeKutta der Funktion x(t)');

% Funkton z plotten.
figure(2);
plot(X,RK_Y(:,3));
legend('RungeKutta der Funktion z(t)');

% Modifizierten Lorenz-Attraktor mit dem Runge-Kutta-Verfahren berechnen.
[X, RK_YM] = rk2(@dglsUngenau, x_end, h, [0.01,0.01,0.0]);

% Funktion x und modifizierte Funktion x plotten.
figure(3);
plot(X,RK_Y(:,1),X,RK_YM(:,1));
legend('RungeKutta der Funktion x(t)', 'RungeKutta der modifizierten Funktion x(t)');

end