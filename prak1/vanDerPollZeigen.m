function [  ] = vanDerPollZeigen( y1Sim, y2Sim, h )
    sum(Prak1Aufg2Simulink)
    %[x, y1, y2] = vanDerPolEuler(h, 31);
    [x, y1, y2] = this_rk2(h,31);
    
   hold on;
    subplot(121);
    p1=plot(x,y1,'r:',y1Sim.time, y1Sim.signals.values ,'b-');
    set(p1,'LineWidth',2);
    title('Euler Explizit');
    legend('y1Euler','y1Simulink');

    subplot(122);
    p2=plot(x,y2,'r:',y2Sim.time, y2Sim.signals.values ,'b-');
    set(p2,'LineWidth',2);
    title('Euler Explizit');
    legend('y2Euler','y2Simulink');

end

