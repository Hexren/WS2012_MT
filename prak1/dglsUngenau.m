function [ res ] = dglsUngenau( t, z )

dx = -10 * (z(1) - z(2));
dy = (40.000000001 - z(3)) * z(1) - z(2);
dz = z(1) * z(2) -2.67 * z(3);

res = [dx, dy, dz]; 

end