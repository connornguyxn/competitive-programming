type intar = array[0..10000] of longint;
var d1,d2:intar;
    a,i,n,l,r,tcs,tc:longint;
///////////////////////////////////////
function cnt(l,r:longint;a:intar):longint;
    /////////////////
    begin
    exit(a[r] - a[l - 1]);
    end;
///////////////////////////////////////
begin
assign(input,'ucode_arrayarrange.inp');reset(input);
readln(n,tcs);
for i := 1 to n do
    begin
    read(a);
    d1[i] := d1[i - 1];
    d2[i] := d2[i - 1];
    if (a = 1) then
        d1[i] := d1[i] + 1
    else
        d2[i] := d2[i] + 1;
    end;
for tc := 1 to tcs do
    begin
    readln(l,r);
    
    writeln('YES');
    end;
end.