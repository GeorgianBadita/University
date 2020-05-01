function [x,y,z]=cramer33(a,b,c,m, d, e, f, n, g, h, i, o)
    
    %ax + by + cz = m
    %dx + ey + fz = n
    %gx + hy + iz = o
    
    delta = a*(e*i-h*f)-b*(d*i-g*f)+c*(d*h-g*e); % 14 flops
    deltaX = m*(e*i-h*f)-b*(n*i-o*f)+c*(n*h-o*e); % 14 flops
    deltaY = a*(n*i-o*f)-m*(d*i-g*f)+c*(d*o-g*n); % 14 flops
    deltaZ = a*(e*o-h*n)-b*(d*o-g*n)+m*(d*h-g*e); % 14 flops
    x = deltaX/delta; % 1 flop
    y = deltaY/delta; % 1 flop
    z = deltaZ/delta; % 1 flop
    % total: 59 flops
end