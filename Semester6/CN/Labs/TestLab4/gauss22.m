function [x,y]=gauss22(a,b,e,c,d,f)
    %ax + by = e
    %cx + dy = f
    m = c/a;      % 1 flop
    d = d-b*m;    % 2 flops
    f = f-e*m;    % 2 flops
    y = f/d;      % 1 flop
    x = (e-b*y)/a;  % 3 flops
    % total: 9 flops
end