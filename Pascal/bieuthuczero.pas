var n:longint;
    kq:array[0..100000000] of ansistring;
/////////////////////////////////
procedure print();
var i:longint;
    begin
    for i:=1 to n do
        begin
        if kq[i]<>'' then
            begin
            write(i,kq[i]);
            end;
        end;
    writeln();
    end;
///////////////////
procedure try(i,t:longint);
    begin
    if i=n+1 then
        begin
        if t=0 then
            begin
            print();
            end;
        end
    else
        begin
        kq[i]:='';
        try(i+1,t);
        kq[i]:='-';
        try(i+1,t-i);
        kq[i]:='+';
        try(i+1,t+i);
        end;
    end;
/////////////////////////////
begin
readln(n);
try(1,0);
end.