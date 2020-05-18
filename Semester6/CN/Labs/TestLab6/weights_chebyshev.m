function w = weights_chebyshev(m)
    w = [1/2; ones(m-1,1); 1/2].*(-1).^((0:m)');
    w = w';
end