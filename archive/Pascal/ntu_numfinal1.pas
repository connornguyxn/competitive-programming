var c:array[0..3] of longint;
    s:ansistring;
    a,n,i:longint;
///////////////////////////////////////
begin
readln(s);
val(s[length(s)],a,i);
c[0] := (a * a * a * a) mod 10;
c[1] := a;
c[2] := (a * a) mod 10;
c[3] := (a * a * a) mod 10;
readln(s);
val(copy(s,length(s) - 1,2),n,i);
writeln(c[n mod 4]);
end.
