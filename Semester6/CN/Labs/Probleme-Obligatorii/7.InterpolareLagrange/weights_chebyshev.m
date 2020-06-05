function w = weights_chebyshev(m)
    %funcie care calcueaza ponderile pentru nodurile cebisev de speta a
    %II-a
    %m - numarul de noduri
    
    w = [1/2; ones(m-1,1); 1/2].*(-1).^((0:m)');
    w = w';
end