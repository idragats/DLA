%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
%      Plot DLA fractal       %    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
clc; clear; 
myfile=load("DLA.txt");
x=myfile(:,1);
y=myfile(:,2);
% r=200;
%    theta = linspace(0,2*pi);
%      x1 = r*cos(theta) + r;
%      y1 = r*sin(theta) + r;
%      figure(1)
%      plot(x1,y1,'-black')
%      xlabel("x")
%      ylabel("y")
%      title("DLA - fractal (grid coordinations)") 
%      hold on 
     plot(x,y,'*')
     hold on
     plot(x,y,'.')
    axis([0 2*r 0 2*r])

    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
% Calculate fractal Dimension %    
%%%%%%%%%%%%%%%%%%%%%%%%%%5%%%%    
    
L=10:10:100;  %Length squares
M(10)=0;      %number of new naighbors at every square 
MM(10)=0;     %mean of squares 
for j=1:10
    for N=1:20 % iterations
        Random_number= (r+L(j)/2-(r-L(j)/2))*rand + (r-L(j)/2);
        min=Random_number-L(j)/2;
        max=Random_number+L(j)/2;
        for i=1:length(x)
            if (x(i)>=min) && (x(i)<=max) && (y(i)>=min) && (y(i)<=max)
                M(j)=M(j)+1;
            end
        end
    end
    MM(j)=M(j)/20;
end

% figure
figure(2)
plot(log10(L),log10(MM),'+r')
hold on
p=polyfit(log10(L),log10(MM),1);
f=polyval(p,log10(L));
plot(log10(L),f)
legend('data',['Linear Ewuation is:y=',num2str(p(1)),'*x + ','(',num2str(p(2)),')'],'Location','northwest');
xlabel("Log(L)")
ylabel("Log(M)")
title("fractal Dimension")

