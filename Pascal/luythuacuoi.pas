var du:array[0..3] of longint;
    a,n:ansistring;
    e,nr:longint;

begin
readln(a);
readln(n);
val(a[length(a)],du[0],e);
val(n[length(n)] + n[length(n) - 1],nr,e);
du[1]:=du[0]*du[0] mod 10;
du[2]:=du[1]*du[0] mod 10;
du[3]:=du[2]*du[0] mod 10;
writeln(du[(nr - 1) mod 4]);
end.