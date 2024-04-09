var c:array[0..3] of longint;
    a,n,i:longint;
///////////////////////////////////////
begin
readln(a,n);
c[0] := (a * a * a * a) mod 10;
c[1] := a mod 10;
c[2] := (a * a) mod 10;
c[3] := (a * a * a) mod 10;
writeln(c[n mod 4]);
end.
