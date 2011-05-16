   
% fajlok beolvasasa es feldolgozasa
     d=dir('saf_*'); % <- retrieve all names: file(s) and folder(s)
     d=d(~[d.isdir]); % <- keep file name(s), only
     d={d.name}.'; % <- file name(s)
     nf=numel(d);
for i=1:nf
     fprintf('working on %d/%d: %s\n',i,nf,d{i}); 
     A = dlmread(d{i},'\n'); 
     na = A(1,1);
     A(1,:) = [];
     for j=i+1:nf
        B = dlmread(d{j},'\n'); 
        nb = B(1,1);
        B(1,:) = [];      
       [h,p, max] = kstest2_cum(A,B,na,nb);
       fprintf('H = %d, P = %f, Dmax = %f \n',h,p,max); 
   % disp (  [h,p, max] );
     end
     %disp(M);
end
%disp(M);

A = dlmread('saf_3_1','\n');
B = dlmread('saf_3_3','\n');
nb = B(1,1);
 na = A(1,1);
A(1,:) = [];
B(1,:) = [];
%nb = B(1,1);
% na = A(1,1);
[h,p, max] = kstest2_cum(A,B,na,nb);
disp([h,p,max]);

%M(1,:) = [];
%disp(M);