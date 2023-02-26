clc
ezplot('x.^2 + y.^2 = 5');
hold on;
ezplot('y = exp(-x.*y)');
title('The system of nonlinear functions')
grid on;

func = @(x)f_syst(x);
x1 = [-0.4; 2.2];
fsolve(func, x1)

x2 = [2.2; 0.5];
fsolve(func, x2)
