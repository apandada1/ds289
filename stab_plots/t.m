z=[2+3i 1+4i];
psi= -pi;
z=roots([1/24 1/6 1/2 1 1-exp(i*psi)]);
z(1,1);
r=1;
nIter=500;
stepSize=2*pi/nIter;
for l=1:nIter
      z=roots([1 1-exp(i*psi)]);
      y(r)=imag(z);
      x(r)=real(z);
      r++;
      psi=psi+stepSize;
end 
C = [0 2 4 6; 8 10 12 14; 16 18 20 22; 4 30 9 6];
X=[-1.5 1.5];
Y=[-1.5 1.5];
image(X,Y,C);
set(gca,'YDir','normal');