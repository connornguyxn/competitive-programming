var du:array[0..3] of longint;
    i,n,t,c:longint;
/////////////////////////////////////// 
begin
readln(n);
for i := 1 to n do
    begin
    read(c);
    t := t + c div 4;
    du[c mod 4] := du[c mod 4] + 1;
    end;
t := t + du[2] div 2;
du[2] := du[2] mod 2;
if (du[3] < du[1]) then
    begin
    t := t + du[3];
    du[1] := du[1] - du[3];
    t := t + du[1] div 4;
    du[1] := du[1] mod 4;
    t := t + du[1] mod 2 + du[1] div 2;
    end
else if (du[3] > du[1]) then
    begin
    t := t + du[1];
    du[3] := du[3] - du[1];
    t := t + du[3] + du[2];
    end
else
    begin
    t := t + du[3] + du[2];
    end;
writeln(t);
end.