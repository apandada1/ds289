function b=solidPlot(n,xDiv,yDiv)

  xMin=-3;xMax=2;yMin=-3;yMax=3;
  xStepSize=(xMax-xMin)/xDiv;
  yStepSize=(yMax-yMin)/yDiv;
  x=xMin;y=yMin;
  
  # Setting up growth polynomial
  if(n==1)
    G=[1 1];
  elseif(n==2)
    G=[1/2 1 1];
  elseif(n==3)
    G=[1/6 1/2 1 1];
  elseif(n==4)
    G=[1/24 1/6 1/2 1 1];
  end
  G
  #Color matrix based on growth factor value
  for l=1:yDiv
    x=xMin;
    for k=1:xDiv
      if(abs(polyval(G,x+i*y))<=1)
        #abs(polyval(G,x+i*y))
        C(l,k)=60;
        x=x+xStepSize;
      else
        #abs(polyval(G,x+i*y))
        C(l,k)=0;
        x=x+xStepSize;
      end
    end
    y=y+yStepSize;
  end
  #C
  X=[xMin xMax];
  Y=[yMin yMax];
  image(X,Y,C);
  grid on;
  set(gca,'YDir','normal');
  line([0 0], ylim); # y-axis
  line(xlim, [0 0]); # x-axis
end
  