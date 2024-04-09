var a:array[1..10] of longint;
    n:longint;
/////////////////////////////////////
procedure try(k,t:longint);
var i,kq:longint;
    begin
    if k=10 then
        begin
        n:=n-1;
        if n=0 then
            begin
            a[10]:=t;
            kq:=0;
            for i:=1 to 10 do
                begin
                kq:=kq*10+a[i];
                end;
            writeln(kq);
            halt;
            end;
        end
    else
        begin
        for i:=0 to t do
            begin
            if i=10 then
                exit();
            a[k]:=i;
            try(k+1,t-i);
            end;
        end;
    end;
/////////////////////////////////////
begin
//assign(input,'ucode_sumdigit.inp');reset(input);
//assign(output,'ucode_sumdigit.out');rewrite(output);
readln(n);
n:=n+1;
try(1,10);
end.