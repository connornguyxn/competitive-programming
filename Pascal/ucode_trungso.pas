var n:longint;
///////////////////////////////////////
begin
readln(n);
writeln(n div 100 + (n mod 100) div 20 + ((n mod 100) mod 20) div 10 + (((n mod 100) mod 20) mod 10) div 5 + (((n mod 100) mod 20) mod 10) mod 5)
end.