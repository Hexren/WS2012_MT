h = 0.001;
vec_ana_x = 0:h:0.2;
vec_ana_y = mtp0101_ana(vec_ana_x);
[vec_eulerexpl_x, vec_eulerexpl_y] = euler_expl(1, h, 0.2, @f);
[vec_eulerimpl_x, vec_eulerimpl_y] = euler_impl(1, h, 0.2, @f);
[vec_runge_x, vec_runge_y] = rungeKutta(1, h, 0.2, @f);


subplot(1,2,1)
hold on;
plot(vec_ana_x, vec_ana_y, 'r');
plot(vec_eulerexpl_x, vec_eulerexpl_y, 'k');
plot(vec_eulerimpl_x, vec_eulerimpl_y, 'g');
plot(vec_runge_x, vec_runge_y, 'b');
grid on;
title('Approximation');
legend('analytische Loesung', 'Vorwaerts Euler', 'Runge-Kutta');
axis([0, 0.05, 0, 0.2]);