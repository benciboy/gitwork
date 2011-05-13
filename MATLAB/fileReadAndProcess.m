   
% fajlok beolvasasa es feldolgozasa
     d=dir('d*'); % <- retrieve all names: file(s) and folder(s)
     d=d(~[d.isdir]); % <- keep file name(s), only
     d={d.name}.'; % <- file name(s)
     nf=numel(d);
for i=1:nf
     fprintf('working on %d/%d: %s\n',i,nf,d{i});
     M = dlmread(d{i},'\n'); 
end
disp(M);

A = dlmread('data.txt','\n');
B = dlmread('data1.txt','\n');
[h,p] = kstest2(A,B);
disp([h,p]);