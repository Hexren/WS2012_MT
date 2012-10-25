function [  ] = vanDerPollZeigen( y1Sim, y2Sim, h )
    sum(Prak1Aufg2Simulink)
    [~, Y_E] = eulerE(@vdp, 31, h, [0;1]);
    [X, Y_RK] = rk2(@vdp, 31, h, [0;1]);
    
    
   hold on;
    subplot(121);
    p1=plot(y2Sim.time, y2Sim.signals.values ,'b-', X,Y_E(:,1),'r:', X,Y_RK(:,1), 'g:');
    set(p1,'LineWidth',2);
    title('Runge Kutta 2');
    legend('y1Simulink', 'y1Euler', 'y1 RK2');

    subplot(122);
    p2=plot(y1Sim.time, y1Sim.signals.values ,'b-', X,Y_E(:,2),'r:', X,Y_RK(:,2), 'g:');
    set(p2,'LineWidth',2);
    title('Runge Kutta 2');
    legend('y2Simulink', 'y2Euler', 'y2 RK2');

end

