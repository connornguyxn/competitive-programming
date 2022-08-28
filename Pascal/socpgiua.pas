var a,b:int64;

begin
readln(a,b);
if sqr(trunc(sqrt(a)))=a then write(sqr(trunc(sqrt(a)))-sqr(trunc(sqrt(b))))
    else write(sqr(trunc(sqrt(b)))-sqr(trunc(sqrt(a))));
readln;
end.