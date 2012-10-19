h = 0.001;
vec_ana_x = 0:h:0.2;
vec_ana_y = mtp0101_ana(vec_ana_x);
[vec_eulerexpl_x, vec_eulerexpl_y] = euler_expl(1, h, 0.2, @f);
[vec_eulerimpl_x, vec_eulerimpl_y] = euler_impl(1, h, 0.2, @f);
[vec_runge_x, vec_runge_y] = rungeKutta(1, h, 0.2, @f);


fh = figure('color','w');
subplot(1,2,1)
set(gca,'fontName','Comic Sans MS','fontSize',18,'lineWidth',3,'box','off')

%annotation(fh,'textarrow',[0.38 0.34],[0.42 0.55],...
%     'string',sprintf('analytische Loesung',char(10)),'headStyle','none','lineWidth',1.5,...
%     'fontName','Comic Sans MS','fontSize',14,'verticalAlignment','middle','horizontalAlignment','left')


hold on;
plot(vec_ana_x, vec_ana_y, 'r','lineWidth',3);
plot(vec_eulerexpl_x, vec_eulerexpl_y, 'k','lineWidth',3);
plot(vec_eulerimpl_x, vec_eulerimpl_y, 'g','lineWidth',3);
plot(vec_runge_x, vec_runge_y, 'b','lineWidth',3);
grid on;
title('Approximation');
legend('analytische Loesung', 'Vorwaerts Euler', 'Rueckwaerts Euler', 'Runge-Kutta');
axis([0, 0.04, 0, 0.5]);

%# capture with export_fig
im = export_fig('-nocrop', fh);

%# add a bit of border to avoid black edges
im = padarray(im,[15 15 0],255);

%# make distortion grid
sfc = size(im);
[yy,xx]=ndgrid(1:7:sfc(1),1:7:sfc(2));
pts = [xx(:),yy(:)];
tf = cp2tform(pts+randn(size(pts)),pts,'lwm',12);
w = warning;
warning off images:inv_lwm:cannotEvaluateTransfAtSomeOutputLocations
imt = imtransform(im,tf);
warning(w)

%# remove padding
imt = imt(16:end-15,16:end-15,:);

figure('color','w')
imshow(imt)



%subplot(1,2,2)
%
%hold on;
%plot(vec_eulerexpl_x, vec_eulerexpl_y - vec_ana_y, 'k');
%plot(vec_eulerimpl_x, vec_eulerimpl_y - vec_ana_y, 'g');
%plot(vec_runge_x, vec_runge_y - vec_ana_y, 'b');
%grid on;
%title('Error');
%legend( 'Vorwaerts Euler','Rueckwaerts Euler', 'Runge-Kutta');
%axis([0,0.2, -1.5, 1.5]);
