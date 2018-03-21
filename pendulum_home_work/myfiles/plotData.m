m=dlmread("data.csv");
t=m(2:end,1);
rk=m(2:end,2);
sa=m(2:end,3);
plot(t,rk,"r",t,sa,"b");
grid on;
title("theta vs time for a quarter period")
xlabel("time (s)");
ylabel("theta (degrees)");
legend("RK4","Small Angle Approximation");
