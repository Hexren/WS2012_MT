figure('Position', [100 460 1120 420]);
a(1) = subplot(121); a(2) = subplot(122);

x = 0:.05:2*pi;
y1 = zeros(size(x));  % flat line
y2 =  mod(round(x / pi),2)*1.5 - .75; % Square wave
y3 = .2 + .6 * sin(x); % sine wave

plot(x,y1,x,y2,x,y3, 'linewidth', 4, 'Parent', a(1));
plot(x,y1,x,y2,x,y3, 'linewidth', 4, 'Parent', a(2));
set(a, 'XLim', [x(1) - .25, x(end)+.25], 'YLim', [-.9 .9]);

xkcdify(a(2));