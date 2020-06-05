function R=cholesky_decomposition(A)
% Functie care face descompunerea Cholesky a unei matrici
% Descompunerea Cholesky(R) a unei matrici A are proprietatea ca R'*R = A
% Pentru existenta R, matricea A trebuie sa fie Hermiteana pozitiv
% definita
% Exemplu parametrii:
% A = [4 12 -16
%      12 37 -43
%      -16 -43 98]

[m,n]=size(A);
R = A;
for k=1:m
    for j=k+1:m
        R(j,j:m)=R(j,j:m)-R(k,j:m)*R(k,j)/R(k,k);
    end
    R(k,k:m)=R(k,k:m)/sqrt(R(k,k));
end
R = triu(R);
end