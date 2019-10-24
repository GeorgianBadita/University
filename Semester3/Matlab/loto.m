function [rez]=loto(n, nums)
    rez=zeros(1, 7);
    bwin = randsample(1:nums, 6, false);
    
    for i = 1:n
        b = randsample(1:nums, 6, false);
        x = ismember(bwin, b);
        c = sum(x);   
        rez(c + 1) = rez(c + 1) + 1; 
    end
end
