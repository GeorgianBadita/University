function x = solve_cholesky(A,b)
    R = transpose(cholesky_decomposition(A)); 
    
    y = forwardsubst(R, b);
    x = backsubst(R', y);
    
end