vec_ana_x = 0:h:0.2;
vec_ana_y = mtp0101_ana(vec_ana_x);
[vec_eulerexpl_x, vec_eulerexpl_y] = euler_expl(0, 0.001, 0.05, @f);



subplot(1,2,1)
hold on;
plot(vec_eulerexpl_x, vec_eulerexpl_y, 'r');
%plot(vec_eulerexpl_x, vec_eulerexpl_y, 'k');
%plot(vec_eulerimpl_x, vec_eulerimpl_y,'g');
%plot(vec_rk2_x, vec_rk2_y,'m');
grid on;
title('Approximation');
legend('analytische Loesung', 'Vorwaerts Euler','Rueckwaerts Euler', 'Runge-Kutta');
axis([0, 0.05, 0, 0.2]);