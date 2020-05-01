function [x,y]=cramer22(a, b, e, c, d, f)
    
    % ax + by = e
    % cx + dy = f
    
    delta = a*d - b*c; % 3 flops
    deltaX = e*d - f*b; % 3 flops
    deltaY = a*f - c*e; % 3 flops
    x = deltaX / delta; % 1 flop
    y = deltaY / delta; % 1 flop
    % total: 11 flops
end