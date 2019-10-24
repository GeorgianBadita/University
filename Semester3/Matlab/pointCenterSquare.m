function [p] = pointCenterSquare(n)
    
    closerCenter = 0;
    hold on
    
    for i = 1:n
        x = rand;
        y = rand;
        xCentru=1/2;
        yCentru=1/2;
        distCentru = pdist([x, y ; xCentru, yCentru]);
        dist00 = pdist([x,y ; 0, 0]);
        dist01 = pdist([x, y ; 0, 1]);
        dist11 = pdist([x,y ; 1,1]);
        dist10 = pdist([x,y ; 1, 0]);
        if distCentru < dist00 && distCentru < dist01 && distCentru < dist11 && distCentru < dist10
            closerCenter = closerCenter +1;
            plot(x, y, 'b*');
        end
    end
    p = closerCenter/n;
end