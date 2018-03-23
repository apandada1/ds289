function b=boundaryPlot(n,nIter)
  angle=-pi;
  r=1;
  stepSize=2*pi/nIter;
  if(n==1)
    for l=1:nIter
      z=roots([1 1-exp(i*angle)]);
      y(r)=imag(z);
      x(r)=real(z);
      r++;
      angle=angle+stepSize;
    end  
  elseif(n==2)
    for l=1:nIter
      z=roots([1/2 1 1-exp(i*angle)]);
      for k=1:2
        y(r)=imag(z(k,1));
        x(r)=real(z(k,1));
        r++;
      end  
      angle=angle+stepSize;
    end 
  elseif(n==3)
    for l=1:nIter
      z=roots([1/6 1/2 1 1-exp(i*angle)]);
      for k=1:3
        y(r)=imag(z(k,1));
        x(r)=real(z(k,1));
        r++;
      end  
      angle=angle+stepSize;
    end
  elseif(n==4)
    for l=1:nIter
      z=roots([1/24 1/6 1/2 1 1-exp(i*angle)]);
      for k=1:4
        y(r)=imag(z(k,1));
        x(r)=real(z(k,1));
        r++;
      end  
      angle=angle+stepSize;
    end
  end
 plot(x,y,".");
 xlim([-4 4]);
 ylim([-4 4]);
 grid on;
 line([0 0], ylim); # y-axis
 line(xlim, [0 0]); # x-axis
  