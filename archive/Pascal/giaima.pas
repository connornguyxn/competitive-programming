var a:ansistring;

begin
assign(input, 'giaima.inp'); reset(input);
assign(output, 'giaima.out'); rewrite(output);
readln(a);
while pos(' #', a) <> 0 do
    delete(a, pos(' #', a) + 1, 1);
while pos('#', a) <> 0 do
    delete(a, pos('#', a) - 1, 2);
writeln(a);
end.