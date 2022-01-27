var v:array[0..10000000] of longint;
    t:array[0..10000000] of int64;
    n,k,mx:int64;
    p,i:longint;
///////////////////////////////////////
begin
//assign(input,'ntu_mobi.inp');reset(input);
readln(n,k);
for i := 1 to n do
    begin
    read(p);
    if (p > mx) then
        mx := p;
    readln(v[p]);
    end;
{for i := 0 to mx do
    write(v[i],' ');
writeln();}
for i := 0 to (k * 2) do
    t[k] := t[k] + v[i];
//writeln('t[k] = ',t[k]);
n := mx - k;
mx := t[k];
for i := (k + 1) to n do
    begin
    t[i] := t[i - 1] - v[i - k - 1] + v[i + k];
    if (t[i] > mx) then
        begin
        mx := t[i];
        //write('*');
        end;
    //write(i,' ');
    end;
writeln(mx);
end.