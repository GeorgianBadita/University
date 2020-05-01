function b = construct_b_vector(n)
 b=[2.5; 1.5*ones(n/2-2,1);1;1; 1.5*ones(n/2-2,1); 2.5];
end

%!assert (construct_b_vector(6).' == [5/2, 3/2, 1, 1, 3/2, 5/2])