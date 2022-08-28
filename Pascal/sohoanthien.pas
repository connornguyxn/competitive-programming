var a,d,n,i,j,t:longint;
    kq:array[0..1000000] of longint;
///////////////////////////////////////
begin
assign(input,'test.inp');reset(input);
readln(n);
for j := 1 to n do
    begin
    read(a);
    t := 1;
    for i := 2 to (trunc(sqrt(a - 1))) do
        begin
        if (a mod i = 0) then
            t := t + i + a div i;
        if (t > a) then
            break;
        end;
    if (frac(sqrt(a)) = 0) then
        t := t + trunc(sqrt(a));
    if (t = a) then
        begin
        d := d + 1;
        kq[d] := a;
        end;
    end;
writeln(d);
for i := 1 to d do
    write(kq[i],' ');
end.
Số nguyên tố mersene là số nguyên tố có dạng 2^k-1 với k là số nguyên tố. Cho n số. Hỏi trong đó có
những số nào là số nguyên tố mersene?
đầu vào:
1 <= n <= 10^6
n số 1 <= n <= 10^6
đầu ra 
dãy gồm các số nguyên tố mersene