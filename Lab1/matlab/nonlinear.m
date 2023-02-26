x1 = -2:0.1:6;
subplot(2,1,1);
plot(x1, f1(x1),'-r');
legend('y=x^4-4x^3-8x^2+1');
hold on;
grid on;

x2 = 0:0.1:3;
subplot(2,1,2);
plot(x2, f2(x2),'-b');
legend('y=x^x+9x-20');
hold on;
grid on;

syms x1
eqn = f1(x1) == 0;
S = vpasolve(eqn, x1);
disp('Solving the 1st equential')
S

syms x2
eqn = f2(x2) == 0;
S = vpasolve(eqn, x2);
disp('Solving the 2nd equential')
S

