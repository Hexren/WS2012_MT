function [ y ] = vanDerPol_eins( z1, z2 )
    y = -z2 + 6 * (1-z2^2) * z1;
end

