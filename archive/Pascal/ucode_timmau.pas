var x,y,i,n:longint;
    mau:array[0..1] of string = ('white','black');
///////////////////////////////////////
function dist(x,y:longint):longint;
    /////////////////
    begin
    dist := trunc(sqrt(sqr(x) + sqr(y)));
    if (frac(sqrt(sqr(x) + sqr(y))) > 0) then
        dist := dist + 1;
    end;
///////////////////////////////////////
begin
//assign(input,'ucode_timmau.inp');reset(input);
readln(n);
for i := 1 to n do
    begin
    readln(x);
    readln(y);
    if (x * y >= 0) then
        writeln(mau[dist(x,y) mod 2])
    else
        writeln(mau[(dist(x,y) + 1) mod 2]);
    end;
end.