const
        nmax=9;
type
        data = byte;
var
        n:data;
        res:array[1..nmax]of data;
 
procedure xuat;
var     i:data;
begin
        for i:=1 to n do
                write(res[i]);
        writeln;
end;
 
procedure try(i:data);
var     j:data;
begin
if i>n then
    exit
else
    for j:=0 to 1 do
        begin
        res[i]:=j;
        writeln('res[',i,']=',j);
        try(i+1);
        end;
end;

begin
        readln(n);
        try(1);
end.