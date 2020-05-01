function lorentzTest(v) 
 
c = 299792458; % m/s
v_ms = v * 5/18; %m/s 

approx_matlab=1/sqrt(1-v_ms^2/c^2)

approx_taylor_O4= lorentzTaylorDeg2(v_ms/c)

approx_taylor_conv = lorentzTaylorConv(v_ms/c)

approx_vpa = double(vpa(1/sqrt(1-(sym(v) * sym(5) / sym(18))^2/sym(c)^2),1000))


err_matlab = approx_vpa - approx_matlab

err_taylor_O4 = approx_vpa - approx_taylor_O4

err_taylor_conv = approx_vpa - approx_taylor_conv

end
