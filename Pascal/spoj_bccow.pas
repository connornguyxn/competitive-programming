var a:array[0..100000000] of longint;
    n,c,mx,i:longint;
//////////////////////////////////////
procedure try(k,t:longint);
var i:longint;
    begin
    if (t > c) then
        begin
        exit();
        end;
    if (t > mx) then
        begin
        mx:=t;
        end;
    for i:=k to n do
        begin
        try(i,t+a[i]);
        end;
    end;
//////////////////////////////////////
begin
assign(input,'spoj_bccow.inp');reset(input);
//assign(output,'spoj_bccow.out');rewrite(output);
readln(c,n);
for i:=1 to n do
    begin
    readln(a[i]);
    end;
mx:=0;
try(1,0);
writeln(mx);
end.