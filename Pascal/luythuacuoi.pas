var du:array[0..3] of longint;
    a:ansistring;
    e:longint;
    n:qword;

begin
readln(a);
readln(n);
val(a[length(a)],du[0],e);
du[1]:=du[0]*du[0] mod 10;
du[2]:=du[1]*du[0] mod 10;
du[3]:=du[2]*du[0] mod 10;
writeln(du[(n-1) mod 4]);
end.