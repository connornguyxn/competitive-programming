var days:array[0..6] of ansistring=('Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday');
    a:longint;

begin
readln(a);
writeln(days[a mod 7])
end.
