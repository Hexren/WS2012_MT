function [] = stiff(h)

    vec_ana_x = 0:h:0.2;
    vec_ana_y = mtp0101_ana(vec_ana_x);
    [vec_eulerexpl_x, vec_eulerexpl_y] = euler_expl(1, h, 0.2, @f);
    [vec_eulerimpl_x, vec_eulerimpl_y] = euler_impl(1, h, 0.2, @f);
    [vec_runge_x, vec_runge_y] = rungeKutta(1, h, 0.2, @f);


    fh = figure('color','w');
    screen_size = get(0, 'ScreenSize');
    set(fh, 'Position', [0 0 screen_size(3) screen_size(4) ] );
    a = subplot(1,2,1);
    %set(gca,'fontName','Humor Sans111','fontSize',14,'lineWidth',3,'box','off')

    lw = 1;


    %annotation(fh,'textarrow',[0.38 0.34],[0.42 0.55],...
    %     'string',sprintf('analytische Loesung',char(10)),'headStyle','none','lineWidth',1.5,...
    %     'fontName','Comic Sans MS','fontSize',14,'verticalAlignment','middle','horizontalAlignment','left')


    hold on;
    plot(vec_ana_x, vec_ana_y, 'r','lineWidth',lw);
    plot(vec_eulerexpl_x, vec_eulerexpl_y, 'k','lineWidth',lw);
    plot(vec_eulerimpl_x, vec_eulerimpl_y, 'g','lineWidth',lw);
    plot(vec_runge_x, vec_runge_y, 'b','lineWidth',lw);
    grid off;
    title('Approximation');
    legend('analytische Loesung', 'Expl Euler', 'Impl Euler', 'Runge-Kutta');
    axis([0, 0.12, 0, 5]);

    %xkcdify(a)



    subplot(1,2,2)
    %
    hold on;
    plot(vec_eulerexpl_x, vec_eulerexpl_y - vec_ana_y, 'k');
    plot(vec_eulerimpl_x, vec_eulerimpl_y - vec_ana_y, 'g');
    plot(vec_runge_x, vec_runge_y - vec_ana_y, 'b');
    grid on;
    title('Error');
    legend( 'Expl Euler','Impl Euler', 'Runge-Kutta');
    axis([0,0.2, -1.5, 1.5]);

end