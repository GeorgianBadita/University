function [p] = pointTriangles(n)
    hold on
    numTri = 0;
    axis([0, 1, 0, 1]);
    for i = 1:n
        canTri = 0;
        x = rand;
        y = rand;
        A = [1/2, 0];
        B = [0, 1/2];
        C = [1/2, 1];
        D = [1, 1/2];
        
        distCadr11 = pdist([x, y; C]);
        distCadr12 = pdist([x, y ; D]);
        
        distCadr21 = pdist([x, y ; C]);
        distCadr22 = pdist([x, y ; B]);
        
        distCadr31 = pdist([x, y ; B]);
        distCadr32 = pdist([x, y ; A]);
        
        distCadr41 = pdist([x, y ; A]);
        distCadr42 = pdist([x, y ; D]);
        
        if distCadr11 < 1/2 && distCadr12 < 1/2
            canTri=1;
        end
        
        if distCadr21 < 1/2 && distCadr22 < 1/2
            canTri=1;
        end
        
        if distCadr31 < 1/2 && distCadr32 < 1/2
            canTri=1;
        end
        
        if distCadr41 < 1/2 && distCadr42 < 1/2
            canTri=1;
        end
        
        
        if canTri == 1
            plot(x, y, 'b*');
            numTri = numTri + 1;
        end
    end
    p = numTri/n;
end