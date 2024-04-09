var a,i:longint;
gt:qword;
begin
readln(a);
gt:=1;
for i:=1 to a mod 1000003 do
    gt:=gt*i mod 1000003;
writeln(gt mod 1000003);
end.
