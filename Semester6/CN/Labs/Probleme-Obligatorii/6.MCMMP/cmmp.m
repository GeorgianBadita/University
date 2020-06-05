function y=cmmp(X,Y,x)
    %X - nodurile 
    %Y - f(X)
    %x - punctele unde vrem sa approximam
    %y - rezultatul aproximarii
    
    powers = [1:length(X) - 2];
    E = [ones(size(X')), X'.^powers];
    c = E\Y';
    %c = [1, 2, 3, 4, 1, 2]
    %appox(x) = 1 + 2x + 3x^2 + ... 
    y = [ones(size(x')), x'.^powers]*c;
end