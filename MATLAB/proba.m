function [mean,stdev] = proba(x)
%PROBAS Summary of this function goes here
%   Detailed explanation goes here
%    getting first row to check column number
% for m = 1: length(A(1,:))

n = length(x);
mean = sum(x)/n;
stdev = sqrt(sum((x-mean).^2/n));

end

