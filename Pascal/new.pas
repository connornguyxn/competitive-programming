type ar=array[1..100000] of longint;
var a:ar;
i,n:longint;

procedure sx(var a:ar;l,r:longint);
var i,j,tg:longint;
    begin
    for i:=l to r-1 do
        for j:=i+1 to r do
            begin
            if a[i]>a[j] then
                begin
                tg:=a[i];
                a[i]:=a[j];
                a[j]:=tg;
                end;
            end;
    end;

begin
assign(input,'new.inp');reset(input);
assign(output,'new.out');rewrite(output);
readln(n);
for i:=1 to n do
    read(a[i]);
sx(a,1,n);
for i:=1 to n do
    write(a[i], ' ');
end.
